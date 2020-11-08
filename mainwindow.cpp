#include "mainwindow.h"
#include "document.h"
#include "page.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QAction>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // File
    QToolBar *fileToolBar = addToolBar("File");

    QIcon exportToPdfIcon(":/images/export-pdf.svg");
    QAction *exportToPdfAct =new QAction(exportToPdfIcon, "Export to PDF", this);
    exportToPdfAct->setToolTip("Export current document to PDF");

    QIcon addPageIcon(":images/add-page.svg");
    QAction *addPageAct =new QAction(addPageIcon, "Export to PDF", this);
    addPageAct->setToolTip("Add a new page to the end of the document");

    fileToolBar->addAction(exportToPdfAct);
    fileToolBar->addAction(addPageAct);

    // Tools
    QToolBar *toolsToolBar = addToolBar("Tools");

    QIcon PenIcon(":/images/pen.svg");
    QAction *choosePenAct =new QAction(PenIcon, "Choose pen", this);
    choosePenAct->setToolTip("Use pen to draw on page");

    QIcon eraserIcon(":/images/eraser.svg");
    QAction *chooseEraserAct =new QAction(eraserIcon, "Choose erase", this);
    chooseEraserAct->setToolTip("Use eraser to delete from page");


    toolsToolBar->addAction(choosePenAct);
    toolsToolBar->addAction(chooseEraserAct);


    //Pen colors
    QToolBar *penColorToolBar = addToolBar("Pen colors");

    QIcon blackPenIcon(":/images/pen-color-black.svg");
    QAction *chooseBlackPenAct =new QAction(blackPenIcon, "Choose black pen", this);
    chooseBlackPenAct->setToolTip("Choose black color for pen");

    QIcon redPenIcon(":/images/pen-color-red.svg");
    QAction *chooseRedPenAct =new QAction(redPenIcon, "Choose red pen", this);
    chooseRedPenAct->setToolTip("Choose red color for pen");

    QIcon bluePenIcon(":/images/pen-color-blue.svg");
    QAction *chooseBluePenAct =new QAction(bluePenIcon, "Choose blue pen", this);
    chooseBluePenAct->setToolTip("Choose blue color for pen");


    QIcon greenPenIcon(":/images/pen-color-green.svg");
    QAction *chooseGreenPenAct =new QAction(greenPenIcon, "Choose green pen", this);
    chooseGreenPenAct->setToolTip("Choose green color for pen");

    penColorToolBar->addAction(chooseBlackPenAct);
    penColorToolBar->addAction(chooseRedPenAct);
    penColorToolBar->addAction(chooseBluePenAct);
    penColorToolBar->addAction(chooseGreenPenAct);

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
{}
