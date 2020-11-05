#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>


#include "page.h"

class Document : public QWidget
{
    Q_OBJECT
public:
    Document(QWidget *parent, const QSize& pageDimension, const QColor& pageBgColor, const PageGrid& pageGrid, const qreal& pageZoom);
    void addNewPage();
    void resizeEvent(QResizeEvent * event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void setPageZoom(const qreal& newZoom);

private:
    QVector<Page*> m_pages;

    QVBoxLayout* m_layout;
    QWidget* m_layoutWrapper;
    QScrollArea* m_scrollArea;

    QSize m_pageDimension;
    QColor m_pageBgColor;
    PageGrid m_pageGrid;

    qreal m_pageZoom;
    void initScrollArea();

};

#endif // DOCUMENT_H
