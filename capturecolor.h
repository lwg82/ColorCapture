#pragma once

#include <QtWidgets/QWidget>
#include "ui_capturecolor.h"

#include <QTimer>
#include <QScreen>

class CaptureColor : public QWidget
{
	Q_OBJECT

public:
	CaptureColor(QWidget *parent = Q_NULLPTR);

protected:
	virtual void keyPressEvent(QKeyEvent * event) override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	Ui::CaptureColorClass ui;

	QTimer *m_timer;
	
	bool    m_bCapture;

public slots:
	void on_timeout();
};
