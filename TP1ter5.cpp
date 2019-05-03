#include <cstdlib>
#include <iostream>
#include <ostream>
#include <chrono>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

enum Espece{ Vide , Lapin , Renard };

void afficheEspece(Espece e){
  switch(e){
    case Vide : cout << "Vide"; break;
    case Lapin : cout << "Lapin"; break;
    case Renard : cout << "Renard"; break;
  }
}


struct Animal{
  Coord ou;
  Espece quoi;
  int food;
};


struct Grille{
  Animal caseG[GRILLE_TAILLE][GRILLE_TAILLE];
};


int FoodInit = 5;
int FoodLapin = 5;
int FoodReprod = 8;
int MaxFood = 10;
float ProbBirthRenard = 0.05;
float ProbBirthLapin = 0.3;
int MinFreeBirthLapin = 4;
float ProbReproLapin = 0.2;
float ProbReproRenard = 0.07;


/**********************************************************************/


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
  cout << "(" << c.x << "," << c.y << ")";
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
cout << "L'ensemble contient: ";
  for (int i = 0; i < ec.nbPoint; i++){
  afficheCoord(ec.point[i]);
  cout << ", ";
  }
  cout << "Il y a " << ec.nbPoint << " coordonnées dans cet ensemble." << endl;
}

// CREER UN ENSEMBLE DE COORDONNES CONTENANT AUCUN ELEMENT // bla

Ens creerEc(){
Ens ec;
    for(int i = 0 ; i < GRILLE_TAILLE ; i++){
    ec.point[i] = creerCoord(0,0);
    }
ec.nbPoint = 0;
return ec;
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

// AJOUTE EC //

void ajouteEc(Ens &ec, Coord c){
  if (estDansEc(ec, c)==true){
  cout << "Déjà présent" << endl;
  } else {
    ec.point[ec.nbPoint] = c;
    ec.nbPoint++;
  }
}


// ENS VIDE //


void ecVide(Ens &ec){
    for(int i= 0;i<GRILLE_TAILLE;i++){
    ec.point[i] = creerCoord(0,0);
    }
 ec.nbPoint = 0;
}


// EST VIDE //



bool estVideEc(Ens ec){
  return ec.nbPoint == 0;
}

// RETOURNE LE NOMBRE DE POINT DANS L'ENSEMBLE //


int cardEc(Ens ec){
  return ec.nbPoint;
}

// TROUVER VOISIN //

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

// INIT TESTRAND //
/*
void initrand(){
int i = 0;
int nombre_aleatoire = 0;
srand(time(NULL)); // initialisation de rand
for(i=0; i<1000; i++){
    nombre_aleatoire = rand();
}
}

// RETOURNE UN NOMBRE AU HASARD ENTRE a ET b //

int rand_a_b(int a, int b){
  initrand();
    //  cout<<rand()%(b-a) +a<<endl;
    return rand()%(b-a) +a;
}
*/

// RETOURNE UNE COORDONNEE AU HASARD PARMI UN ENSEMBLE //

Coord randomEc(Ens ec){
  //srand(time(NULL));
  int compteur;
  compteur = rand()%ec.nbPoint;
  //cout << compteur << endl;
  //afficheCoord(ec.point[compteur]);
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

/*******************************************************************/

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
  cout << "Ce renard est mort..." << endl;
 }
}

void faimRenard(Animal &a){
  a.food--;
}

// MORT ANIMAL //

bool mortAnimal(Animal a){
  if (especeAnimal(a) == Renard){
    if (nourritureRenard(a) == 0){
      cout << "L'animal est décéde...RIP" << endl;
      return true;
    }
  } else if (especeAnimal(a) == Lapin){
    return false;
  } else {
    cout << "Il n'y a pas d'animal" << endl;
  }
  return false;
}


// SE REPRODUIT ANIMAL //
/*int aleatoire(int n){
  srand(time(NULL));
  int temp = 0;
  for (int i = 0; i < n; i++){
    temp = rand() % 100;
  }
  return temp;
}
*/

// SE REPRODUIT ANIMAL //
bool seReproduitAnimal (Animal a, int casesVides){
  int compteur = rand()%100;
  if (especeAnimal(a) == Renard){
    if (nourritureRenard(a) >= FoodReprod){
      if (compteur <= ProbBirthRenard*100){
        cout << "Le renard peut se reproduire." << endl;
        return true;
      }
    }
  } else if (especeAnimal(a) == Lapin){
      if (casesVides >= MinFreeBirthLapin){
        if (compteur <= ProbBirthLapin*100){
	        cout << "Le lapin peut se reproduire." << endl;
          return true;
        }
      }
  }
  cout << "L'animal ne peut pas se reproduire." << endl;
  return false;
}


