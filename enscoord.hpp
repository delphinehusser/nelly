#ifndef enscoord_hpp
#define enscoord_hpp

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cmath>
#include <chrono>
using namespace std;
#include "coord.hpp"

const int MAXENSCOORD = 1000;
const int GRILLE_TAILLE = 20;
struct Ens{
  Coord point[MAXENSCOORD];
  int nbPoint;
};

void ecVide(Ens &ec);
void afficheEc(Ens ec);
Ens creerEc();
Coord randomEc(Ens ec);
void ajouteEc(Ens &ec,Coord c);
int cardEc(Ens ec);
bool estVideEc(Ens ec);
bool estDansEc(Ens ec, Coord c);
Ens trouverVoisin(Coord c);
Ens supprimeEc(Ens &ec, Coord c);
Coord randomEC(Ens ec);
#endif
