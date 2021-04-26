#include <stdio.h>
#include <mysql/mysql.h>
#include "../header/deposer.h"

void deposer(MYSQL *con, int idx) {
    char requete[200] = "";
    sprintf(requete, "UPDATE student_book SET rendu=1 WHERE student = '%d';", idx);
    mysql_query(con, requete);
}
