#include <QPainter>

#include "constants.h"
#include "food.h"

static const qreal FOOD_RADIUS = 3;

/*
构造函数
x,y 为坐标的元素
setdata提供额外的数据信息
*/
Food::Food(qreal x, qreal y)
{
    setPos(x,y);
    setData(GD_Type, GO_Food);
}

/*
返回一个QRect对象
原程序上是return QRectF(-TILE_SIZE, -TILE_SIZE, TILE_SIZE * 2, TILE_SIZE * 2);
原程序以(-TILE_SIZE, -TILE_SIZE)为坐标原点获得四个格子（一个正方形），所以
p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
(TILE_SIZE / 2, TILE_SIZE / 2)在四个格子的右下角

我写的QRectF(0, 0, TILE_SIZE * 2, TILE_SIZE * 2);以（0，0）为坐标原点
所以(TILE_SIZE / 2, TILE_SIZE / 2)在正方形大格子的左上角
原程序说右下角写起来方便，这里不甚理解
*/
QRectF Food::boundingRect() const
{
    return QRectF(0, 0, TILE_SIZE * 2, TILE_SIZE * 2);
}

//绘制食物
void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHints(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);

    painter->restore();
}

//设置食物的形状
QPainterPath Food::shape() const
{
    QPainterPath p;
    //以(TILE_SIZE / 2, TILE_SIZE / 2)为圆心，FOOD_RADIUS为长和宽绘制食物
    p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}
