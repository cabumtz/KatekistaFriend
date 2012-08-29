#include<QDebug>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlError>

#include <msqkf_catalogosdao.h>
#include <msqkf_constantes.h>
#include <msqkf_loggerfactory.h>

CatalogosDAO::CatalogosDAO()
{
	mLogger = LoggerFactory::getInstance()->getLogger("CatalogosDAO");
}


QList<Escuela*> CatalogosDAO::getCatEscuela()
{
	QSqlQuery query( QSqlDatabase::database(Constantes::CONNECTION_NAME_KF) );
	Escuela* escuela;
	QList<Escuela*> lista;
	QString strQuery = "SELECT ID_ESCUELA, NOMBRE FROM CAT_ESCUELA ORDER BY ID_ESCUELA ASC";

	query.setForwardOnly(true);

	LOGGER_DEBUG( mLogger, QString("SQL: %1").arg( strQuery ) );

	if( ! query.prepare( strQuery ) )
	{
		// hubo un error
		LOGGER_ERROR( mLogger, QString("Error al preparar SQL: %1").arg( query.lastError().text() ) );
		return lista;
	}

	if( ! query.exec() )
	{
		// hubo un error
		LOGGER_ERROR( mLogger, QString("Error al ejecutar SQL: %1").arg( query.lastError().text() ) );
		return lista;
	}

	while(query.next())
	{
		escuela = new Escuela();

		escuela->setIdEscuela( query.value(0).toInt() );
		escuela->setNombre( query.value(1).toString() );

		lista.append(escuela);
	}

	return lista;
}



QMap<int, QList<NivelEducativo *> * > CatalogosDAO::getCatNivelEducativo()
{
	QSqlQuery query( QSqlDatabase::database(Constantes::CONNECTION_NAME_KF) );
	NivelEducativo* nivel;
	QList<NivelEducativo*>* lista;
	QMap< int, QList<NivelEducativo*> * > mapa;
	int idEscuela;
	QString strQuery = "SELECT ID_NIVELEDUCATIVO, DESCRIPCION, ID_ESCUELA, ORDEN FROM CAT_NIVELEDUCATIVO ORDER BY ORDEN ASC";

	query.setForwardOnly(true);

	LOGGER_DEBUG( mLogger, QString("SQL: %1").arg( strQuery ) );

	if( ! query.prepare(strQuery) )
	{
		// hubo un error
		LOGGER_ERROR( mLogger, QString("Error al preparar SQL: %1").arg( query.lastError().text() ) );
		return mapa;
	}



	if( ! query.exec() )
	{
		// hubo un error
		LOGGER_ERROR( mLogger, QString("Error al ejecutar SQL: %1").arg( query.lastError().text() ) );
		return mapa;
	}

	while(query.next())
	{
		nivel = new NivelEducativo();

		nivel->setIdNivelEducativo( query.value(0).toInt() );
		nivel->setDescripcion( query.value(1).toString() );

		idEscuela = query.value(2).toInt();
		nivel->setIdEscuela( idEscuela );
		nivel->setOrden( query.value(3).toInt() );


		if( mapa.contains( idEscuela ) )
		{
			lista = mapa.value( idEscuela );
		}
		else
		{
			lista = new QList<NivelEducativo*>();

			mapa.insert( idEscuela, lista );
		}

		lista->append(nivel);
	}

	return mapa;
}

QList<Sacramento *> CatalogosDAO::getSacramentos()
{
	QSqlQuery query( QSqlDatabase::database(Constantes::CONNECTION_NAME_KF) );
	Sacramento* sacramento;
	QList<Sacramento*> lista;
	QString strQuery = "SELECT ID_SACRAMENTO, NOMBRE, ORDEN FROM CAT_SACRAMENTO ORDER BY ORDEN ASC";

	query.setForwardOnly(true);

	LOGGER_DEBUG( mLogger, QString("SQL: %1").arg( strQuery ) );

	if( ! query.prepare( strQuery ) )
	{
		// hubo un error
		LOGGER_ERROR( mLogger, QString("Error al preparar SQL: %1").arg( query.lastError().text() ) );
		return lista;
	}

	if( ! query.exec() )
	{
		// hubo un error
		LOGGER_ERROR( mLogger, QString("Error al ejecutar SQL: %1").arg( query.lastError().text() ) );
		return lista;
	}

	while(query.next())
	{
		sacramento = new Sacramento();

		sacramento->setIdSacramento( query.value(0).toInt() );
		sacramento->setNombre( query.value(1).toString() );
		sacramento->setOrden( query.value(2).toInt() );

		lista.append(sacramento);
	}

	return lista;
}
