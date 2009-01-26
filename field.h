/* 
 * File:   field.h
 * Author: kamil
 *
 * Created on December 16, 2008, 11:14 PM
 */

#ifndef _FIELD_H
#define	_FIELD_H

#include <boost/shared_ptr.hpp>
#include "utils.h"
#include "player.h"

class Field {
public:
  Field(char f = '#');
//  Field(const Field& orig);
  virtual ~Field();

  void clearStats() {
  //TODO
  }

  void clear() {
    field = '.';
    clearStats();
  }

  bool operator== (const char field) {
    return this->field == field;
  }

  bool operator!= (const char field) {
    return this->field != field;
  }

//private:
  char field;

  FastMap<Player, 2, unsigned int> distance;

};

typedef boost::shared_ptr<Field> FieldPtr;

#endif	/* _FIELD_H */

