#ifndef MSQKF_SERVICEFACTORY_H
#define MSQKF_SERVICEFACTORY_H

#include<msqkf_catalogosdao.h>
#include<msqkf_catalogosservice.h>


class ServiceFactory
{
public:
	static ServiceFactory* getInstance();
	~ServiceFactory();
	CatalogosService* getCatalogosService();


private:
    ServiceFactory();

protected:
	static ServiceFactory mInstance;

private:



	CatalogosDAO mCatalogosDAO;
	CatalogosService mCatalogosService;
};

#endif // MSQKF_SERVICEFACTORY_H
