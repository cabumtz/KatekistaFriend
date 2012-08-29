#ifndef MSQKF_CATALOGOSDTO_H
#define MSQKF_CATALOGOSDTO_H


#include<QDebug>
#include<QList>
#include<QMap>
#include<msqkf_escuela.h>
#include<msqkf_niveleducativo.h>

class CatalogosDTO
{
public:
    CatalogosDTO();
	~CatalogosDTO();


	void setCatalogoEscuelas(const QList<Escuela* > & catEscuela);
	QList<Escuela* > getCatalogoEscuelas();

	void setCatalogoNivelEducativo(const QMap< int, QList<NivelEducativo * > * > & catNivelEducativo);
	QMap< int, QList<NivelEducativo * > * > getCatalogoNivelEducativo();

private:
	QList<Escuela* > mCatEscuela;
	QMap< int, QList< NivelEducativo* > * > mCatNivelEducativo;

};

#endif // MSQKF_CATALOGOSDTO_H
