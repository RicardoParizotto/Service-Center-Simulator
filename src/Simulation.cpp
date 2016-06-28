#include "include/Simulation.hh"


void Simulation::agent_generator( void ){
    agent aux;

    for ( int qtd_agent = 0; qtd_agent < 40000; qtd_agent++ ){

        aux.id = qtd_agent;
        aux.time = GVT;

        centers[init].push_in(aux);
    }
}


void Simulation::start( void ){

    qtd_agent_final = sum_agent_time = 0;

	while( GVT <= this->ST ){
        //realiza as atividades dos componentes em relação a esse instante de tempo
        for (int i = 0; i < qtd_cmp; i++){
            double agent_time = centers[i].done( GVT, (centers[i].out_t == 'D')? (Box*)&routers[centers[i].out]: (Box*)&centers[centers[i].out] );
            
            if(agent_time != NONFINAL){
                qtd_agent_final++;
                sum_agent_time+=agent_time;
                /*atualiza informações sobre o agent que terminou*/
            }

            centers[i].serving( GVT );
        }
        //realiza as atividades dos roteadores
		for (int i = 0; i < qtd_rts; i++ )
			routers[i].done(&centers[routers[i].out1.id_out], &centers[routers[i].out2.id_out]);
        GVT++;
    }

    show_statistics();
}


void Simulation::show_statistics( void ){  
    unsigned long sum_idle_med = 0;
    unsigned long sum_avg_queue = 0;

    for(int i = 0; i < qtd_cmp; i++){
        centers[i].show_statistics( GVT );
        sum_idle_med+=centers[i].avg_idle;
        sum_avg_queue+=centers[i].avg_queue;
    }

    std::cout << "Tempo médio de permanência no modelo: " << (double)sum_agent_time/qtd_agent_final << 
    "  \nOciosidade média geral: " << (double)sum_idle_med/qtd_agent_final << std::endl;
}
