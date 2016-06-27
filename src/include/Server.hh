#include "Box.hh"

class Server{
    private:
        unsigned long total_idle_t;     //tempo total que o servidor ficou ocioso
        unsigned long total_idle;       //quantidade de vezes que ficou ocioso

    public:

        bool use;
        int min, max;
        unsigned long final_time;
        agent user;

        void start_serv( unsigned long, agent );
        double avg_idle( void );
        
};


