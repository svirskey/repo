#ifndef GRAPHICSHUMAN_H
#define GRAPHICSHUMAN_H
#include <QGraphicsItem>
#include <QPainter>
#include "tree.h"
#include <QLinkedList>


class GraphicsHuman : public QGraphicsItem
{
public:
    const int rectangleWidth=200;
    const int rectangleHeight=100;
    const int widgetWidth=1300;
    const int widgetHeight=800;

    GraphicsHuman();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    virtual QRectF boundingRect() const override;

    const Node* node;
    int treeHeight;
    int treeWidth;


};

#endif // GRAPHICSHUMAN_H
