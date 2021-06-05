#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    listWidget=new QListWidget();

    openFile();
    setFixedSize(1250,900);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{

    QString filename="C:\\Qt\\Projects\\hw2_qt\\middleBd.h";
    if (filename.isEmpty())
           return;

       QFile file(filename);

       if (!file.open(QIODevice::ReadOnly))
       {
            QMessageBox::warning(0, "Ошибка", "Не удалось открыть файл.");
            return;
       }


        QByteArray contents=file.readAll();
        auto contentsQString=QString::fromLocal8Bit(contents);

        auto strings = contentsQString.split('\n');

        QRegExp rx("(class|struct)\\s*\\b\\S+\\b\\s*(:\\s*(\\b(public|private|protected)\\b\\s+|\\s*)\\b\\S+\\b)?\\s*\\s*;?");

        foreach (QString string, strings)
        {
            if (rx.indexIn(string) != -1)
                tree.add(string);
        }

        widthTraversal();

        listWidget->addItem("Depth: "+ QString::number(tree.depth));
        listWidget->addItem("Width: "+ QString::number(tree.width));
      //  listWidget->show();

        paintStudents();
}

int* MainWindow::findWidth()
{
    int *wid= new int[10];

    for (int i=0; i<10;i++)
        wid[i]=0;

    QLinkedList<Node*> list;
    list.push_back(tree.root);

    while (!list.isEmpty())
    {
        Node *tmp=list.first();
        list.pop_front();
        wid[tmp->levelOfDepth]++;

        for (int i=0; i<tmp->children.count();i++)
            list.push_back(tmp->children[i]);

    }
    return wid;
}

void MainWindow::widthTraversal()
{
    int *wids=findWidth();
    int *j=new int[10];

    for (int i=0; i<10;i++)
        j[i]=0;


    QLinkedList<Node*> list;
    list.push_back(tree.root);
    while (!list.isEmpty())
    {
        Node *tmp=list.first();
        list.pop_front();

        if (tmp->levelOfDepth>tree.depth)
            tree.depth=tmp->levelOfDepth;


        tmp->levelOfWidth=wids[tmp->levelOfDepth];

        if (j[tmp->levelOfDepth]!=wids[tmp->levelOfDepth])
            tmp->numFromBros=++j[tmp->levelOfDepth];


        listWidget->addItem(tmp->name +'\t'+ QString::number(tmp->levelOfDepth)+
                            '\t'+ QString::number(tmp->levelOfWidth)+'\t'+ QString::number(tmp->numFromBros));
        for (int i=0; i<tmp->children.count();i++)
        {
            if (tmp->children.count()>tree.width)
                tree.width=tmp->children.count();


            list.push_back(tmp->children[i]);
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    listWidget->clear();

    QString filename= QFileDialog::getOpenFileName(this,tr("Open File"),"C:\\Qt\\Projects\\hw2_qt",".h Files (*.h)");

    if (filename.isEmpty())
           return;

   QFile file(filename);

   if (!file.open(QIODevice::ReadOnly))
   {
        QMessageBox::warning(0, "Ошибка", "Не удалось открыть файл.");
        return;
   }


    QByteArray contents=file.readAll();
    auto contentsQString=QString::fromLocal8Bit(contents);

    auto strings = contentsQString.split('\n');

    QRegExp rx("(class|struct)\\s*\\b\\S+\\b\\s*(:\\s*(\\b(public|private|protected)\\b\\s+|\\s*)\\b\\S+\\b)?\\s*\\s*;?");


    foreach (QString string, strings)
    {
        if (rx.indexIn(string) != -1)
            tree.add(string);
    }

   foreach (QString string, strings)
   {
       if (rx.indexIn(string) != -1)
       {
          listWidget->addItem(string);
          listWidget->show();
       }
   }

}


void MainWindow::paintStudents()
{

    QLinkedList<Node*> list;

    list.push_back(tree.root);

    while (!list.isEmpty())
    {
        GraphicsHuman *hooman=new GraphicsHuman();
        Node *tmp=list.first();
        list.pop_front();

        hooman->node=tmp;
        hooman->treeWidth=tree.width;
        hooman->treeHeight=tree.depth;

        scene->addItem(hooman);

        for (int i=0; i<tmp->children.count();i++)
            list.push_back(tmp->children[i]);
    }

}

