#include "Crypto/Hash.hpp"

#include <QLatin1String>
#include <QCryptographicHash>
#include <QString>
#include <QByteArray>
#include <QRandomGenerator>

/* // 10 - 32 chars */
/* // actual - 20 */
/* static const QVector<QByteArray> salts({ */
/*     R"(0@1.*$1j}7{9$=G&03U+)", // no spec no nums */
/*     R"(12jsdlJO198TG12pQ12v)", // no nums no alpha */
/*     R"(*l@?,05492*(#`27<>?%)", // no spec no alpha */
/*     R"(nqlkjASlIasjdipauLKu)", // no alpha */
/*     R"(32578301987-29855879)", // no nums */
/*     R"(#$!><?{%.*!@[^(*)}`~)", // no spec */
/* }); */

static const int salt_length(32);
    // mean xxx system max unique password
    // if /dev/urandom will not fail :)

static const QLatin1String specials(R"(!”#$%&'()*+,-./:;?@[\]^_`{ |  }~`]')");
static const QLatin1String alphabet(R"(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ)");
static const QLatin1String digits(R"(0123456789)");
    // for salt gen

enum PasswordWeaknesses : quint8 {
    Alpha = 0x1,
    Digit = 0x2,
    Special = 0x4,
};

static void setBit(unsigned long& num, unsigned long bit) { num |= (1 << bit); }
static int getBit(unsigned long num, unsigned long bit) { return (num & ( 1 << bit  )) >> bit; }

static const QByteArray saltGen(quint8 w)
{

}

static const quint8 passWeaknesses(const QByteArray& data) {
    int spec = 0;
    int nums = 0;
    int alph = 0;
    for (auto ch : data) {
        if (isalpha(ch)) { alph++;
        } else if (isdigit(ch)) { nums++;
        } else if (isgraph(ch) || isspace(ch)) { spec++;
        }
    }

    int len = data.length();
    double spec_c = static_cast<double>(spec)/len;
    double nums_c = static_cast<double>(nums)/len;
    double alph_c = static_cast<double>(alph)/len;

    if (spec_c > nums_c && spec_c > alph_c) {
        if (spec_c > 0.5) {
            return Digit & Alpha; //no num no alpha
        } else {
            if (std::max(nums_c, alph_c) - std::min(nums_c, alph_c) < 0.1) {
                return (nums_c > alph_c ? 3 : 4);
            } else {
                return Digit & Alpha;
            }
        }
    } else if (nums_c > spec_c && nums_c > alph_c) {
        if (nums_c > 0.5) {
            return 2; // no spec no alpha
        } else {
            if (std::max(spec_c, alph_c) - std::min(spec_c, alph_c) < 0.1) {
                return (spec_c > alph_c ? 3 : 5);
            } else {
                return 2;
            }
        }
    } else {
        if (alph_c > 0.5) {
            return 0; // no spec no nums
        } else {
            if (std::max(spec_c, nums_c) - std::min(spec_c, nums_c) < 0.1) {
                return (spec_c > nums_c ? 4 : 5);
            } else {
                return 0;
            }
        }
    }
}

// There is no check bit or little endiang, may currupt on db export to another machine :) im not care :)
//Proposed Algorithm from IAENG International Journal of Computer Science, 43:1, IJCS_43_1_04
QString encryptPassword(const QByteArray& data)
{
    using algo = QCryptographicHash::Algorithm;

    QByteArray toCrypt;
    QByteArray salt = saltGen(passWeaknesses(data));
    QByteArray hash = QCryptographicHash::hash(data, algo::Sha512);

    int prev = -1;
    int cur;
    int inserted = 0;
    for (int i = 0; i < data.length() && inserted < salt_length; i++) {
        cur = getBit(data[i], sizeof(data[i])) ^ getBit(hash[i], sizeof(hash[i]));
        toCrypt.push_back(data[i]);
        if (cur == 1) {
            toCrypt.push_back(salt[inserted++]);
        } else if (cur == 0 && prev == 0) { //may only prev == 0 :)
            toCrypt.push_back(salt[inserted++]);
            toCrypt.push_back(salt[inserted++]);
        }
        prev = cur;
    }

    if (inserted != salt_length-1) {
        for (int i = inserted; i < salt_length; i++) {
            toCrypt.push_back(salt[i]);
        }
    }

    return QCryptographicHash::hash(toCrypt, algo::Sha512);
}

