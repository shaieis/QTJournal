#include "mainwindow.h"
#include "document.h"
#include "page.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//   QScrollArea *scrollArea = new QScrollArea( this );
//   scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
//   scrollArea->setWidgetResizable( true );
//   setCentralWidget(scrollArea);

//   QWidget *widget = new QWidget();
//   scrollArea->setWidget( widget );

//   QVBoxLayout *layout = new QVBoxLayout();
//  // layout->setAlignment()


//   widget->setLayout( layout );

//   Page *p = new Page();
//   Page *q1 = new Page();
//   Page *q2 = new Page();
//   Page *q3 = new Page();



//layout->addWidget( p );
//layout->addWidget( q1 );
//layout->addWidget( q2 );
//layout->addWidget( q3 );
//layout->setAlignment(Qt::AlignTop);
//layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

QColor bg("yellow");
PageGrid grid(true,25,1,"blue",25,1,"orange",250,1,"red");
QSize dim(300,300);
Document* d = new Document(this,dim,bg,grid,3);

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


}
