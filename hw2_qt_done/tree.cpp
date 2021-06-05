#include "tree.h"


Node::Node(QString name,QString typeOfInheritance, Node *parent, QVector<Node*> children)
{
    this->typeOfInheritance=typeOfInheritance;
    this->children=children;
    this->name=name;
    this->parent=parent;
}

Node::Node()
{
    parent=nullptr;
}


Node::~Node()
{
    delete parent;
}


Tree::Tree()
{
    root=nullptr;
    width=0;
    depth=0;
}


void Tree::add(QString string)
{
    auto words=string.split(' ');

    Node *tmp=new Node();
    if (words.last()=='\r')
        words.removeAt(words.count());
    words[1].remove('\r');
    tmp->name=words[1];

    if (words.count()==2) // class aaa
    {
        tmp->parent=nullptr;
        tmp->typeOfInheritance="";
        tmp->levelOfDepth=1;
        tmp->levelOfWidth=1;
        root=tmp;
    }
    else if (words.count()==4) // class aaa : bbb
    {
       words[3].remove('\r');
        tmp->typeOfInheritance="private";
        tmp->parent=findParent(words[3],*tmp); // bbb

    }
    else if (words.count()==5) // class aaa : public bbb
    {
       words[4].remove('\r');
        tmp->typeOfInheritance=words[3];
        tmp->parent=findParent(words[4],*tmp); // bbb
    }
}


Node *Tree::findParent(QString name,Node& node)
{
    QLinkedList<Node*> list;

    list.push_back(this->root);

    while (!list.isEmpty())
    {
        Node *tmp=list.first();
        list.pop_front();

        if (tmp->name == name)
            {
                tmp->children.append(&node);
                node.levelOfDepth = tmp->levelOfDepth + 1;
                return tmp;
            }

        for (int i=0; i<tmp->children.count();i++)
            list.push_back(tmp->children[i]);
    }
    return nullptr;
}

void Tree::clear()
{
    root=nullptr;
    depth=0;
    width=0;

}

