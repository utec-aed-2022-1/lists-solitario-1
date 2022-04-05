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
     void push_back(T value) override 
         { 
             if(head->next = NULL){ 
                 tail->data = value; 
                 tail->prev = head; 
             } 
             Node<T>* temp = new Node<T>(value); 
             temp->data = value; 
             tail->next = temp; 
             temp->prev = tail; 
             tail = temp; 
             tail->next = NULL; 
         } 
     T pop_front() override 
         { 
             if (nodes == 0){ 
                 std::cerr<<"La lista esta vacia"<<std::endl; 
             } 
             Node<T>* temp = head; 
             head = temp->next; 
             auto pf = temp->data; 
             delete temp; 
             return pf; 
         }
    
   T pop_back() override 
         { 
             Node<T>* temp = tail; 
             tail = temp->prev; 
             auto pb = temp->data; 
             delete temp; 
             return pb; 
         } 
        
    
    
    void insert(T value, int p) override 
         { 
             if (p > nodes || p < 0 ) 
                 std::cerr<<"No permitido"<<std::endl; 
             else{ 
             Node<T>* nodo = new Node<T>(value); 
             Node<T>* temp = head; 
             int i = 0; 
             while (i++ < p - 1) temp = temp->next; 
             nodo->next = temp->next; 
             temp->next->prev = nodo; 
             nodo->prev = temp; 
             temp->next = nodo; 
             nodes++; 
             } 
         }
};
#endif
