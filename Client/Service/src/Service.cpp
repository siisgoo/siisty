#include "Client/Service/Service.hpp"

#include <QJsonDocument>
#include <QJsonParseError>
#include <qnamespace.h>

ResponseWaiter::ResponseWaiter(QObject * p)
    : QObject(p)
{ }

ResponseWaiter::~ResponseWaiter()
{ }

void ResponseWaiter::set_failed(int n, QString desc) { Q_EMIT failed(n, desc); }
void ResponseWaiter::set_success(QJsonObject obj) { Q_EMIT success(obj); }

/*------------------------------------------*/

Service::Service(QObject *p)
    : SslClientBase(new QSslSocket(), p)
{
    connect(this, SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this, SLOT(on_networkError(QAbstractSocket::SocketError)));
    connect(_control, SIGNAL(sslErrors(const QList<QSslError> &)),
            this, SLOT(on_sslError(const QList<QSslError> &)));
    connect(_control, SIGNAL(peerVerifyError(const QList<QSslError> &)),
            this, SLOT(on_sslError(const QList<QSslError> &)));
    /* connect(this, SIGNAL(proxyAuthenticationRequired(const QNetworkProxy &, QAuthenticator *)), this, */
    /*         SLOT(on_proxyAuthenticationRequired(const QNetworkProxy &, QAuthenticator *))); */
}

Service::~Service()
{
}

void
Service::sendCommand(QJsonObject load, ResponseWaiter * waiter)
{
    qint64 stamp = QDateTime::currentSecsSinceEpoch();
    _waiters[stamp] = waiter;

    /* qDebug() << "sending request to server " << load; */

    // TODO add check
    QJsonDocument d;
    d.setObject(load);
    this->sendMessage(iiNPack::pack(d.toJson(QJsonDocument::Compact),
                                    iiNPack::REQUEST, 0,
                                    stamp));
}

void
Service::parseResonce(iiNPack::Header header, QByteArray load)
{
    if (header.PacketLoadType != iiNPack::JSON) {
        _waiters[header.ClientStamp]->set_failed(
            iiNPack::UNSUPPORTED_FORMAT, "Resived unsupported load format");
    } else {
        load.resize(header.Size-iiNPack::HeaderSize);
        // TODO move unpack json doc to function
        switch (header.PacketType) {
            case iiNPack::RESPONSE:
                {
                    QJsonParseError err;
                    QJsonDocument res = QJsonDocument::fromJson(load, &err);
                    if (err.error == QJsonParseError::NoError) {

                    } else {
                        _waiters[header.ClientStamp]->set_failed(
                            iiNPack::PARSE_ERROR,
                            "Parse responce error: " + err.errorString());
                        break;
                    }
                    if (res.isObject()) {
                        _waiters[header.ClientStamp]->set_success(res.object());
                    } else {
                        _waiters[header.ClientStamp]->set_failed(
                            iiNPack::PARSE_ERROR,
                            "Parse responce error: Load is NULL");
                    }
                }
                break;
            case iiNPack::PacketType::ERROR_MESSAGE:
                {
                    QJsonParseError err;
                    QJsonDocument res = QJsonDocument::fromJson(load, &err);
                    if (err.error == QJsonParseError::NoError) {

                    } else {
                        _waiters[header.ClientStamp]->set_failed(
                            iiNPack::PARSE_ERROR,
                            "Parse responce error: " + err.errorString());
                        break;
                    }
                    if (res.isObject()) {
                        QJsonObject obj = res.object();
                        _waiters[header.ClientStamp]->set_failed(
                            obj["errno"].toInt(), obj["details"].toString());
                    } else {
                        _waiters[header.ClientStamp]->set_failed(
                            iiNPack::PARSE_ERROR,
                            "Parse responce error occured when "
                            "parsing error message: " +
                                err.errorString());
                    }
                }
                break;
            default:
                qDebug() << "Something wrong " << load;
                /* _waiters[header.ClientStamp]->set_failed( */
                /*     iiNPack::UNSUPPORTED_TYPE, */
                /*     "Recived unsupported packet type"); */
                break;
        }
    }
    _waiters.remove(header.ClientStamp);
}

void
Service::on_networkError(QAbstractSocket::SocketError err)
{
    qDebug() << "Error network output not implemented yet";
    // TODO add reconnect attemts in some error reasons
    /* set_failed(iiNPack::NETWORK_ERROR, */
    /*                                          _control->errorString()); */
}

// TODO
void
Service::on_sslError(const QList<QSslError>& errs)
{
    QString err;
    for (auto se : errs) {
        err += se.errorString() + '\n';
    }
    /* Q_EMIT commandFailed(iiNPack::NETWORK_ERROR, err); */
}

void
Service::login(const QString& login, const QString& password)
{
    QJsonDocument doc;
    doc.setObject({
        { "login", login },
        { "password", password }
    });

    connect(this, SIGNAL(recivedMessage(iiNPack::Header, QByteArray)),
            this, SLOT(parseLoginResponce(iiNPack::Header, QByteArray)), Qt::SingleShotConnection);

    this->sendMessage(iiNPack::pack(doc.toJson(QJsonDocument::Compact),
                                    iiNPack::AUTORIZATION_REQUEST, 0,
                                    QDateTime::currentSecsSinceEpoch()));
}

void
Service::parseLoginResponce(iiNPack::Header header, QByteArray load)
{
    if (header.PacketLoadType != iiNPack::JSON) {
        Q_EMIT loginFailed(iiNPack::UNSUPPORTED_FORMAT, "Resived unsupported load format");
        return;
    }
    QJsonParseError err;
    QJsonDocument res = QJsonDocument::fromJson(load, &err);
    if (err.error == QJsonParseError::NoError) {
        if (res.isObject()) {
            QJsonObject obj = res.object();

            if (header.PacketType == iiNPack::PacketType::ERROR_MESSAGE) {
                Q_EMIT loginFailed(obj["errno"].toInt(), obj["details"].toString());
            } else if (header.PacketType == iiNPack::PacketType::RESPONSE) {
                // TODO add disconnect on socket disconnected
                connect(this, SIGNAL(recivedMessage(iiNPack::Header, QByteArray)),
                        this, SLOT(parseResonce(iiNPack::Header, QByteArray)));

                Q_EMIT loginSuccess(obj["name"].toString(), obj["role"].toInt(), obj["id"].toString().toInt());
            } else {
                qDebug() << "Something wrong...... TODO";
            }
        } else {
            Q_EMIT loginFailed(iiNPack::PARSE_ERROR,
                               "Parse responce error: null obj passed");
        }
    } else {
        Q_EMIT loginFailed(iiNPack::PARSE_ERROR,
                           "Parse responce error: " + err.errorString());
    }
}
