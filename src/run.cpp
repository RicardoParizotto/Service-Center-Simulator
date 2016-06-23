#include "../lib/serv_center.hh"


/*gerar entidades com GVT = 0*/


void run(){
	GVT = 0;
	while( GVT <= ST ){
        for (int i = 0; i < qtd_cmp; i++){
            centers[i].done();
            centers[i].serving;
        }
        GVT++;
    }
}
