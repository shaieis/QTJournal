#include "mainwindow.h"
#include "document.h"
#include "page.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QAction>
#include <QToolBar>
#include <QWheelEvent>
#include <type_traits>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    initFileToolBar();
    initToolsToolBar();
    initPenToolBar();
    initEraserToolBar();
    initZoomToolBar();

    setToolBarsIconSize({35,35});
    setToolBarsSpacing(20);
    QColor bg("white");

    PageGrid grid(true,50,0.1,"blue",50,0.1,"blue",250,1,"red");

    QSize dim(2100,2700);


    m_document = new Document(this,dim,bg,grid,1, true);


    setCentralWidget(m_document);

    m_document->addNewPage();
    m_document->addNewPage();
    m_document->addNewPage();

    Eraser* e = new Eraser ({20,20});
    m_document->setTool(e);
}

MainWindow::~MainWindow()
{
}



void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier)
    {
        toggleZoomToFitWidth(false);
    }
}



void MainWindow::zoomIn()
{
    m_zoomToFitWidthAct->setChecked(false);
    m_document->zoomIn();
}

void MainWindow::zoomOut()
{
    m_zoomToFitWidthAct->setChecked(false);
    m_document->zoomOut();
}
void MainWindow::toggleZoomToFitWidth(bool enable)
{
    qDebug() << enable;
    m_zoomToFitWidthAct->setChecked(enable);
    m_document->toggleZoomToFitWidth(enable);
}




// ======== Private methods ========

void MainWindow::initFileToolBar()
{
    // Export to pdf
    m_exportToPdfAct =new QAction(QIcon(":/images/export-pdf.svg"), "Export to PDF", this);
    m_exportToPdfAct->setToolTip("Export current document to PDF");

    // Add page
    QAction *addPageAct =new QAction(QIcon(":images/add-page.svg"), "Export to PDF", this);
    addPageAct->setToolTip("Add a new page to the end of the document");

    // Create ToolBar
    m_fileToolBar = addToolBar("File");
    m_fileToolBar->addAction(m_exportToPdfAct);
    m_fileToolBar->addAction(addPageAct);
}

void MainWindow::initToolsToolBar()
{
    // Pen selection
    m_penSelectAct =new QAction(QIcon(":/images/pen.svg"), "Choose pen", this);
    m_penSelectAct->setToolTip("Use pen to draw on page");
    m_penSelectAct->setCheckable(true);


    // Eraser selection
    m_eraserSelectAct =new QAction(QIcon(":/images/eraser.svg"), "Choose erase", this);
    m_eraserSelectAct->setToolTip("Use eraser to delete from page");
    m_eraserSelectAct->setCheckable(true);

    m_toolsToolBar = addToolBar("Tools");
    m_toolActionGroup = new QActionGroup(m_toolsToolBar);

    m_toolActionGroup->addAction(m_penSelectAct);
    m_toolActionGroup->addAction(m_eraserSelectAct);

    m_toolsToolBar->addActions(m_toolActionGroup->actions());

    // Start with pen selected
    m_penSelectAct->setChecked(true);
}

void MainWindow::initPenToolBar()
{

    //Pen properties
    m_penToolBar = addToolBar("Pen properties");


    // Colors

    // Black
    QAction *chooseBlackPenAct =new QAction(QIcon(":/images/pen-color-black.svg"), "Choose black pen", this);
    chooseBlackPenAct->setToolTip("Choose black color for pen");

    // Red
    QAction *chooseRedPenAct =new QAction(QIcon(":/images/pen-color-red.svg"), "Choose red pen", this);
    chooseRedPenAct->setToolTip("Choose red color for pen");


    // Blue
    QAction *chooseBluePenAct =new QAction(QIcon(":/images/pen-color-blue.svg"), "Choose blue pen", this);
    chooseBluePenAct->setToolTip("Choose blue color for pen");

    // Green
    QAction *chooseGreenPenAct =new QAction(QIcon(":/images/pen-color-green.svg"), "Choose green pen", this);
    chooseGreenPenAct->setToolTip("Choose green color for pen");

    m_penColorActs << chooseBlackPenAct << chooseRedPenAct << chooseBluePenAct << chooseGreenPenAct;
    m_penColorActionGroup = new QActionGroup(m_penToolBar);

    for (auto action : m_penColorActs)
    {
        action->setCheckable(true);
        m_penColorActionGroup->addAction(action);
    }



    // Thicknesses

    // Thin
    QAction *chooseThinPenAct =new QAction(QIcon(":/images/pen-thin.svg"), "Choose thin pen", this);
    chooseThinPenAct->setToolTip("Choose thin pen stroke");

    // Medium
    QAction *chooseMediumPenAct =new QAction(QIcon(":/images/pen-medium.svg"), "Choose medium pen", this);
    chooseMediumPenAct->setToolTip("Choose medium pen stroke");

    // Thick
    QAction *chooseThickPenAct =new QAction(QIcon(":/images/pen-thick.svg"), "Choose thick pen", this);
    chooseThickPenAct->setToolTip("Choose thick pen stroke");

    m_penThicknessActs << chooseThinPenAct << chooseMediumPenAct << chooseThickPenAct;
    m_penThicknessActionGroup = new QActionGroup(m_penToolBar);

    for (auto action : m_penThicknessActs)
    {
        action->setCheckable(true);
         m_penThicknessActionGroup->addAction(action);
    }


    // Add groups to toolbar
    m_penToolBar->addActions(m_penColorActionGroup->actions());
    m_penToolBar->addSeparator();
    m_penToolBar->addActions(m_penThicknessActionGroup->actions());

    // Start with black medium pen
    chooseBlackPenAct->setChecked(true);
    chooseMediumPenAct->setChecked(true);

}

