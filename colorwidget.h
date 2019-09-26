#pragma once

#include <QWidget>
#include "ui_colorwidget.h"

#include <QColor>
#include <QPixmap>

class ColorWidget : public QWidget
{
	Q_OBJECT

public:
	ColorWidget(QWidget *parent = Q_NULLPTR);
	~ColorWidget();

	
	void SetPix(QPixmap &pix) { m_pix = pix; update();}
protected:
	virtual void    paintEvent(QPaintEvent *event) override;
private:
	Ui::ColorWidget ui;

	
	QPixmap  m_pix;
};
