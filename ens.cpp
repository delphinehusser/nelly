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


// CREER UN ENSEMBLE DE COORDONNEES //

Ens creerEc(){
  Ens ec;
  ec.point[] = 0;
  ec.nbPoint = 0;
}

// AFFICHE UN ENSEMBLE DE COORDONNEES //

void afficheEc(Ens ec){
  cout << L'ensemble contient: ";
  for (int i = 0; i < ec.nbPoint; i++){
    afficheCoord(ec.point[i]);
    cout << " ";
  }
}

// ENS VIDE //

void ecVide(Ens &ec){
  ec.point[] = 0;
  ec.nbPoint = 0;
}

// AJOUTE EC //

void ajouteEc(Ens &ec, Coord c){
	ec.nbPoint++;
  ec.point[nbPoint] = c;
}

// RETOURNE LE NOMBRE DE POINT DANS L'ENSEMBLE //

int cardEc(Ens ec){
  return ec.nbPoint;
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

// TROUVER VOISIN //

Ens trouverVoisin(Coord c){
  int x, y, minx, maxx, nx;
  Ens res;
  ecVide(res);
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
      for(nx = minx;nx <= maxx; nx++)
      ajouteEc(res,creerCoord(nx,y-1));
  }
  if(y != GRILLE_TAILLE-1){
    for(nx = minx; nx <= maxx; nx++){
      ajouteEc(res,creerCoord(nx,y+1));
    }
  }
  return res;
}


// RETOURNE UNE COORDONNEE AU HASARD PARMI UN ENSEMBLE //

Coord randomEC(Ens ec){
  Coord c;
  int abs, ord;
  abs = rand();// pour obtenir un nombre aléatoire entre 0 et n (compris), il faut appliquer un modulo (n+1) au résultat de l'appel à rand()
  ord = rand();// idem
  c.x = abs;
  c.y = ord;
  return c;
}

// SUPPRIME UNE COORDONNEE D'UN ENSEMBLE //

Ens supprimeEc(Ens &ec, Coord c){
  for (int i = 0; i < ec.nbPoint; i++){
    if (egalCoord(ec.point[i], c)){
      for (int j = i; j < ec.nbPoint; j++){
	ec.point[j].x = ec.point[j+1].x;
	ec.point[j].y = ec.point[j+1].y;
      }
      ec.point[ec.nbPoint].x = 0;
      ec.point[ec.nbPoint].y = 0;
      ec.nbPoint--;
    }
  }
  return ec;
}





