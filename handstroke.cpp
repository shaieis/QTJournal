#include "handstroke.h"

HandStroke::HandStroke() : Stroke()
{}

HandStroke::HandStroke(const QColor& penColor, const qreal& penWidth) :
    Stroke(penColor, penWidth)

{}

void HandStroke::draw(QPainter& painter, qreal zoom)
{
    if (m_points.size() == 0) return;

    QPen pen(penColor());
    pen.setWidthF(penWidth() * zoom);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);

    if (m_points.size() == 1)
    {
        painter.drawPoint(m_points.at(0));
        return;
    }

    // more than one point. Draw a line

    for(int i = 1; i < m_points.size(); ++i)
    {
        const QPointF& start = m_points.at(i-1) * zoom;
        const QPointF& end = m_points.at(i) * zoom;

        painter.drawLine(start.x(), start.y(), end.x(), end.y());
    }
}

void HandStroke::appendPoint(const QPointF& point)
{
    m_points.append(point);
}

bool HandStroke::intersects(const QPolygonF& poly) const
{
    return m_points.intersects(poly);
}





