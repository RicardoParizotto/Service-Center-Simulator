/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - CHAPECÓ
 *
 * Autores: RICARDO PARIZOTTO, MAIKON PEREIRA
 *
 */

#ifndef defs_INCLUDED
#define defs_INCLUDED


#include <queue>   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>


#define MAX_S 1000 				  //numero máximo de servidores -- infinito numero de servidores

#define NONFINAL 0

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
















