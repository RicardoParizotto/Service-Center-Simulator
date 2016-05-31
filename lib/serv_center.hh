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

#define MAX_S 1000 										//numero máximo de servidores

struct agent{
    int id, time;
};


struct component{
    private:
	unsigned int servers[MAX_S], numb_servers;               //indice é o servidor e o valor é o tempo do servidor
    	int min_time, max_time;  				     //Ex: atender entre min_time e max_time unidades de tempo
    	int in, out;		                             //indíce das filas de entrada e saída

    public:
	unsigned int mintime_server();			     //retorna o id do servidor com menor tempo.
    	void serving(int server, agent * p);		     //servidor "server" atende a pessoa "p"
};

/*
struct router{
    
    router...//construtor

    int jhonson_queue(int queue[]){}            //retorna uma das filas conforme a distribuição uniforme de probabilidade
};
*/

/***************************************
*filas de pessoas
* mutexes para filas
*******************************************/

std::queue<agent> queues[MAX_S];
pthread_mutex_t lockqueue[MAX_S];

//função para as threads dos centros
void * centro(void * v);






