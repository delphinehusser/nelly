#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cmath>
#include <chrono>
using namespace std;

#include "coord.cpp"

struct Coord{
  int x;
  int y;
};

coord creerCoord(int x, int g);
int getX(coord c);
int getY(coord c);
bool egalCoord(Coord c1, Coord c2);


