#include <QtGui/QApplication>
#include <QStyleFactory>
#include "mainwindow.h"


void establecerTema()
{
	/*
 -  "Windows"
 -  "WindowsXP"
 -  "WindowsVista"
 -  "Motif"
 -  "CDE"
 -  "Plastique"
 -  "Cleanlooks"
	 */

	/*
	foreach(QString cadena, QStyleFactory::keys())
	{
		qDebug() << " - "<< cadena;
	}
	*/

	QApplication::setStyle(QStyleFactory::create("Cleanlooks"));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


	establecerTema();


	MainWindow w;
    w.show();

    return a.exec();
}
