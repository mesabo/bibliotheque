/**
 * \file choisir.c
 * \brief Fichier choisir contenant la fonctions de choisir un bookin.
 */
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \fn choisir(MYSQL *con, char choix[50])
* \brief Fonction de reinitialisationde la base de donnees.
* \param *con de type MYSQL.
* \param choix de type char. Le bookin choisi
* \details Dans Cette fonction, nous enregistrons le choix de l'utilisateur (empruntur)
*/
void choisir(MYSQL *con, char choix[50]) {

    char requete[200] = "";

    sprintf(requete, "SELECT * FROM books WHERE id='%s' LIMIT 1;", choix);
    mysql_query(con, requete);


    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    printf("==================Vous avez choisi==================\n");
    while ((row = mysql_fetch_row(result))) {
        printf("=====");
        for (int i = 0; i < num_fields; i++) {

            printf("[%s] ", row[i] ? row[i] : "NULL");
        }

        printf("=====\n");
    }
    printf("===================================================\n");

    mysql_free_result(result);
}