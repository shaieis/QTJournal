#include "mainwindow.h"
#include "document.h"
#include "page.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

QColor bg("white");
PageGrid grid(true,50,0.1,"blue",50,0.1,"blue",250,1,"red");

QSize dim(2100,2700);


Document* d = new Document(this,dim,bg,grid,1, true);


setCentralWidget(d);

d->addNewPage();
d->addNewPage();
d->addNewPage();


}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *)
{

    qDebug() << "mainWindow width "<< width();
}
