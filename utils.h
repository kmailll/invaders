#ifndef _UTILS_H
#define	_UTILS_H

template <typename Index, unsigned size, typename Element> class FastMap {
  Element tab[size];
public:
  Element& operator[] (Index x) { return tab[x.getID()]; }
  const Element& operator[] (Index x) const { return tab[x.getID()]; }

  Element& operator[] (unsigned x) { return tab[x]; }
  const Element& operator[] (unsigned x) const { return tab[x]; }
};


class FastMapIndex {
public:
  unsigned int id;
  unsigned int getID() const { return id; }
  unsigned int setID(unsigned int id) { this->id = id; }
};

#endif
