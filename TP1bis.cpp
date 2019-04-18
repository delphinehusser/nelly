#include <cstdlib>
#include <iostream>
#include <ostream>
#include <chrono>
#include <cmath>

using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl



const int MAXENSCOORD = 400;
const int GRILLE_TAILLE = 20;

// CREER COORD //

struct Coord{
  int x;
  int y;
};

struct Ens{
  Coord point[MAXENSCOORD];
  int nbPoint;
};



Coord creerCoord(int abs, int ord){
  Coord point;
  if (abs >= 0 and ord >=0){
    if (abs <= GRILLE_TAILLE and ord <= GRILLE_TAILLE){
      point.x = abs;
      point.y = ord;
    }
  }
  return point;
}


void afficheCoord(Coord c){
  cout << "(" << c.x << "," << c.y << ")" << endl;
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
  if (c1.x == c2.x){
    if (c1.y == c2.y){
      return true;
    }
  }
  return false;
}

void testEgalCoord(){
  ASSERT (egalCoord(creerCoord(1,2),creerCoord(1,2)) == true);
}


void afficheEc(Ens ec){
  for (int i = 0; i < ec.nbPoint; i++){
    afficheCoord(ec.point[i]);
  }
  cout << "Il y a " << ec.nbPoint << " coordonnées dans cet ensemble." << endl;
}

// CREER UN ENSEMBLE DE COORDONNES CONTENANT AUCUN ELEMENT //

Ens creerEc(){
  Ens ec;
  for (int i = 0; i < MAXENSCOORD; i++){
    ec.point[i].x = 0;
    ec.point[i].y = 0;
  }
  ec.nbPoint = 0;
  return ec;
}


// AJOUTE EC //

void ajouteEc(Ens &ec, Coord c){
  ec.point[ec.nbPoint].x = c.x;
  ec.point[ec.nbPoint].y = c.y;
  ec.nbPoint++;
}

// ENS VIDE //

void ensVide(Ens &ec){
  ec.nbPoint = 0;
}


int cardEc(Ens ec){
  return ec.nbPoint;
}


Ens trouverVoisin(Coord c){
  int x, y, minx, maxx, nx;
  Ens res = creerEc();
  x = getX(c);
  y = getY(c);

  if (x == 0){
    minx = x;
  }else{
    minx = x-1;
    ajouteEc(res,creerCoord(x-1,y));
  }
  if(GRILLE_TAILLE == x-1){
    maxx = x;
  }else{
    maxx = x+1;
    ajouteEc(res,creerCoord(x+1,y));
  }
  if (y != 0){
      for(nx = minx; nx <= maxx; nx++)
      ajouteEc(res,creerCoord(nx,y-1));
  }
  if(y != GRILLE_TAILLE-1){
    for(nx = minx; nx <= maxx; nx++){
      ajouteEc(res,creerCoord(nx,y+1));
    }
  }
  return res;
}


/*Coord randomEc(Ens ec){
  Coord c;
  int abs, ord;
  abs = rand()%(GRILLE_TAILLE+1);//A TESTER
  ord = rand()%(GRILLE_TAILLE+1);
  cout << "(" << abs << "," << ord << ")" << endl;

  for (int i = 0; i < ec.nbPoint; i++){
    while (egalCoord(creerCoord(abs,ord), ec.point[i]) == false){
      abs = rand()%(GRILLE_TAILLE+1);
      ord = rand()%(GRILLE_TAILLE+1);
    }
  }
  c.x = abs;
  c.y = ord;
  return c;
}*/


Coord randomEc(Ens ec){
  int compteur;
  compteur = rand() % ec.nbPoint;
  cout << compteur << endl;
  afficheCoord(ec.point[compteur]);
  return ec.point[compteur];
}



Ens supprimeEc(Ens &ec, Coord c){
  for (int i = 0; i < ec.nbPoint; i++){
    if (egalCoord(ec.point[i], c)){
      for (int j = i; j < ec.nbPoint; j++){
	ec.point[j].x = ec.point[j+1].x;
	ec.point[j].y = ec.point[j+1].y;
      }
      ec.point[ec.nbPoint-1].x = 0;
      ec.point[ec.nbPoint-1].y = 0;
      ec.nbPoint--;
    }
  }
  return ec;
}





int main(){

  Coord c1 = creerCoord(2,1);
  Coord c2 = creerCoord(3,4);
  Coord c3 = creerCoord(0,0);
  
  Ens exemple = creerEc();
  ajouteEc(exemple, c1);
  ajouteEc(exemple, c2);
  ajouteEc(exemple, c3);
  afficheEc(exemple);
  cout << endl;
 
  cout << "Ajout d'un élément :" << endl;
  ajouteEc(exemple, creerCoord(4,0));
  afficheEc(exemple);
  cout << endl;

  cout << "Ajout d'un élément :" << endl;
  ajouteEc(exemple, creerCoord(1,6));
  afficheEc(exemple);
  cout << endl;

  /*cout << "Choix d'une coordonnée random :" << endl;
  Coord random;
  random = randomEc(exemple);
  cout << endl;

  cout << "Suppression d'un élément :" << endl;
  supprimeEc(exemple, random);
  cout << endl;

  cout << "Un élément supprimé" << endl;
  afficheEc(exemple);*/

  cout << rand() % 40 << endl;

  return 0;
}



