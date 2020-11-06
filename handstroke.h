#ifndef HANDSTROKE_H
#define HANDSTROKE_H

#include <QPolygonF>
#include "stroke.h"

class HandStroke : public Stroke
{
public:
    HandStroke();
    HandStroke(const QColor& penColor, const qreal& penWidth = 1);
    virtual ~HandStroke() {};
    virtual void draw(QPainter& painter, qreal zoom) override;
    virtual void appendPoint(const QPointF& point);
    virtual bool intersects(const QPolygonF& poly) const override;
private:
    QPolygonF m_points;

};

#endif // HANDSTROKE_H
