#include "graphicshuman.h"

GraphicsHuman::GraphicsHuman() : QGraphicsItem()
{
}

void GraphicsHuman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawRect( -widgetWidth/2 + (widgetWidth/(node->levelOfWidth+1))*(node->numFromBros)-rectangleWidth/2,
                       -widgetHeight/2 + ((widgetHeight/treeHeight)*(2*(node->levelOfDepth-1)+1))/2-rectangleHeight/2,
                       rectangleWidth,
                       rectangleHeight);
    QFont f=painter->font();
    f.setPointSize(20);
    painter->setFont(f);
    painter->drawText(QRect( -widgetWidth/2 + (widgetWidth/(node->levelOfWidth+1))*(node->numFromBros)-rectangleWidth/2,
                             -widgetHeight/2 + ((widgetHeight/treeHeight)*(2*(node->levelOfDepth-1)+1))/2-rectangleHeight/2,
                             rectangleWidth,
                             rectangleHeight),Qt::AlignCenter,node->name);

        if (node->parent!=nullptr)
            painter->drawLine(-widgetWidth/2 + widgetWidth/(node->levelOfWidth+1)*(node->numFromBros),
                          -widgetHeight/2 + ((widgetHeight/treeHeight)*(2*(node->levelOfDepth-1)+1))/2 - rectangleHeight/2,
                          -widgetWidth/2,
                          -widgetHeight/2);
}

QRectF GraphicsHuman::boundingRect() const
{
    return QRectF(0,0,50,50);
}
