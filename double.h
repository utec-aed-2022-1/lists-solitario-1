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
             Node<T>*aux = head; 
             int i = 0; 
             while (i++ < p - 1) 
                 aux = aux->next; 
             nodo->next = aux->next; 
             aux->next->prev = nodo; 
             nodo->prev = aux; 
             aux->next = nodo; 
             nodes++; 
             } 
         }
    
    T& operator[](int p) override 
         { 
             if ( p < 0 || p > nodes )
                 std::cerr<<"No permitido"<<std::endl; 
  
              
             Node<T>* aux = head; 
             for(int i = 0; i < p ; i++)
                 aux = aux->next;
             return aux->data; 
              
         } 
    void remove(int p) override 
         { 
             if (p > nodes || p < 0 ) 
                 std::cerr<<"No permitido"<<std::endl; 
             else{ 
             Node<T>* aux = head; 
             int i = 0;      
             while (i++ < p - 1) 
                 aux = aux->next 
             delete temp->next; 
             temp->next = aux->next->next; 
             temp->next->next->prev = aux; 
             nodes--; 
             } 
         }
    
    
    int size() override 
         { 
          return nodes; 
         }
         void clear() override 
         { 
             while(head != nullptr) 
             { 
                 Node<T>* aux = head; 
                 head = head->next; 
                 delete aux; 
                 nodes--; 
             } 
             head = nullptr; 
         } 
    
    bool is_empty() override 
         { 
             if(head == nullptr){ 
                 return true; 
             } 
            return false; 
         }
    void clear() override 
         { 
             while(head != nullptr) 
             { 
                 Node<T>* aux = head; 
                 head = head->next; 
                 delete aux; 
                 nodes--; 
             } 
             head = nullptr; 
         }
    
    bool is_sorted() override 
         { 
             Node<T>* aux = head; 
    
             while (temp) { 
                 Node<T>* min = aux; 
                 Node<T>* aux_1 = aux->next; 
                  
                 while (aux_1) { 
                     if (min->data > r->data) 
                         return false; 
          
                     aux_1 = aux_1->next; 
                 } 
             } 
             return true; 
         } 
    
    void sort() override 
         { 
             if (size() == 1 || is_empty() || is_sorted()) 
                 return; 
             else{ 
                 Node<T>* aux = head; 
      
                 while (temp) { 
                     Node<T>* min = aux; 
                     Node<T>* aux = aux->next; 
 
                     while (aux) { 
                         if (min->data > aux->data) 
                             min = aux; 
              
                         aux = aux->next; 
                     } 
          
                     int aux_1 = aux->data; 
                     aux->data = min->data; 
                     min->data = aux_1; 
                     aux = aux->next; 
                  } 
                } 
              }
    void reverse() override 
         { 
             Node<T>* temp = new Node<T>(); 
             Node<T>* ptrActual = head; 
              
             while (current != NULL) 
             { 
                 aux = ptrActual->prev; 
                 ptrActual->prev = ptrActual->next; 
                 ptrActual->next = aux;             
                 ptrActual = ptrActual->prev; 
             } 
              
             if(aux != NULL ) 
                 head = aux->prev; 
         } 
};
#endif
