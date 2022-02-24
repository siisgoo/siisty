#ifndef IINETWORKPACKET_HPP_T3ZVG9UF
#define IINETWORKPACKET_HPP_T3ZVG9UF

/*
 *
 * First packet sended after success connections must be a Cliet Autorization request
 *  Must contain 
 *
 */

#include <QPair>
#include <QJsonDocument>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>
#include <QDateTime>

/*
 * siisty Network Packet
 */
struct iiNPack {
    enum class PacketType : quint8
    {
        AUTORIZATION_REQUEST,
        GET_REQUEST,
        PUT_REQUEST,
        RESPONSE,
        ERROR_MESSAGE, //first byte contain ResponseError, other - errstr
    };

    enum class PacketLoadType : quint8
    {
        JSON = 0,
        XML,
        RAW,
    };

    enum class ResponseError : quint8
    {
        ACCESS_DENIED = 0,
        REQUEST_ERROR,
    };

    struct Header
    {
/* 0x0  - 0x4  */ quint32 Size;           /* Overall packet load size in bytes */
/* 0x4  - 0x12 */ qint64  SendStamp;      /* Send time; using QDateTime SecsSinceEpoch */
/* 0x12 - 0x13 */ quint8  PacketType;     /* Type of packet; enum class PacketType */
/* 0x13 - 0x14 */ quint8  PacketLoadType; /* Operation type, see enum class PacketLoadType */
    };

    static const qsizetype HeaderSize;
    static QByteArray pack(const QByteArray& load, const PacketType);
    static QByteArray packError(const QString& errDesc, const ResponseError err);
        // package creators

    static Header unpackHeader(QDataStream& input);
    static QByteArray unpackLoad(Header, QDataStream& input);
    static ResponseError extractErrno(const QByteArray& load);
    static QString extractErrStr(const QByteArray& load);

    private:
        iiNPack();
        iiNPack(const iiNPack&) = delete;
        iiNPack(const iiNPack&&) = delete;
        iiNPack& operator = (const iiNPack&) = delete;
            // not creatable
};

#endif /* end of include guard: IINETWORKPACKET_HPP_T3ZVG9UF */
