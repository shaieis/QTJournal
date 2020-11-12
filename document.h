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

    static constexpr qreal scrollWheelZoomFactor = 0.00875;  // How much the zoom changes in mouse wheel + ctrl event
    static constexpr qreal zoomFactor = 1.05;

    Document(QWidget *parent, const QSize& pageDimension, const QColor& pageBgColor, const PageGrid& pageGrid, const qreal& pageZoom, bool pageFitsWidth = false);
    void addNewPage();
    void resizeEvent(QResizeEvent * event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    void zoomIn();
    void zoomOut();
    void toggleZoomToFitWidth(bool enable);
    void setZoom(const qreal& newZoom);


private:
    QVector<Page*> m_pages;

    QVBoxLayout* m_layout;
    QWidget* m_layoutWrapper;

    QSize m_pageDimension;
    QColor m_pageBgColor;
    PageGrid m_pageGrid;

    qreal m_pageZoom;
    bool m_pageFitsWidth;


    void setZoomToFitWidth(int width = 0); // If width == 0, width of layout is used
};

#endif // DOCUMENT_H
