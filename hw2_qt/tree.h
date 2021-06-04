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
    int levelOfDepth;
    Node *parent;
    QVector<Node*> children;
    Node(QString name,QString typeOfInheritance,Node *parent,QVector<Node*> children);
    Node();
    Node* find(QString name,Node& node);
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

};

#endif // FOREST_H
