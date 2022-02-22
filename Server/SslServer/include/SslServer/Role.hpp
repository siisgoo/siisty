#ifndef ROLE_HPP_TLNRD93C
#define ROLE_HPP_TLNRD93C

#include <QPointer>
#include <QPair>
#include <QList>
#include <QString>

enum class PrivilegyOperations {
    OPERATION_READ  = 0x1,
    OPERATION_WRITE = 0x2,
};

class Privilegy {
    public:
        Privilegy();

        virtual ~Privilegy();
    private:
        using PrivilegyList = QList<QPair<PrivilegyOperations, QString>>;

        PrivilegyList _accessible_databases;
        PrivilegyList _accessible_tables;
};

class Role {
    public:

        QString name() const;

        virtual ~Role();
    protected:
        Role(int id, const QString& name, const Privilegy& privel);
        Privilegy _privelegies;
        QString   _name;
        int       _id;
};

class Admin : public Role {

};

class Security : public Role {

};

class Inkosor : public Role {

};

class Reqruiter : public Role {

};

using ptrRole = QPointer<Role>;

#endif /* end of include guard: ROLE_HPP_TLNRD93C */
