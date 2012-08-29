#ifndef MSQKF_CATALOGOSSERVICE_H
#define MSQKF_CATALOGOSSERVICE_H

#include<QString>
#include<QList>
#include<QMap>
#include<msqkf_escuela.h>
#include<msqkf_niveleducativo.h>
#include<msqkf_catalogosdao.h>

class CatalogosService
{
public:
    CatalogosService();

	QList<Escuela*> getCatEscuela();
	QMap< int, QList<NivelEducativo*>* > getCatNivelEducativo();


	CatalogosDAO* getCatalogosDAO();
	void setCatalogosDAO(CatalogosDAO* catalogosDAO);

private:
	CatalogosDAO* mCatalogosDAO;
};

#endif // MSQKF_CATALOGOSSERVICE_H
