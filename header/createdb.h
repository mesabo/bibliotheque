#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

///ON INITIALISE UNE NOUVELLE BASE DE DONNEES A LA DEMANDE DE
/// L'UTILISATEUR SI PROBLEME
void initdb(MYSQL *con);
void createdb(MYSQL *con);