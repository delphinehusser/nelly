#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cmath>
#include <chrono>
using namespace std;

struct Coord{
  int x;
  int y;
};

Coord creerCoord(int x, int g);
void afficheCoord (Coord c);
int getX(Coord c);
int getY(Coord c);
bool egalCoord(Coord c1, Coord c2);
void testEgalCoord();


