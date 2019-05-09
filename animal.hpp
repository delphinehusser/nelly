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

const int FoodInit = 5;
const int FoodLapin = 5;
const int FoodReprod = 8;
const int MaxFood = 10;
const float ProbBirthRenard = 0.05;
const float ProbBirthLapin = 0.3;
const int MinFreeBirthLapin = 4;
const float ProbReproLapin = 0.2;
const float ProbReproRenard = 0.07;

enum Espece{ Vide , Lapin , Renard };

struct Animal{
  Coord ou;
  Espece quoi;
  int food;
};


Animal creerAnimal(Espece e, Coord c);
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