void MainWindow::initEraserToolBar()
{
    m_eraserToolBar = addToolBar("Eraser properties");

    QAction *chooseSmallEraserAct =new QAction(QIcon(":/images/eraser-small.svg"), "Choose small eraser", this);
    chooseSmallEraserAct->setToolTip("Choose small eraser size");

    QAction *chooseMediumEraserAct =new QAction(QIcon(":/images/eraser-medium.svg"), "Choose medium eraser", this);
    chooseMediumEraserAct->setToolTip("Choose medium eraser size");

    QAction *chooseLargeEraserAct =new QAction(QIcon(":/images/eraser-large.svg"), "Choose large eraser", this);
    chooseLargeEraserAct->setToolTip("Choose large eraser size");

    m_eraserThicknessActs << chooseSmallEraserAct << chooseMediumEraserAct << chooseLargeEraserAct;
    m_eraserThicknessActionGroup = new QActionGroup(m_eraserToolBar);

    for (auto action : m_eraserThicknessActs)
    {
        action->setCheckable(true);
         m_eraserThicknessActionGroup->addAction(action);
    }

    m_eraserToolBar->addActions(m_eraserThicknessActionGroup->actions());

    // Start with small eraser
    chooseSmallEraserAct->setChecked(true);
}

void MainWindow::initZoomToolBar()
{
    m_zoomToolBar = addToolBar("Zoom");

    m_zoomToFitWidthAct =new QAction(QIcon(":/images/zoom-to-width.svg"), "Zoom to width", this);
    m_zoomToFitWidthAct->setToolTip("Zoom to fill Width");
    m_zoomToFitWidthAct->setCheckable(true);
    m_zoomToFitWidthAct->setChecked(true);
    connect(m_zoomToFitWidthAct, &QAction::triggered,this, &MainWindow::toggleZoomToFitWidth);

    m_zoomOutAct =new QAction(QIcon(":/images/zoom-out.svg"), "Zoom out", this);
    m_zoomOutAct->setToolTip("Zoom out");
    connect(m_zoomOutAct, &QAction::triggered,this, &MainWindow::zoomOut);

    m_zoomInAct =new QAction(QIcon(":/images/zoom-in.svg"), "Zoom in", this);
    m_zoomInAct->setToolTip("Zoom in");
    connect(m_zoomInAct, &QAction::triggered,this, &MainWindow::zoomIn);

    m_zoomToolBar->addAction(m_zoomToFitWidthAct);
    m_zoomToolBar->addAction(m_zoomOutAct);
    m_zoomToolBar->addAction(m_zoomInAct);
}

void MainWindow::setToolBarsIconSize(const QSize& iconSize)
{
    m_fileToolBar->setIconSize(iconSize);
    m_toolsToolBar->setIconSize(iconSize);
    m_penToolBar->setIconSize(iconSize);
    m_eraserToolBar->setIconSize(iconSize);
    m_zoomToolBar->setIconSize(iconSize);
}

void MainWindow::setToolBarsSpacing(int spacePx)
{
    m_fileToolBar->setStyleSheet("QToolBar{spacing:" + QString::number(spacePx) + ";}");
    m_toolsToolBar->setStyleSheet("QToolBar{spacing:" + QString::number(spacePx) + ";}");
    m_penToolBar->setStyleSheet("QToolBar{spacing:" + QString::number(spacePx) + ";}");
    m_eraserToolBar->setStyleSheet("QToolBar{spacing:" + QString::number(spacePx) + ";}");
    m_zoomToolBar->setStyleSheet("QToolBar{spacing:" + QString::number(spacePx) + ";}");
}


