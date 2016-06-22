#include "serv_center.hh"


component::push_in( agent v ){
	queue.push(v);
}


component::serving( void ){
	for ( int i = 0; i < numb_servers; i++ ){
		if( !serv[i].use ){
			if( !queue.empty() && queue.front().time < GVT ){
				serv[i].use = true;
				serv[i].user = queue.pop();
				srand(time(NULL));
				serv[i].final_time = rand()%(serv[i].max - serv[i].min) + serv[i].min + GVT;  			
			}	
		}
	}
}


component::done(void){
	for( int i = 0; i < numb_servers; i++ ){
		if(serv[i].use && serv[i].final_time == GVT){
			serv[i].use = false;
			/*component[out].push_in(serv[i].user);*/
		}
	}
}





