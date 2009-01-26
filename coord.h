/* 
 * File:   coord.h
 * Author: kamil
 *
 * Created on December 15, 2008, 2:09 PM
 */

#ifndef _COORD_H
#define	_COORD_H

#include <string>
#include "logger.h"

class Dir;

class Coord {
  unsigned int id;
  unsigned int coord[2];
  static Coord dirIDtoCoordMap[8];
public:

  static void init();

  Coord() {
    coord[0] = 0;
    coord[1] = 0;
  }

  Coord(unsigned int a, unsigned int b) {
    coord[0] = a;
    coord[1] = b;
  }

  Coord(const std::string& str) {
    char al;
    std::stringstream stream(str);
    stream >> al >> coord[1];

    //Logger logger;
    //logger << al << " " << coord[1] << "\n";

    coord[0] = short(al - 'a' + 1);
  }

  unsigned int getID() const {
    return id;
  }

  unsigned int& operator[] (unsigned int x) {
    return coord[x];
  }

  bool operator== (Coord c2) const {
    return coord[0] == c2[0] && coord[1] == c2[1];
  }

  Coord operator+(Coord coord);
  Coord operator-(Coord coord);

  Coord operator+(const unsigned int dirID);
  Coord operator-(const unsigned int dirID);

  int getDistance(Coord& c2) {
    int result = 0;
    result += ( coord[0] > c2[0] ) ? (coord[0] - c2[0]) : (c2[0] - coord[0]);
    result += ( coord[1] > c2[1] ) ? (coord[1] - c2[1]) : (c2[1] - coord[1]);
  }

  std::string toString() const {
    std::stringstream output;
    output << char('a' + coord[0] - 1) << coord[1];
    return output.str();
  }

};

#endif	/* _COORD_H */

