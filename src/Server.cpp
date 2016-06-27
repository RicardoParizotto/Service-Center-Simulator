#include "include/Server.hh"


double Server::avg_idle( void ){
    return (double)this->total_idle_t/this->total_idle;
}


void Server::start_serv( unsigned long GVT, agent user ){
    use = true;
    this->user = user;

    att_idle( GVT );

    printf("\n cu %lu %lu\n\n", total_idle, total_idle_t);

    user.time = GVT;
    
    srand(time(NULL));
    final_time = rand()%(this->max - this->min) + this->min + GVT; 

}


void Server::att_idle( unsigned long GVT ){
    total_idle++;
    total_idle_t+= (GVT - final_time);
}
