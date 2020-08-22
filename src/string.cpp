#include "string.hpp"

String::String(): str_(nullptr),
                  length_(0){}; 


int String::length() const{
    short i=0;

    while(str_[i] != ""); i++;
    return i;
}