/**
 * \file deposer.c
 * \brief Fichier deposer contenant les fonctions deposer un bookin.
 */
#include <stdio.h>
#include <mysql/mysql.h>
#include "../header/deposer.h"

/**
* \fn deposer(MYSQL *con, int idx)
* \brief Fonction de creation de la base de donnees.
* \param *con de type MYSQL.
* \param idx de type int. contient l'id 'id du bookin a deposer.
 * \details Dans Cette fonction, nous faisons juste une requete sql de mise a jour
* \return On renvoie idx
*/
void deposer(MYSQL *con, int idx) {
    char requete[200] = "";
    sprintf(requete, "UPDATE student_book SET rendu=1 WHERE student = '%d';", idx);
    mysql_query(con, requete);
}
