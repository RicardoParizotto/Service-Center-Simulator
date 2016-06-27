#include "include/Component.hh"


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


double Component::avg_queue_time( void ){
    return this->queue_wait/this->queue_users;
}


double Component::avg_serving_time( void ){
    return this->serving_time/this->done_users;
}

void Component::show_statistics( void ){
    double sum_avg = 0.;

    std::cout << "\n\nComponente" << this->id << std::endl;
    std::cout << "tempo medio em fila: " << avg_queue_time() << "  Tempo medio de atendimento: " << avg_serving_time() << std::endl;

    for( int i = 0; i < numb_servers; i++ ){
        double aux = serv[i].avg_idle();
        sum_avg+=aux;
        std::cout << "      Tempo medio de atendimento de servidor" << i << ":" << aux << std::endl;
    }
        
}




