#include <cstdlib>
#include <iostream>
#include <ostream>
#include <chrono>

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
  ASSERT (egalCoord(creerCoord(0,0),creerCoord(0,0)) == true);
 ASSERT (egalCoord(creerCoord(0,0),creerCoord(0,1)) == false);
}


void afficheEc(Ens ec){
  for (int i = 0; i < ec.nbPoint; i++){
    afficheCoord(ec.point[i]);
  }
  cout << "Il y a " << ec.nbPoint << " coordonnées dans cet ensemble." << endl;
  cout << endl;
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

// SUPPRIME EC //



// ENS VIDE //

void ensVide(Ens &ec){
  ec.nbPoint = 0;
}


int cardEc(Ens ec){
  return ec.nbPoint;
}


Ens trouverVoisin(Coord c){
  int x, y, minx, maxx, nx;
  Ens res;
  ensVide(res);
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


Coord randomEC(Ens ec){
  Coord c;
  int abs, ord;
  abs = rand();
  abs = abs%(GRILLE_TAILLE+1);// pour obtenir un nombre aléatoire entre 0 et n (compris), il faut appliquer un modulo (n+1) au résultat de l'appel à rand() _ A TESTER
  ord = rand();
  ord = ord%(GRILLE_TAILLE+1);
  c.x = abs;
  c.y = ord;
  return c;
}

/*Ens supprimeEc(Ens &ec, Coord c){
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
}*/



int main(){

  Coord c1 = creerCoord(2,1);
  afficheCoord(c1);
  cout << endl;
  Coord c2 = creerCoord(3,4);
  Coord c3 = creerCoord(0,0);
	
	//TEST GET X ET GET Y //
	
	ASSERT(getX(c1)==2);
	ASSERT(getY(c1)==1);
	ASSERT(getX(c2)==3);
	ASSERT(getY(c3)==0);
  
  Ens exemple = creerEc();
	ASSERT(exemple.nbPoint==0);
  ajouteEc(exemple, c1);
  ajouteEc(exemple, c2);
  ajouteEc(exemple, c3);
  afficheEc(exemple);
	
	// TEST AJOUTE EC //
	
	ASSERT(exemple[0]==c1);
	ASSERT(exemple[1]==c2);	
 
  cout << "Ajout d'un élément :" << endl;
  ajouteEc(exemple, creerCoord(4,0));
  afficheEc(exemple);

  return 0;
}



