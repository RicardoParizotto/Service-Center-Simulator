/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - CHAPECÓ
 *
 * ALUNOS: LUCAS ROSTIROLLA, MAIKON PEREIRA, RICARDO PARIZOTTO
 *
 */

#ifndef SERV_CENTER_INCLUDED
#define SERV_CENTER_INCLUDED


#include <queue>   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_S 1000 				  //numero máximo de servidores

struct agent{
    int id;
    unsigned long time;
};

struct server{
    bool use;
    int min, max;
    unsigned long final_time;

    agent user;
};

class component{
    private:								
        unsigned long queue_wait; 		                             
        std::queue<agent> queue;

    public:

        server serv[MAX_S];
	    unsigned int numb_servers;                      
    	int out;		


        void serving();
        void done();
        void push_in ( agent );
};

class Simulation{
    public:
        int qtd_cmp, init;
        component centers[MAX_S];

        unsigned long GVT;                //global virtual time
        unsigned long ST;	              //SIMULATION TIME    


        void run();
};

static Simulation run;
/*
class router{
	

}
*/


#endif




