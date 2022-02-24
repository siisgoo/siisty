#ifndef AUTHORITYMANAGER_HPP_FRVCZGUD
#define AUTHORITYMANAGER_HPP_FRVCZGUD

#include <QString>

/*
 * Purpose: accepts data exchange with client by role privilegies
 * and check login data recived from client
 */
class AuthorityManager {
    public:
        AuthorityManager();

        bool isAuthorized(const QString& login, const QString& password);

        virtual ~AuthorityManager ();
    private:
};

#endif /* end of include guard: AUTHORITYMANAGER_HPP_FRVCZGUD */
