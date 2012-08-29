#ifndef DAOUTIL_H
#define DAOUTIL_H

#include <msqkf_logger.h>

class DAOUtil
{

private:
	DAOUtil();
	~DAOUtil();

public:
	static bool preparaConexionKF();

private:
	static Logger mLogger;
};

#endif // DAOUTIL_H
