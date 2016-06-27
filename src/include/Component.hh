#include "Server.hh"

class Component : public Box{

    private:

        /*variáveis para monitoramento*/								
        unsigned long queue_wait; 	    //tempo total de espera de usuários na fila do componente
        unsigned long queue_users;      //número de usuários de usuários que passaram entraram no componente
        unsigned long done_users;       //número de usuários que concluiram o atendimento
        unsigned long serving_time;     //Somatorio de tempo de atendimento dos usuarios neste componente
        
	                            
    public:

        unsigned int numb_servers;  
        Server serv[MAX_S];                 
    	int out;
        char out_t;

        void serving( unsigned long );
        void done( unsigned long, Box *);
        double avg_queue_time( void );
        double avg_serving_time( void );
        void show_statistics ( void );

};



