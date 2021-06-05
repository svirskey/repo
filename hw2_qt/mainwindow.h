#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QRegExp>
#include <QLinkedList>
#include <QListWidget>
#include "tree.h"
#include <QGraphicsScene>
#include "graphicshuman.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow:public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void openFile();
    void widthTraversal();
    int* findWidth();

    void paintStudents();

    Tree tree;
    QGraphicsScene *scene;

    QListWidget *listWidget;

};



#endif // MAINWINDOW_H


