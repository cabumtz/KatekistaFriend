#ifndef LOGGER_H
#define LOGGER_H

// Default format for date time
#define LOGGER_DEFAULT_DATE_FORMAT "dd/MM/yyyy hh:mm:ss.zzz"

// Default format for messages
// Date MessageType Filename Classname Line Message
#define LOGGER_DEFAULT_LOG_FORMAT "[%1] %2 %3{%4}:%5\n  %6"

// MessageType string constants
#define LOGGER_MESSAGETYPE_STR_INFO			"I"
#define LOGGER_MESSAGETYPE_STR_DEBUG		"D"
#define LOGGER_MESSAGETYPE_STR_WARNING		"W"
#define LOGGER_MESSAGETYPE_STR_ERROR		"E"
#define LOGGER_MESSAGETYPE_STR_FATAL		"F"

// Auxiliar Macros
#define LOGGER_INFO( logger, msg )			( logger . info( msg, __FILE__ , __LINE__ ) )				
#define LOGGER_DEBUG( logger, msg )			( logger . debug( msg, __FILE__ , __LINE__ ) )
#define LOGGER_WARNING( logger, msg )		( logger . warning( msg, __FILE__ , __LINE__ ) )
#define LOGGER_ERROR( logger, msg )			( logger . error( msg, __FILE__ , __LINE__ ) )
#define LOGGER_FATAL( logger, msg )			( logger . fatal( msg, __FILE__ , __LINE__ ) )

#include <QString>

class Logger
{
public:
	Logger();
    Logger(const QString & classname);
    ~Logger();

//functions
public:
	void info(const QString msg, const QString & filename, int lineNumber );
	void debug(const QString msg, const QString & filename, int lineNumber );
	void warning(const QString msg, const QString & filename, int lineNumber );
	void error(const QString msg, const QString & filename, int lineNumber );
	void fatal(const QString msg, const QString & filename, int lineNumber );

private:
	const QString message(const QString & message, const QString & messageType, const QString &filename, int lineNumber);

//variables
public:
private:
	QString mClassname;
};

#endif // LOGGER_H
