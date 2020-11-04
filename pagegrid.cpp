#include "pagegrid.h"

PageGrid::PageGrid() :
    m_enabled(false),
    m_vGridSpacing(0),
    m_vStokeWidth(0),
    m_vColor(),
    m_hGridSpacing(0),
    m_hStokeWidth(0),
    m_hColor(),
    m_rulerXPos(0),
    m_rulerStokeWidth(0),
    m_rulerColor()
{}


PageGrid::PageGrid(
        bool enabled,
        const qreal& vGridSpacing,
        const qreal& vStokeWidth,
        const QColor& vColor,
        const qreal& hGridSpacing,
        const qreal& hStokeWidth,
        const QColor& hColor,
        const qreal& rulerXPos,
        const qreal& rulerStokeWidth,
        const QColor& rulerColor
        ) :
    m_enabled(enabled),
    m_vGridSpacing(vGridSpacing),
    m_vStokeWidth(vStokeWidth),
    m_vColor(vColor),
    m_hGridSpacing(hGridSpacing),
    m_hStokeWidth(hStokeWidth),
    m_hColor(hColor),
    m_rulerXPos(rulerXPos),
    m_rulerStokeWidth(rulerStokeWidth),
    m_rulerColor(rulerColor)
{}

PageGrid::PageGrid(const PageGrid& other) :
    m_enabled(other.m_enabled),
    m_vGridSpacing(other.m_vGridSpacing),
    m_vStokeWidth(other.m_vStokeWidth),
    m_vColor(other.m_vColor),
    m_hGridSpacing(other.m_hGridSpacing),
    m_hStokeWidth(other.m_hStokeWidth),
    m_hColor(other.m_hColor),
    m_rulerXPos(other.m_rulerXPos),
    m_rulerStokeWidth(other.m_rulerStokeWidth),
    m_rulerColor(other.m_rulerColor)
{}

PageGrid& PageGrid::operator=(const PageGrid& other)
{
    m_enabled = other.m_enabled;
    m_vGridSpacing = other.m_vGridSpacing;
    m_vStokeWidth = other.m_vStokeWidth;
    m_vColor =other.m_vColor;
    m_hGridSpacing = other.m_hGridSpacing;
    m_hStokeWidth = other.m_hStokeWidth;
    m_hColor = other.m_hColor;
    m_rulerXPos = other.m_rulerXPos;
    m_rulerStokeWidth = other.m_rulerStokeWidth;
    m_rulerColor = other.m_rulerColor;

    return *this;
}

void PageGrid::draw(QPainter& painter,const QSize& pageDimensions, const qreal& zoom)
{
    if (!m_enabled) return;

    int numOfVGridStrokes = pageDimensions.width() / m_vGridSpacing;
    int numOfHGridStrokes = pageDimensions.height() / m_hGridSpacing;

    QPen pen;

    pen.setColor(m_vColor);
    pen.setCapStyle(Qt::FlatCap);

    pen.setWidthF(m_vStokeWidth * zoom);

    painter.setPen(pen);
    for (int i = 0; i < numOfVGridStrokes; i++)
    {
      painter.drawLine(QLineF((i+1)*m_vGridSpacing*zoom, 0, (i+1)*m_vGridSpacing*zoom, pageDimensions.height()*zoom));
    }

    pen.setColor(m_hColor);
    pen.setWidthF(m_hStokeWidth * zoom);
    painter.setPen(pen);

    for (int i = 0; i < numOfHGridStrokes; i++)
    {
      painter.drawLine(QLineF(0, (i+1)*m_hGridSpacing*zoom, pageDimensions.width()*zoom, (i+1)*m_hGridSpacing*zoom));
    }

    pen.setColor(m_rulerColor);
    pen.setWidthF(m_rulerStokeWidth * zoom);
    painter.setPen(pen);

    painter.drawLine(QLineF(m_rulerXPos*zoom, 0,  m_rulerXPos*zoom, pageDimensions.height()*zoom));
}

bool PageGrid::enabled() const
{
    return m_enabled;
}

void PageGrid::setEnabled(bool enabled)
{
    m_enabled = enabled;
}

qreal PageGrid::vGridSpacing() const
{
    return m_vGridSpacing;
}

void PageGrid::setVGridSpacing(const qreal &vGridSpacing)
{
    if (vGridSpacing <= 0) return;
    m_vGridSpacing = vGridSpacing;
}

qreal PageGrid::vStokeWidth() const
{
    return m_vStokeWidth;
}

void PageGrid::setVStokeWidth(const qreal& vStokeWidth)
{
    if (vStokeWidth <= 0) return;
    m_vStokeWidth = vStokeWidth;
}

QColor PageGrid::vColor() const
{
    return m_vColor;
}

void PageGrid::setVColor(const QColor &vColor)
{
    if (!vColor.isValid()) return;
    m_vColor = vColor;
}

qreal PageGrid::hGridSpacing() const
{
    return m_hGridSpacing;
}

void PageGrid::setHGridSpacing(const qreal &hGridSpacing)
{
    if (hGridSpacing <= 0) return;
    m_hGridSpacing = hGridSpacing;
}

qreal PageGrid::hStokeWidth() const
{
    return m_hStokeWidth;
}

void PageGrid::setHStokeWidth(const qreal& hStokeWidth)
{
    if (hStokeWidth <= 0) return;
    m_hStokeWidth = hStokeWidth;
}

QColor PageGrid::hColor() const
{
    return m_hColor;
}

void PageGrid::setHColor(const QColor &hColor)
{
    if (!hColor.isValid()) return;
    m_hColor = hColor;
}

qreal PageGrid::rulerXPos() const
{
    return m_rulerXPos;
}

void PageGrid::setRulerXPos(const qreal &rulerXPos)
{
    m_rulerXPos = rulerXPos;
}

qreal PageGrid::rulerStokeWidth() const
{
    return m_rulerStokeWidth;
}

void PageGrid::setRulerStokeWidth(const qreal& rulerStokeWidth)
{
    if (rulerStokeWidth <= 0) return;
    m_rulerStokeWidth = rulerStokeWidth;
}

QColor PageGrid::rulerColor() const
{

    return m_rulerColor;
}

void PageGrid::setRulerColor(const QColor &rulerColor)
{
    if (!rulerColor.isValid()) return;
    m_rulerColor = rulerColor;
}