/***********************************************************************/

Grille creerGrille(){
  Grille g;
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      g.caseG[i][j] = creerAnimal(Vide, creerCoord(0,0));
    }
  }
  return g;
}


// COPIE UNE GRILLE G1 DANS UNE GRILLE G2 //

void copieGrille (Grille g1, Grille &g2){
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      g1.caseG[i][j] = g2.caseG[i][j];
    }
  }
}

// RENVOIE LA COPIE DE L'ANIMAL D'UNE' UNE CASE DE LA GRILLE //

Animal getAnimal (Grille g, Coord c){
  Animal copie;
  return copie = g.caseG[c.x][c.y];
}

// RANGE UN ANIMAL A SA PLACE DANS LA GRILLE //

void setAnimal (Grille &g, Animal a){
  g.caseG[a.ou.x][a.ou.y] = a;
}

// INITIALISE UNE GRILLE //

void initialiseGrille(Grille &g){
  srand(time(NULL));
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      int compteur = rand()%100;
      Coord c = creerCoord(i, j);
      if(compteur < 7){
        Animal b = creerAnimal(Renard, c);
        setAnimal(g, b);
      } else if (compteur < 27){
        Animal b = creerAnimal(Lapin, c);
        setAnimal(g, b);
      } else if (compteur >= 27){
        Animal b = creerAnimal(Vide, c);
        setAnimal(g, b);
      }
    }
  }
}


/*void initialiseGrille(Grille &g){
  int compteur;
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++) {
      compteur = rand()%100;
      if(compteur < 7){
        g.caseG[i][j].quoi = Renard;
        g.caseG[i][j].food = FoodInit;
      } else if (compteur < 27){
        g.caseG[i][j].quoi = Lapin;
        g.caseG[i][j].food = 0;
      } else if (compteur >= 27){
        g.caseG[i][j].quoi = Vide;
        g.caseG[i][j].food = -1;
      }
    }
  }
}*/


// TROUVE LES CASES VOISINES D'UNE ESPECE D'UNE COORD //

Ens voisinsEspece(Grille g, Coord c, Espece e){
  Ens casesEspece;
  ecVide(casesEspece);
  Ens voisins = trouverVoisin(c);
  for (int i = 0; i < voisins.nbPoint; i++){
    if(g.caseG[getX(voisins.point[i])][getY(voisins.point[i])].quoi == e){
      ajouteEc(casesEspece,voisins.point[i]);
    }
  }
  return casesEspece;
}

// DEPLACE UN ANIMAL SUR UNE CASE VOISINE LIBRE ET LE RANGE DANS LA GRILLE//

void deplaceAnimal(Grille &g, Animal &a, Ens casesEspece){
  //cout << "Il est en ";
  //afficheCoord(a.ou);
  a.ou = randomEc(casesEspece);
  //afficheCoord(a.ou);
  setAnimal(g, a);
}

// RETOURNE L'ENSEMBLE DES COORDS DES ANIMAUX DE L'ESPECE e PRESENTS SUR LA GRILLE g //
Ens trouveTousEspece(Grille g, Espece e){
  Ens ec = creerEc();
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      if (g.caseG[i][j].quoi == e){
        ajouteEc(ec, creerCoord(i,j));
      }
    }
  }
  return ec;
}

//TRUC QUI CLOCHE DANS LES CONDITIONS DU if(seReproduitAnimal(b,e.nbPoint)) == false/true)
// SOIT TOUS! LES LAPINS SE REPRODUISENT, SOIT NON
void deplaceTousLapins(Grille g, Grille &g1){
  Ens ec = trouveTousEspece(g, Lapin);
  Ens el = creerEc();
  if (ec.nbPoint == 0){
    return;
  }
  for (int i = 0; i < ec.nbPoint; i++){
    Animal b = g.caseG[getX(ec.point[i])][getY(ec.point[i])];
    Animal temp = b;
    el = voisinsEspece(g, ec.point[i], Vide);
    if (el.nbPoint != 0){
      deplaceAnimal(g1, b, el);
      cout << "Maintenant en ";
      afficheCoord(b.ou);
    }
    if (seReproduitAnimal(b, el.nbPoint) == false){
      temp.quoi = Vide;
      setAnimal(g1, temp);
    } else if (seReproduitAnimal(b, el.nbPoint) == true){
      setAnimal(g1, temp);
    }
  }
}

// APRES QUE LES DEPLACEMENTS DES LAPINS AIENT ETE TRANSFERES A LA NOUVELLE GRILLE,
// IL FAUT TRANSFERER LA POSITION DE TOUS LES RENARDS DANS LA NOUVELLE GRILLE AVANT DE FAIRE deplacerTousRenard()
// fonction qui marche
void tourRenard(Grille g, Grille &g1){
  Ens ec = trouveTousEspece(g, Renard);
  afficheEc(ec);
  for (int i = 0; i < ec.nbPoint; i++){
    Animal b = creerAnimal(Renard, ec.point[i]);
    setAnimal(g1, b);
  }
}



