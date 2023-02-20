#ifndef MY_ARR_H
#define MY_ARR_H

#include <iostream>
#include "OperationCounter.h"

class My_arr{
    private:
        int * arr;
        int size;
        int capacity;
        OperationCounter opCount;
        void naive_remove();
        void smarter_remove();

    public:
        My_arr(int);
        My_arr();
        ~My_arr();
        void removeOdd(int);
        void insertNum(int);
        void grow();
        friend std::ostream& operator<<(std::ostream&, My_arr const &);
};

#endif