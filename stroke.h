
#ifndef STROKEINTERFACE_H
#define STROKEINTERFACE_H

#include <QPainter>

class Stroke
{
public:
    Stroke();
    Stroke(const QColor& penColor, const qreal& penWidth = 1);

    virtual ~Stroke() {};

    // Draws Stroke to painter
    virtual void draw(QPainter& painter, qreal zoom) = 0;

    // Checks if point intersects Stroke
    virtual bool intersects(const QPointF& point) = 0;

    virtual QColor penColor() const;
    virtual void setPenColor(const QColor &penColor);

    virtual qreal penWidth() const;
    virtual void setPenWidth(const qreal &penWidth);

private:
    QColor m_penColor;
    qreal m_penWidth;
};


#endif // STROKEINTERFACE_H


