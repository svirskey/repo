#include <QString>
#include <QRegExp>
#include <QVector>
#include <QStringList>
#include <QLinkedList>

#ifndef FOREST_H
#define FOREST_H


struct Node
{
    QString name;
    QString typeOfInheritance;
    int levelOfDepth=0;
    int levelOfWidth=0;
    int numFromBros=1;
    Node *parent;
    QVector<Node*> children;
    Node(QString name,QString typeOfInheritance,Node *parent,QVector<Node*> children);
    Node();
    ~Node();
};


class Tree
{
public:
    Node* root;
    int depth;
    int width;
    Tree();
    void add(QString string);
    Node* findParent(QString name,Node& node);
    void clear();
};

#endif // FOREST_H
