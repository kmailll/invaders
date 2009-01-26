// 
// File:   Logger.h
// Author: kamil
//
// Created on 18 pazdziernik 2008, 17:25
//

#ifndef _LOGGER_H
#define	_LOGGER_H

#include <fstream>
#include <sstream>
#include <iostream>

class Logger {
    std::ofstream output;
//    static bool active;
    
public:
    Logger() : output( "debug.log", std::ios_base::app ) {
//        active = true;
    }

    static void setActive( bool active_ ) {
//        active = active_;
    }

    template <typename T>
    Logger& operator<< ( const T& message ) {
//        if(!active) return *this;
        std::stringstream messageStr;
        messageStr << message;
        output << messageStr.str() << std::flush;
        std::cerr << messageStr.str() << std::flush;
        return *this;
    }
 
};

//bool Logger::active = true;

#endif	/* _LOGGER_H */