// SE DEPLACE SUR L'EMPLACEMENT DU LAPIN, ET RETOURNE VRAI SI LE RENARD A MANGE LE LAPIN //

/*bool attaqueRenard(Grille &g, Animal &a){
  Ens ec = creerEc();
  ec = voisinsEspece(g, a.ou, Lapin);
  if (ec.nbPoint == 0){
    ec = voisinsEspece(g, a.ou, Vide);
    if (ec.nbPoint != 0){
       deplaceAnimal(g, a, ec);
    }
    return false;
  }
  deplaceAnimal(g, a, ec);
  mangeRenard(a);
  return true;
}*/

// RETOURNE VRAI SI LE RENARD A MANGE LE LAPIN, FAUX SINON//
bool attaqueRenard2(Grille g, Animal a){
  Ens ec = creerEc();
  ec = voisinsEspece(g, a.ou, Lapin);
  if (ec.nbPoint == 0){
    return false;
  }
  return true;
}

/*void deplaceTousRenard(Grille g, Grille &g1){
  Coord c = creerCoord(0,0);
  Animal a = creerAnimal(Vide, creerCoord(0,0));
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      if (g.caseG[i][j].quoi == Renard){
        c = creerCoord(i,j);
        a = g.caseG[i][j];
        getAnimal(g, c);
        faimRenard(a);
        if (mortAnimal(a) == true){
          g1.caseG[i][j].quoi = Vide;
          break;
        }
        attaqueRenard(g, a);
        if (seReproduitAnimal(a, GRILLE_TAILLE) == true){
          setAnimal(g1, a);
        }
      }
    }
  }
}
*/

/*void deplaceTousRenard(Grille g, Grille &g1){
  Ens ec = trouveTousEspece(g, Renard);
  Ens el = creerEc();
  Animal b;
  Animal temp;
  for (int i = 0; i < ec.nbPoint ; i++){
      b = g.caseG[getX(ec.point[i])][getY(ec.point[i])];
      temp = b;
      if (mortAnimal(b) == true){
          Animal mort = creerAnimal(Vide, ec.point[i]);
          setAnimal(g1, mort);
      }
      else if (mortAnimal(b) == false){
          if (attaqueRenard2(g, b) == true){
            el = voisinsEspece(g, b.ou, Lapin);
            cout << "Lapin autour " << el.nbPoint << endl;
            deplaceAnimal(g1, b, el);
            mangeRenard(b);
          } else if (attaqueRenard2(g, b) == false){
            el = voisinsEspece(g, b.ou, Vide);
            cout << "Vide autour " << el.nbPoint << endl;
            deplaceAnimal(g1, b, el);
          }

          if (seReproduitAnimal(b, 5) == false){
           temp.quoi = Vide;
           setAnimal(g1, temp);
          } else if (seReproduitAnimal(b, 5) == true){
           //Animal temp2 = creerAnimal(Renard, ec.point[i]);
           setAnimal(g1, temp);
         }
          faimRenard(b);
      }
   }
}
*/

//AFFICHE UNE GRILLE POUR PREMIERE SIMUlATION //

void affichegrille(Grille g){
  for (int i=0;i<GRILLE_TAILLE;i++){
    cout<<"_________________________________________"<<endl;
    cout<<"|";
    for (int j=0;j<GRILLE_TAILLE;j++){
      if (g.caseG[i][j].quoi == Lapin){
        cout<< "L|";
      } else if (g.caseG[i][j].quoi == Renard){
        cout<< "R|";
      } else if (g.caseG[i][j].quoi == Vide){
        cout<< " |";
      }
    }
    cout << endl;
  }
}







/*********************************************************************/

