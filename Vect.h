//
// Created by tuli on 20/11/2020.
//

#ifndef HW1_VECT_H
#define HW1_VECT_H
#include "Location.h"

class Vect {

public:
    int getCapacity() const;
  friend class ChessTool;
    Vect();
    Vect(const Vect& other);
    Vect(int capacity);
    ~Vect();
    void push(int data, int index);
    void push(int data);
    int get(int index) const;
    void print() const;
    int size();
    int pop();
    int operator [](int index);
    void clear();
    Vect& operator = (const Vect & rhs);
private:
    int* elms;
    int capacity;
    int current;

    void Sort();
};


#endif //HW1_VECT_H
