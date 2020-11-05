#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>


#include "page.h"

class Document : public QScrollArea
{
    Q_OBJECT
public:
    Document(QWidget *parent, const QSize& pageDimension, const QColor& pageBgColor, const PageGrid& pageGrid, const qreal& pageZoom, bool pageFitsWidth = false);
    void addNewPage();
    void resizeEvent(QResizeEvent * event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void setPageZoom(const qreal& newZoom);

    void zoomToWidth(int width = 0, bool resizeToFitScrollBar = true); // if width == 0, set to fit width of widget

private:
    QVector<Page*> m_pages;

    QVBoxLayout* m_layout;
    QWidget* m_layoutWrapper;

    QSize m_pageDimension;
    QColor m_pageBgColor;
    PageGrid m_pageGrid;

    qreal m_pageZoom;
    bool m_pageFitsWidth;


};

#endif // DOCUMENT_H
