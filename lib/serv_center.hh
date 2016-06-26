/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - CHAPECÓ
 *
 * Autor: RICARDO PARIZOTTO
 *
 */

#ifndef SERV_CENTER_INCLUDED
#define SERV_CENTER_INCLUDED


#include <queue>   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_S 1000 				  //numero máximo de servidores

#define OUT 0
#define NORMAL 1
#define ROUTER 2

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

class Box{
    public:
        std::queue<agent> queue;
        int id;

        void done();
         void push_in ( agent );    
};



class component : public Box{
    private:								
     //   unsigned long queue_wait; 	
	                            
    public:

        unsigned int numb_servers;  
        server serv[MAX_S];                 
    	int out;
        char out_t;


        void serving( unsigned long );
        void done( unsigned long, Box *);
};


struct chance{
    int id_out;
    char out_t;
    unsigned prob;
};



class Router : public Box{    
    public:
        chance out1, out2;

        void done(component, component);      
};


class Simulation{
    public:


        unsigned long GVT;                //global virtual time
        unsigned long ST;	              //SIMULATION TIME    

        int qtd_cmp, qtd_rts, init;
        component centers[MAX_S];
        Router routers[MAX_S];


        void agent_generator( void );
        void start( void );
};




static Simulation run;


#endif




