#include "include/Simulation.hh"

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
            centers[i].done( GVT, (centers[i].out_t == 'D')? (Box*)&routers[centers[i].out]: (Box*)&centers[centers[i].out] );
            centers[i].serving( GVT );
        }
		for (int i = 0; i < qtd_rts; i++ )
			routers[i].done(&centers[routers[i].out1.id_out], &centers[routers[i].out2.id_out]);
        GVT++;
    }
}
