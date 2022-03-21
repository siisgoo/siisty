#include "General/iiNPack.hpp"
#include "General/logger.hpp"

#include <QJsonObject>
#include <QJsonDocument>

const qsizetype iiNPack::HeaderSize =
    sizeof(quint32) + sizeof(qint64) + sizeof(quint8) + sizeof(quint8);

//todo add conversion little-endian

QByteArray
iiNPack::pack(const QByteArray& load, const PacketType type)
{
    QByteArray packet(iiNPack::HeaderSize + load.size(), 0);
    QDataStream out(&packet, QIODevice::WriteOnly);

    out << (quint32)0 <<
        (qint64)QDateTime::currentDateTimeUtc().toSecsSinceEpoch() <<
        (quint8)type <<
        (quint8)PacketLoadType::JSON;

    out.writeRawData(load.data(), load.size());

    out.device()->seek(0);
    out << (quint32)(packet.size());

    qDebug() << QString::number((quint32)(packet.size()));

    return packet;
}

QByteArray
iiNPack::packError(const QString& errDesc, const ResponseError err)
{
    QJsonDocument d(QJsonObject{
        { "errno", (int)err },
        { "details", errDesc }
    });
    return iiNPack::pack(d.toJson(QJsonDocument::Compact), PacketType::ERROR_MESSAGE);
}

iiNPack::Header
iiNPack::unpackHeader(QDataStream& io)
{
    io.device()->seek(0);
    Header header;
    std::memset(&header, 0, HeaderSize);

    io >> header.Size >>
        header.SendStamp >>
        header.PacketType >>
        header.PacketLoadType;

    io.device()->seek(0);

    return header;
}

QByteArray
iiNPack::unpackLoad(Header header, QDataStream& io)
{
    QByteArray load(header.Size - iiNPack::HeaderSize, 0);

    io.device()->seek(iiNPack::HeaderSize);
    io.readRawData(load.data(), load.size());

    return load;
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
