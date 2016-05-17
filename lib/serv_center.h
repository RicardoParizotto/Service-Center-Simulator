/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - CHAPECÓ
 *
 * ALUNOS: LUCAS ROSTIROLLA, RICARDO PARIZOTTO
 *
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
    unsigned int servers[MAX_S], numb_servers;               //indice é o servidor e o valor é o tempo do servidor
    int min_time, max_time;  								 //Ex: atender entre min_time e max_time unidades de tempo
    int in, out;											 //indíce das filas de entrada e saída


    //retorna o id do servidor com menor tempo.
    unsigned int mintime_server(){
        int min = 0;
        for ( int i = 1; i < this.numb_servers; i++ )
            if(servers[i] < servers[min])
                min = i;         
        return min;    
    }

    //servidor "server" atende a pessoa "p"
    void serving(int server, agent * p){
        srand((unsigned)time(NULL));
        int t = rand()%(this.min_time + 1);
        this.servers[server]+=t;
		//atualiza o tempo da pessoa. -- tempo da pessoa somado com o tempo de atendimento mais o tempo de espera na fila --
        p->time+=t + (this.servers[server] - p->time);
    }

};

struct router{
    
    router...//construtor

    int jhonson_queue(int queue[]){}            //retorna uma das filas conforme a distribuição uniforme de probabilidade
};

/***************************************
*filas de pessoas
* mutexes para filas
*******************************************/
std::queue<agent> queues[;
pthread_mutex_t * lockqueue;



//função para as threads dos centros
void * centro(void * v){
	agent pers;  
	component _center;
	
	//_center = (component*)v;

	while(1){
		if(queues[_center.in].empty())continue;					//se a fila estiver vazia, continua até que exista um elemento.
        //seta semaforo para fila de entrada
		pthread_mutex_lock(&lockqueue[_center.in]);
        //remove pessoa da fila
		pers = queues[_center.in].front();
		queues[_center.in].pop();
        //deseta semaforo para fila de entrada
		pthread_mutex_unlock(&lockqueue[_center.in]);
        //coloca o servidor "mintime_server" servir a pessoa
		_center.serving(mintime_server(), &pers);
        //seta semaforo para fila de saída
		pthread_mutex_lock(&lockqueue[_center.out]);
        //coloca a pessoa na fila de saída
		queues[_center.out].push(pers);
        //desbloqueia semaforo para fila de saída
		pthread_mutex_unlock(&lockqueue[_center.out]);		
    }
}








