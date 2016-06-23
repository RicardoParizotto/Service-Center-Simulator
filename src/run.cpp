#include "../lib/serv_center.hh"


void Simulation::agent_generator( void ){
    agent aux;

    for ( int qtd_agent = 0; qtd_agent < 8; qtd_agent++ ){

        aux.id = qtd_agent;
        aux.time = GVT;

        centers[init].push_in(aux);
    }

}


void Simulation::start(){
	GVT = 0;
	while( GVT <= this->ST ){
        for (int i = 0; i < qtd_cmp; i++){
            centers[i].done( GVT, &centers[centers[i].out] );
            centers[i].serving( GVT );
        }
        GVT++;
    }
}
