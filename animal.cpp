#include <cstdlib>
#include "code.hpp"
#include "coord.cpp"
#include "animal.cpp"
#include "ens.cpp"
#include "grille.cpp"
#include <iostream>
#include <chrono>;

using namespace std;

//  CREER ANIMAL //

Animal creerAnimal(Espece e, Coord c){
  Animal a;
  a.quoi = e;
  a.ou = c;
  a.food = FoodInit;
  return a;
}

// COORD ANIMAL //

Coord CoordAnimal (Animal a){
  return a.ou;
}

// ESPECE ANIMAL //

Espece especeAnimal(Animal a){
  return a.quoi;
}

// EST VIDE //

bool estVide(Animal a){
  return a.quoi == Vide;
}

// CHANGE COORD //

void changeCoordAnimal (Animal &a, Coord c){
  a.ou.x = c.x;
  a.ou.y = c.y;
}

// MANGE RENARD //
void mangeRenard(Animal &a){
  if (a.food > 0){
    if (a.food <= 5){
      a.food = a.food + FoodLapin;
    } else {
      a.food = MaxFood;
    }
  } else {
  cout << "Ce renard est mort..." << endl;
 }
}

void faimRenard(Animal &a){
  a.food--;
}

// MORT ANIMAL //

bool mortAnimal(Animal a){
  if (especeAnimal(a) == renard){
    if (nourritureRenard(a) == 0){
      return true;
    }
  } else if (especeAnimal(a) == lapin){
    return false;
  } else {
    cout << "Il n'y a pas d'animal" << endl;
  }
}

// SE REPRODUIT ANIMAL //

bool seReproduitAnimal (Animal a, int v){
  float prob = float(rand());
  Ens res;
  int compteur = 0;
  if (especeAnimal(a) == renard){
    if (nourritureRenard(a) >= FoodReprod){
      if (prob <= ProbBirthRenard){
        return true;
      }
    }
  } else if (especeAnimal(a) == lapin){
    res = trouverVoisins(a.ou);
    for (int i = 0; i < res.nbPoint; i++){
      if (estVideEc(res.point[i].e == Vide){//en gros : si une case autour du lapin est vide, ajouter +1 au compteur
      compteur++;
      }
    }
    if (compteur >= MinFreeBirthLapin){
      if (prob <= ProbBirthLapin){
        return true;
      }
    }
  }
}
          
