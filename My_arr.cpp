#include "My_arr.h"
#include <iostream>

My_arr::My_arr(): capacity(0), size(0), arr(nullptr){};

My_arr::My_arr(int starting_cap): capacity(starting_cap), size(0), arr(nullptr) {
    arr = new int[capacity];
}

My_arr::~My_arr() {
    delete[] arr;
}

void My_arr::naive_remove() {
    std::cout << "Running naive_remove on list: " << *this << std::endl;
    //find the first odd number
    int index = 0;
    while(true){
        while (arr[index] % 2 == 0 && index < size) {
            opCount++;
            index++;
            opCount++;
        }
        if (index == size) {
            opCount++;
            std::cout << "Finished removing odd numbers, here is the list: " << *this << std::endl; 
            return;
        }
        int aheadIndex = index + 1;
        opCount++;
        while (index < size - 1) {
            opCount++;
            arr[index] = arr[aheadIndex];
            opCount++;
            index++;
            opCount++;
            aheadIndex++;
            opCount++;
        }
        size--;
        opCount++;
        index = 0;
        opCount++;
    }
}

void My_arr::smarter_remove(){
    std::cout << "Running smarter_remove on list: " << *this << std::endl;
    int index = 0;
    int head = 0;
    int num_removed = 0;
    while (index < size) {
        opCount++;
        if (arr[index] % 2 == 0) { //If it is even copy it to head and increment both
            opCount++;
            arr[head] = arr[index];
            opCount++;
            index++;
            opCount++;
            head++;
            opCount++;
        } else { //If it is odd, don't copy to the head just increment the index.
            num_removed++;
            opCount++;
            index++;
            opCount++;
        }
    }
    size = size - num_removed;
    opCount++;
    std::cout << "Finished removing odd numbers, here is the list: " << *this << std::endl; 
}

void My_arr::removeOdd(int method) {
    switch(method) {
        case 1:
            opCount.reset();
            std::cout << "======== STARTING EXPERIMENT WITH NAIVE REMOVE ========" << std::endl;
            naive_remove();
            std::cout << "Number of Operations: " << opCount << std::endl;
            std::cout << "======== FINISHED EXPERIMENT ========" << std::endl;
            break;
        case 2:
            opCount.reset();
            std::cout << "======== STARTING EXPERIMENT WITH SMARTER REMOVE ========" << std::endl;
            smarter_remove();
            std::cout << "Number of Operations: " << opCount << std::endl;
            std::cout << "======== FINISHED EXPERIMENT ========" << std::endl;
            break;
        default:
            
            break;
    }
}

std::ostream& operator<<(std::ostream& os, My_arr const & arr) {
    for(int i = 0; i < arr.size; i++){
        std::cout << arr.arr[i] << ", ";
    }
    std::cout << std::endl;
    return os;
}

void My_arr::grow() {
    if (capacity == 0 ) {
        capacity = 2;
    } else {
        capacity = size * 2;
    }
    int * newMem = new int[capacity];
    for(int i = 0; i < size; i++) {
        newMem[i] = arr[i];
    }
    delete[] arr;
    arr = newMem;
}


void My_arr::insertNum(int num){
    if (size == capacity) {
        grow();
    }
    arr[size] = num;
    size++;
}

// arr[10,2,3,4,5,6]