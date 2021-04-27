/**
 * \file connexion.c
 * \brief Fichier choisir contenant les fonctions de connexion et savelogin.
 */
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../header/connexion.h"

/** \fn connexion(MYSQL *con, char username[50], char user_password[50], char dbname[50])
* \brief Fonction de connexion a la base de donnees.
* \param *con de type MYSQL.
* \param username de type char. Nom d'utilisateur mysal; souvent `root`
* \param user_password de type char. Mot de passe
* \param dbname de type char. Nom de la bd
* \details Dans Cette fonction, nous etablissons une connexion a la bd.
*/
void connexion(MYSQL *con, char username[50], char user_password[50], char dbname[50]) {
    if (mysql_real_connect(con, "localhost", username, user_password, dbname, 0, NULL, 0) == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
}

/** \fn savelogin(MYSQL *con, char student[50])
* \brief Fonction de reinitialisationde la base de donnees.
* \param *con de type MYSQL.
* \param student de type char. Le login avec lequel se connecter
* \details Dans Cette fonction, nous tentons une
 * connexion a un compte utilisateur dans l'appli
*/
void savelogin(MYSQL *con, char student[50]) {
    char requete[200] = "";

    sprintf(requete, "INSERT INTO students(name) VALUES('%s');", student);
    mysql_query(con, requete);
}
