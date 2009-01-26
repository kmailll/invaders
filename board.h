/* 
 * File:   board.h
 * Author: kamil
 *
 * Created on December 8, 2008, 11:52 PM
 */

#ifndef _BOARD_H
#define	_BOARD_H

#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <cassert>

#include "move.h"
#include "coord.h"
#include "field.h"
#include "player.h"
#include "logger.h"
#include "utils.h"


const unsigned MAX_BOARD_SIZE = 19;

class Board {
public:
  static void init();

  Board();
  //    Board(const Board& orig);

  void makeMove(const Move& move);
  void undoMove(const Move& move);

  void clearDistanceStats() {
//    for (int i = 1; i <= size; ++i)
//      for (int j = 1; j <= size; ++j)
//        if( board[i][j]->field == '.' )
//          board[i][j]->clearStats();
  }

  void updateOwnedFieldsCounter() {
//    for (int i = 1; i <= size; ++i)
//      for (int j = 1; j <= size; ++j)
//        if (board[i][j]->ownerPtr != NULL)
//          board[i][j]->ownerPtr->ownedFieldsNumber++;
  }

  int evaluateCoord(Coord coord);

  void getPossibleMovesForPawn(std::vector<Move>& moves, unsigned int pawnID);

  unsigned short getSize() const {
    return size;
  }

  void setSize(unsigned short size) {
    this->size = size;
  }

  FieldPtr getField(unsigned int x, unsigned int y) {
    return board[ Coord(x,y) ];
  }

  FieldPtr& getFieldByCoord(Coord& coord) {
    return board[ coord ];
  }

  FieldPtr & operator[] (Coord& coord) {
    return getFieldByCoord(coord);
  }


  std::string toString() const;
  std::string toStringDebug() const;

  virtual ~Board();

  //private:
  static Logger logger;

  //FieldPtr board[ (MAX_BOARD_SIZE + 2) * (MAX_BOARD_SIZE + 2) ];
  FastMap<Coord, (MAX_BOARD_SIZE + 2) * (MAX_BOARD_SIZE + 2), FieldPtr> board;

  Coord pawnsCoord[256];
  unsigned short size;

  static Move possibleMoveDirs[];
  static unsigned int possibleMoveDirsNumber;
};


#endif	/* _BOARD_H */

