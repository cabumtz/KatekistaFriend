#include "msqkf_escuela.h"



Escuela::Escuela()
{
}



int Escuela::getIdEscuela()
{
	return mIdEscuela;
}

void Escuela::setIdEscuela(int idEscuela)
{
	mIdEscuela = idEscuela;
}

QString Escuela::getNombre()
{
	return mNombre;
}

void Escuela::setNombre(const QString& nombre)
{
	mNombre = nombre;
}


