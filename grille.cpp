#include <iostream>
#include <cmath>
#include <cstdlib>
#include"grille.hpp"
#include <time.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//////////////////////////////////////////FONCTION GRILLE VIDE ///////////////////////////////////////

void grilleVide(grille &g){
		for(int i =0; i< GRILLETAILLE; i++){
	
			for(int j =0; j< GRILLETAILLE; j++){
		
			g.tab[i][j] = creerAnimal(Vide, creerCoord(i, j));
		
			}
		} 		
}		
	
//////////////////////////////////////////FONCTION COPIE GRILLE ///////////////////////////////////////	

void copieGrille(grille g1,grille &g2){
	for(int i = 0; i < GRILLETAILLE; i++){
		for(int j = 0; j <GRILLETAILLE; j++){
			g2.tab[i][j] = g1.tab[i][j];
		}
	}
}

//////////////////////////////////////////FONCTION GET ANIMAL ///////////////////////////////////////

animal getAnimal( grille g, Coord c){
	animal a2;
	a2 = g.tab[c.li][c.co];
	return a2;
}

//////////////////////////////////////////FONCTION SET ANIMAL ///////////////////////////////////////

void setAnimal(grille &g, animal p){
	for (int i = 0; i < GRILLETAILLE; i++){
		for(int j= 0; j < GRILLETAILLE; j++){
			if(egalCoord(creerCoord(i,j), p.c) == true){
				g.tab[i][j] = p;
			}
		}
	}
}

//////////////////////////////////////////FONCTION INITIALISER GRILLE ///////////////////////////////////////

void initialiserGrille(grille &g){
	srand(time(NULL));
	for(int i = 0; i < GRILLETAILLE; i++){
		for(int j = 0; j < GRILLETAILLE; j++){
				int r = rand()%100;
			cout << r << endl;
			if(r > 27){
				g.tab[i][j] = creerAnimal( Vide, creerCoord(i, j));
			}else if(r <= 7){
				g.tab[i][j] = creerAnimal(Renard, creerCoord(i,j));
			}else{
				g.tab[i][j] = creerAnimal(Lapin, creerCoord(i,j));
			}
		}
	}
}

//////////////////////////////////////////FONCTION VERIFIE GRILLE ///////////////////////////////////////
	
		
/*void verifieGrille(grille g){
		for(int i =0; i< GRILLETAILLE; i++){
	
			for(int j =0; j< GRILLETAILLE; j++){
			c=creeCoord(i,j);
			a= getAnimal(g,c);
			
				if(not egalCoord(c,coordAnimal(a)){
			cout<<"verifie gille car animal n'est pas à sa place" << endl;
			
				}
			}
		}
	}

*/

//////////////////////////////////////////FONCTION VOISIN VIDE ///////////////////////////////////////

EnsCoord VoisinVide(grille g,Coord c){
	EnsCoord res = creerEC();
	EnsCoord Vs = trouverVoisins(c);
	animal a;
	for (int i = 0; i<Vs.nbElements; i++){
		a = getAnimal(g,Vs.tab[i]);
		if (a.e == Vide){
			ajouteEC(res,Vs.tab[i]);
		}
	}
	return res;
}

//////////////////////////////////////////FONCTION AFFICHE GRILLE ///////////////////////////////////////

	void afficheGrille(grille g){
		for(int i = 0; i < GRILLETAILLE; i++){
			for(int j = 0; j < GRILLETAILLE; j++){
				if(g.tab[i][j].e == 0){
					cout << "0" ;
				}
				if(g.tab[i][j].e == 1){
						cout << "L";
				}
				if(g.tab[i][j].e == 2){
						cout << "R";
				}
			}
			cout << endl;
		}
}

//////////////////////////////////////////FONCTION AFFICHE GRILLE 2 ///////////////////////////////////////

	void afficheGrille2(grille g){
		//variable globale permettant de creer des noms de fichiers differents //
		int compteurFichier = 0;
		int r, v, b;
			ostringstream filename;
			// creation d'un nouveau nom de fichier de la forme img347.ppm //
			filename << "img" << setfill('0') << setw(3) << compteurFichier << ".ppm";
			compteurFichier++;
			cout << "Ecriture dans le fichier : " << filename.str() << endl;
			// ouverture du fichier //
			ofstream fic(filename.str(), ios::out | ios::trunc);
			//ecriture de l'entête //
			fic << "P3" << endl;
			fic << 20 << " " << 20 << " " << endl;
			fic << 255 << " " << endl;
			// écriture des pixels //
			for (int i = 0; i < GRILLETAILLE; i++){
				for(int j = 0 ; j < GRILLETAILLE; j++){
					// calcul de la couleur //
					if(g.tab[i][j].e == 0){
						{r = 255; v = 255; b = 255; }
					}if(g.tab[i][j].e == 1){
						{r = 0; v = 0; b = 255; }
					}
					if(g.tab[i][j].e == 2){
						{r = 255; v = 0; b = 0; }
					}
					// écriture de la couleur dans le fichier //
					fic << r << " " << v << "  " << b << " ";
					}
					// fin de ligne dans l'image //
					fic << endl;
			}
			// fermeture du fichier //
			fic.close();
	}
				
				
				
				
				
				
				
				
