#ifndef IINETWORKPACKET_HPP_T3ZVG9UF
#define IINETWORKPACKET_HPP_T3ZVG9UF

/*
 *
 * First packet sended after success connections must be a Cliet Autorization request
 *  Must contain 
 *
 */


#include <QByteArray>

struct iiNetworkPacket {
    enum class Operation : quint8
    {
        AUTORIZATION_REQUEST = 0x1,
        GET_REQUEST = 0x2,
        PUT_REQUEST = 0x3,
    };

    enum class ResponceError : quint8
    {
        ACCESS_DENIED = 0x1,
        REQUEST_ERROR = 0x2,
    };

    //use pragma push?
    struct Header
    {
/* 0x0  - 0x4  */ quint32 Size;         /* Overall packet load size in bytes */
/* 0x4  - 0x12 */ qint64  SendStamp;    /* Send time; using QDateTime SecsSinceEpoch */
/* 0x12 - 0x13 */ quint8  PacketType;   /* Type of packet; not implemented, reserved */
/* 0x13 - 0x14 */ quint8  Operation;    /* Operation type, see enum class Operation */
/* 0x14 - 0x24 */ char    Specific[10]; /* specific info(username and password separator bit, etc) */
    };

    // the load
    Header     header;
    QByteArray data;
};

#endif /* end of include guard: IINETWORKPACKET_HPP_T3ZVG9UF */
