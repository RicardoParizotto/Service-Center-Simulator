#include "../lib/serv_center.hh"




void Router::done(component cm1, component cm2){
    while(!this->queue.empty()){
        srand(time(NULL));
        int t = rand()%100;
        if(this->out1.prob < t) 
            cm1.push_in(queue.front());
		else return cm1.push_in(queue.front());  /*tem que mudar aqui pra poder ter uma saida ou um router*/
        queue.pop();
    }	
}
