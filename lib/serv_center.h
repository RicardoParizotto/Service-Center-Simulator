/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - CHAPECÓ
 *
 * ALUNOS: LUCAS ROSTIROLLA, RICARDO PARIZOTTO
 *
 *
 */

#define MAX_CENTERS 1000   //máximo de centros de serviço por componente

struct queues{
    <queue>...//fila do c++

    int entrada, saída;
};

struct representa_componentes{
    /*vai possuir as filas e componentes | vai instanciar as classes
     * vai relacionar entradas dos componentes as saídas das filas
     * e saídas dos componentes para as entradas das filas
     */
};


struct component{
    unsigned int servers, av_servers; // quantidade de servidores | quantidade de servidores disponiveis no momento. Se 0, pessoa aguarda na fila.
    int min_time, max_time;   //atender entre 4 e 8 unidades de tempo
    int 


};

struct router{
    
    router...//construtor

    int jhonson_queue(int queue[]){}            //retorna uma das filas conforme a distribuição uniforme de probabilidade
};



