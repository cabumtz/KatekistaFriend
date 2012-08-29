#include "msqkf_dialogocapturaalumno.h"
#include "ui_msqkf_dialogocapturaalumno.h"

#include <msqkf_loggerfactory.h>

DialogoCapturaAlumno::DialogoCapturaAlumno(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogoCapturaAlumno),
	mSacramentosModel()
{
	mLogger = LoggerFactory::getInstance()->getLogger("DialogoCapturaAlumno");

	ui->setupUi(this);


}

DialogoCapturaAlumno::~DialogoCapturaAlumno()
{
	delete ui;
}



void DialogoCapturaAlumno::on_mRdBttnFechaNacimientoNotNull_toggled(bool checked)
{
	LOGGER_DEBUG( mLogger, QString("on_mRdBttnFechaNacimientoNotNull_toggled: %1").arg(checked) );

	if( checked )
	{
		ui->mDtEdtFechaNacimiento->setEnabled(true);
	}
	else
	{
		ui->mDtEdtFechaNacimiento->setEnabled(false);
	}
}
