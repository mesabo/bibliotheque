#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>


/**
* \fn deposer(MYSQL *con, int idx)
 * \details Dans Cette fonction, nous faisons juste une requete sql de mise a jour
* \return On renvoie idx
*/
void deposer(MYSQL *con, int idx);