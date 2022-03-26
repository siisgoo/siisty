#include "RoleSetup/General/Profile.hpp"
#include "ui_Profile.h"
#include <qnamespace.h>

Profile::Profile(bool HideWapon, QWidget *parent) :
    QWidget(parent),
        ui(new Ui::Profile)
{
    ui->setupUi(this);
    if (HideWapon) {
        ui->waponValue->hide();
        ui->waponLabel->hide();
    }

    QPixmap pi = QPixmap(":icons/noProfileImage");
    ui->personaImage->setPixmap(pi.scaled(218, 218, Qt::AspectRatioMode::KeepAspectRatio, Qt::FastTransformation));
}

Profile::~Profile()
{
    delete ui;
}

void
Profile::dataLoaded(QJsonObject data)
{

}
