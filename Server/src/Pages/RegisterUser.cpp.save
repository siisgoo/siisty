#include "Pages/Users/RegisterUser.hpp"
#include "ui_RegisterUser.h"

#include <QPixmap>
#include <QMimeDatabase>
#include <QFileSystemModel>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "Database/Database.hpp"

class FileSystemModel : public QFileSystemModel {
    public:
        FileSystemModel(QObject *parent = nullptr)
            : QFileSystemModel(parent) {  }
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
        {
            if (role == Qt::DisplayRole && index.column() == 0) {
                QString path = QDir::toNativeSeparators(filePath(index));
                if (path.endsWith(QDir::separator())) path.chop(1);
                return path;
            }

            return QFileSystemModel::data(index, role);
        }
};

RegisterUser::RegisterUser(const QMap<Database::RoleId, Database::Driver::role_set>& roles, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::RegisterUser),
        _dbRWaiter(new Database::DriverAssistant()),
        _dbWWaiter(new Database::DriverAssistant()),
        _filePathCompleter(new QCompleter(this))
{
    ui->setupUi(this);

    for (auto role : roles) {
        if (role.id != Database::ROLE_AUTO) {
            ui->role_cb->addItem(role.name, role.id);
        }
    }

    connect(_dbRWaiter, SIGNAL(success(QJsonObject)), this, SLOT(on_saveSuccess(QJsonObject)));
    connect(_dbRWaiter, SIGNAL(failed(Database::CmdError)), this, SLOT(on_saveFailed(Database::CmdError)));

    connect(_dbWWaiter, SIGNAL(success(QJsonObject)), this, SLOT(on_waponsFetched(QJsonObject)));
    connect(_dbWWaiter, SIGNAL(failed(Database::CmdError)), this, SLOT(on_waponsFetchFailed(Database::CmdError)));

    connect(ui->openImageFile_btn, SIGNAL(clicked()), this, SLOT(openImgFileChooer()));

    connect(ui->image_path_edit, SIGNAL(textChanged(QString)), this, SLOT(validateImgFilePath(QString)));

    connect(this, SIGNAL(imgFileValid()), this, SLOT(on_imgFilePathValid()));
    connect(this, SIGNAL(imgFileNotValid()), this, SLOT(on_imgFilePathNotValid()));

    _filePathCompleter->setModel(new FileSystemModel(_filePathCompleter));
    _filePathCompleter->setCompletionRole(Qt::DisplayRole);
    _filePathCompleter->setCompletionMode(QCompleter::PopupCompletion);
    ui->image_path_edit->setCompleter(_filePathCompleter);

    ui->entryDate_edit->setMaximumDate(QDate::currentDate());
    ui->entryDate_edit->setDate(QDate::currentDate());

    connect(ui->update_wapons, SIGNAL(clicked()), this, SLOT(requestWaponDetails()));

    auto name = ui->name_edit;
    auto login = ui->login_edit;
    auto pass = ui->password_edit;
    auto date = ui->entryDate_edit;
    auto wapon = ui->wapon_cb;
    auto role = ui->role_cb;
    auto email = ui->email_edit;
    auto image = ui->image_path_edit;
    auto imagebtn = ui->openImageFile_btn;
    auto accept = ui->register_buttons;

    QVector<QWidget *> widgets{ name, login, pass, date, wapon, role, email, image, imagebtn, accept };
    for (int i = 0; i < widgets.length()-1; ++i) {
        ui->frame_2->setTabOrder(widgets[i], widgets[i+1]);
    }

    /* requestWaponDetails(); */
    QTimer::singleShot(1000, [this](){ requestWaponDetails(); });
}

RegisterUser::~RegisterUser()
{
    delete _filePathCompleter;
    delete _dbWWaiter;
    delete _dbRWaiter;
    delete ui;
}

void RegisterUser::on_dbWaponsChanged() { requestWaponDetails(); }

void
RegisterUser::requestWaponDetails()
{
    Q_EMIT requestedWaponDetails({Database::ROLE_AUTO,
            QJsonObject{
                { "command", Database::CMD_GET_WAPON_DETAILS },
                { "arg",
                    QJsonObject{
                        { "wapon", "*" },
                        { "where", "WHERE employee_id IS NULL" },
                        { "takeImage", true },
                    }
                }
            },
            _dbWWaiter});
}

void
RegisterUser::on_waponsFetched(QJsonObject obj)
{
    ui->wapon_cb->clear();
    QJsonArray wapons = obj.take("wapons").toArray();

    for (auto wapon : wapons) {
        QJsonObject cur = wapon.toObject();
        ui->wapon_cb->addItem(
                QIcon(QIconFromQString(cur["image"].toString())),
                QString::number(cur["id"].toInteger()) + " - " + cur["name"].toString(),
                cur["id"].toInteger());
    }
}

void RegisterUser::on_waponsFetchFailed(Database::CmdError e) { Q_EMIT logMessage(e.String(), Error); }

void RegisterUser::on_saveFailed(Database::CmdError err) { Q_EMIT logMessage("Cannot register new user: " + err.String(), LoggingLevel::Error); }

void
RegisterUser::on_saveSuccess(QJsonObject obj)
{
    this->on_register_buttons_rejected();
        //clear
}

void
RegisterUser::on_register_buttons_accepted()
{
    QJsonObject data = QJsonObject{
        { "command", Database::CMD_REGISTER_EMPLOYEE },
        { "arg",
            QJsonObject{
                { "login", ui->login_edit->text() },
                { "password", ui->password_edit->text() },
                { "name", ui->name_edit->text() },
                { "entryDate", ui->entryDate_edit->dateTime().toSecsSinceEpoch() },
                { "wapon", ui->wapon_cb->currentData().toInt() },
                { "role", ui->role_cb->currentData().toInt() },
                { "email", ui->email_edit->text() },
                { "image", QStringFromQImage(QImage(ui->image_path_edit->text())) } // TODO
            }
        }
    };

    Q_EMIT registrateUser({Database::ROLE_AUTO, data, _dbRWaiter});
}


void
RegisterUser::on_register_buttons_rejected()
{
    ui->email_edit->setText("");
    ui->login_edit->setText("");
    ui->entryDate_edit->setDate(QDate::currentDate());
    ui->password_edit->setText("");
    ui->image_path_edit->setText("");
}

void
RegisterUser::validateImgFilePath(QString file)
{
    if (file.length()) {
        QMimeDatabase db;
        QMimeType mime = db.mimeTypeForFile(file);

        QRegularExpression r("(image/)");
        if (!QFile(file).exists() ||
                !r.match(mime.name()).hasMatch())
        {
            Q_EMIT imgFileNotValid();
            return;
        }
    }
    Q_EMIT imgFileValid();
}

void RegisterUser::on_imgFilePathValid() { ui->image_path_edit->setStyleSheet(""); }
void RegisterUser::on_imgFilePathNotValid() { ui->image_path_edit->setStyleSheet("color: #ba3939; background: #ffe0e0; border: 1px solid #a33a3a;"); }

void
RegisterUser::openImgFileChooer()
{
    _fileChooser = new QFileDialog(this,
            tr("Open image"), QDir::currentPath(), tr("Image Files (*.png *.jpg *.bmp)"));
    _fileChooser->setFileMode(QFileDialog::FileMode::ExistingFile);
    _fileChooser->show();
    if (_fileChooser->exec() == QDialog::Accepted) {
        ui->image_path_edit->setText(_fileChooser->selectedFiles()[0]);
    }
}
