#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

///ON INITIALISE UNE NOUVELLE BASE DE DONNEES A LA DEMANDE DE
/// L'UTILISATEUR SI PROBLEME

/** \fn initdb(MYSQL *con)
* \details Dans Cette fonction, nous faisons juste une requete sql.
* Suppresion de la bd et creation, donc reinitialisation de la bd
*/
void initdb(MYSQL *con);
void createdb(MYSQL *con);