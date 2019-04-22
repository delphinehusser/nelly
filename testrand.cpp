#include <cstdlib>
#include <iostream>
#include <ostream>
#include <chrono>
#include <cmath>
#include <ctime>

using namespace std;

#include <stdio.h>

#include <stdlib.h>

#include <time.h> //Ne pas oublier d'inclure le fichier time.h

// On suppose a<b
int rand_a_b(int a, int b){
      cout<<rand()%(b-a) +a<<endl;
    return rand()%(b-a) +a;

}

int main(void){

    int i = 0;

    int nombre_aleatoire = 0;

    srand(time(NULL)); // initialisation de rand

    for(i=0; i<5; i++){

        nombre_aleatoire = rand();

    }

    rand_a_b(0,10);

    return 0;

}
