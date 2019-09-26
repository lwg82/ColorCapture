#include "capturecolor.h"

#include <QDebug>
#include <QMouseEvent>
#include <QCursor>
#include <QPixmap>
#include <QApplication>
#include <QDesktopWidget>

CaptureColor::CaptureColor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_bCapture = false;

	m_timer = new QTimer(this);

	connect(m_timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
	m_timer->start(100);
}

void CaptureColor::mousePressEvent(QMouseEvent *e)
{
	//qDebug() << e->pos();
	m_timer->disconnect();
	m_timer->stop();
}

void CaptureColor::on_timeout()
{
	QPoint cpos = QCursor::pos();
	
	ui.label_ms->setText(QString("(%1,%2)").arg(cpos.x()).arg(cpos.y()));

	QScreen *screen = QApplication::primaryScreen();
	
	int wh = 25;

	QPixmap pix = screen->grabWindow(qApp->desktop()->winId(), cpos.x(), cpos.y(), wh, wh);

	//QRgb rgb = pix.toImage().pixel(0,0);
	//ui.widgetColor->SetColor(color);

	if (m_bCapture)
		return;

	QColor color = pix.toImage().pixel(wh / 2, wh / 2);

	ui.widgetColor->SetPix(pix);
	ui.widgetColorPoint->SetColor(color);

	

	ui.label_rgb->setText(QString("[%1, %2, %3]")
		.arg(QString::number(color.redF(), 10, 4))
		.arg(QString::number(color.greenF(), 10, 4))
		.arg(QString::number(color.blueF(), 10, 4)));

	ui.label_hsv->setText(QString("[%1, %2, %3]")
		.arg(QString::number(color.hueF(), 10, 4)) // 色度
		.arg(QString::number(color.saturationF(), 10, 4)) // 饱和度
		.arg(QString::number(color.lightnessF(), 10, 4))); // 亮度
}


void CaptureColor::keyPressEvent(QKeyEvent * event)
{
	if (Qt::Key_F12 == event->key())
	{
		m_bCapture = !m_bCapture;
	}
}