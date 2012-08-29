#include<msqkf_loggerfactory.h>
#include<QtGlobal>
#include<QDateTime>


QString LoggerFactory::CLASSNAME("LoggerFactory");

LoggerFactory LoggerFactory::mInstance;

LoggerFactory::LoggerFactory()
{
	QString now;
	QString msg;
	QString lineN;
	
	
	lineN = QString::number( __LINE__ );
	now = QDateTime::currentDateTime().toString(LOGGER_DEFAULT_DATE_FORMAT);
	
	// Date MessageType Filename Classname Line Message
	msg = QString(LOGGER_DEFAULT_LOG_FORMAT).arg(
		now,
		LOGGER_MESSAGETYPE_STR_DEBUG,
		__FILE__,
		CLASSNAME,
		lineN,
		"initialized");
	
	qDebug(qPrintable(msg));
}

LoggerFactory::~LoggerFactory()
{
	QString now;
	QString msg;
	QString lineN;
	
	
	lineN = QString("%1").arg( __LINE__ );
	now = QDateTime::currentDateTime().toString(LOGGER_DEFAULT_DATE_FORMAT);
	
	// Date MessageType Filename Classname Line Message
	msg = QString(LOGGER_DEFAULT_LOG_FORMAT).arg(
		now,
		LOGGER_MESSAGETYPE_STR_DEBUG,
		__FILE__,
		CLASSNAME,
		lineN,
		"Finalized");
	
	qDebug(qPrintable(msg));
}


LoggerFactory* LoggerFactory::getInstance()
{
	return &mInstance;
}

Logger LoggerFactory::getLogger(const QString & classname)
{
	Logger logger(classname);
	
	return logger;
}
