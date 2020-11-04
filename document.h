#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QWidget>
#include "page.h"

class Document : public QWidget
{
    Q_OBJECT
public:
    Document(QWidget *parent = nullptr);

private:
    QVector<Page> m_pages;
};

#endif // DOCUMENT_H
