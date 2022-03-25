#ifndef PAGERPRESETS_HPP_CCDGDJA4
#define PAGERPRESETS_HPP_CCDGDJA4

#define MAIN_PAGE_ID -1092837
    // try true unique

#include <functional>
#include <QMap>

#include "PagesManager/PagesManager.hpp"
#include "Database/Role.hpp"

#include "MainPage.hpp"

#include "RoleSetup/Admin/AdminMain.hpp"
#include "RoleSetup/Admin/Accidents.hpp"
#include "RoleSetup/Admin/AccidentList.hpp"
#include "RoleSetup/Admin/ObjectTypeAdministration.hpp"
#include "RoleSetup/Admin/RegisterAccidentDialog.hpp"
#include "RoleSetup/Admin/RoleManagment.hpp"
#include "RoleSetup/Admin/UsersList.hpp"

#include "RoleSetup/General/Profile.hpp"
#include "RoleSetup/General/DebugConsole.hpp"
#include "RoleSetup/General/DutySchedule.hpp"
#include "RoleSetup/General/PersonalAccounting.hpp"

#include "Service.hpp"

using pagemanSetuper = std::function<void(QMainWindow *, PagesManager *, Service *)>;

inline pagemanSetuper mainPage = [](QMainWindow * w, PagesManager * pm, Service *) {
    pm->reset();
    QWidget * ml = new MainPage;
    pm->addRoot("Main", ml);

    ml->connect(ml, SIGNAL(employeeLoginClicked()), w, SLOT(showLogin()));
    /* ml->connect(ml, SIGNAL(cusomerLoginClicked()), w, SLOT(showLogin())); */

    pm->finalize();
};

inline pagemanSetuper admin = [](QMainWindow *, PagesManager * pm , Service *) {
    pm->reset();
    pm->addRoot("Admin", new AdminMain, { "Profile", "Accidents", "Object types", "PSC Roles", "Users list", "Help" });
    pm->addPage("Profile", new Profile, { "Accounting", "Schedule" });
    pm->addPage("Accounting", new PersonalAccounting);
    pm->addPage("Schedule", new DutySchedule);
    pm->addPage("Accidents", new AccidentList);
    pm->addPage("Object types", new ObjectTypeAdministration);
    pm->addPage("PSC Roles", new RoleManagment);
    pm->addPage("Users list", new UsersList);

    pm->finalize();
};

inline pagemanSetuper security = [](QMainWindow *, PagesManager * , Service *) {
};

inline pagemanSetuper recruter = [](QMainWindow *, PagesManager * , Service *) {
};

inline pagemanSetuper incosor = [](QMainWindow *, PagesManager * , Service *) {
};

inline pagemanSetuper waponManager = [](QMainWindow *, PagesManager * , Service *) {
};

inline pagemanSetuper customer = [](QMainWindow *, PagesManager * , Service *) {
};

inline QMap<int, pagemanSetuper> pagerPresets{
    { MAIN_PAGE_ID,                mainPage },
    { Database::ROLE_Admin,        admin },
    { Database::ROLE_Security,     security },
    { Database::ROLE_Recruter,     recruter },
    { Database::ROLE_Inkosor,      incosor },
    { Database::ROLE_WaponManager, waponManager },
    { Database::ROLE_Customer,     customer },
};

#endif /* end of include guard: PAGERPRESETS_HPP_CCDGDJA4 */
