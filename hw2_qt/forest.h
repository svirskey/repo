#include <QString>
#include <QRegExp>
#include <QVector>
#include <QStringList>

#ifndef FOREST_H
#define FOREST_H


struct Node
{
    QString name;
    QString typeOfInheritance;
    Node *parent;
    QVector<Node*> children;
    Node(QString name,QString typeOfInheritance,Node *parent,QVector<Node*> children);
    Node();
    Node* find(QString name,Node& node);
    ~Node();
};


class Forest
{
//private:
public:
   QVector<Node*> roots;

public:
   int getSize();
    Forest();
    void add(QString string);
    Node* findParent(QString name,Node& node);
    ~Forest();
};

#endif // FOREST_H
