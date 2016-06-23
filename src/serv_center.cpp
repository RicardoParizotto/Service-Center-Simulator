#include "../lib/serv_center.hh"



void component::push_in( agent v ){
	queue.push(v);
}

void component::serving(){
	for ( int i = 0; i < numb_servers; i++ ){
		if( !serv[i].use ){
			if( !queue.empty() && queue.front().time <= run.GVT ){
				serv[i].use = true;
				serv[i].user = queue.front();
                queue.pop();
				srand(time(NULL));
				serv[i].final_time = rand()%(serv[i].max - serv[i].min) + serv[i].min + run.GVT; 
                printf("%lu\n", serv[i].final_time); 			
			}	
		}
	}
}

void component::done(){
	for( int i = 0; i < numb_servers; i++ ){
        printf("%lu", run.GVT);
		if(serv[i].use && serv[i].final_time == run.GVT){
			serv[i].use = false;
            printf("%d - %lu", serv[i].user.id, serv[i].user.time);
            if(this->id == run.qtd_cmp - 1)
                printf("%d done in %lu\n", serv[i].user.id, serv[i].user.time); 
			else run.centers[this->out].push_in(serv[i].user);
		}
	}
}





