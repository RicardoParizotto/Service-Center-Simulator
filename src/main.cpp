
#include "../lib/serv_center.hh"



int main ( void ){

	scanf("%d-%d", &run.qtd_cmp, &run.init);

    int aux = run.qtd_cmp;

	while(aux--){
        int id, id_srv;
	    scanf("%d; %d:", &id, &id_srv);
             
        while(id_srv--)
            scanf("%d-%d;", &run.centers[id].serv[id_srv].min, &run.centers[id].serv[id_srv].max);
        
        scanf("%d", &run.centers[id].out);

	}

    scanf("%lu", &run.ST);

    
    return 0;
}