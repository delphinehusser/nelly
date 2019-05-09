# Le compilateur à utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -g

# Les programmes principaux
# On donne le fichier cpp et la liste des fichiers .o qu'ils utilisent
projet: projet.cpp coord.o enscoord.o animal.o grille.o
testenscoord: testenscoord.cpp coord.o enscoord.o

# Les différents composants
# on donne le fichier cpp ainsi que la liste des fichiers .hpp dont ils dépendent
coord.o: coord.cpp coord.hpp
enscoord.o: enscoord.cpp enscoord.hpp coord.hpp
animal.o: animal.cpp animal.hpp coord.hpp
grille.o: grille.cpp grille.hpp animal.hpp coord.hpp



# Pour faire le ménage
clean:
	rm -f projet test *.o
