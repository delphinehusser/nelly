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

Coord trouverVoisin(Coord c){
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
}
