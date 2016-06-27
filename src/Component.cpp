#include "include/Component.hh"




void Component::serving( unsigned long GVT){
    for ( int i = 0; i < numb_servers; i++ ){
        if( !serv[i].use ){
            if( !queue.empty() && queue.front().time <= GVT ){
                serv[i].use = true;
                serv[i].user = queue.front();
                queue.pop();
                srand(time(NULL));
                serv[i].final_time = rand()%(serv[i].max - serv[i].min) + serv[i].min + GVT; 			
            }	
        }
    }
}

void Component::done( unsigned long GVT, Box * next){
    for( int i = 0; i < numb_servers; i++ ){
        if(serv[i].use && serv[i].final_time == GVT){
            serv[i].use = false;
            if(this->out_t == 'S')
                printf("%d done in %lu\n", serv[i].user.id, serv[i].user.time); 
            else{ 
                serv[i].user.time = GVT;
                next->push_in(serv[i].user);
            }
        }
    }
}





