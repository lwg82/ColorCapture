#pragma once

#include <QWidget>
#include "ui_colorwidgetpoint.h"
#include <QColor>

class ColorWidgetPoint : public QWidget
{
	Q_OBJECT

public:
	ColorWidgetPoint(QWidget *parent = Q_NULLPTR);
	~ColorWidgetPoint();

	void SetColor(QColor c) { m_color = c; update(); }

protected:
	virtual void    paintEvent(QPaintEvent *event) override;

private:
	Ui::ColorWidgetPoint ui;

	QColor   m_color;
};
