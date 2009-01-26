/* 
 * File:   board.cpp
 * Author: kamil
 * 
 * Created on December 8, 2008, 11:52 PM
 */

#include "board.h"
#include <queue>
#include <iomanip>

Move Board::possibleMoveDirs[64];
unsigned int Board::possibleMoveDirsNumber(0);
Logger Board::logger;

void Board::
init() {
  possibleMoveDirsNumber = 0;
  for (int d1 = 0; d1 < 8; ++d1)
    for (int d2 = 0; d2 < 8; ++d2)
      possibleMoveDirs[ possibleMoveDirsNumber++ ] =
        Move(d1, d2, 0);

  //  for (int i = 0; i < possibleMoveDirsNumber; ++i)
  //    logger << possibleMoveDirs[i].toString() << "\n";
}

int Board::
evaluateCoord(Coord coord) {

  int result = 0;
  std::queue<Coord> queue;

  queue.push(coord);
  int bonus = 5;
  int layerSize = 1;

  while (!queue.empty()) {

    coord = queue.front();
    queue.pop();

    if (getFieldByCoord(coord)->field == '.')
      result += bonus;

    getFieldByCoord(coord)->field = '*';
    //logger << board.toString() << "\n";

    Coord nextCoord;
    for (int i = 0; i < 8; ++i) {
      //nextCoord = coord + Dir::getCoordStatic(i);
      if (getFieldByCoord(nextCoord)->field == '.') {
        queue.push(nextCoord);
      }
      //      else
      //        if (board[ nextCoord ] != '*'
      //          && (tSet.empty() || tSet.count(board[ nextCoord ]) > 0))
      //        return result;
    }

    if (--layerSize == 0) {
      if (--bonus == 0)
        return result;
      layerSize = queue.size();
    }

    //logger << this->toString() << "\n";
    //logger << "score = " << result << "\n";
    //sleep(1);

  }

  return result;
}

void Board::
makeMove(const Move& move) {
  Coord pawnCoord = pawnsCoord[ move.pawnID ];
  Coord stoneCoord;

//  logger << "Board::makeMove " << move.pawn->id << " " << pawnCoord.toString() << "\n";

  assert(getFieldByCoord(pawnCoord)->field == move.pawnID);

  FieldPtr field = getFieldByCoord(pawnCoord);
  field->clear();

  pawnCoord = pawnCoord + move.moveDirID;
  stoneCoord = pawnCoord + move.stoneDirID;

  assert(getFieldByCoord(stoneCoord)->field == '.');

  field = getFieldByCoord(stoneCoord);
  field->clearStats();
  field->field = '#';

  //addPawn(move.pawn, pawnCoord);
}

void Board::
undoMove(const Move& move) {
  Coord pawnCoord = pawnsCoord[ move.pawnID ];
  Coord stoneCoord = pawnCoord + move.stoneDirID;
  FieldPtr field;

//  logger << "Board::undoMove " << move.pawn->id << " " << pawnCoord.toString() << "\n";

  assert(getFieldByCoord(pawnCoord)->field == move.pawnID);
  assert(getFieldByCoord(stoneCoord)->field == '#');

  field = getFieldByCoord(pawnCoord);
  field->clear();

  field = getFieldByCoord(stoneCoord);
  field->clear();

  pawnCoord = pawnCoord - move.moveDirID;

  assert(getFieldByCoord(pawnCoord)->field == '.');

  //addPawn(move.pawn, pawnCoord);
}

void Board::
getPossibleMovesForPawn(std::vector<Move>& moves, unsigned int pawnID) {

  Coord pawnCoord = pawnsCoord[ pawnID ];
  Coord pawnNextCoord, stoneCoord;
  Move move;

//  logger << "Board::getPossibleMovesForPawn: " << pawn->id << "\n";

//  assert(getFieldByCoord(pawnCoord)->field == pawnID);

  //  for(char c='a';c<'f';++c)
  //    logger << c << " " << pawnIDToCoordMap[c].toString() << "\n";
  //  for(char i='1';i<'6';++i)
  //    logger << i << " " << pawnIDToCoordMap[i].toString() << "\n";
  //  logger << "Board::getPossibleMovesForPawn " << pawnID << " " << pawnCoord.toString() << " " << getByCoord(pawnCoord) << "\n";

  for (int i = 0; i < possibleMoveDirsNumber; ++i) {
    //      logger << "before " << pawnCoord.toString();
    pawnNextCoord = pawnCoord + possibleMoveDirs[i].moveDirID;
    //      logger << " after " << pawnCoord.toString() << " next " << pawnNextCoord.toString() << "\n";

    if (getFieldByCoord(pawnNextCoord)->field == '.') {
      stoneCoord = pawnNextCoord + possibleMoveDirs[i].stoneDirID;
      if (getFieldByCoord(stoneCoord)->field == '.' ||
          getFieldByCoord(stoneCoord)->field == pawnID) {
        move = possibleMoveDirs[i];
        move.pawnID = pawnID;
        moves.push_back(move);

        //        logger << "found move " << move.toString() << "\n";
      }
    }
  }
}

std::string Board::
toString() const {
  std::stringstream output;
  for (int j = size + 1; j >= 0; --j) {
    output << j << "\t";
//    for (int i = 0; i <= size + 1; ++i)
//      output << board[i][j]->field << " ";
    output << "\n";
  }
  return output.str();
}

std::string Board::
toStringDebug() const {
  std::stringstream output;
//  for (int j = size + 1; j >= 0; --j) {
//    output << j << "\t";
//    for (int i = 0; i <= size + 1; ++i)
//      output << board[i][j]->field << " ";
//
//    output << "  ";
//    for (int i = 0; i <= size + 1; ++i) {
//      if (board[i][j]->ownerPtr != NULL)
//        output << board[i][j]->ownerPtr->id << " "; // << std::setw(2) << board[i][j]->ownerDistance << " ";
//      else
//        output << "#" << " "; // << std::setw(2) << board[i][j]->ownerDistance << " ";
//    }
//
//    output << "  ";
//    for (int i = 0; i <= size + 1; ++i)
//      if(board[i][j]->ownerPtr != NULL)
//        output << board[i][j]->ownerDistance << " ";
//      else
//        output << "# ";
//
//
//    output << "  ";
//    for (int i = 0; i <= size + 1; ++i)
//      if(board[i][j]->prevFieldDir != -1)
//        output << board[i][j]->prevFieldDir << " ";
//      else
//        output << "# ";
//    output << "\t" << j;
//
//    output << "\n";
//  }
    output << " \t";
    for (int i = 0; i <= size + 1; ++i)
      output << char('a'+i-1) << " ";
    output << "  ";
    for (int i = 0; i <= size + 1; ++i)
      output << char('a'+i-1) << " ";
    output << "  ";
    for (int i = 0; i <= size + 1; ++i)
      output << char('a'+i-1) << " ";
    output << "  ";
    for (int i = 0; i <= size + 1; ++i)
      output << char('a'+i-1) << " ";
    output << "\t";
    output << "\n";

  return output.str();
}

Board::Board() {
//  for (int i = 0; i <= MAX_BOARD_SIZE + 1; ++i)
//    for (int j = 0; j <= MAX_BOARD_SIZE + 1; ++j)
//      board[i][j] = FieldPtr(new Field('#'));
}

//Board::Board(const Board& orig) {
//}

Board::~Board() {
}
