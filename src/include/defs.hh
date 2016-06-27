/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - CHAPECÓ
 *
 * Autor: RICARDO PARIZOTTO
 *
 */

#ifndef defs_INCLUDED
#define defs_INCLUDED


#include <queue>   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


#define MAX_S 1000 				  //numero máximo de servidores -- infinito numero de servidores

#define OUT 0
#define NORMAL 1
#define ROUTER 2

struct agent{
    int id;
    unsigned long time;
};


struct chance{
    int id_out;
    char out_t;
    unsigned prob;
};

#endif
















