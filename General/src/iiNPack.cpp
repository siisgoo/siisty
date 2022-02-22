#include "iiNetworkPacket/iiNetworkPacket.hpp"
#include "General/logger.hpp"

const qsizetype iiNPack::HeaderSize =
    sizeof(quint32) + sizeof(qint64) + sizeof(quint8) + sizeof(quint8);

//todo add conversion little-endian

QByteArray
iiNPack::pack(const QByteArray& load, const PacketType type)
{
    QByteArray packet(0);
    QDataStream out(&packet, QIODevice::WriteOnly);

    out << (quint32)0 <<
        (qint64)QDateTime::currentDateTimeUtc().toSecsSinceEpoch() <<
        (quint8)type <<
        (quint8)PacketLoadType::JSON <<
        load;

    out.device()->seek(0);
    out << (quint32)(packet.size() - sizeof(quint32));

    return packet;
}

QByteArray
iiNPack::packError(const QString& errDesc, const ResponseError err)
{
    QByteArray load(0);
    load.append((quint8)err);
    load.append(errDesc.toLocal8Bit());

    return iiNPack::pack(load, PacketType::ERROR_MESSAGE);
}

iiNPack::Header
iiNPack::unpack(QByteArray& input, QByteArray& res)
{
    QDataStream io(&input, QIODevice::ReadOnly);
    Header header;
    std::memset(&header, 0, HeaderSize);

    if (input.size() < sizeof(quint32)) {
        //log
        return header;
    } else if (input.size() < HeaderSize) {
        //log
        return header;
    }

    io >> header.Size >>
        header.SendStamp >>
        header.PacketType >>
        header.PacketLoadType;

    //work?
    io >> res;

    return header;
}

iiNPack::ResponseError
iiNPack::extractErrno(const QByteArray& load)
{
    return (ResponseError)load.at(0);
}

QString
extractErrStr(const QByteArray& load)
{
    QString str;

    if (load.size() > 1) {
        for (int i = 1; i < load.size(); i++) {
            str.append(load.at(i));
        }
    } else {
        str.append("No error message");
    }

    return str;
}
