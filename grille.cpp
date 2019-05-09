
#include <cstdlib>
#include <iostream>
#incude <fstream>
#incude <stdexept>


#include "enscoord.hpp"
#include "animal.hpp"
#include "grille.hpp"
#include "coord.hpp"
using namespace std;



Grille creerGrille(){
  Grille g;
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
      g.caseG[i][j] = creerAnimal(Vide, creerCoord(i,j));
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
  a.ou = randomEc(casesEspece);
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
void deplaceTousLapins(Grille &g, Grille &g1){
  Ens ec = trouveTousEspece(g, Lapin);
  Ens el = creerEc();
  if (ec.nbPoint == 0){
    return;
  }
  for (int i = 0; i < ec.nbPoint; i++){
    el = voisinsEspece(g, ec.point[i], Vide);
    Animal b = g.caseG[getX(ec.point[i])][getY(ec.point[i])];
    bool a = seReproduitAnimal(b, el.nbPoint);
    Animal temp = g.caseG[getX(ec.point[i])][getY(ec.point[i])];
      if(el.nbPoint == 0){
        setAnimal(g1, b);
      } else if (el.nbPoint != 0){
        deplaceAnimal(g1, b, el);
        setAnimal(g, b);
        g.caseG[getX(ec.point[i])][getY(ec.point[i])].quoi = Vide;
        if (a == true){
          setAnimal(g1, temp);
          setAnimal(g, temp);
        } else {
	  temp.quoi = Vide;
	  setAnimal(g1, temp);
	  setAnimal(g, temp);
        }
      }
   }
}


/*void deplaceTousLapins(Grille g, Grille &g1){
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
      //g.caseG[getX(ec.point[i])][getY(ec.point[i])].quoi = Vide;
      //cout << "Maintenant en ";
      //afficheCoord(b.ou);
    } else if (el.nbPoint == 0){
      setAnimal(g1, b);
    }

    if (seReproduitAnimal(b, el.nbPoint) == false){
      temp.quoi = Vide;
      setAnimal(g, temp);
      setAnimal(g1, temp);
    } else if (seReproduitAnimal(b, el.nbPoint) == true){
      setAnimal(g1, temp);
    }
    copieGrille(g, g1);
  }
}*/


/*/void verifieGrille(Grille g, Espece e){
  Ens animaux = creerEc();
  animaux = trouveTousEspece(g, e);
  for (int i = 0; i < GRILLE_TAILLE; i++){
    for (int j = 0; j < GRILLE_TAILLE; j++){
     if (animaux[i].quoi == g.caseG[i][j].quoi){
    }
  }
}*/

// APRES QUE LES DEPLACEMENTS DES LAPINS AIENT ETE TRANSFERES A LA NOUVELLE GRILLE,
// IL FAUT TRANSFERER LA POSITION DE TOUS LES RENARDS DANS LA NOUVELLE GRILLE AVANT DE FAIRE deplacerTousRenard()
// fonction qui marche
void tourRenard(Grille g, Grille &g1){
  Ens ec = trouveTousEspece(g, Renard);
  //afficheEc(ec);
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


/*void deplaceTousLapins(Grille &g, Grille &g1){
  Ens ec = trouveTousEspece(g, Lapin);
  Ens el = creerEc();
  if (ec.nbPoint == 0){
    return;
  }
  for (int i = 0; i < ec.nbPoint; i++){
    el = voisinsEspece(g, ec.point[i], Vide);
    Animal b = g.caseG[getX(ec.point[i])][getY(ec.point[i])];
    bool a = seReproduitAnimal(b, el.nbPoint);
    Animal temp = g.caseG[getX(ec.point[i])][getY(ec.point[i])];
      if(el.nbPoint == 0){
        setAnimal(g1, b);
      } else if (el.nbPoint != 0){
        deplaceAnimal(g1, b, el);
        setAnimal(g, b);
        g.caseG[getX(ec.point[i])][getY(ec.point[i])].quoi = Vide;
        if (a == true){
          setAnimal(g1, temp);
          setAnimal(g, temp);
        } else {
	  temp.quoi = Vide;
	  setAnimal(g1, temp);
	  setAnimal(g, temp);
        }
      }
   }
}*/



void deplaceTousRenard(Grille &g, Grille &g1){
  Ens ec = trouveTousEspece(g, Renard);
  Ens el = creerEc();
  for (int i = 0; i < ec.nbPoint ; i++){
      Animal b = g.caseG[getX(ec.point[i])][getY(ec.point[i])];
      Animal temp = g.caseG[getX(ec.point[i])][getY(ec.point[i])];
      if (mortAnimal(b) == true){
          Animal mort = creerAnimal(Vide, ec.point[i]);
          setAnimal(g1, mort);
          setAnimal(g, mort);
      }
      else if (mortAnimal(b) == false){
          if (attaqueRenard2(g1, b) == true){
            el = voisinsEspece(g1, ec.point[i], Lapin);
            //cout << "Lapin autour " << el.nbPoint << endl;
            deplaceAnimal(g1, b, el);
	    mangeRenard(b);
  	    faimRenard(b);
            setAnimal(g, b);
            g.caseG[getX(ec.point[i])][getY(ec.point[i])].quoi = Vide;

	    if (seReproduitAnimal(b, 5) == true){
               Animal temp2 = creerAnimal(Renard, ec.point[i]);
               setAnimal(g1, temp2);
	       setAnimal(g, temp2);
            }
	  }	
	  else if (attaqueRenard2(g1, b) == false){
            el = voisinsEspece(g1, ec.point[i], Vide);
//            cout << "Vide autour " << el.nbPoint << endl;
		if(el.nbPoint == 0){
		  setAnimal(g1, b);
                } else if (el.nbPoint != 0){
            	  deplaceAnimal(g1, b, el);
                  setAnimal(g, b);
	    	  g.caseG[getX(ec.point[i])][getY(ec.point[i])].quoi = Vide;

		  if (seReproduitAnimal(b, 5) == true){
                     Animal temp2 = creerAnimal(Renard, ec.point[i]);
           	     setAnimal(g1, temp2);
		     setAnimal(g, temp2);
          	  } else {
		     Animal temp2 = creerAnimal(Vide, ec.point[i]);
		     setAnimal(g1, temp2);
		     setAnimal(g, temp2);
                  }
	          faimRenard(b);
		
	        } 
          }
     }
  }
}

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
  cout << endl;
  cout << endl;
}



/*void afficheGrille2(Grille g){
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
			for (int i = 0; i < GRILLE_TAILLE; i++){
				for(int j = 0 ; j < GRILLE_TAILLE; j++){
					// calcul de la couleur //
					if(g.caseG[i][j].quoi == 0){
						{r = 255; v = 255; b = 255; }
					}if(g.caseG[i][j].quoi == 1){
						{r = 0; v = 0; b = 255; }
					}
					if(g.caseG[i][j].quoi == 2){
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
	}*/


