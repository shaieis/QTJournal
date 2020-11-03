#ifndef PAGEGRID_H
#define PAGEGRID_H
#include <QtGlobal>
#include <QColor>
#include <QPainter>

class PageGrid
{
public:
    PageGrid(bool enabled, const qreal& vGridSpacing, const qreal& vStokeWidth, const QColor& vColor, const qreal& hGridSpacing,
             const qreal& hStokeWidth, const QColor& hColor, const qreal& rulerXPos, const qreal& rulerStokeWidth, const QColor& rulerColor);

    PageGrid(const PageGrid& other);

    PageGrid& operator=(const PageGrid& other);

    void paint(QPainter &painter, qreal zoom, qreal pageWidthMm, qreal pageHeightMm);

    bool enabled() const;
    void setEnabled(bool enabled);

    qreal vGridSpacing() const;
    void setVGridSpacing(const qreal &vGridSpacing);

    qreal vStokeWidth() const;
    void setVStokeWidth(const qreal& vStokeWidth);

    QColor vColor() const;
    void setVColor(const QColor &vColor);

    qreal hGridSpacing() const;
    void setHGridSpacing(const qreal &hGridSpacing);

    qreal hStokeWidth() const;
    void setHStokeWidth(const qreal &hStokeWidth);

    QColor hColor() const;
    void setHColor(const QColor &hColor);

    qreal rulerXPos() const;
    void setRulerXPos(const qreal &rulerXPos);

    qreal rulerStokeWidth() const;
    void setRulerStokeWidth(const qreal &rulerStokeWidth);

    QColor rulerColor() const;
    void setRulerColor(const QColor &rulerColor);

protected:
    bool m_enabled;

    qreal m_vGridSpacing;
    qreal m_vStokeWidth;
    QColor m_vColor;

    qreal m_hGridSpacing;
    qreal m_hStokeWidth;
    QColor m_hColor;

    qreal m_rulerXPos;
    qreal m_rulerStokeWidth;
    QColor m_rulerColor;
};

#endif // PAGEGRID_H
