#include <cstdlib>
#include <iostream>
#include <ostream>
#include <chrono>
#include <cmath>
#include <ctime>

using namespace std;

#include "TP1ter2.cpp"

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl



int main(){
  Grille g, g1;
  g = creerGrille();
  initialiseGrille(g);
  for(int i;i<=3;i++){
      deplaceTousLapins(g,g1);
      deplaceTousRenard(g,g1);
      affichegrille(g1);
      cout<<" "<<endl;
      cout<<" "<<endl;
      copieGrille(g, g1);
  }
}
