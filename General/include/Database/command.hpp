#ifndef COMMAND_HPP_KQHNGFS8
#define COMMAND_HPP_KQHNGFS8

#include <QObject>
#include <QJsonDocument>
#include <QRunnable>

#define COMMANDS_ERRNO_MAP(XX) \
    XX( 0, OK,             "Success" )                   \
    XX( 1, InvalidParam,   "Invalid command parameter" ) \
    XX( 2, AccessDenied,   "Access denied" )             \
    XX( 3, InvalidCommand, "Invalid command passed" )    \
    XX( 4, MiscError,      "Misc error" )                \
    XX( 5, SQLError,       "SQL Query Error" )           \

// id, name, executor, sendback
#define COMMANDS_MAP(XX) \
    XX( 0,  MAKE_CONTRACT,        exec_make_contract,        false ) \
    XX( 1,  MAKE_DUTY_SCHEDULE,   exec_make_duty_schedule,   false ) \
    XX( 2,  REGISTER_ACCIDENT,    exec_register_accident,    false ) \
    XX( 3,  REGISTER_EMPLOYEE,    exec_register_employee,    false ) \
    XX( 4,  REGISTER_CUSTOMER,    exec_register_customer,    false ) \
    XX( 5,  REGISTER_OBJECT_TYPE, exec_register_object_type, false ) \
    XX( 6,  REGISTER_WAPON,       exec_register_wapon,       false ) \
    XX( 7,  ASSIGN_WAPON,         exec_assign_wapon,         false ) \
    XX( 8,  PAY_AMMO,             exec_pay_ammo,             false ) \
    XX( 9,  PAY_EMPLOYEE,         exec_pay_employee,         false ) \
    XX( 10, PAY_ACCIDENT,         exec_pay_accident,         false ) \
    XX( 11, ADD_OBJECT_TYPE,      exec_add_object_type,      false ) \
    XX( 12, EDIT_OBJECT_TYPE,     exec_edit_object_type,     false ) \
    XX( 13, UPDATE_ROLE,          exec_update_role,          false ) \
    XX( 14, GET_EMPLOYEE_ENTRY,   exec_get_employee_entry,   true  ) \
    XX( 15, GET_CUSTOMER_ENTRY,   exec_get_customer_entry,   true  ) \
    XX( 16, GET_ACCIDENT_DETAILS, exec_get_accident_details, true  ) \
    XX( 17, GET_ACCOUNTING_ENTRY, exec_get_accounting_entry, true  ) \
    XX( 18, GET_OBJECT_DETAILS,   exec_get_object_detalils,  true  ) \
    XX( 19, GET_ROLE_DETAILS,     exec_get_role_details,     true  ) \
    XX( 20, GET_WAPON_DETAILS,    exec_get_wapon_details,    true  ) \
    XX( 21, GET_DUTY_SCHEDULE,    exec_get_duty_schedule,    true  ) \

namespace Database {

QString encryptAuth(const QByteArray&);
    // password cipher

class CmdError {
    public:
        #define XX(id, name, str) name = id,
            enum ErrorNo {
                COMMANDS_ERRNO_MAP(XX)
            };
        #undef XX

        CmdError(); //mean no error
        CmdError(CmdError::ErrorNo, QString = "");

        bool Ok();

        int Type();
        QString String();
        QString Name();
        QString Details();

    private:
        CmdError::ErrorNo _errno;
        QString _details;
};

using command_exec_t = std::function<CmdError(QJsonObject&)>;

CmdError exec_make_contract(QJsonObject& d);
CmdError exec_make_duty_schedule(QJsonObject& d);
CmdError exec_register_accident(QJsonObject& d);
CmdError exec_register_employee(QJsonObject& d);
CmdError exec_register_customer(QJsonObject& d);
CmdError exec_register_object_type(QJsonObject& d);
CmdError exec_register_wapon(QJsonObject& d);
CmdError exec_assign_wapon(QJsonObject& d);
CmdError exec_pay_ammo(QJsonObject& d);
CmdError exec_pay_employee(QJsonObject& d);
CmdError exec_pay_accident(QJsonObject& d);
CmdError exec_add_object_type(QJsonObject& d);
CmdError exec_edit_object_type(QJsonObject& d);
CmdError exec_update_role(QJsonObject& d);
CmdError exec_get_employee_entry(QJsonObject& d);
CmdError exec_get_customer_entry(QJsonObject& d);
CmdError exec_get_accident_details(QJsonObject& d);
CmdError exec_get_accounting_entry(QJsonObject& d);
CmdError exec_get_object_detalils(QJsonObject& d);
CmdError exec_get_role_details(QJsonObject& d);
CmdError exec_get_wapon_details(QJsonObject& d);
CmdError exec_get_duty_schedule(QJsonObject& d);
    // mean validate and execute
    // on success return 0 or CommandErrno::OK
    // on faild return error number

/* int exec_do_payment(); */
/* int exec_ */

#define XX(id, name, e, s) name = id,
    enum class CommandId {
        COMMANDS_MAP(XX)
        COMMANDS_COUNT
    };
#undef XX

} /*  Database  */
#endif /* end of include guard: COMMAND_HPP_KQHNGFS8 */
