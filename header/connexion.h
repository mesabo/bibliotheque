#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

/** \fn connexion(MYSQL *con, char username[50], char user_password[50], char dbname[50])
* \details Dans Cette fonction, nous etablissons une connexion a la bd.
*/
void connexion(MYSQL *con, char username[50], char user_password[50], char dbname[50]);

/** \fn savelogin(MYSQL *con, char student[50])
* \details Dans Cette fonction, nous tentons une
 * connexion a un compte utilisateur dans l'appli
*/
void savelogin(MYSQL *con, char student[50]);