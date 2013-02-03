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


#ifndef UBGRAPHICSCACHE_H
#define UBGRAPHICSCACHE_H

#include <QColor>
#include <QGraphicsSceneMouseEvent>

#include "domain/UBItem.h"
#include "core/UB.h"

typedef enum
{
    eMaskShape_Circle,
    eMaskShap_Rectangle
}eMaskShape;

class UBGraphicsCache : public QGraphicsRectItem, public UBItem
{
public:
    static UBGraphicsCache* instance(UBGraphicsScene *scene);
    ~UBGraphicsCache();

    enum { Type = UBGraphicsItemType::cacheItemType };

    virtual int type() const{ return Type;}

    virtual UBItem* deepCopy() const;

    virtual void copyItemParameters(UBItem *copy) const;

    QColor maskColor();
    void setMaskColor(QColor color);
    eMaskShape maskshape();
    void setMaskShape(eMaskShape shape);
    int shapeWidth();
    void setShapeWidth(int width);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    static QMap<UBGraphicsScene*, UBGraphicsCache*> sInstances;

    QColor mMaskColor;
    eMaskShape mMaskShape;
    int mShapeWidth;
    bool mDrawMask;
    QPointF mShapePos;
    int mOldShapeWidth;
    QPointF mOldShapePos;
    UBGraphicsScene* mScene;
    

    UBGraphicsCache(UBGraphicsScene *scene);
    
    void init();
    QRectF updateRect(QPointF currentPoint);
};

#endif // UBGRAPHICSCACHE_H
