#include "md5hashgenerator.h"
#include <QCryptographicHash>


using namespace CORE;


md5HashGenerator::md5HashGenerator()
{

}

md5HashGenerator::~md5HashGenerator()
{

}

QString md5HashGenerator::getHash(QFile& file)const
{
    qint64 fileSize = file.size();
    const qint64 bufferSize = 10240;


    if (file.open(QIODevice::ReadOnly))
    {
        char buffer[bufferSize];
        int bytesRead;
        int readSize = qMin(fileSize, bufferSize);

        QCryptographicHash hash(QCryptographicHash::Algorithm::Md5);
        while (readSize > 0 && (bytesRead = file.read(buffer, readSize)) > 0)
        {
            fileSize -= bytesRead;
            hash.addData(buffer, bytesRead);
            readSize = qMin(fileSize, bufferSize);
        }

        file.close();
        return QString(hash.result().toHex());
    }
    return QString();
}


