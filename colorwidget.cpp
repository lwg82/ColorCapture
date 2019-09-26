#include "colorwidget.h"

#include <QPainter>

ColorWidget::ColorWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pix = QPixmap(rect().size());
	m_pix.fill(Qt::black);
}

ColorWidget::~ColorWidget()
{
}



void   ColorWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	//painter.fillRect(rect(), m_color);
	painter.drawPixmap(rect(), m_pix);

	painter.drawLine(0, rect().height() / 2 + 1, rect().width(), rect().height() / 2 + 1);
	painter.drawLine(rect().width()/2+1, 0, rect().width() / 2 + 1, rect().height());

}
