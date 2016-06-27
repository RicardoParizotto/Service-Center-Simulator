#include "include/Router.hh"



void Router::done(Component * cm1, Component * cm2){
    while(!(this->queue.empty())){
        srand(time(NULL));
        int t = rand()%100;
        if(this->out1.prob > t) 
            cm1->push_in(queue.front());
		else cm2->push_in(queue.front());  /*tem que mudar aqui pra poder ter uma saida ou um router*/
        queue.pop();
    }	
}
