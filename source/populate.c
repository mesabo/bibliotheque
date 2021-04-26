#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../header/populate.h"

// INSERTION DE DONNER DANS LA DB
void add_data(MYSQL *con) {
    ///CREATION DES TABLES A NOUVEAU
    if (mysql_query(con,
                    "CREATE TABLE IF NOT EXISTS books(id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(255),author VARCHAR(255))")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    if (mysql_query(con,
                    "CREATE TABLE IF NOT EXISTS students(id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(255))")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    if (mysql_query(con,
                    "CREATE TABLE IF NOT EXISTS student_book(id INT PRIMARY KEY AUTO_INCREMENT, book VARCHAR(255),student VARCHAR(255),rendu INT)")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    /// REMPLISSAGE DE LA BIBLIOTHEQUE DE LIVRES
    printf("==========Remplissage de la bibliotheque...===================\n");

    printf("....\n");
    if (mysql_query(con, "INSERT INTO books(id,name,author) VALUES(1,'L Innommable','Samuel Beckett')")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    printf("....\n");
    if (mysql_query(con, "INSERT INTO books(id,name,author) VALUES(2,'Le monde s effondre','Chinua Achebe')")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    printf("....\n");
    if (mysql_query(con, "INSERT INTO books(id,name,author) VALUES(3,'L Étranger','Albert Camus')")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    printf("....\n");
    if (mysql_query(con, "INSERT INTO books(id,name,author) VALUES(4,'Les poèmes de...','Paul Celan')")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    printf("....\n");
    if (mysql_query(con,
                    "INSERT INTO books(id,name,author) VALUES(5,'Voyage au bout de la nuit','Louis-Ferdinand Céline')")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    printf("....\n");
    if (mysql_query(con, "INSERT INTO books(id,name,author) VALUES(6,'Nostromo','Joseph Conrad')")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    printf("....\n");
    if (mysql_query(con,
                    "INSERT INTO books(id,name,author) VALUES(7,'Homme invisible,pour qui chantes-tu ?','Ralph Ellison')")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    printf("===========Remplissage de la bibliotheque termine=================\n");
}