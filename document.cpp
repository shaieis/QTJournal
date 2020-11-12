#include "document.h"
#include <QDebug>
#include <QResizeEvent>
#include <QScrollBar>

Document::Document(QWidget *parent, const QSize& pageDimension, const QColor& pageBgColor, const PageGrid& pageGrid,const qreal& pageZoom, bool pageFitsWidth) :
    QScrollArea(parent),
    m_pageDimension(pageDimension),
    m_pageBgColor(pageBgColor),
    m_pageGrid(pageGrid),
    m_pageZoom(pageZoom),
    m_pageFitsWidth(pageFitsWidth)
{
    //Init QScrollArea

    setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    setWidgetResizable( true );

    //Init layout
    m_layoutWrapper = new QWidget(this);

    m_layout = new QVBoxLayout(m_layoutWrapper);
    m_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    m_layoutWrapper->setLayout(m_layout);

    //Insert layout in scrollArea
    setWidget(m_layoutWrapper);

}

void Document::addNewPage()
{
    Page *p = new Page(this, m_pageDimension, m_pageBgColor, m_pageGrid, m_pageZoom);

    m_pages.append(p);
    m_layout->addWidget(p);

}

void Document::resizeEvent(QResizeEvent * event)
{
    if (m_pageFitsWidth) setZoomToFitWidth(event->size().width());

    return QScrollArea::resizeEvent(event);
}



void Document::zoomIn()
{
     m_pageFitsWidth = false;
     setZoom(m_pageZoom * zoomFactor);
}

void Document::zoomOut()
{
     m_pageFitsWidth = false;
     setZoom(m_pageZoom / zoomFactor);
}



void Document::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "key pressed" << event->key();

}

void Document::setZoom(const qreal& newZoom)
{
    m_pageZoom = newZoom;
    for (auto page : m_pages)
    {
        page->setZoom(m_pageZoom);
    }
    update();
}

void Document::wheelEvent(QWheelEvent *event)
{

    if (event->modifiers() != Qt::ControlModifier)
    {
       QScrollArea::wheelEvent(event);
       return;
    }

    qDebug() <<event->angleDelta().y();

    if (event->angleDelta().y() > 0)
    {
        m_pageFitsWidth = false;
        setZoom(m_pageZoom * event->angleDelta().y() *scrollWheelZoomFactor);

    }
    else if (event->angleDelta().y() < 0)
    {
        m_pageFitsWidth = false;
        setZoom(m_pageZoom / ((-(event->angleDelta().y())) * scrollWheelZoomFactor));
    }
}

void Document::toggleZoomToFitWidth(bool enable)
{
    if (enable)
    {
        if (m_pageFitsWidth) return;

        m_pageFitsWidth = true;
        setZoomToFitWidth();
    }
    else
    {
        m_pageFitsWidth = false;
    }
}


// =========== Private methods ===========

void Document::setZoomToFitWidth(int width) // If width == 0, width of layout is used
{
    qDebug() << width;
    if (width == 0)
    {
        width = this->width() - verticalScrollBar()->width() - 2;
    }

    qDebug() << width <<'\n';
    const QMargins& layoutMargins = m_layout->contentsMargins();

    width -= layoutMargins.left() + layoutMargins.right(); // take into account margins of layout

    int pageWidth = m_pageDimension.width();

    qreal zoom = (qreal)width / pageWidth;
    setZoom(zoom);
}
