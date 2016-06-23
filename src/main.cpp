
#include "../lib/serv_center.hh"



int main ( void ){

	scanf("%d %d", &run.qtd_cmp, &run.init);

    int aux = run.qtd_cmp;

	while(aux--){
        int id, id_srv;
        scanf("%d;%d:", &id, &id_srv);
        
        run.centers[id].id = id;   //hehe

        run.centers[id].numb_servers = id_srv;
             
        while(id_srv--)
            scanf("%d-%d;", &run.centers[id].serv[id_srv].min, &run.centers[id].serv[id_srv].max);
        
        if(aux){
            scanf("%d", &run.centers[id].out);
            run.centers[id].type = NORMAL;  
        }else
            run.centers[id].type = OUT;
      
    }

    scanf("%lu", &run.ST);

    run.agent_generator();
    run.start();    

    return 0;
}
