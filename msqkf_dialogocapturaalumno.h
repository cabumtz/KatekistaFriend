#ifndef MSQKF_DIALOGOCAPTURAALUMNO_H
#define MSQKF_DIALOGOCAPTURAALUMNO_H

#include <QDialog>
#include <QStandardItemModel>

#include <msqkf_logger.h>

namespace Ui {
class DialogoCapturaAlumno;
}

class DialogoCapturaAlumno : public QDialog
{
	Q_OBJECT
	
public:
	explicit DialogoCapturaAlumno(QWidget *parent = 0);
	~DialogoCapturaAlumno();

public slots:
	void on_mRdBttnFechaNacimientoNotNull_toggled(bool checked);
	
private:
	Ui::DialogoCapturaAlumno *ui;
	Logger mLogger;
	QStandardItemModel mSacramentosModel;
};

#endif // MSQKF_DIALOGOCAPTURAALUMNO_H
