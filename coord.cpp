/* 
 * File:   coord.cpp
 * Author: kamil
 * 
 * Created on December 15, 2008, 2:09 PM
 */

#include "coord.h"

Coord Coord::dirIDtoCoordMap[8];

void Coord::
init() {
  dirIDtoCoordMap[1] = Coord(0, 1);
  dirIDtoCoordMap[5] = Coord(0, -1);
  dirIDtoCoordMap[3] = Coord(1, 0);
  dirIDtoCoordMap[7] = Coord(-1, 0);
  dirIDtoCoordMap[2] = Coord(1, 1);
  dirIDtoCoordMap[0] = Coord(-1, 1);
  dirIDtoCoordMap[4] = Coord(1, -1);
  dirIDtoCoordMap[6] = Coord(-1, -1);
}

Coord Coord::
operator+(Coord coord) {
  Coord newCoord = *this;
  newCoord.coord[0] += coord[0];
  newCoord.coord[1] += coord[1];
  return newCoord;
}

Coord Coord::
operator-(Coord coord) {
  Coord newCoord = *this;
  newCoord.coord[0] -= coord[0];
  newCoord.coord[1] -= coord[1];
  return newCoord;
}

Coord Coord::
operator+(const unsigned int dirID) {
  return Coord(*this) + dirIDtoCoordMap[ dirID ];
}

Coord Coord::
operator-(const unsigned int dirID) {
  return Coord(*this) - dirIDtoCoordMap[ dirID ];
}

//Coord Coord::
//operator+(const Dir dir) {
//  return operator+(dir);
//}
//
//Coord Coord::
//operator-(const Dir dir) {
//  return operator+(dir);
//}

