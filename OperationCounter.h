#ifndef OP_COUNT_H
#define OP_COUNT_H

#include <iostream>

class OperationCounter {
    private:
        int opCount;

    public:
        OperationCounter();
        friend std::ostream& operator<<(std::ostream&, OperationCounter&);
        OperationCounter operator++(int);
        void reset();
};


#endif