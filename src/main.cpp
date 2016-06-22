
#include "../lib/run.hh"





int main ( void ){

	scanf("%d-%d", &qtd_cmp, &init);

	while(qtd_cmp--){
        int id, id_srv;
	    scanf("%d; %d:", &id, &id_srv);
             
        while(id_srv--)
            scanf("%d-%d;", &centers[id].serv[id_srv].min, &centers[id].serv[id_srv].max);
        
        scanf("%d", &centers[id].out);

	}

    scanf("%lu", &ST);

    run
    
    return 0;
}
