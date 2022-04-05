#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
    public:
    
    DoubleList() : List<T>() { 
             this->head = nullptr; 
             this->tail = nullptr; 
             nodes =0; 
         } 

        ~DoubleList(){ 
         	    clear(); 
              delete head; 
              delete tail; 
        }
    T front() override 
         { 
             return head->data; 
         } 
  
         T back() override 
         { 
             return tail->data; 
         } 
    
    
    void push_front(T value) override 
         { 
             if (is_empty()){ 
                 head->data = value; 
                 head->next = NULL; 
                 head->prev = NULL; 
                 nodes++; 
             } 
             Node<T>* temp = new Node<T>(value); 
             temp->next = head; 
             temp->data = value; 
             head->prev = temp; 
             tail = head; 
             head = temp; 
             head->prev = NULL; 
             tail->next = NULL; 
         } 
        
};
#endif
