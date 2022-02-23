#ifndef __KAREN_HPP__
# define __KAREN_HPP__
# include <string>
class Karen
{
public:
	enum logLevel {
		DEBUG = 0,
		INFO,
		WARNING,
		ERROR,
		NONE
	};
	Karen(void);
	Karen(const std::string logLevel);
	Karen(logLevel level);
	~Karen(void);

	void complain(const std::string level);
	void complain(logLevel level);
	void complain(void);

	logLevel getLogLevel(void) const;
	bool setLogLevel(const logLevel level);
private:
	logLevel _level;

	void defaultMessage(void);
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	logLevel getLogLevelFromString(std::string level);
};

#endif