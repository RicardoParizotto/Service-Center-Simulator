#include "../lib/serv_center.hh"




int router::done(){
	//for all in queue
		srand(time(NULL));
		int t = rand()%100;
		if(this->out1.prob < t) return out1.id_out;
		else return out2.id_out;
		//insert into out
	
}
