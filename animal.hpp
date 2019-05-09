#ifndef animal_hpp
#define animal_hpp

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "enscoord.hpp"

enum Espece{ Vide , Lapin , Renard };

struct Animal{
  Coord ou;
  Espece quoi;
  int food;
};



void afficheAnimal(Animal a);
Coord coordAnimal (Animal a);
Espece especeAnimal(Animal a);
bool estVide(Animal a);
void changeCoordAnimal (Animal &a, Coord c);
int nourritureRenard(Animal a);
void mangeRenard(Animal &a);
void faimRenard(Animal &a);
bool mortAnimal(Animal a);
bool seReproduitAnimal (Animal a, int casesVides);

#endif
