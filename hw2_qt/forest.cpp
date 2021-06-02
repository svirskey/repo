#include "forest.h"


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

Node* Node::find(QString name,Node& node)
{
    if (this->name==name)
    {
        children.append(&node);
        return this;
    }
    for (int k=0;k<children.size();k++)
    {
       return children[k]->find(name,node);
    }
    return nullptr;
}

Node::~Node()
{
    delete parent;
}


int Forest::getSize()
{
    return roots.size();
}

Forest::Forest()
{
}

void Forest::add(QString string)
{
    auto words=string.split(' ');

    Node *tmp=new Node();
    if (words.last()=='\r')
        words.removeAt(words.count());
        //words[].detach();
    words[1].remove('\r');
    tmp->name=words[1];

    if (words.count()==2) // class aaa
    {
        tmp->parent=nullptr;
        tmp->typeOfInheritance="";
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

    if (tmp->parent==nullptr)
    {
        roots.append(tmp);
    }

}

Node *Forest::findParent(QString name,Node& node)
{
    for (int i=0; i<roots.size();i++)
    {
        if (roots[i]->name==name)
        {
            roots[i]->children.append(&node);
            return roots[i];
        }
    }
//TODO
    // оптимизировать надо
    for (int i=0; i<roots.size();i++)
    {
        for (int j=0; j<roots[i]->children.size();j++)
            return roots[i]->children[j]->find(name,node);
    }
    return nullptr;
}

Forest::~Forest()
{
}
