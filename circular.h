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
};
    

#endif
