## Exemple de Makefile avec macros
# definition du compilateur
CC = gcc
# definition des options de compilation pour obtenir un fichier .o
MYFLAGS = -c -O3
# definition des options de compilation pour obtenir un fichier .do
DEBUGFLAGS =-c -g -O3
#output folder
OUTPUTFOLDER = -o ./ofile/

#mysql lib
SQLIB = -lmysqlclient


# Fichier executable prod
bibliotheque: ./ofile/choisir.o   ./ofile/connexion.o  ./ofile/createdb.o  ./ofile/deposer.o  ./ofile/emprunter.o ./ofile/lister.o ./ofile/login.o ./ofile/populate.o main.o
	$(CC) -o bibliotheque  "./ofile/choisir.o" "./ofile/connexion.o" "./ofile/createdb.o" "./ofile/deposer.o" "./ofile/emprunter.o" "./ofile/lister.o" "./ofile/login.o" "./ofile/populate.o"  "main.o" $(SQLIB)

# compile main
main.o: main.c
	$(CC) $(MYFLAGS) main.c $(SQLIB)

# compile choisir
./ofile/choisir.o:  ./source/choisir.c
	$(CC) $(MYFLAGS) "./source/choisir.c" $(OUTPUTFOLDER)choisir.o $(SQLIB)
# compile connexion
./ofile/connexion.o:  ./source/connexion.c
	$(CC) $(MYFLAGS) "./source/connexion.c" $(OUTPUTFOLDER)connexion.o $(SQLIB)
# compile createdb
./ofile/createdb.o:  ./source/createdb.c
	$(CC) $(MYFLAGS) "./source/createdb.c" $(OUTPUTFOLDER)createdb.o $(SQLIB)
# compile deposer
./ofile/deposer.o:  ./source/deposer.c
	$(CC) $(MYFLAGS) "./source/deposer.c" $(OUTPUTFOLDER)deposer.o $(SQLIB)
# compile emprunter
./ofile/emprunter.o:  ./source/emprunter.c
	$(CC) $(MYFLAGS) "./source/emprunter.c" $(OUTPUTFOLDER)emprunter.o $(SQLIB)
# compile lister
./ofile/lister.o:  ./source/lister.c
	$(CC) $(MYFLAGS) "./source/lister.c" $(OUTPUTFOLDER)lister.o $(SQLIB)
# compile login
./ofile/login.o:  ./source/login.c
	$(CC) $(MYFLAGS) "./source/login.c" $(OUTPUTFOLDER)login.o $(SQLIB)
# compile populate
./ofile/populate.o:  ./source/populate.c
	$(CC) $(MYFLAGS) "./source/populate.c" $(OUTPUTFOLDER)populate.o $(SQLIB)
