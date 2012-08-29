#ifndef MSQKF_SACRAMENTO_H
#define MSQKF_SACRAMENTO_H

#include <QString>

class Sacramento
{
public:
	Sacramento();

	~Sacramento();

	int getIdSacramento();
	void setIdSacramento(int idSacramento);

	QString getNombre();
	void setNombre(const QString& nombre);

	int getOrden();
	void setOrden(int orden);

private:
	int mIdSacramento;
	QString mNombre;
	int mOrden;
};

#endif // MSQKF_SACRAMENTO_H
