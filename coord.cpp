#include <cstdlib>
#include "code.hpp"
#include "coord.cpp"
#include "animal.cpp"
#include "ens.cpp"
#include "grille.cpp"
#include <iostream>
#include <chrono>;

using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl


// CREER COORD //

Coord creerCoord(int abs, int ord){
  Coord point;
  point.x = abs;
  point.y = ord;
}

void afficheCoord (Coord c){
  cout << "(" << c.x << "," << c.y << ")" << endl;
}

// EGAL COORD //

bool egalCoord(Coord c1, Coord c2){
  if (c1.x == c2.x){
    if (c1.y == c2.y){
      return true;
    }
  }
  return false;
}

void testEgalCoord(){
  ASSERT( egalCoord(creerCoord(4,5),creerCoord(4,5)) );
  ASSERT( egalCoord(creerCoord(3,6),creerCoord(3,6)) );
}

// GET X //

int getX(Coord c){
  int abs = c.x;
  return abs;
}

// GET Y //

int getY(Coord c){
  int ord = c.y;
  return ord;
}

// EGAL COORD //

bool egalCoord(Coord c1, Coord c2){
  if ((c1.x == c2.x) and (c1.x == c2.y)){
    return true;
  }
  return false;
}
