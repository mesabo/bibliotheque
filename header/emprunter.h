#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>

void emprunter(MYSQL *con, int student, char book[50]);