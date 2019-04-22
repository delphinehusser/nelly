#include <cstdlib>
#include <iostream>
#include <ostream>
#include <chrono>
#include <cmath>
#include <ctime>

using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl



int main(){
  Grille g, g1;
  g = creerGrille();
  initialiseGrille(g);

  copieGrille(g, g1);

  

}
