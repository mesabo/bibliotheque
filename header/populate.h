#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

// INSERTION DE DONNER DANS LA DB
/**
* \fn add_data(MYSQL *con)
* \brief Fonction de remplissage de la base de donnees.
*/
void add_data(MYSQL *con);