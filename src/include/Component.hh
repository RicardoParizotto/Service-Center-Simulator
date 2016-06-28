#include "Server.hh"

class Component : public Box{

    private:

        /*variáveis para monitoramento*/								
        unsigned long queue_wait; 	    //tempo total de espera de usuários na fila do componente
        unsigned long queue_users;      //número de usuários de usuários que passaram entraram no componente
        unsigned long done_users;       //número de usuários que concluiram o atendimento
        unsigned long serving_time;     //Somatorio de tempo de atendimento dos usuarios neste componente

	                            
    public:
        double avg_idle;                //media de ociosidade do componente
        double avg_queue;               //media de tempo na fila
        double avg_serv;                //media de tempo no componente

        unsigned int numb_servers;  
        Server serv[MAX_S];                 
    	int out;
        char out_t;

        void serving( unsigned long );
        unsigned long done( unsigned long, Box *);
        void show_statistics ( unsigned long );

};



