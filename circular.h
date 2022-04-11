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
            
           
             void insert(T value, int p) override 
         { 
             if (p > nodes || p < 0 ) std::cerr<<"No se puede acceder"<<std::endl; 
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
             pop_back() override 
         { 
             Node<T>* temp = tail; 
             tail = temp->prev; 
             auto ptrCola = temp->data; 
             delete temp; 
             return ptrCola; 
         } 
            
             T& operator[](int p) override 
         { 
             if (p > nodes || p < 0 ) std::cerr<<"No se puede acceder"<<std::endl; 
  
              
             Node<T>* temp = head; 
             for(int i = 0; i < p ; i++) temp = temp->next; 
             
             return temp->data; 
              
         } 
            
            bool is_empty() override 
         { 
             return nodes == 0; 
         } 
  
         int size() override 
         { 
             return nodes; 
         } 
  
         void clear() override 
         { 
             while(nodes != 0) { 
                 pop_front(); 
                 nodes--; 
             } 
         } 
           void sort()override 
           {
           if(size()==1 ||is_empty()|| is_sorted())
               return;
              else {
               Node<T>*temp=head;
                  while(temp){
                   Node<T>*menor=temp;
                   Node<T>*aux=temp->next;
                      while(aux){
                      if(menor->data->aux->data)
                          menor=aux;
                          
                          aux=aux->next;
                      }
                      int aux_2=temp->data;
                      temp->data=menor->data;
                      menor->data=aux_2;
                      temp=temp->next;
                  }
              }
           }
            
           bool is_sorted() override {
            Node<T>*temp=head;
               
               while(temp){
                Node<T>*menor=temp;
                Node<T>*aux=temp->next;
               while(aux){
                  if(menor->data->aux->data)
                      return false;
                   aux=aux->next;
               }
              }
               return true;
           }
           void reverse() override{
                Node<T>*temp=new Node<T>();
                Node<T>*ptrActual=head;
               while(ptrActual!=NULL){
               temp=ptrActual->prev;
               ptrActual->prev=ptrActual->next;   
               ptrActual->next=temp;
               ptrActual=ptrActual->prev;
               }
           if(temp!=NULL)
               head=temp->prev;
           } 

        std::string name() override {
         return "Circular linked list";
        }
        };
    

#endif
