#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QActionGroup>
#include "document.h"
#include "tool.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    static constexpr qreal penThicknesses[] = {1,2,3};
    static constexpr QSizeF erasers[] = { {10,10}, {15,15}, {20,20} };


    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void wheelEvent(QWheelEvent *event) override; // used to toggle m_zoomToFitWidthAct

    void zoomIn();
    void zoomOut();
    void toggleZoomToFitWidth(bool enable);




private:
    QScrollArea* m_scrollArea;
    Document* m_document;



    Pen *m_pen;
    Eraser *m_eraser;

    void initTools();
    void initFileToolBar();
    void initToolsToolBar();
    void initPenToolBar();
    void initEraserToolBar();
    void initZoomToolBar();

    void setToolBarsIconSize(const QSize& iconSize);
    void setToolBarsSpacing(int spacePx);





    QAction *m_exportToPdfAct;
    QAction *m_addPageAct;

    QAction *m_penSelectAct;
    QAction *m_eraserSelectAct;

    QAction *m_zoomInAct;
    QAction *m_zoomOutAct;
    QAction *m_zoomToFitWidthAct;

    QList<QAction*> m_penColorActs;
    QList<QAction*> m_penThicknessActs;
    QList<QAction*> m_eraserThicknessActs;

    QActionGroup *m_toolActionGroup;
    QActionGroup *m_penColorActionGroup;
    QActionGroup *m_penThicknessActionGroup;
    QActionGroup *m_eraserThicknessActionGroup;


    QToolBar *m_fileToolBar;
    QToolBar *m_toolsToolBar;
    QToolBar *m_penToolBar;
    QToolBar *m_eraserToolBar;
    QToolBar *m_zoomToolBar;




};




#endif // MAINWINDOW_H
