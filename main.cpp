#include <cstdlib>
#include "code.hpp"
#include "coord.cpp"
#include "animal.cpp"
#include "ens.cpp"
#include "grille.cpp"
#include <iostream>
#include <chrono>;

using namespace std;

int main() {
  Coord c1 = creerCoord(2,1);
  afficheCoord(c1);
  cout << endl;
  return 0;
}
