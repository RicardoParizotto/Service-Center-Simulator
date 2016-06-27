#include "defs.hh"

class Box{
    public:
        std::queue<agent> queue;
        int id;

        void push_in ( agent );    
};

