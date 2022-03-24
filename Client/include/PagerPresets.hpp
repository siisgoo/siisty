#ifndef PAGERPRESETS_HPP_CCDGDJA4
#define PAGERPRESETS_HPP_CCDGDJA4

#include <functional>
#include <QMap>

#include "PagesManager/PagesManager.hpp"
#include "Database/Role.hpp"

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

using pagemanSetuper = std::function<void(PagesManager * )>;

inline pagemanSetuper admin = [](PagesManager* pm) {
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

inline pagemanSetuper security = [](PagesManager* pm) {
};

inline pagemanSetuper recruter = [](PagesManager* pm) {
};

inline pagemanSetuper incosor = [](PagesManager* pm) {
};

inline pagemanSetuper waponManager = [](PagesManager* pm) {
};

inline pagemanSetuper customer = [](PagesManager* pm) {
};

inline QMap<int, pagemanSetuper> pagerPresets{
    { Database::ROLE_Admin,        admin },
    { Database::ROLE_Security,     security },
    { Database::ROLE_Recruter,     recruter },
    { Database::ROLE_Inkosor,      incosor },
    { Database::ROLE_WaponManager, waponManager },
    { Database::ROLE_Customer,     customer },
};

#endif /* end of include guard: PAGERPRESETS_HPP_CCDGDJA4 */
