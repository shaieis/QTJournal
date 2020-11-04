#include "document.h"

Document::Document(QWidget *parent) :QWidget(parent)
{
    m_pages.append(Page());

}
