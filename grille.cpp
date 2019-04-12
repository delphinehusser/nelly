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


// INITIALISE UNE GRILLE VIDE //
          
void grilleVide (Grille &g){
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      g.caseG[i][j] = 0;
    }  
  }
}
          
// COPIE UNE GRILLE G1 DANS UNE GRILLE G2 //  
          
void copieGrille (Grille g1, Grille &g2){
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      g1.caseG[i][j] = g2.caseG[i][j];
    }  
  }
}
          
// RENVOIE LA COPIE L'ANIMAL DANS UNE CASE DE LA GRILLE //  
         
Animal getAnimal (Grille g, Coord c){
  Animal copie;
  return copie = g.caseG[c.x][c.y];
}
          
// RANGE UN ANIMAL A SA PLACE DANS LA GRILLE //

void setAnimal (Grille &g, Animal a){
  g.caseG[a.ou.x][a.ou.y] = a;
}  
       
