#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \file choisir.c
 * \brief Fichier choisir contenant la fonctions de saisie au clavier.
 */
void choisir(MYSQL *con, char choix[50]);