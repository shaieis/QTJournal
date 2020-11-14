#include "tool.h"
#include <QPixmap>
#include <QPainter>

Pen::Pen(const QColor& color, const qreal& thickness) :
    m_color(color), m_thickness(thickness)
{}

const QCursor& Pen::cursor(const qreal& zoom) const
{
    return m_currCursor;
}

QColor Pen::color() const
{
    return m_color;
}

qreal Pen::thickness() const
{
    return m_thickness;
}



Eraser::Eraser(const QSizeF& size) : m_size(size), m_currZoom(-1)
{
}

QSizeF Eraser::size() const
{
    return m_size;
}



const QCursor& Eraser::cursor(const qreal& zoom) const
{
    if (m_currZoom != zoom)
    {
        QSize zoomedSize = (m_size*zoom).toSize();
        QPixmap pixmap(zoomedSize);
        pixmap.fill();
        QPainter painter(&pixmap);

        painter.drawRect(0,0, zoomedSize.width()-1, zoomedSize.height()-1);
        m_currCursor = QCursor(pixmap);
        m_currZoom = zoom;
    }

    return m_currCursor;
}
