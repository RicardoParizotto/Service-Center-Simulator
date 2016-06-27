#include "Component.hh"

class Router : public Box{    
    public:
        chance out1, out2;

        void done(Box *, Box *);      
};

