#include "capturecolor.h"

#include "capturecolorapplication.h"

int main(int argc, char *argv[])
{
	CaptureColorApplication a(argc, argv);
	CaptureColor w;
	w.show();
	return a.exec();
}
