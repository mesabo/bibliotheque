/**
 * \file login.c
 * \brief Fichier login contenant la fonction signin.
 */
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>
#include "../header/login.h"

/**
* \fn *signin(MYSQL *con, char login[50])
* \brief Fonction de creation de la base de donnees.
* \param *con de type MYSQL.
* \param login de type char. contient le login de l'utilisateur recupere au clavier.
* \param idx de type int. Un pointeur sur l'id du bookin trouve.
 * \details Dans Cette fonction, nous faisons juste une requete sql et retournons un entier
* \return On renvoie idx
*/
char *signin(MYSQL *con, char login[50]) {
    char requete[200] = "";

    sprintf(requete, "SELECT id FROM students WHERE name='%s' LIMIT 1;", login);
    mysql_query(con, requete);

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    char *idx;

    while ((row = mysql_fetch_row(result)) != 0) {
        for (int i = 0; i < num_fields; i++) {
            idx = row[0] ? row[0] : "NULL";

        }
    }
    mysql_free_result(result);
    return idx;
}