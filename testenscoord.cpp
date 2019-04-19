#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cmath>
#include <chrono>
using namespace std;

#include "coord.hpp"
#include "enscoord.hpp"

int main{
  Coord B = creerCoord(2,1);
  Coord C = creerCoord(3,4);
  Coord D = creerCoord(0,0);
  Coord E = creerCoord(8,6);
  
  Ens machin = creerEc();
  ASSERT(estVideEc(machin)==true);
  
  ajouteEc(machin,B);
  ajouteEc(machin,C);
  ajouteEc(machin,D);
  
  ASSERT(estVideEc(machin)==false);
  ASSERT(cardEc(machin)==3);
  
  
  ASSERT(estDansEc(machin,B)==true);
  ASSERT(estDansEc(machin,C)==true);
  ASSERT(estDansEc(machin,D)==true);
  ASSERT(estDansEc(machin,E)==false);
  
  trouverVoisin(D);
  
  supprimeEc(machin,D);
  ASSERT(estDansEc(machin,D)==false);
  
}
  
  
  
  

