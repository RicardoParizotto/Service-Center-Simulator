#include "include/Server.hh"


void Server::start_serv( unsigned long GVT, agent user ){
    use = true;
    this->user = user;
        

    total_idle++;
    total_idle_t+= (GVT - final_time);   

    user.time = GVT;
    
    srand(time(NULL));
    final_time = rand()%(this->max - this->min) + this->min + GVT; 

}
