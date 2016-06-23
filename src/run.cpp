#include "../lib/serv_center.hh"


void Simulation::agent_generator( void ){
    agent aux;

    for ( int qtd_agent = 0; qtd_agent < 5; qtd_agent++ ){

        aux.id = qtd_agent;
        aux.time = GVT;

        centers[init].push_in(aux);
    }

}


void Simulation::start(){
	GVT = 0;
	while( GVT <= ST ){
        for (int i = 0; i < qtd_cmp; i++){
            centers[i].done();
            centers[i].serving();
        }
        GVT++;
    }
}
