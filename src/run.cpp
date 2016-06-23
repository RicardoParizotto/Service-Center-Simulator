#include "../lib/serv_center.hh"


void Simulation::agent_generator( void ){
    agent aux;

    for ( int qtd_agent = 0; qtd_agent < 5; qtd_agent++ ){

        aux.id = qtd_agent;
        aux.time = run.GVT;

        centers[init].push_in(aux);
    }

}


void Simulation::start(){
	this->GVT = 0;
	while( this->GVT <= this->ST ){
        for (int i = 0; i < qtd_cmp; i++){
            centers[i].done(GVT);
            centers[i].serving(GVT);
        }
        this->GVT++;
    }
}
