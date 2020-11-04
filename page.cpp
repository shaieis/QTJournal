#include "page.h"

Page::Page(QWidget *parent) : QWidget(parent), m_dimension(QSize(200,200))
{
    resize(m_dimension);
    setBackground("white");
}

Page::Page(QWidget *parent, const QSize& dimension, const QColor& bg, PageGrid& grid) :
    QWidget(parent),
    m_dimension(dimension),
    m_bg(bg),
    m_grid(grid)
{
    resize(m_dimension);
    setBackground(bg);
}


void Page::setBackground(const QColor& color)
{
    QPalette pal(palette());

    pal.setColor(QPalette::Background, color);
    setAutoFillBackground(true);
    setPalette(pal);
}

