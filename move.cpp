/* 
 * File:   move.cpp
 * Author: kamil
 * 
 * Created on December 10, 2008, 6:32 PM
 */

#include "move.h"
#include <sstream>

Move::Move() {
}

Move::Move(const Move& orig) {
  *this = orig;
}

Move::~Move() {
}

std::string Move::
toString() {
  std::stringstream output;
//  output << pawn->id << " "
//         << Dir::dirIDtoDirStatic(moveDirID) << " "
//         << Dir::dirIDtoDirStatic(stoneDirID);

  return output.str();
}


