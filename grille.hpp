#ifndef grille_hpp
#define grille_hpp
#include "enscoord.hpp"
#include "animal.hpp"



struct Grille{
  Animal caseG[GRILLE_TAILLE][GRILLE_TAILLE];
};

Grille creerGrille();
void copieGrille (Grille g1, Grille &g2);
Animal getAnimal (Grille g, Coord c);
void setAnimal (Grille &g, Animal a);
void initialiseGrille(Grille &g);
Ens voisinsEspece(Grille g, Coord c, Espece e);
void deplaceAnimal(Grille &g, Animal &a, Ens casesEspece);
Ens trouveTousEspece(Grille g, Espece e);
void deplaceTousLapins(Grille &g, Grille &g1);
void tourRenard(Grille g, Grille &g1);
bool attaqueRenard2(Grille g, Animal a);
void deplaceTousRenard(Grille &g, Grille &g1);
void affichegrille(Grille g);

#endif
