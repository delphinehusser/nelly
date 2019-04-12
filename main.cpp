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

int main() {
  Coord c1 = creerCoord(2,1);
  Coord c1 = creerCoord(3,4);
  Coord c3 = creerCoord(0,0);
  
  afficheCoord(c1);
  cout << endl;
  
  testEgalCoord();
  
  // on construit un exemple d'ensemble
  Ens exemple = creerEc();
  ajouteEc(exemple, c1);
  ajouteEc(exemple, c2);
  ajouteEc(exemple, c3);
  afficheEc(exemple);
  
  // on ajoute encore un élément
  cout << "Ajout d'un élément :" << endl;
  ajouteEc(exemple, creerCoord(4,0));
  afficheEc(exemple);

  return 0;
}
