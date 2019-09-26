#pragma once

#include <QApplication>

class CaptureColorApplication : public QApplication
{
	Q_OBJECT

public:
	CaptureColorApplication(int &argc, char **argv);
	~CaptureColorApplication();


};
