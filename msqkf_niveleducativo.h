#ifndef MSQKF_NIVELEDUCATIVO_H
#define MSQKF_NIVELEDUCATIVO_H

#include <QString>

class NivelEducativo
{
public:
	NivelEducativo();

	int getIdNivelEducativo();
	void setIdNivelEducativo(int idNivelEducativo);

	QString getDescripcion();
	void setDescripcion(const QString& descripcion);

	int getIdEscuela();
	void setIdEscuela(int idEscuela);

	int getOrden();
	void setOrden(int orden);

private:
	int mIdNivelEducativo;
	QString mDescripcion;
	int mIdEscuela;
	int mOrden;
};

#endif // MSQKF_NIVELEDUCATIVO_H

