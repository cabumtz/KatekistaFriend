#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <msqkf_catalogosdto.h>
#include <msqkf_logger.h>

#include <msqkf_dialogocapturaalumno.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
	bool inicializar();

	void cargarCatalogos();

	void conectarComponentes();
	void inicializaComponentes();

public slots:
	void on_mTlBtnFijarEscuela_toggled(bool checked);
	void on_mTlBtnNuevo_clicked();

private:
    Ui::MainWindow *ui;
	CatalogosDTO mCatalogosDTO;
	Logger mLogger;
	DialogoCapturaAlumno mDialogoCapturaAlumno;
};

#endif // MAINWINDOW_H
