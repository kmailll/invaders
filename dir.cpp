/* 
 * File:   dir.cpp
 * Author: kamil
 * 
 * Created on December 15, 2008, 2:07 PM
 */

#include "dir.h"

Logger Dir::logger;
std::string Dir::dirIDToDirMap[8];

void Dir::
init() {
  dirIDToDirMap[1] = std::string("n");
  dirIDToDirMap[5] = std::string("s");
  dirIDToDirMap[3] = std::string("e");
  dirIDToDirMap[7] = std::string("w");
  dirIDToDirMap[2] = std::string("ne");
  dirIDToDirMap[0] = std::string("nw");
  dirIDToDirMap[4] = std::string("se");
  dirIDToDirMap[6] = std::string("sw");
}
