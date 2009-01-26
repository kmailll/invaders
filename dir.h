/* 
 * File:   dir.h
 * Author: kamil
 *
 * Created on December 15, 2008, 2:07 PM
 */

#ifndef _DIR_H
#define	_DIR_H

#include <string>
#include <cassert>

#include "coord.h"
#include "logger.h"

class Dir {
public:
  static void init();

  static unsigned int dirToDirIDStatic(const std::string& dir) {
    for (int i = 0; i < 8; ++i)
      if (dirIDToDirMap[i] == dir)
        return i;
  }

  static std::string dirIDtoDirStatic(unsigned int dirID) {
    return dirIDToDirMap[ dirID ];
  }

  Dir(unsigned int dirID) {
    this->dirID = dirID;
  }

  Dir(const std::string& dir) {
    dirID = dirToDirIDStatic(dir);
  }

  std::string toString() const {
    return dirIDToDirMap[dirID];
  }

  unsigned int getDirID() const {
    return dirID;
  }

private:
  static Logger logger;

  static std::string dirIDToDirMap[8];
  unsigned int dirID;
};


#endif	/* _DIR_H */

