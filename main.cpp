#include <iostream>
#include "OperationCounter.h"
#include "My_arr.h"

//Goal: The goal of this exercise is the demonstrate why different algorithms
//      to solve a problem might be better than others even if they all 
//      accomplish the task.

//      We will demonstrate this with different methods of removing odd numbers
//      from a dynamically allocated array.

const int SMALL_SIZE = 100;
const int MED_SIZE = 200;
const int LAR_SIZE = 300;


int main() {
    My_arr small_arr;
    My_arr med_arr;
    My_arr lar_arr;
    My_arr small_arr_2;
    My_arr med_arr_2;
    My_arr lar_arr_2;
    for(int i = 0; i < SMALL_SIZE; i++){
        small_arr.insertNum(rand()%100);
        small_arr_2.insertNum(rand()%100);

    }
    for(int i = 0; i < MED_SIZE; i++){
        med_arr.insertNum(rand()%100);
        med_arr_2.insertNum(rand()%100);
    }
    for(int i = 0; i < LAR_SIZE; i++){
        lar_arr.insertNum(rand()%100);
        lar_arr_2.insertNum(rand()%100);
    }
    std::cout << "Starting Experiments" << std::endl << std::endl;
    small_arr.removeOdd(1);
    med_arr.removeOdd(1);
    lar_arr.removeOdd(1);
    std::cout << std::endl << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl << std::endl;
    small_arr_2.removeOdd(2);
    med_arr_2.removeOdd(2);
    lar_arr_2.removeOdd(2);
}