/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - CHAPECÓ
 *
 * ALUNOS: LUCAS ROSTIROLLA, MAIKON PEREIRA, RICARDO PARIZOTTO
 *
 */

#include <queue>   
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define MAX_S 1000 				  //numero máximo de servidores


unsigned long GVT;                //global virtual time

struct agent{
    int id;
    unsigned long time;
};

struct server{
    bool use;
    int min, max;
    unsigned long final_time;

    agent user;
}

class component{
    private:
        server serv[MAX_S]
	    unsigned int numb_servers;                       //indice é o servidor e o valor é o tempo do servidor
    	int min_time, max_time;  				         //Ex: atender entre min_time e max_time unidades de tempo
    	int in, out;
                    		                             //indíce das filas de entrada e saída
        std::queue<agent> queue;

    public:
        void serving( void );
        void done( void );
        void push_in ( agent );
};





