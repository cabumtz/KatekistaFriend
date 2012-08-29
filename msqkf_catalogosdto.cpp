#include "msqkf_catalogosdto.h"

CatalogosDTO::CatalogosDTO()
{
}

CatalogosDTO::~CatalogosDTO()
{
	Escuela* escuela;
	NivelEducativo* nivelEducativo;

	QList< QList< NivelEducativo* > * > catNivelesEducativos;
	QList< NivelEducativo* > * listaNivelesEducativos;

	QListIterator< Escuela* > iterEscuela(mCatEscuela);
	while( iterEscuela.hasNext() )
	{
		 escuela = iterEscuela.next();
		 delete escuela;
	}



	catNivelesEducativos = mCatNivelEducativo.values();
	QListIterator< QList< NivelEducativo* > * > iterCatNivelEducativo(catNivelesEducativos);

	while( iterCatNivelEducativo.hasNext() )
	{
		listaNivelesEducativos = iterCatNivelEducativo.next();
		QListIterator< NivelEducativo* > iterNivelEducativo( (*listaNivelesEducativos) );


		while( iterNivelEducativo.hasNext() )
		{
			nivelEducativo = iterNivelEducativo.next();

			delete nivelEducativo;
		}

		delete listaNivelesEducativos;
	}


	//qDebug("Se ejecuta destructor de catalogos");
}

void CatalogosDTO::setCatalogoEscuelas(const QList< Escuela* > & catEscuela)
{
	mCatEscuela = catEscuela;
}

QList< Escuela* > CatalogosDTO::getCatalogoEscuelas()
{
	return mCatEscuela;
}


void CatalogosDTO::setCatalogoNivelEducativo(const QMap< int, QList< NivelEducativo * > * > & catNivelEducativo)
{
	mCatNivelEducativo = catNivelEducativo;
}

QMap< int, QList< NivelEducativo * > * > CatalogosDTO::getCatalogoNivelEducativo()
{
	return mCatNivelEducativo;
}

