#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QActionGroup>
#include "document.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *) override;

    void wheelEvent(QWheelEvent *event) override;

private:
    QScrollArea* m_scrollArea;
    Document* m_document;

    void initFileToolBar();
    void initToolsToolBar();
    void initPenToolBar();
    void initEraserToolBar();
    void initZoomToolBar();

    void setToolBarsIconSize(const QSize& iconSize);
    void setToolBarsSpacing(int spacePx);

    void zoomIn();
    void zoomOut();
    void toggleZoomToFitWidth(bool enable);


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
