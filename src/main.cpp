
#include "../lib/serv_center.hh"



int main ( void ){
    char in_t;
    int in_id;
    int ax;

    run.qtd_cmp = 0;

    scanf("%lu", &run.ST);

    scanf("%d", &run.init);

    while(scanf("%c %d", &in_t, &in_id )!= EOF){
        switch(in_t){
            case 'C':
                    run.qtd_cmp++;
                    run.centers[in_id].id = in_id;
                    scanf("%d", &run.centers[in_id].numb_servers);
                    for ( int i = 0; i < run.centers[in_id].numb_servers; i++ )
                        scanf("%d-%d;", &run.centers[in_id].serv[i].min, &run.centers[in_id].serv[i].max);
            case 'D': //... fazer aqui a pira para as decisoes
            case default: printf("ERROR"); break;
        }

        
 
        if(aux){
            scanf("%d", &run.centers[id].out);
            run.centers[id].type = NORMAL;  
        }else
            run.centers[id].type = OUT;
      
    }



    run.agent_generator();
    run.start();    

    return 0;
}
