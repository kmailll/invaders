/* 
 * File:   player.h
 * Author: kamil
 *
 * Created on December 10, 2008, 12:28 AM
 */

#ifndef _PLAYER_H
#define	_PLAYER_H

#include <map>
#include <boost/shared_ptr.hpp>
#include "logger.h"

class Player {
public:
    unsigned int id;
    unsigned int getID() { return id; }
    unsigned int setID(unsigned int id) { this->id = id; }

    Player();
//    Player(const Player& orig);

    void clearOwnedFieldsConter() {
//      for(std::map<char, PawnPtr>::const_iterator it = pawns.begin();
//          it != pawns.end();
//          ++it){
//        it->second->ownedFieldsNumber = 0;
//      }
    }

    int getOwnedFieldsNumber() {
//      int sum = 0;
//      for(std::map<char, PawnPtr>::const_iterator it = pawns.begin();
//          it != pawns.end();
//          ++it){
//        //logger << it->first << " score: " << it->second->ownedFieldsNumber << "\n";
//        sum += it->second->ownedFieldsNumber;
//      }

      //logger << "sum: " << sum << "\n";
//      return sum;
    }

    virtual ~Player();
//private:
    static Logger logger;

    char pawns[5];
};

typedef boost::shared_ptr<Player> PlayerPtr;

#endif	/* _PLAYER_H */

