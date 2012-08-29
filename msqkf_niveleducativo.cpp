#include "msqkf_niveleducativo.h"

NivelEducativo::NivelEducativo()
{

}

int NivelEducativo::getIdNivelEducativo()
{
	return mIdNivelEducativo;
}

void NivelEducativo::setIdNivelEducativo(int idNivelEducativo)
{
	mIdNivelEducativo = idNivelEducativo;
}

QString NivelEducativo::getDescripcion()
{
	return mDescripcion;
}

void NivelEducativo::setDescripcion(const QString& descripcion)
{
	mDescripcion = descripcion;
}

int NivelEducativo::getIdEscuela()
{
	return mIdEscuela;
}


void NivelEducativo::setIdEscuela(int idEscuela)
{
	mIdEscuela = idEscuela;
}

int NivelEducativo::getOrden()
{
	return mOrden;
}

void NivelEducativo::setOrden(int orden)
{
	mOrden = orden;
}


