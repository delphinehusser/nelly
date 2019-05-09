
#include <iostream>
#include <chrono>

#include "coord.hpp"
#include "enscoord.hpp"



using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

// CREER UN ENSEMBLE DE COORDONNEES //

Ens creerEc(){
Ens ec;
    for(int i = 0 ; i < GRILLE_TAILLE ; i++){
    ec.point[i] = creerCoord(0,0);
    }
ec.nbPoint = 0;
return ec;
}

// AFFICHE UN ENSEMBLE DE COORDONNEES //

void afficheEc(Ens ec){
cout << "L'ensemble contient: ";
  for (int i = 0; i < ec.nbPoint; i++){
  afficheCoord(ec.point[i]);
  cout << " ";
  }
cout << "Il y a " << ec.nbPoint << " coordonnées dans cet ensemble." << endl;
}

// ENS VIDE //

void ecVide(Ens &ec){
    for(int i= 0;i<GRILLE_TAILLE;i++){
    ec.point[i] = creerCoord(0,0);
    }
 ec.nbPoint = 0;
}

// AJOUTE EC //

void ajouteEc(Ens &ec, Coord c){
  if (estDansEc(ec, c)==true){
    cout << "Déjà présent" << endl;
  } else {
    ec.point[ec.nbPoint] = c;
    ec.nbPoint++;
  }
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
                        // A MODIFIER
/*Coord randomEC(Ens ec){
  Coord c;
  int abs, ord;
  abs = rand();// pour obtenir un nombre aléatoire entre 0 et n (compris), il faut appliquer un modulo (n+1) au résultat de l'appel à rand()
  ord = rand();// idem
  c.x = abs;
  c.y = ord;
  return c;
}*/

Coord randomEc(Ens ec){
  int compteur;
  compteur = rand()%ec.nbPoint;
  cout << compteur << endl;
  afficheCoord(ec.point[compteur]);
  return ec.point[compteur];
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
