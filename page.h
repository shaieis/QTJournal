#ifndef PAGE_H
#define PAGE_H

#include <QWidget>
#include <QColor>
#include <QPoint>

#include "pagegrid.h"
#include "stroke.h"
class Page : public QWidget
{
    Q_OBJECT

public:

    Page(QWidget *parent = nullptr);
    Page(QWidget *parent, const QSize& dimension, const QColor& bg, PageGrid& grid, const qreal& zoom);

    void setBackground(const QColor& color);
    void paintEvent(QPaintEvent *) override;
    void setZoom(const qreal& newZoom);
    void setDimension(const QSize& newDimension);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void eraseLast(const QPolygonF& polygon);
private:

    QVector<QPair<Stroke*, int >> intersect(const QPolygonF& polygon) const; // returns a vector of all strokes that intersect the polygon and their index
    int intersectsLastIndex(const QPolygonF& polygon) const;
    QPointF widgetPosToModelPos(const QPoint& widgetPos) const;
    QSize m_dimension;
    QColor m_bg;
    PageGrid m_grid;
    qreal m_zoom;
    QVector<Stroke*> m_strokes;

};

#endif // PAGE_H
