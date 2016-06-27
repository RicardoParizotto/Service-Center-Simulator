#include "include/Component.hh"

/*construtor
void Component::Component(){
        
        queue_wait = 0; 	
        queue_users = 0;
        done_users = 0;      
        serving_time = 0; 
        LVT = 0; 
}
*/


/*remove o usuário da fila se tiver servidor livre e coloca ele no servidor*/
void Component::serving( unsigned long GVT ){
    for ( int i = 0; i < numb_servers; i++ ){
        if( !serv[i].use ){
            if( !queue.empty() && queue.front().time <= GVT ){                                           
               
                serv[i].start_serv( GVT, queue.front() );                      
                queue.pop();

                this->queue_wait+=(GVT - serv[i].user.time);        //estatísticas     
                this->queue_users++;
                
                serv[i].user.time = GVT;                            //atualiza o tempo do usuário que chegou     
            }	
        }
    }
}

/*Caso um usuário tiver terminado seu atendimento ele é removido do servidor e colocado na fila de saída*/
void Component::done( unsigned long GVT, Box * next){
    for( int i = 0; i < numb_servers; i++ ){
        if(serv[i].use && serv[i].final_time == GVT){
            serv[i].use = false;

            done_users++;
            serving_time+=(GVT - serv[i].user.time);
            
            serv[i].user.time = GVT;

            if(this->out_t == 'S')
                printf("%d done in %lu\n", serv[i].user.id, serv[i].user.time); 
            else
                next->push_in(serv[i].user);
        }
    }
}





