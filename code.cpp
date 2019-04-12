#include <iostream>
#include <cmath>
#include <cstdlib>

#include "code.hpp"

using namespace std;

// CREER COORD //

Coord creerCoord(int abs, int ord){
  Coord point;
  point.x = abs;
  point.y = ord;
}

// EGAL COORD //

bool egalCoord(Coord c1, Coord c2){
  if (c1.x == c2.x){
    if (c1.y == c2.y){
      return true;
    }
  }
  return false;
}

// ENS VIDE //

void ensVide(Ens &ec){
  ec.point[] = 0;
  ec.nbPoint = 0;
}

// AJOUTE EC //

void ajouteEc(Ens &ec, Coord c){
  ec.point[nbPoint] = c;
  ec.nbPoint++;
}

// EST VIDE //

bool estVideEc(Ens ec){
  return ec.nbPoint == 0;
}

// EST DANS //

bool estDansEc(Ens ec, Coord c){
  for (int i = 0; i < ec.nbPoint; i++){
    if ( egalCoord(ec.point[i], c)){
      return true;
    }
  }
  return false;
}

// GET X //

int getX(Coord c){
  int abs = c.x;
  return abs;
}

// GET Y //

int getY(Coord c){
  int ord = c.y;
  return ord;
}

// EGAL COORD //

bool egalCoord(Coord c1, Coord c2){
  if ((c1.x == c2.x) and (c1.x == c2.y)){
    return true;
  }
  return false;
}

// TROUVER VOISIN //

Ens trouverVoisin(Coord c){
  int x,y,minx,maxx,nx;
  Ens res;
  ensVide(res);
  x=getX(c);
  y=getY(c);
  if (x==0){
    minx=x;
  }else{
    minx = x-1;
    ajouteEc(res,creerCoord(x-1,y));
  }
  if(GRILLE_TAILLE== x-1){
    maxx=x;
  }else{
    maxx=x+1;
    ajouteEc(res,creerCoord(x+1,y));
  }
  if (y!=0){
      for(nx=minx;nx<=maxx;nx+1)
      ajouteEc(res,creerCoord(nx,y-1));
  }
  if(y!=GRILLE_TAILLE-1){
    for(nx=minx;nx<=maxx;nx++){
      ajouteEc(res,creerCoord(nx,y+1));
    }
  }
  return res;
}

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
          
// INITIALISE UNE GRILLE VIDE //
          
void grilleVide (Grille &g){
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      g.case[i][j] = 0;
    }  
  }
}
          
// COPIE UNE GRILLE G1 DANS UNE GRILLE G2 //  
          
void copieGrille (Grille g1, Grille &g2){
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      g1.case[i][j] = g2.case[i][j];
    }  
  }
}
          
// RENVOIE LA COPIE L'ANIMAL DANS UNE CASE DE LA GRILLE //  
         
Animal getAnimal (Grille g, Coord c){
  Animal copie;
  return copie = g.case[c.x][c.y];
}
          
// //

          
          
