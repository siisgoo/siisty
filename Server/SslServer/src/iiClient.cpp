#include "SslServer/iiClient.hpp"

iiClient::iiClient(QSslSocket * socket, QObject * parent)
    : SslClientBase(socket, parent),
        _dbAssistant(new Database::DriverAssistant),
        _identified(false),
        _ident_tries(0)
{
    connect(_dbAssistant, SIGNAL(success(QJsonObject)), this, SIGNAL(identified(QJsonObject)));
    connect(_dbAssistant, SIGNAL(failed(Database::CmdError)),  this, SIGNAL(identificationFailed(Database::CmdError)));

    connect(this, SIGNAL(identified(QJsonObject)),
            this, SLOT(on_identified(QJsonObject)));
    connect(this, SIGNAL(identificationFailed(Database::CmdError)),
            this, SLOT(on_identificationFailed(Database::CmdError)));
}

iiClient::~iiClient()
{
    delete _dbAssistant;
}

bool iiClient::identified() const { return _identified; }

void
iiClient::identify(QString login, QString password)
{
    _login = login;
    _password = password;
    Q_EMIT logMessage("Trying identify user", Debug);
    Q_EMIT addCommand({(int)Database::RoleId::AUTO,
            QJsonObject{
                { "command", (int)Database::CommandId::IDENTIFY },
                { "arg",
                    QJsonObject{
                        { "login", _login, },
                        { "password", _password },
                    }
                }
            },
            _dbAssistant});
}

void
iiClient::on_identified(QJsonObject obj)
{
    disconnect(_dbAssistant, SIGNAL(success(QJsonObject)), this, SIGNAL(identified(QJsonObject)));
    disconnect(_dbAssistant, SIGNAL(failed(Database::CmdError)), this, SIGNAL(identificationFailed(Database::CmdError)));

    disconnect(this, SIGNAL(identified(QJsonObject)),
               this, SLOT(on_identified(QJsonObject)));
    disconnect(this, SIGNAL(identificationFailed(Database::CmdError)),
               this, SLOT(on_identificationFailed(Database::CmdError)));

    connect(_dbAssistant, SIGNAL(success(QJsonObject)), this, SIGNAL(requestSuccess(QJsonObject)));
    connect(_dbAssistant, SIGNAL(failed(QJsonObject)),  this, SIGNAL(requestFailed(Database::CmdError)));

    _identified = true;

    QJsonDocument doc(obj); // must contain role and basic user information
    QByteArray res = iiNPack::pack(doc.toJson(QJsonDocument::Compact), iiNPack::RESPONSE);

    Q_EMIT logMessage("Identified user: " + obj["name"].toString(), Trace);

    this->sendMessage(res);

    _password.clear();
}

void
iiClient::on_identificationFailed(Database::CmdError err)
{
    /* _ident_tries++; */
    /* if (_ident_tries > _max_tries) { // make configurable */
    /*     this->disconnectFromHost(); */
    /*     // TODO set timeout for connect avalible again */
    /*     return; */
    /* } */

    Q_EMIT logMessage("User identification error: " + err.String(), Debug);

    QByteArray res = iiNPack::packError(err.String(), iiNPack::ACCESS_DENIED);
    this->sendMessage(res);
    /* this->waitForBytesWritten(); */
    this->disconnectFromHost();
}

void
iiClient::processRequest(QJsonObject obj)
{

}

void
iiClient::processResponce(QJsonObject obj)
{

}
