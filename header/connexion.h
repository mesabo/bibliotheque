#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void connexion(MYSQL *con, char username[50], char user_password[50], char dbname[50]);
void savelogin(MYSQL *con, char student[50]) ;