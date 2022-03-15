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
    XX( 0,  MAKE_CONTRACT,        exec_make_contract      ) \
    XX( 1,  MAKE_DUTY_SCHEDULE,   exec_make_duty_schedule ) \
    XX( 2,  REGISTER_ACCIDENT,    exec_register_accident  ) \
    XX( 3,  REGISTER_EMPLOYEE,    exec_register_employee  ) \
    XX( 4,  REGISTER_CUSTOMER,    exec_register_customer  ) \
    XX( 5,  REGISTER_OBJECT_TYPE, exec_register_object_type) \
    XX( 6,  REGISTER_WAPON,       exec_register_wapon     ) \
    XX( 7,  ASSIGN_WAPON,         exec_assign_wapon       ) \
    XX( 8,  PAY_AMMO,             exec_pay_ammo           ) \
    XX( 9,  PAY_EMPLOYEE,         exec_pay_employee       ) \
    XX( 10, PAY_ACCIDENT,         exec_pay_accident       ) \
    XX( 11, ADD_OBJECT_TYPE,      exec_add_object_type    ) \
    XX( 12, EDIT_OBJECT_TYPE,     exec_edit_object_type   ) \
    XX( 13, UPDATE_ROLE,          exec_update_role        ) \
    XX( 14, GET_EMPLOYEE_ENTRY,   exec_get_employee_entry ) \
    XX( 15, GET_CUSTOMER_ENTRY,   exec_get_customer_entry ) \
    XX( 16, GET_ACCIDENT_DETAILS, exec_get_accident_details) \
    XX( 17, GET_ACCOUNTING_ENTRY, exec_get_accounting_entry) \
    XX( 18, GET_OBJECT_DETAILS,   exec_get_object_detalils) \
    XX( 19, GET_ROLE_DETAILS,     exec_get_role_details   ) \
    XX( 20, GET_WAPON_DETAILS,    exec_get_wapon_details  ) \
    XX( 21, GET_DUTY_SCHEDULE,    exec_get_duty_schedule  ) \
    XX( 22, CREATE_TABLE,         exec_create_table       ) \
    XX( 23, IDENTIFY,             exec_identify           ) \

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

using command_exec_t = std::function<CmdError(QJsonObject)>;

// AUTO only commands
/* CmdError exec_add_role(QJsonObject obj); */
/* CmdError exec_send_moneys(QJsonObject obj); */
CmdError exec_create_table(QJsonObject obj);
CmdError exec_identify(QJsonObject obj);

// Role avalible commands
CmdError exec_make_contract(QJsonObject obj);
CmdError exec_make_duty_schedule(QJsonObject obj);
CmdError exec_register_accident(QJsonObject obj);
CmdError exec_register_employee(QJsonObject obj);
CmdError exec_register_customer(QJsonObject obj);
CmdError exec_register_object_type(QJsonObject obj);
CmdError exec_register_wapon(QJsonObject obj);
CmdError exec_assign_wapon(QJsonObject obj);
CmdError exec_pay_ammo(QJsonObject obj);
CmdError exec_pay_employee(QJsonObject obj);
CmdError exec_pay_accident(QJsonObject obj);
CmdError exec_add_object_type(QJsonObject obj);
CmdError exec_edit_object_type(QJsonObject obj);
CmdError exec_update_role(QJsonObject obj);
CmdError exec_get_employee_entry(QJsonObject obj);
CmdError exec_get_customer_entry(QJsonObject obj);
CmdError exec_get_accident_details(QJsonObject obj);
CmdError exec_get_accounting_entry(QJsonObject obj);
CmdError exec_get_object_detalils(QJsonObject obj);
CmdError exec_get_role_details(QJsonObject obj);
CmdError exec_get_wapon_details(QJsonObject obj);
CmdError exec_get_duty_schedule(QJsonObject obj);
    // mean validate and execute
    // on success return 0 or CommandErrno::OK
    // on faild return error number

/* int exec_do_payment(); */
/* int exec_ */

#define XX(id, name, e) name = id,
    enum class CommandId {
        COMMANDS_MAP(XX)
        COMMANDS_COUNT
    };
#undef XX

} /*  Database  */
#endif /* end of include guard: COMMAND_HPP_KQHNGFS8 */
