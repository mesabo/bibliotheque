/**
 * \file lister.c
 * \brief Fichier lister contenant la fonction lister.
 */
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/lister.h"

/**
* \fn *lister(MYSQL *con)
* \brief Fonction de creation de la base de donnees.
* \param *con de type MYSQL.
 * \details Dans Cette fonction, nous faison juste une requete sql et affichons le resultat
* \return On renvoie idx
*/
void lister(MYSQL *con) {

    if (mysql_query(con, "SELECT * FROM books")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("[%s] ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
}