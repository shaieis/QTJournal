#include "document.h"
#include <QDebug>
#include <QResizeEvent>
Document::Document(QWidget *parent, const QSize& pageDimension, const QColor& pageBgColor, const PageGrid& pageGrid,const qreal& pageZoom) :
    QWidget(parent),
    m_pageDimension(pageDimension),
    m_pageBgColor(pageBgColor),
    m_pageGrid(pageGrid),
    m_pageZoom(pageZoom)
{
    initScrollArea();
}

void Document::addNewPage()
{
    Page *p = new Page(this, m_pageDimension, m_pageBgColor, m_pageGrid, m_pageZoom);

    m_pages.append(p);
    m_layout->addWidget(p);

}

void Document::resizeEvent(QResizeEvent * event)
{

    m_scrollArea->setGeometry(0,0,event->size().width(), event->size().height());
    return QWidget::resizeEvent(event);
}
void Document::initScrollArea()
{
    //Init QScrollArea
    m_scrollArea = new QScrollArea( this );
    m_scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    m_scrollArea->setWidgetResizable( true );

    //Init layout
    m_layoutWrapper = new QWidget(m_scrollArea);

    m_layout = new QVBoxLayout(m_layoutWrapper);
    m_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    m_layoutWrapper->setLayout(m_layout);

    //Insert layout in scrollArea
    m_scrollArea->setWidget(m_layoutWrapper);
}

void Document::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "key pressed" << event->key();
    if (event->key() == Qt::Key::Key_X)
    {
        setPageZoom(m_pageZoom *2);
    }
    if (event->key() == Qt::Key::Key_Y)
    {
        setPageZoom(m_pageZoom /2);
    }
}

void Document::setPageZoom(const qreal& newZoom)
{
    m_pageZoom = newZoom;
    for (auto page : m_pages)
    {
        page->setZoom(m_pageZoom);
    }

}
