 
#include <log4cplus/logger.h>    
#include <log4cplus/loggingmacros.h> 
#include <iomanip>
using namespace log4cplus;    
using namespace log4cplus::helpers;  

/*
NOT_SET_LOG_LEVEL ( -1) 接受缺省的LogLevel，如果有父logger则继承它的LogLevel

ALL_LOG_LEVEL (0) 开放所有log信息输出

TRACE_LOG_LEVEL (0) 开放trace信息输出(即ALL_LOG_LEVEL)

DEBUG_LOG_LEVEL(10000) 开放debug信息输出

INFO_LOG_LEVEL (20000) 开放info信息输出

WARN_LOG_LEVEL (30000) 开放warning信息输出

ERROR_LOG_LEVEL(40000) 开放error信息输出

FATAL_LOG_LEVEL (50000) 开放fatal信息输出

OFF_LOG_LEVEL (60000) 关闭所有log信息输出
*/

// global object    
extern Logger logger;    
// define some macros for simplicity    

#define LOG_TRACE(logEvent)         LOG4CPLUS_TRACE(logger, logEvent)    
#define LOG_DEBUG(logEvent)         LOG4CPLUS_DEBUG(logger, logEvent)    
#define LOG_INFO(logEvent)          LOG4CPLUS_INFO(logger, logEvent)    
#define LOG_WARN(logEvent)          LOG4CPLUS_WARN(logger, logEvent)    
#define LOG_ERROR(logEvent)         LOG4CPLUS_ERROR(logger, logEvent)    
#define LOG_FATAL(logEvent)         LOG4CPLUS_FATAL(logger, logEvent)    
    
extern void InitLogger();  