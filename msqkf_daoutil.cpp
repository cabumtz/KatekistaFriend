#include "msqkf_daoutil.h"

#include<QFile>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QProcessEnvironment>
#include<msqkf_constantes.h>
#include<msqkf_loggerfactory.h>


Logger DAOUtil::mLogger = LoggerFactory::getInstance()->getLogger("DAOUtil");

DAOUtil::DAOUtil()
{

}


DAOUtil::~DAOUtil()
{

}


bool DAOUtil::preparaConexionKF()
{
	int result;
	QSqlQuery query;
	QProcessEnvironment environment;
	QString databasePath;

	QSqlDatabase db =
			QSqlDatabase::addDatabase(
				Constantes::DATABASE_TYPE,
				Constantes::CONNECTION_NAME_KF);

	db.setHostName(Constantes::DATABASE_HOST);

	environment = QProcessEnvironment::systemEnvironment();
	databasePath = environment.value(Constantes::ENV_VAR_DATABASE_NAME);

	LOGGER_INFO( mLogger,
				  QString("DB Path: %1").arg( databasePath ) );

	db.setDatabaseName(databasePath);


	db.setUserName(Constantes::DATABASE_USER);
	db.setPassword(Constantes::DATABASE_PASSWORD);


	if( ! QFile(databasePath).exists() )
	{
		LOGGER_ERROR( mLogger,
					  QString("Error al abrir conecci'on a BD: La BD %1 no existe").arg( databasePath ) );

		return false;
	}


	result = db.open();

	if( !result )
	{
		LOGGER_ERROR( mLogger,
					  QString("Error al abrir conecci'on a BD: %1").arg( db.lastError().text() ) );

		return false;
	}


	query = QSqlQuery( "PRAGMA encoding = \"UTF-16\"", db);


	if( !query.exec() )
	{
		LOGGER_ERROR( mLogger,
					  QString("Error al ejecutar query: PRAGMA encoding = \"UTF-16\" : %1"
							  ).arg(query.lastError().text()) );

		return false;
	}

	return true;
}
