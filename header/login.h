#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>

/**
* \fn *signin(MYSQL *con, char login[50])
 * \details Dans Cette fonction, nous faisons juste une requete sql et retournons un entier
* \return On renvoie idx
*/
char *signin(MYSQL *con, char login[50]);