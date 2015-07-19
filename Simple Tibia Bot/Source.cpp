#include "pch.h"
#include "mainwindow.h"


int main(int argc, char* argv[])
{
	Application a(argc, argv);

	MainWindow mw("Simple tibia bot");
	mw.show();

	return a.exec();
}
