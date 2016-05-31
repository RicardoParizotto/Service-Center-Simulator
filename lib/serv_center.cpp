#include "serv_center.hh"


unsigned int mintime_server(){
	int min = 0;
	for ( int i = 1; i < this.numb_servers; i++ )
	    if(servers[i] < servers[min])
		min = i;         
	return min;    
}


void serving(int server, agent * p){
    srand((unsigned)time(NULL));
    int t = rand()%(this.min_time + 1);
    this.servers[server]+=t;
	//atualiza o tempo da pessoa. -- tempo da pessoa somado com o tempo de atendimento mais o tempo de espera na fila --
    p->time+=t + (this.servers[server] - p->time);
}


void * centro(void * v){
	agent pers;  
	component _center;
	
	//_center = (component*)v;

	while(1){
		if(queues[_center.in].empty())continue;					//se a fila estiver vazia, continua até que exista um elemento.
        
		pthread_mutex_lock(&lockqueue[_center.in]);             //seta semaforo para fila de entrada

		pers = queues[_center.in].front();                  
		queues[_center.in].pop();                               //remove pessoa da fila
                                                       
		pthread_mutex_unlock(&lockqueue[_center.in]);           //deseta semaforo para fila de entrada
       
		_center.serving(mintime_server(), &pers);               //coloca o servidor "mintime_server" servir a pessoa
     
		pthread_mutex_lock(&lockqueue[_center.out]);               //seta semaforo para fila de saída
      
		queues[_center.out].push(pers);                           //coloca a pessoa na fila de saída
        
		pthread_mutex_unlock(&lockqueue[_center.out]);		      //desbloqueia semaforo para fila de saída
    }
}

