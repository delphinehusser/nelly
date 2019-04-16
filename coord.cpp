#include <cstdlib>
#include <iostream>
#include <chrono>

using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

// CREER COORD //

struct Coord{
  int x;
  int y;
};

Coord creerCoord(int abs, int ord){
  Coord point;
  point.x = abs;
  point.y = ord;
  return point;
}

void afficheCoord (Coord c){
  cout << "(" << c.x << "," << c.y << ")" << endl;
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
  if (c1.x == c2.x){
    if (c1.y == c2.y){
      return true;
    }
  }
  return false;
}


void testEgalCoord(){
  ASSERT (egalCoord(creerCoord(1,2),creerCoord(1,2)) == true);
}


int main(){
  Coord c1 = creerCoord(2,1);
  afficheCoord(c1);
  cout << endl;

  testEgalCoord;
  return 0;
}



