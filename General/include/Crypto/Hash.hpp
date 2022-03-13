#ifndef HASH_HPP_5XQNUTL6
#define HASH_HPP_5XQNUTL6

#include <QByteArray>
#include <QCryptographicHash>
#include <QString>

enum charWeakness : quint8 {
    Alpha = 0x1,
    Digit = 0x2,
    Special = 0x4,
};

const quint32 salt_length(32);
    // mean xxx system max unique password
    // if /dev/urandom will not fail :)

QByteArray saltGen(quint8 weakness_f);
quint8 passWeaknesses(const QByteArray& password);
QByteArray encryptPassword(
    const QByteArray& password, const QByteArray& salt,
    QCryptographicHash::Algorithm = QCryptographicHash::Algorithm::Sha512);

#endif /* end of include guard: HASH_HPP_5XQNUTL6 */
