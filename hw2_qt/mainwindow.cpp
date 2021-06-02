#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      //  ui->listWidget->addItems(strings);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
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


        int countTrees=0;
        Forest frt;


        foreach (QString string, strings)
        {
            if (rx.indexIn(string) != -1)
            {
                frt.add(string);
                countTrees++;
            }
        }
        countTrees=frt.getSize();

       QListWidget* *lists=new QListWidget*[countTrees]; // надо считать кол-во и распределить по равномерно по экрану чтоб не перекрывало друг друга
       // задать изначальные размер окна и местоположение


        int j;

        for (j=0;j<countTrees;j++)
        {
            lists[j]=new QListWidget();
        }

        j=0;
        foreach (QString string, strings)
        {
            if (rx.indexIn(string) != -1)
                        {
                          lists[j]->addItem(string);
                          lists[j]->show();
                          j++;
                        }

        }

        for (int i=0; i<countTrees;i++)
        {
            lists[i]->addItem(frt.roots.at(i)->name);
            lists[i]->show();
        }

        this->setHidden(true);

}
