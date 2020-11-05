#include "page.h"
#include <QDebug>

Page::Page(QWidget *parent) : QWidget(parent), m_dimension(QSize(200,200)), m_zoom(1)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize(m_dimension*m_zoom);
    setBackground("white");

}

Page::Page(QWidget *parent, const QSize& dimension, const QColor& bg, PageGrid& grid, const qreal& zoom) :
    QWidget(parent),
    m_dimension(dimension),
    m_bg(bg),
    m_grid(grid),
    m_zoom(zoom)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize(m_dimension*m_zoom);
    setBackground(bg);
}


void Page::setBackground(const QColor& color)
{
    QPalette pal(palette());

    pal.setColor(QPalette::Background, color);
    setAutoFillBackground(true);
    setPalette(pal);
}

void Page::paintEvent(QPaintEvent * e)
{
    QPainter p(this);
    m_grid.draw(p, m_dimension, m_zoom);
    qDebug() << "Paint Event " << e;
    return QWidget::paintEvent(e);
}
