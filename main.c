#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "./header/populate.h"
#include "./header/createdb.h"
#include "./header/connexion.h"
#include "lire.c"
#include "./header/lister.h"
#include "./header/login.h"
#include "./header/choisir.h"
#include "./header/emprunter.h"
#include "./header/deposer.h"

///P R E P R O C E S S E U R S
void finish_with_error(MYSQL *con);

/// M A  I N
void main() {
    char username[50];
    char user_password[50];
    char db_name[50];
    char table_name[50];
    char login[50];
    int theid = 0;
    char reponsedb[10];
    char choix[10];
    char option[10];
    int idx;


    printf("==========CONNEXION A LA BASE DE DONNEES ============\n");
    printf("========== SAISIR VOS INFORMATIONS DE BASE DE DONNEES POUR Y ACCEDER ============\n");
    printf("DB username: ");
    lire(username, 50);
    printf("DB password: ");
    lire(user_password, 50);
    printf("==========M E R C I, VO U S  C O M M E N C E Z  !==========\n");

    MYSQL *con = mysql_init(NULL);
    // ON PROCEDE A LA CONNEXION
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }
    ///INCLUSION DES FONCTIONS
    connexion(con, username, user_password, NULL);

    //add_data(con);

    printf("Voulez-vous reinitialiser la base de donnees\nou conserver une existante au nom de `testdb` ?\n");
    printf("accepter: 1\nrefuser: 0\n");
    printf("reponse: ");
    lire(reponsedb, 10);

    if (strcmp(reponsedb, "1") == 0) {
        initdb(con);

        MYSQL *con = mysql_init(NULL);
        // ON PROCEDE A LA CONNEXION
        if (con == NULL) {
            fprintf(stderr, "mysql_init() failed\n");
            exit(1);
        }
        connexion(con, username, user_password, "testdb");

        add_data(con);
        printf("login: ");
        lire(username, 50);
        signin(con, username);
    } else {
        MYSQL *con = mysql_init(NULL);
        // ON PROCEDE A LA CONNEXION
        if (con == NULL) {
            fprintf(stderr, "mysql_init() failed\n");
            exit(1);
        }
        connexion(con, username, user_password, "testdb");
        printf("-----Vous connecter avec votre login-----\n");
        printf("login: ");
        lire(login, 50);
        if (login != NULL) idx = atoi(signin(con, login));

        ///MENU
        printf("\n\t*** BIENVENU DANS VOTRE BIBLIOTHEQUE VIRTUELLE 'virtual biblio' ***\n");
        do {
            printf("\n\n--<:Main Menu:>--");
            printf("\n 1. Se reconnecter avec son login");
            printf("\n 2. lister les livres disponibles");
            printf("\n 3. emprunter un livre");
            printf("\n 4. deposer un livre");
            printf("\n 0. Quitter\n");
            printf("\nQuel est votre choix (0-4)? :  ");
            lire(option, 10);

            /// ALTERNATIVE DE CHOIX
            int opt;
            switch (opt = atoi(option)) {
                case 1:
                    /// SE CONNECTER  AVEC UN LOGIN OU S'ENREGISTRER, LE CAS ECHEANT
                    printf("login: ");
                    lire(login, 50);
                    //int idx = signin(con, login);
                    idx = atoi(signin(con, login));
                    if (idx > 0) {
                        printf("%d\n", idx);
                    } else {
                        printf("Vous n'etes pas inscrit");
                        printf("Nous procedons a votre inscription....\n.....\n.....\n");
                        savelogin(con, login);
                        idx = atoi(signin(con, login));
                        printf("Felicitation !!!\nVous etes enregistre avec le login %s et id %d\n", login, idx);

                    };
                    break;
                case 2:
                    /// LISTER LES LIVRES DISPONIBLES
                    printf("----------<<<Vouci les livres que nous avons en stock>>>----------\n");
                    lister(con);
                    printf("----------<<<<<<<<<<>>>>>>>>>>----------");

                    break;
                case 3:
                    /// EMPRUNTER UN LIVRE
                    printf("entrer numero du livre: ");
                    lire(choix, 10);
                    choisir(con, choix);
                    emprunter(con, idx, choix);
                    break;
                case 4:
                    /// DEPOSER UN LIVRE
                    deposer(con, idx);
                    printf("Merci, vous venez de deposer le livre emprunte\n");
                    break;
                case 0:
                    printf("A bientot :)\n");
                    exit(0);
                    break;
                default:
                    printf("Saisir une valeur correct entre (0-1)!");
            }
        } while (option != 0);


        /// LISTER BIBLIOTHEQUE
        //lister(con);
        ///CHOISIR LE LIVRE
//        printf("entrer numero du livre: ");
//        lire(choix, 10);
//        choisir(con, choix);
//        emprunter(con, login, choix);
        //if (strcmp(signin(con, login), "0") > 0){printf("Bonjour");}
        //emprunter(con, login, choix);
    }


}

//////////////////////////////////////////////////////////////////////
void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}
