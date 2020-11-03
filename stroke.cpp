#include "stroke.h"

Stroke::Stroke() : m_penColor("black"), m_penWidth(1)
{}

Stroke::Stroke(const QColor& penColor, const qreal& penWidth) :
    m_penColor(penColor), m_penWidth(penWidth)
{}

QColor Stroke::penColor() const
{
    return m_penColor;
}

void Stroke::setPenColor(const QColor &penColor)
{
    m_penColor = penColor;
}

qreal Stroke::penWidth() const
{
    return m_penWidth;
}

void Stroke::setPenWidth(const qreal &penWidth)
{
    m_penWidth = penWidth;
}
