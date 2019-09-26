#include "colorwidgetpoint.h"
#include <QPainter>

ColorWidgetPoint::ColorWidgetPoint(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_color = QColor(Qt::black);
}

ColorWidgetPoint::~ColorWidgetPoint()
{
}



void   ColorWidgetPoint::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	painter.fillRect(rect(), m_color);
}
