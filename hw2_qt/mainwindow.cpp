#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openFile();
    setFixedSize(900,600);
//    auto pp=new QPainter(ui->listWidget);
//    pp->drawEllipse(10,10,20,20);
//    pp->end();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this->ui->listWidget);
    p.drawEllipse(10,10,20,20);
    return QMainWindow::paintEvent(event);
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

        Tree tree;


        foreach (QString string, strings)
        {
            if (rx.indexIn(string) != -1)
                tree.add(string);
        }


      //  this->widthTraversal(*tree.root,tree.width,tree.depth);

    //    this->ui->listWidget->addItem("Depth: "+ QString::number(tree.depth));
    //    this->ui->listWidget->addItem("Width: "+ QString::number(tree.width));

      // this->drawTree();

       ui->listWidget->show();
    //   ui->listWidget->hide();
}


void MainWindow::widthTraversal(Node& node,int& width,int &depth)
{
    QLinkedList<Node*> list;
    list.push_back(&node);
    while (!list.isEmpty())
    {
        Node *tmp=list.first();
        list.pop_front();

        if (tmp->levelOfDepth>depth)
            depth=tmp->levelOfDepth;


        this->ui->listWidget->addItem(tmp->name +'\t'+ QString::number(tmp->levelOfDepth));
        for (int i=0; i<tmp->children.count();i++)
        {
            if (tmp->children.count()>width)
            {
                width=tmp->children.count();
            }

            list.push_back(tmp->children[i]);
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();

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

        Tree tree;


        foreach (QString string, strings)
        {
            if (rx.indexIn(string) != -1)
                tree.add(string);
        }

       foreach (QString string, strings)
       {
           if (rx.indexIn(string) != -1)
           {
                 ui->listWidget->addItem(string);
                 ui->listWidget->show();
           }
       }

}
