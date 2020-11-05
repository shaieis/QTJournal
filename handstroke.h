#ifndef HANDSTROKE_H
#define HANDSTROKE_H

#include "stroke.h"

class HandStroke : public Stroke
{
public:
    HandStroke();
    HandStroke(const QColor& penColor, const qreal& penWidth = 1);
    virtual ~HandStroke() {};
    virtual void draw(QPainter& painter, qreal zoom) override;
    virtual void appendPoint(const QPointF& point);
    virtual bool intersects(const QPointF& point) override {};
private:
    QVector<QPointF> m_points;

};

#endif // HANDSTROKE_H
