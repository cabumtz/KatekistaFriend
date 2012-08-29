#include <msqkf_logger.h>
#include <QDateTime>

Logger::Logger():
	mClassname()
{
}

Logger::Logger(const QString & classname):
	mClassname(classname)
{

}

Logger::~Logger()
{
}

const QString Logger::message(const QString & message, const QString & messageType, const QString &filename, int lineNumber)
{
	QString now;
	QString msg;
	QString lineN;
	
	lineN = QString::number( lineNumber );
	
	now = QDateTime::currentDateTime().toString(LOGGER_DEFAULT_DATE_FORMAT);
	
	// Date MessageType Filename Classname Line Message
	msg = QString(LOGGER_DEFAULT_LOG_FORMAT).arg(
		now,
		messageType,
		filename,
		mClassname,
		lineN,
		message);
		
	return msg;
}

void Logger::info(const QString msg, const QString & filename, int lineNumber )
{
	qDebug(qPrintable(message(msg,LOGGER_MESSAGETYPE_STR_INFO, filename, lineNumber)));
}

void Logger::debug(const QString msg, const QString &filename, int lineNumber)
{
	qDebug(qPrintable(message(msg,LOGGER_MESSAGETYPE_STR_DEBUG, filename, lineNumber)));
}

void Logger::warning(const QString msg, const QString & filename, int lineNumber )
{
	qWarning(qPrintable(message(msg,LOGGER_MESSAGETYPE_STR_WARNING, filename, lineNumber)));
}

void Logger::error(const QString msg, const QString &filename, int lineNumber)
{
	qCritical(qPrintable(message(msg,LOGGER_MESSAGETYPE_STR_ERROR, filename, lineNumber)));
}

void Logger::fatal(const QString msg, const QString &filename, int lineNumber)
{
	qFatal(qPrintable(message(msg,LOGGER_MESSAGETYPE_STR_FATAL, filename, lineNumber)));
}

