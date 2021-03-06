#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// STRUCTURES //

struct Coord{
  int x;
  int y;
};

struct Ens {
  Coord point[];
  int nbPoint;
};

struct Animal{
  Coord ou;
  Espece quoi;
  int food;
};

struct Grille{
  Animal caseG[GRILLE_TAILLE][GRILLE_TAILLE];
};

// VARIABLES GLOBALES //

int FoodInit = 5;
int FoodLapin = 5;
int FoodReprod = 8;
int MaxFood = 10;
float ProbBirthRenard = 0.05;
float ProbBirthLapin = 0.3;
int MinFreeBirthLapin = 4;
float ProbReproLapin = 0.2;
float ProbReproRenard = 0.07;

enum Espece { Vide, Lapin , Renard };

int GRILLE_TAILLE = 20;

coord creerCoord(int x, int g);//
int getX(coord c);//
int getY(coord c);//
bool egalCoord(Coord c1, Coord c2);//
//costructeur
void ensVide(Ens ec);//
void afficheEc(Ens ec);//
Ens creerEc();//
void ajouteEc(Ens ec,Coord c);//
int cardEc(Ens ec);//
//test
bool estVide(Ens ec);//
bool estDans(Ens ec, Coord c);//

Coord trouverVoisin(Coord c);//

Animal creerAnimal(Espece e,Coord c);//
Coord CoordAnimal (Animal a);//
Espece especeAnimal(Animal a);//
int nourritureRenard(Animal a);
bool estVide(Coord c);//
void changeCoordAnimal (Animal &a,Coord c);//
void mangeRenard(Animal &a);//
void faimRenard(Animal& a);//
bool mortAnimal(Animal a);//
bool sereproduitAnimal (Animal a,int v);//
void grilleVide( Grille &g);//
void copieGrille (Grille g1, Grille & g2 );//
Animal getAnimal ( Grille g,Coord c);//
void setAnimal (Grille &g,Animal a);//







