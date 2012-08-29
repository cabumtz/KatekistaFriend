#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>
#include<QList>
#include<QListIterator>
#include<msqkf_daoutil.h>
#include<msqkf_escuela.h>
#include<msqkf_servicefactory.h>
#include<msqkf_loggerfactory.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	mLogger = LoggerFactory::getInstance()->getLogger("MainWindow");

	LOGGER_INFO( mLogger, "Inicializando Aplicaci'on" );

    ui->setupUi(this);

	inicializar();
}

MainWindow::~MainWindow()
{
    delete ui;

	LOGGER_INFO( mLogger, "Finalizando Aplicaci'on" );
}



bool MainWindow::inicializar()
{

	// crear BD
	if( ! DAOUtil::preparaConexionKF() )
	{
		LOGGER_ERROR( mLogger, "Error al abrir la conexi'on" );
		return false;
	}

	cargarCatalogos();

	inicializaComponentes();

	conectarComponentes();

	return true;
}


void MainWindow::cargarCatalogos()
{
	ServiceFactory* serviceFactory;
	CatalogosService* catalogosService;

	// serviceFactory
	serviceFactory = ServiceFactory::getInstance();
	catalogosService = serviceFactory->getCatalogosService();

	// obteniendo catálogo Escuela
	QList<Escuela* > catalogoEscuela = catalogosService->getCatEscuela();
	mCatalogosDTO.setCatalogoEscuelas(catalogoEscuela);

	QMap< int, QList<NivelEducativo*>* > catalogoNivelEducativo = catalogosService->getCatNivelEducativo();
	mCatalogosDTO.setCatalogoNivelEducativo(catalogoNivelEducativo);
}

void MainWindow::inicializaComponentes()
{

	QSize size = ui->mFrm2->size();
	size.setHeight(0);

	ui->mFrm2->resize(size);

	// combos de catalogos


	QListIterator<Escuela* > iter( mCatalogosDTO.getCatalogoEscuelas() );

	ui->mCmbBxEscuela->addItem("<ninguna>", QVariant::fromValue(-1));
	//ui->mCmbBxEscuela->addItem("<Todas>", QVariant::fromValue(-2));

	while( iter.hasNext())
	{
		Escuela* es = iter.next();
		ui->mCmbBxEscuela->addItem(es->getNombre(), QVariant::fromValue(es->getIdEscuela()));

		/*qDebug() << " - " << es->getIdEscuela() << ", " << es->getNombre();
		delete es;*/
	}


	// dialogo de agregar alumnos
	//mDialogoCapturaAlumno.setModal(true);
}


void MainWindow::conectarComponentes()
{/*
	QObject::connect(
				ui->mTlBtnFijarEscuela, SIGNAL(toggled(bool)),
				this, SLOT(on_mTlBtnFijarEscuela_toggled(bool)));
*/

}





void MainWindow::on_mTlBtnFijarEscuela_toggled(bool checked)
{
	LOGGER_DEBUG( mLogger, QString("on_mTlBtnFijarEscuela_toggled: %1").arg(checked) );

	int currentIndex = ui->mCmbBxEscuela->currentIndex();
	int idEscuela;

	if(checked)
	{
		ui->mCmbBxEscuela->setEnabled(false);
		ui->mFrm1->setEnabled(true);

		ui->mCmbBxNivelEducativo->clear();

		if(currentIndex < 0)
			return;

		idEscuela =  ui->mCmbBxEscuela->itemData(currentIndex).toInt();

		if( idEscuela < 0 )
			return;

		QList< NivelEducativo * > * lista =
				mCatalogosDTO.getCatalogoNivelEducativo().value(idEscuela);


		QListIterator<NivelEducativo* > iter( *lista );

		ui->mCmbBxNivelEducativo->addItem("<ninguno>", QVariant::fromValue(-1));
		//ui->mCmbBxNivelEducativo->addItem("<Todos>", QVariant::fromValue(-2));

		while( iter.hasNext())
		{
			NivelEducativo* ne = iter.next();
			ui->mCmbBxNivelEducativo->addItem(ne->getDescripcion(), QVariant::fromValue(ne->getIdNivelEducativo()));

			/*LOGGER_DEBUG(mLogger,
						 QString("idNivelEducativo: %1, descripci'on: %2")
						 .arg(ne->getIdNivelEducativo()).arg(ne->getDescripcion()) );*/
		}
	}
	else
	{
		ui->mCmbBxEscuela->setEnabled(true);
		ui->mFrm1->setEnabled(false);

		ui->mCmbBxNivelEducativo->clear();
	}
}


void MainWindow::on_mTlBtnNuevo_clicked()
{
	LOGGER_DEBUG(mLogger, "on_mTlBtnNuevo_clicked");

	mDialogoCapturaAlumno.show();
}
