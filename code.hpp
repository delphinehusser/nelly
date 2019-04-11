#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct Coord{
  int x;
  int y;
};

struct Ens {
  Coord point[];
  int nbPoint;
};

struct Animal{
  coord loc;
  Espece e;
};

enum Espece { Vide, Lapin , Renard };

int GRILLE_TAILLE = 20;

coord creerCoord(int x, int g);
int getX(coord c);
int getY(coord c);
bool egalCoord(Coord c1, Coord c2);
//costructeur
void ensVide(Ens ec);
void ajouteEc(Ens ec,Coord c);
//test
bool estVide(Ens ec);
bool estDans(Ens ec, Coord c);

Coord trouverVoisin(Coord c);

Animal creerAnimal(Espece e,Coord c);
Coord CoordAnimal (Animal a);
Espece especeAnimal(Animal a);
int nourritureRenard(Animal a);
bool estVide(Animal a);
void changeCoordAnimal (Animal &a,Coord c);
void mangeRenard(Animal &a);
void faimRenard(Animal& a);
bool mortAnimal(Animal a);
bool sereproduitAnimal (Animal a,int v);
