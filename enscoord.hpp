#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cmath>
#include <chrono>
using namespace std;

#include "enscoord.cpp"
#include "coord.hpp"

struct Ens {
  Coord point[];
  int nbPoint;
};

void ensVide(Ens ec);
void afficheEc(Ens ec);
Ens creerEc();
void ajouteEc(Ens ec,Coord c);
int cardEc(Ens ec);
bool estVideEc(Ens ec);
bool estDansEc(Ens ec, Coord c);
Coord trouverVoisin(Coord c);
Ens supprimeEc(Ens &ec, Coord c);
Coord randomEC(Ens ec);
