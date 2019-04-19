#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cmath>
#include <chrono>
using namespace std;
#include "coord.cpp"



struct Ens {
  Coord point[];
  int nbPoint;
};

void ecVide(Ens &ec);
void afficheEc(Ens ec);
Ens creerEc();
void ajouteEc(Ens &ec,Coord c);
int cardEc(Ens ec);
bool estVideEc(Ens ec);
bool estDansEc(Ens ec, Coord c);
Ens trouverVoisin(Coord c);
Ens supprimeEc(Ens &ec, Coord c);
Coord randomEC(Ens ec);