int main(){

  /*Coord c1 = creerCoord(2,1);
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

  cout << "Choix d'une coordonnée random :" << endl;
  Coord random;
  random = randomEc(exemple);
  cout << endl;
  cout << "Suppression d'un élément :" << endl;
  supprimeEc(exemple, random);
  cout << endl;

  cout << "Un élément supprimé" << endl;
  afficheEc(exemple);
  cout << endl;
  cout << "Les voisins de c3 sont :" << endl;
  Ens exemple2;
  exemple2 = trouverVoisin(c3);
  afficheEc(exemple2);
  cout << endl;

  Animal truc, bidule, gertrude;
  truc = creerAnimal(Renard, c3);
  bidule = creerAnimal(Lapin, c1);
  gertrude = creerAnimal(Lapin, c2);
  faimRenard(truc);
  faimRenard(truc);
  faimRenard(truc);
  faimRenard(truc);
  faimRenard(truc);

  cout << "Le niveau de nourriture de l'animal est " << nourritureRenard(truc) << "." << endl;
  mortAnimal(truc);
  seReproduitAnimal(truc, 3);
  cout << endl;

  Grille g, g1;
  g = creerGrille();
  g1 = creerGrille();
  Ens vides, vides2, vides3;
  //Animal a, b;

  setAnimal (g, truc);
  setAnimal (g, bidule);
  setAnimal (g, gertrude);
  affichegrille(g);

  cout << "Les cases vides se trouvent là :" << endl;
  vides = voisinsEspece(g, c3, Vide);
  afficheEc(vides);
  cout << "Les cases vides se trouvent là :" << endl;
  vides2 = voisinsEspece(g, creerCoord(1,1), Vide);
  afficheEc(vides2);
  cout << "Le(s) lapin(s) se trouvent là :" << endl;
  vides3 = voisinsEspece(g, creerCoord(1,1), Lapin);
  afficheEc(vides3);
  cout << endl;
  a = getAnimal (g, c2);
  afficheAnimal(a);
  cout << endl;
  b = getAnimal (g, creerCoord(1,1));
  afficheAnimal(b);
  cout << endl;


  deplaceTousLapins(g, g1);
  tourRenard(g, g1);
  affichegrille(g1);
  cout << "Les coordonnées de truc sont ";
  afficheCoord(truc.ou);
  cout << endl;
  vides = voisinsEspece(g, truc.ou, Vide);
  deplaceAnimal(g, truc, vides3);
  cout << "Maintenant il est en ";
  afficheCoord(truc.ou);
  affichegrille(g);
  */

  srand(time(NULL));

  Grille gg = creerGrille();
  Grille g1 = creerGrille();
  initialiseGrille(gg);
  affichegrille(gg);

  for (int k = 0; k < 6; k++){

  cout << "TOUR " << k << endl;

  Ens lapins;
  lapins = trouveTousEspece(gg, Lapin);
  Ens renards;
  renards = trouveTousEspece(gg, Renard);

  for (int i = 0; i < lapins.nbPoint; i++){
     Animal a, b;
     Ens autour = creerEc();
     autour = voisinsEspece(gg, lapins.point[i], Vide);

     if (autour.nbPoint != 0){
        a = getAnimal(gg, lapins.point[i]);
        b = a;
        afficheCoord(a.ou);
        deplaceAnimal(g1, a, autour);
        cout << " -- Maintenant en ";
        afficheCoord(a.ou);
     }
     if (seReproduitAnimal(a, autour.nbPoint) == false){
       b.quoi = Vide;
       setAnimal(g1, b);
     } else if (seReproduitAnimal(a, autour.nbPoint) == true){
       setAnimal(g1, b);
     }
  }

  tourRenard(gg, g1);
  //affichegrille(g1);
  copieGrille(g1, gg);

  for (int j = 0; j < renards.nbPoint; j++){
     Animal c, d;
     Ens autour2 = creerEc();
     autour2 = voisinsEspece(gg, renards.point[j], Lapin);
     c = getAnimal(gg, renards.point[j]);
     d = c;
     if (mortAnimal(c) == true){
       Animal mort = creerAnimal(Vide, renards.point[j]);
       setAnimal(g1, mort);
     } else if (mortAnimal(c) == false){

        if (attaqueRenard2(gg, c) == true){
           if (autour2.nbPoint != 0){
             afficheCoord(c.ou);
             deplaceAnimal(g1, c, autour2);
             mangeRenard(c);
             cout << " -- Maintenant en ";
             afficheCoord(c.ou);
           } else if (autour2.nbPoint == 0){
             autour2 = voisinsEspece(gg, renards.point[j], Vide);
             afficheCoord(c.ou);
             deplaceAnimal(g1, c, autour2);
             faimRenard(c);
             cout << " -- Maintenant en ";
             afficheCoord(c.ou);
           }
        }

        if (seReproduitAnimal(c, autour2.nbPoint) == false){
          d.quoi = Vide;
          setAnimal(g1, d);
        } else if (seReproduitAnimal(c, autour2.nbPoint) == true){
          setAnimal(g1, d);
        }

     }
  }

  copieGrille(g1, gg);
  affichegrille(gg);

  }
  /*deplaceTousLapins(gg, g1);
  tourRenard(gg, g1);
  copieGrille(g1, gg);
  affichegrille(g1);
  deplaceTousRenard(gg, g1);
  copieGrille(g1, gg);
  affichegrille(gg);*/
cout << "FIN DE LA SIMULATION" << endl;
return 0;
}
