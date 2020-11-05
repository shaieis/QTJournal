#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>

#include "document.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *) override;

private:
    QScrollArea* m_scrollArea;
    Document* m_document;

};




#endif // MAINWINDOW_H
