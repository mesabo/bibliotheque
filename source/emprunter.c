#include <stdio.h>
#include <mysql/mysql.h>
#include "../header/emprunter.h"


void emprunter(MYSQL *con, int student, char book[50])
{
    char requete[200] = "";
    sprintf(requete, "INSERT INTO student_book(book,student,rendu) VALUES('%s','%d',0);", book,student);
    mysql_query(con, requete);
}


