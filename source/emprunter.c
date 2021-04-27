/**
 * \file emprunter.c
 * \brief Fichier emprunter contenant la fonction emprunter.
 */
#include <stdio.h>
#include <mysql/mysql.h>
#include "../header/emprunter.h"


/**
* \fn emprunter(MYSQL *con, int student, char book[50])
* \brief Fonction de creation de la base de donnees.
* \param *con de type MYSQL.
* \param student de type int. contient l'id de l'emprunteur du bookin'.
* \param book de type char. Le livre a emprunter...
 * \details Dans Cette fonction, nous faisons juste une requete sql
*/
void emprunter(MYSQL *con, int student, char book[50]) {
    char requete[200] = "";
    sprintf(requete, "INSERT INTO student_book(book,student,rendu) VALUES('%s','%d',0);", book, student);
    mysql_query(con, requete);
}


