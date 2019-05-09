
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

#include "coord.hpp"
#include "enscoord.hpp"
#include "animal.hpp"

Animal creerAnimal(Espece e, Coord c){
  Animal a;
  a.quoi = e;
  a.ou = c;
  if (e == Renard){
    a.food = FoodInit;
  } else if (e == Lapin){
    a.food = 0;
  } else if (e == Vide){
    a.food = -1;
  }
  return a;
}


void afficheEspece(Espece e){
  switch(e){
    case Vide : cout << "Vide"; break;
    case Lapin : cout << "Lapin"; break;
    case Renard : cout << "Renard"; break;
  }
}

void afficheAnimal(Animal a){
  cout << "C'est un ";
  afficheEspece(a.quoi);
  cout << endl;
  cout << "Le ";
  afficheEspece(a.quoi);
  cout << " est en ";
  afficheCoord(a.ou);
  cout << endl;
  cout << "Le ";
  afficheEspece(a.quoi);
  cout << " a " << a.food << " nourriture(s)" << endl;
}

// COORD ANIMAL //

Coord coordAnimal (Animal a){
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

int nourritureRenard(Animal a){
  if (a.quoi == Renard){
    return a.food;
  }
  return 0;
}

void mangeRenard(Animal &a){
  if (a.food > 0){
    if (a.food <= 5){
      a.food = a.food + FoodLapin;
    } else {
      a.food = MaxFood;
    }
  } else {
  //cout << "Ce renard est mort..." << endl;
 }
}

void faimRenard(Animal &a){
  a.food--;
}

// MORT ANIMAL //

bool mortAnimal(Animal a){
  if (especeAnimal(a) == Renard){
    if (nourritureRenard(a) == 0){
      //cout << "L'animal est décéde...RIP" << endl;
      return true;
    }
  } else if (especeAnimal(a) == Lapin){
    return false;
  } else {
    //cout << "Il n'y a pas d'animal" << endl;
  }
  return false;
}


// SE REPRODUIT ANIMAL //

bool seReproduitAnimal (Animal a, int casesVides){
    int prob2 = rand()%100;
          int prob = rand()%100;
  if (especeAnimal(a) == Renard){
    if (nourritureRenard(a) >= FoodReprod){

      //cout<<prob<<endl;
      if (prob <= ProbBirthRenard*100){
      //  cout << "Le renard peut se reproduire." << endl;
        return true;
      } else {
//cout << "Le renard ne peut pas se reproduire." << endl;
}
    }
  } else if (a.quoi == Lapin){
    //cout<<casesVides<<endl;
      if (casesVides >= MinFreeBirthLapin){
          // cout<<prob2<<endl;
        if (prob2 <= ProbBirthLapin*100){
	       //cout << "Le lapin peut se reproduire." << endl;
          return true;
        } else {
	  //cout << "Le lapin ne peut pas se reproduire." << endl;
}
      }
  }
  //cout << "L'animal ne peut pas se reproduire." << endl;
  return false;
}
