#include "Box.hh"

class Component : public Box{
    private:								
     //   unsigned long queue_wait; 	
	                            
    public:

        unsigned int numb_servers;  
        server serv[MAX_S];                 
    	int out;
        char out_t;


        void serving( unsigned long );
        void done( unsigned long, Box *);
};



