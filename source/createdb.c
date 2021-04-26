#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../header/createdb.h"

///ON INITIALISE UNE NOUVELLE BASE DE DONNEES A LA DEMANDE DE
/// L'UTILISATEUR SI PROBLEME
void initdb(MYSQL *con)
{
    if (mysql_query(con, "DROP DATABASE IF EXISTS testdb"))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    if (mysql_query(con, "CREATE DATABASE IF NOT EXISTS testdb"))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    mysql_close(con);
}

// CRE UNE BASE DE DONNEES SI INEXISTENTE APPELLEE `testdb`
void createdb(MYSQL *con)
{
    if (mysql_query(con, "CREATE DATABASE IF NOT EXISTS testdb"))
    {
        
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    ///ON REMPLIT LA BD EN MEME TEMPS

    mysql_close(con);
}
