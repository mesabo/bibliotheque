#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
* \fn *lister(MYSQL *con)
 * \details Dans Cette fonction, nous faison juste une requete sql et affichons le resultat
* \return On renvoie idx
*/
void lister(MYSQL *con);