
#include "include/Simulation.hh"



int main ( ){
    char in_t;
    int in_id;

    run.qtd_cmp = run.qtd_rts = 0;


    scanf("%lu", &run.ST);

    scanf("%d", &run.init);

    while(scanf(" %c %d", &in_t, &in_id )!= EOF){
        switch(in_t){
            case 'C':
                    run.qtd_cmp++;
                    run.centers[in_id].id = in_id;
                    scanf("%d", &run.centers[in_id].numb_servers);
                    for ( unsigned long i = 0; i < run.centers[in_id].numb_servers; i++ )
                        scanf("%d-%d;", &run.centers[in_id].serv[i].min, &run.centers[in_id].serv[i].max);
                    scanf(" %c %d", &run.centers[in_id].out_t, &run.centers[in_id].out );
                    break;
            case 'D': 
                    run.qtd_rts++;
                    scanf(" %c %d %u", &run.routers[in_id].out1.out_t, &run.routers[in_id].out1.id_out, &run.routers[in_id].out1.prob);
                    scanf(" %c %d %u", &run.routers[in_id].out2.out_t, &run.routers[in_id].out2.id_out, &run.routers[in_id].out2.prob);
                    break;
            default: printf("ERROR: %c do not expected \n", in_t); 
        }
    }


    run.agent_generator();
    run.start();    

    return 0;
}
