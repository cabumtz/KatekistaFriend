#ifndef MSQKF_CATALOGOSDAO_H
#define MSQKF_CATALOGOSDAO_H

#include<QString>
#include<QList>
#include<QMap>

#include<msqkf_logger.h>

#include<msqkf_escuela.h>
#include<msqkf_niveleducativo.h>
#include<msqkf_sacramento.h>

class CatalogosDAO
{
public:
    CatalogosDAO();

	QList<Escuela*> getCatEscuela();
	QMap< int, QList<NivelEducativo*>* > getCatNivelEducativo();
	QList<Sacramento*> getSacramentos();

private:
	Logger mLogger;
};

#endif // MSQKF_CATALOGOSDAO_H
