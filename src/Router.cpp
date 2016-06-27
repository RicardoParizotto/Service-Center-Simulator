#include "include/Router.hh"



void Router::done(Box * cm1, Box * cm2){
    while(!(this->queue.empty())){
        srand(time(NULL));
        unsigned t = rand()%100;
        if(this->out1.prob > t) 
            cm1->push_in(queue.front());
		else cm2->push_in(queue.front());  
        queue.pop();
    }	
}
