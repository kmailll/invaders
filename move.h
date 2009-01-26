/* 
 * File:   move.h
 * Author: kamil
 *
 * Created on December 10, 2008, 6:32 PM
 */

#ifndef _MOVE_H
#define	_MOVE_H

#include <string>
#include <list>

class Move {
public:
  Move();
  Move(const Move& orig);

  Move(unsigned int moveDirID, unsigned int stoneDirID, unsigned int pawnID) {
    this->moveDirID = moveDirID;
    this->stoneDirID = stoneDirID;
    this->pawnID = pawnID;
  }

  unsigned int getScore() const {
    return score;
  }

  void setScore(unsigned int score) {
    this->score = score;
  }

  bool operator<(const Move& move) const {
    return this->score > move.getScore();
  }

  std::string toString();

  virtual ~Move();

//private:
  unsigned int score;
  unsigned int moveDirID, stoneDirID;
  unsigned int pawnID;
};

typedef std::list<Move> MovesListType;

#endif	/* _MOVE_H */

