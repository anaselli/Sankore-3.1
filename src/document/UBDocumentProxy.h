/*
 * Copyright (C) 2012 Webdoc SA
 *
 * This file is part of Open-Sankoré.
 *
 * Open-Sankoré is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * with a specific linking exception for the OpenSSL project's
 * "OpenSSL" library (or with modified versions of it that use the
 * same license as the "OpenSSL" library).
 *
 * Open-Sankoré is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Open-Sankoré.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef UBDOCUMENTPROXY_H_
#define UBDOCUMENTPROXY_H_

#include <QtGui>

#include "frameworks/UBStringUtils.h"

#include "core/UBSettings.h"

class UBGraphicsScene;

class UBDocumentProxy : public QObject
{
    Q_OBJECT

    friend class UBPersistenceManager;

    public:

        UBDocumentProxy();
        UBDocumentProxy(const QString& pPersistencePath);

        virtual ~UBDocumentProxy();

        QString persistencePath() const;

        void setPersistencePath(const QString& pPersistencePath);

        void setMetaData(const QString& pKey , const QVariant& pValue);
        QVariant metaData(const QString& pKey) const;
        QHash<QString, QVariant> metaDatas() const;

        QString name() const;
        QString groupName() const;
        QDateTime documentDate();

        QDateTime lastUpdate();


        QSize defaultDocumentSize() const;
        void setDefaultDocumentSize(QSize pSize);
        void setDefaultDocumentSize(int pWidth, int pHeight);

        QUuid uuid() const;
        void setUuid(const QUuid& uuid);

        bool isModified() const;

        int pageCount();

    protected:
        void setPageCount(int pPageCount);
        int incPageCount();
        int decPageCount();

    signals:
        void defaultDocumentSizeChanged();

    private:

        void init();

        QString mPersistencePath;

        QHash<QString, QVariant> mMetaDatas;

        bool mIsModified;

        int mPageCount;

};

inline bool operator==(const UBDocumentProxy &proxy1, const UBDocumentProxy &proxy2)
{
    return proxy1.persistencePath() == proxy2.persistencePath();
}

inline uint qHash(const UBDocumentProxy &key)
{
    return qHash(key.persistencePath());
}


#endif /* UBDOCUMENTPROXY_H_ */
