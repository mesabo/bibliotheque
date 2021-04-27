#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>

/**
* \fn emprunter(MYSQL *con, int student, char book[50])
 * \details Dans Cette fonction, nous faisons juste une requete sql
*/
void emprunter(MYSQL *con, int student, char book[50]);