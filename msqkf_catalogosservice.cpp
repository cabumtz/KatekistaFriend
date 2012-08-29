#include "msqkf_catalogosservice.h"

CatalogosService::CatalogosService()
{
	mCatalogosDAO = 0;
}

CatalogosDAO* CatalogosService::getCatalogosDAO()
{
	return mCatalogosDAO;
}

void CatalogosService::setCatalogosDAO(CatalogosDAO* catalogosDAO)
{
	mCatalogosDAO = catalogosDAO;
}


QList<Escuela*> CatalogosService::getCatEscuela()
{
	return mCatalogosDAO->getCatEscuela();
}


QMap< int, QList<NivelEducativo*>* > CatalogosService::getCatNivelEducativo()
{
	return mCatalogosDAO->getCatNivelEducativo();
}



