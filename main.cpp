include <cstdlib>

#include "code.hpp"
#include <iostream>
using namespace std;
#include <chrono>

int main() {
  Coord c1 = creerCoord(2,1);
  afficheCoord(c1);
  cout << endl;
  return 0;
}
