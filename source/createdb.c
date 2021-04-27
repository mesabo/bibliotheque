/**
 * \file createdb.c
 * \brief Fichier createdb contenant les fonctions createdb et initdb.
 */
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../header/createdb.h"

///ON INITIALISE UNE NOUVELLE BASE DE DONNEES A LA DEMANDE DE
/// L'UTILISATEUR SI PROBLEME
/**
* \fn initdb(MYSQL *con)
* \brief Fonction de reinitialisationde la base de donnees.
* \param *con de type MYSQL.
 * \details Dans Cette fonction, nous faisons juste une requete sql.
 * Suppresion de la bd et creation, donc reinitialisation de la bd
*/
void initdb(MYSQL *con) {
    if (mysql_query(con, "DROP DATABASE IF EXISTS testdb")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    if (mysql_query(con, "CREATE DATABASE IF NOT EXISTS testdb")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    mysql_close(con);
}

// CRE UNE BASE DE DONNEES SI INEXISTENTE APPELLEE `testdb`
/**
* \fn createdb(MYSQL *con)
* \brief Fonction de creation de la base de donnees.
* \param *con de type MYSQL.
 * \details Dans Cette fonction, nous faisons juste une requete sql.
 * creation de la bd `testdb`
*/
void createdb(MYSQL *con) {
    if (mysql_query(con, "CREATE DATABASE IF NOT EXISTS testdb")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    mysql_close(con);
}

/**
* \attention Simple activite
 * @warning while life()
 *          standup()
 *          code()
 *          recode()
 *          sell()
 *          invest()
 *          ...
 *          :)
*/