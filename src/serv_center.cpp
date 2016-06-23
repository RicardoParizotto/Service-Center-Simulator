#include "../lib/serv_center.hh"



void component::push_in( agent v ){
	queue.push(v);
}

void component::serving(){
	for ( int i = 0; i < numb_servers; i++ ){
		if( !serv[i].use ){
			if( !queue.empty() && queue.front().time < run.GVT ){
				serv[i].use = true;
				serv[i].user = queue.front();
                queue.pop();
				srand(time(NULL));
				serv[i].final_time = rand()%(serv[i].max - serv[i].min) + serv[i].min + run.GVT;  			
			}	
		}
	}
}

void component::done(){
	for( int i = 0; i < numb_servers; i++ ){
		if(serv[i].use && serv[i].final_time == run.GVT){
			serv[i].use = false;
			run.centers[this->out].push_in(serv[i].user);
		}
	}
}





