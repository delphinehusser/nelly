#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include<cstdlib>
#include "coord.hpp"
#include "enscoord.hpp"
#include "animal.hpp"
#include "grille.hpp"
#include <ctime>
#include <unistd.h>

using namespace std;



int main(){
  srand(time(NULL));

Grille gg = creerGrille();
Grille g1 = creerGrille();
initialiseGrille(gg);
affichegrille(gg);

Ens ecl = trouveTousEspece(gg, Lapin);
cout << "Nombre de lapins initial: " << ecl.nbPoint << endl;
Ens ecr = trouveTousEspece(gg, Renard);
cout << "Nombre de renards initial: " << ecr.nbPoint << endl;
cout << endl;

int compteur = 0;

//while (trouveTousEspece(gg, Lapin).nbPoint != 0 and trouveTousEspece(gg, Renard).nbPoint != 0){

for (int i = 0; i < 3; i++){
compteur++;

deplaceTousLapins(gg, g1);
deplaceTousRenard(gg, g1);
affichegrille(g1);
copieGrille(g1, gg);

Ens ecl2 = trouveTousEspece(gg, Lapin);
cout << "Nombre de lapins : " << ecl2.nbPoint << endl;
Ens ecr2 = trouveTousEspece(gg, Renard);
cout << "Nombre de renards : " << ecr2.nbPoint << endl;
cout << endl;
cout << "Compteur : " << compteur << endl;

}
return 0;
}
