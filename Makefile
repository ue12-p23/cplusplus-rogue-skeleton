# le Makefile de base
CPP=g++
RM=rm -f
CFLAGS=-g

# vous mettez ici, la liste de tous vos fichiers d'implémentation
# i.e. tous les .cpp
SRC = game.cpp main.cpp keyboard-event.cpp

# cette règle fabrique la liste de tous les fichiers de code objet (les .o)
# i.e. ceux qu'on doit linker ensemble pour faire un exécutable
OBJ = $(SRC:.cpp=.o)

# là c'est la règle qui linke tous les fichiers .o ensemble
# le nom de l'exécutable sera game
game  : $(OBJ)
	$(CPP) $^ -o $@

# si, dans un premier temps
# on ne veut pas maintenir les dépendances à jour proprement

# sachant que si elles ne sont pas maintenues du tout le code va mal compiler...
# on peut faire dépendre tous les fichiers d'implémentation
# de tous les header files *.hpp (voir règle %.o : %.cpp *.hpp)
# c'est moche et brute-force mais ça dépanne 
%.o:%.cpp *.hpp
	$(CPP) $(CFLAGS) -o $@ -c $<

# on nettoie
clean:
	$(RM) *.o game

# on laisse cette règle
.PHONY: clean
