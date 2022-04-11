#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;

    public:
        ForwardList() : List<T>() {}

        ~ForwardList(){ 
         	clear(); 
            delete head;             
        }

        T front(){ override
            return head->data; 
        }

        T back(){
            auto temp = this->head; 
            while(temp->next != NULL) 
                 temp = temp->next; 
              
             return temp->data; 
        }

        void push_front(T value) override 
         { 
             if (is_empty()){ 
                 head->data = value; 
                 nodes++; 
             } 
             else{ 
                 Node<T>* nodo = new Node<T>(value); 
                 nodo->next = head; 
                 head = nodo; 
                 nodes++; 
            } 
              
         }
      }

        void push_back(T value) override 
         { 
             Node<T>* nodo = new Node<T>(value); 
             Node<T>* temp = head; 
             while(temp->next != NULL) 
                 temp = temp->next; 
                 temp->next = nodo; 
                 nodo->next = NULL; 
                 nodes++; 
         } 

        T pop_front() override{ 
             if (nodes == 0){ 
                 std::cout<<"No hay elementos en la lista"<<std::endl; 
             } 
             Node<T>* temp = head; 
             head = head->next; 
             auto ptrCola = temp->data; 
             delete temp; 
             return ptrCola; 
         } 

        T pop_back() override{ 
             if(head->next ==NULL) 
             { 
                 delete head; 
                 head = NULL; 
                 nodes--; 
                 return 0; 
             } 
 
             else 
             { 
                 Node<T>* temp = head; 
  
                 while(temp->next->next != NULL) 
                     temp = temp->next; 
                 delete temp->next; 
                 temp->next = NULL; 
                 nodes--; 
                 auto ptrCola = temp->next->data; 
                 return ptrCola; 
             } 
           } 

        T insert(T data, int pos){
            throw ("sin definir");
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            throw ("sin definir");
        }

        bool is_empty(){
            throw ("sin definir");
        }

        int size(){
            throw ("sin definir");
        }

        void clear(){
            throw ("sin definir");
        }
        
        void sort(){
            throw ("sin definir");
        }

        bool is_sorted(){
            throw ("sin definir");
        }

        void reverse(){
            Node<T>*ptrAct=head;
            Node<T>*prev=NULL;
            Node<T>*next?NULL;
            while(ptrAct!=NULL){
            next=ptrAct->next;
            ptrAct->next=prev;
            prev=ptrAct;
            ptrAct=next;
            }
            head=prev;
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif
