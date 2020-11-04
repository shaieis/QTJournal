#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>

#include "page.h"

class Document : public QWidget
{
    Q_OBJECT
public:
    Document(QWidget *parent = nullptr);
    void addNewPage();

private:
    QVector<Page*> m_pages;

    QVBoxLayout* m_layout;
    QWidget* m_layoutWrapper;
    QScrollArea* m_scrollArea;


    void initScrollArea();

};

#endif // DOCUMENT_H
