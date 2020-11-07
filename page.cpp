#include "page.h"

#include <QDebug>
#include <QMouseEvent>

#include "handstroke.h"

Page::Page(QWidget *parent) : QWidget(parent), m_dimension(QSize(200,200)), m_zoom(1)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setFixedSize(m_dimension*m_zoom);
    setBackground("white");

}

Page::Page(QWidget *parent, const QSize& dimension, const QColor& bg, PageGrid& grid, const qreal& zoom) :
    QWidget(parent),
    m_dimension(dimension),
    m_bg(bg),
    m_grid(grid),
    m_zoom(zoom)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setFixedSize(m_dimension*m_zoom);
    qDebug() << "page size:" << m_dimension*m_zoom;
    setBackground(bg);
}


void Page::setBackground(const QColor& color)
{
    QPalette pal(palette());

    pal.setColor(QPalette::Background, color);
    setAutoFillBackground(true);
    setPalette(pal);
}

void Page::paintEvent(QPaintEvent * e)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    m_grid.draw(p, m_dimension, m_zoom);

    for (auto stroke : m_strokes)
    {
        stroke->draw(p, m_zoom);
    }

    qDebug() << "Paint Event " << e;
    return QWidget::paintEvent(e);


}

void Page::setZoom(const qreal& newZoom)
{

    m_zoom = newZoom;
    //setMinimumSize(m_dimension*m_zoom);
    qDebug() << "page dims: " << m_dimension*m_zoom;
    setFixedSize(m_dimension*m_zoom);
}

 void Page::setDimension(const QSize& newDimension)
 {
     m_dimension = newDimension;
 }

 void Page::mousePressEvent(QMouseEvent *event)
 {
     if (!(event->buttons() & Qt::LeftButton))
     {
         return;
     }

     qDebug() << "press" << event->pos();
     const QPointF &modelPos = widgetPosToModelPos(event->pos());
     HandStroke *newStroke = new HandStroke();
     newStroke->appendPoint(modelPos);
     m_strokes << newStroke;
     update();
 }
 void Page::mouseReleaseEvent(QMouseEvent *event)
 {
     if (!(event->buttons() & Qt::LeftButton))
     {
         return;
     }

     qDebug() << "release" << event->pos();
     update();

 }
 void Page::mouseMoveEvent(QMouseEvent *event)
 {
    if (event->buttons() & Qt::LeftButton)
    {
         const QPointF &modelPos = widgetPosToModelPos(event->pos());
         static_cast<HandStroke*>(m_strokes.last())->appendPoint(modelPos);
         qDebug() << "move" << event->pos();
         update();
    }
    else if (event->buttons() & Qt::RightButton)
    {
        QPointF center = widgetPosToModelPos(event->pos());

        QPointF offset = {5,5};

        QRectF rect(center-offset, center+offset);
        qDebug() << "move erase. center: " << center << " rect: " << rect;
        eraseLast(rect);
    }
 }

 void Page::eraseLast(const QPolygonF& polygon)
 {

     for (int i = m_strokes.size()-1; i >= 0; --i)
     {
         qDebug() << "Checking stroke " << i << " of " << m_strokes.size();
         if (m_strokes[i]->intersects(polygon))
         {
             qDebug() << "Found intersection";
             m_strokes.remove(i);
             update();
             return;
         }
     }
 }

 //  =================== Private methods ===================
 QVector<QPair<Stroke*, int>> Page::intersect(const QPolygonF& polygon) const
 {
     QVector<QPair<Stroke*, int>> ret;
     for (int i = 0; i < m_strokes.size(); ++i)
     {
         Stroke* curr = m_strokes[i];
         if (curr->intersects(polygon))
         {
             ret << QPair<Stroke*, int>(curr, i);
         }

     }
     return ret;
 }

 QPointF Page::widgetPosToModelPos(const QPoint& widgetPos) const
 {
     QPointF retVal(widgetPos);
     retVal /= m_zoom;

     return retVal;
 }
