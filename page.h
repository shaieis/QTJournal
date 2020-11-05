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
private:
    QSize m_dimension;
    QColor m_bg;
    PageGrid m_grid;
    qreal m_zoom;
    QVector<Stroke*> strokes;

};

#endif // PAGE_H
