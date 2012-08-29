#include "msqkf_servicefactory.h"

#include<msqkf_catalogosdao.h>
#include<msqkf_catalogosservice.h>

ServiceFactory ServiceFactory::mInstance;

ServiceFactory::ServiceFactory()
{
	// creando daos


	// creando services


	// inyectando

	mCatalogosService.setCatalogosDAO(&mCatalogosDAO);
}


ServiceFactory::~ServiceFactory()
{
	// destruir los services y los daos
}


ServiceFactory* ServiceFactory::getInstance()
{
	return & (ServiceFactory::mInstance);
}




CatalogosService* ServiceFactory::getCatalogosService()
{
	return &mCatalogosService;
}

