#include "Service.hpp"

#include <QJsonDocument>
#include <QJsonParseError>
#include <qnamespace.h>

Service::Service(QObject *p)
    : SslClientBase(new QSslSocket(), p)
{
    connect(this, SIGNAL(recivedMessage(iiNPack::Header, QByteArray)),
            this, SLOT(parseResonce(iiNPack::Header, QByteArray)));

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
Service::parseResonce(iiNPack::Header header, QByteArray load)
{
    if (header.PacketLoadType != iiNPack::JSON) {
        Q_EMIT commandFailed(iiNPack::UNSUPPORTED_FORMAT,
                             "Resived unsupported load format");
    }

    // TODO move unpack json doc to function
    switch (header.PacketType) {
        case iiNPack::RESPONSE:
            {
                QJsonParseError err;
                QJsonDocument res = QJsonDocument::fromJson(load, &err);
                if (err.error == QJsonParseError::NoError) {

                } else {
                    Q_EMIT commandFailed(
                        iiNPack::PARSE_ERROR,
                        "Parse responce error: " + err.errorString());
                    break;
                }
                if (res.isObject()) {
                    Q_EMIT commandSuccess(res.object());
                } else {
                    Q_EMIT commandFailed(iiNPack::PARSE_ERROR,
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
                    Q_EMIT commandFailed(
                        iiNPack::PARSE_ERROR,
                        "Parse responce error: " + err.errorString());
                    break;
                }
                if (res.isObject()) {
                    QJsonObject obj = res.object();
                    Q_EMIT commandFailed(obj["errno"].toInt(),
                                         obj["details"].toString());
                } else {
                    Q_EMIT commandFailed(iiNPack::PARSE_ERROR,
                                         "Parse responce error occured when "
                                         "parsing error message: " +
                                             err.errorString());
                }
            }
            break;
        default:
            Q_EMIT commandFailed(iiNPack::UNSUPPORTED_TYPE,
                                 "Recived unsupported packet type");
            break;
    }
}

void
Service::on_networkError(QAbstractSocket::SocketError err)
{
    // TODO add reconnect attemts in some error reasons
    Q_EMIT commandFailed(iiNPack::NETWORK_ERROR, _control->errorString());
}

// TODO
void
Service::on_sslError(const QList<QSslError>& errs)
{
    QString err;
    for (auto se : errs) {
        err += se.errorString() + '\n';
    }
    Q_EMIT commandFailed(iiNPack::NETWORK_ERROR, err);
}

void
Service::login(const QString& login, const QString& password)
{
    QJsonDocument doc;
    doc.setObject({
        { "login", login },
        { "password", password }
    });

    connect(this, SIGNAL(commandSuccess(QJsonObject)),
            this, SLOT(parseLoginResponce(QJsonObject)), Qt::SingleShotConnection);
    connect(this, SIGNAL(commandFailed(int, QString)),
            this, SIGNAL(loginFailed(int, QString)), Qt::SingleShotConnection);

    this->sendMessage(iiNPack::pack(doc.toJson(QJsonDocument::Compact),
                                    iiNPack::AUTORIZATION_REQUEST));
}

void
Service::parseLoginResponce(QJsonObject obj)
{
    Q_EMIT loginSuccess(obj["name"].toString(), obj["role"].toInt(), obj["id"].toInt());
}

void
Service::sendCommand(QJsonObject& load)
{
    QJsonDocument d;
    d.setObject(load);
    this->sendMessage(
        iiNPack::pack(d.toJson(QJsonDocument::Compact), iiNPack::REQUEST));
}
