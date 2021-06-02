#include "mainwindow.h"
#include <QListWidget>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


//    w.list
//    QListWidget listWgt;
//    listWgt.addItems({"aaaa","abbbb"} );
//    listWgt.resize( 300, 300 );
//    listWgt.show();

//    ListController listController;
//    QObject::connect(
//        &listWgt,
//        SIGNAL( doubleClicked( QModelIndex ) ),
//        &listController,
//        SLOT( onListDoubleClicked( QModelIndex ) )
    return a.exec();
}
