#include "document.h"

Document::Document(QWidget *parent) :QWidget(parent)
{
    initScrollArea();

}

void Document::addNewPage()
{
    Page *p = new Page;
    m_pages.append(new Page());
    m_layout->addWidget(p);
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
