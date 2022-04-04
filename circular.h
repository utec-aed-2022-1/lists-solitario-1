#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
    private:
        Node<T>* head;//sentinel
        int nodes; 
    public:
        CircularList() : List<T>() { }

        ~CircularList(){
          DoubleList() : List<T>() { 
             this->head= nullptr; 
             this->tail = nullptr; 
             nodes = 0; 
        }   
            
            ~DoubleList() 
       {  
               clear(); 
              delete head; 
              delete tail; 
         } 
};

#endif
