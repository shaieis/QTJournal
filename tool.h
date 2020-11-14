#ifndef TOOL_H
#define TOOL_H

#include <QColor>
#include <QRect>
#include <QCursor>


enum class ToolType
{
    Pen,
    Eraser,
};

class Tool
{
public:
    Tool() {};
    virtual ToolType type() const = 0;
    virtual const QCursor& cursor(const qreal& zoom) const = 0;


};


class Pen : public Tool
{
public:
    Pen(const QColor& color, const qreal& thickness);

    QColor color() const;

    qreal thickness() const;
    void setThickness(const qreal& thickness) { m_thickness = thickness; };
    void setColor(const QColor& color) { m_color = color; };
    virtual ToolType type() const override { return ToolType::Pen; };
    virtual const QCursor& cursor(const qreal& zoom) const override;
private:
    QColor m_color;
    qreal m_thickness;

    QCursor m_currCursor;
};

class Eraser : public Tool
{
public:
    Eraser(const QSizeF& size);

    QSizeF size() const;
    virtual const QCursor& cursor(const qreal& zoom) const override;
    virtual ToolType type() const override { return ToolType::Eraser; };
private:
    QSizeF m_size;

    mutable qreal m_currZoom;
    mutable QCursor m_currCursor;
};

#endif // TOOL_H

