#include <QPainter>

#include <wall.h>
#include "constants.h"

wall::wall()
{

}

QRectF wall::boundingRect() const
{
    return QRectF(-110, -110, TILE_SIZE*22, TILE_SIZE*22);
}

QPainterPath wall::shape() const
{
    QPainterPath path;

    path.setFillRule(Qt::WindingFill);

    for(zs=-110; zs<=110; zs+=10)
    {
        path.addRect(QRectF(-110, zs, TILE_SIZE, TILE_SIZE));
        path.addRect(QRectF(zs, -110, TILE_SIZE, TILE_SIZE));
        path.addRect(QRectF(zs, 110, TILE_SIZE, TILE_SIZE));
        path.addRect(QRectF(110, zs, TILE_SIZE, TILE_SIZE));
    }

    return path;
}

void wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->fillPath(shape(), Qt::blue);
    painter->restore();
}
