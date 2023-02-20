#include "OperationCounter.h"

OperationCounter::OperationCounter(): opCount(0){}

std::ostream& operator<<(std::ostream& os, OperationCounter& oc) {
    os << "Current Op Count: " << oc.opCount << std::endl;
    return os;
}

OperationCounter OperationCounter::operator++(int) { 
    auto oldCopy = *this;
    opCount++;
    return oldCopy; 
}

void OperationCounter::reset() {
    opCount = 0;
}
