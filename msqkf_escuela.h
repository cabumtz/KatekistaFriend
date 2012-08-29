#ifndef MSQKF_ESCUELA_H
#define MSQKF_ESCUELA_H

#include<QString>

class Escuela
{
public:
	Escuela();

	int getIdEscuela();
	void setIdEscuela(int idEscuela);

	QString getNombre();
	void setNombre(const QString& nombre);

private:
	int mIdEscuela;
	QString mNombre;
};

#endif // MSQKF_ESCUELA_H
