#include "Router.hh"

class Simulation{
    public:

        unsigned long GVT;                //global virtual time
        unsigned long ST;	              //SIMULATION TIME    

        int qtd_cmp, qtd_rts, init;
        Component centers[MAX_S];
        Router routers[MAX_S];


        void agent_generator( void );
        void start( void );
        void show_statistics( void );
};


static Simulation run;
