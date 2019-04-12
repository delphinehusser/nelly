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

