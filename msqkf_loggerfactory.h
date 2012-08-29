#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include<QString>
#include<msqkf_logger.h>

class LoggerFactory
{
//constructors and destructors
public:
	~LoggerFactory();
private:
    LoggerFactory();


//functions
public:
	static LoggerFactory* getInstance();
	Logger getLogger(const QString & classname);
private:

//variables
public:

private:
	static LoggerFactory mInstance;
	
//constants
public:
private:
	static QString CLASSNAME;
};

#endif // LOGGERFACTORY_H
