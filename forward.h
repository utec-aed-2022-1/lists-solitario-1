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

        void push_front(T data){
            throw ("sin definir");
        }

        void push_back(T data){
            throw ("sin definir");
        }

        T pop_front(){
            throw ("sin definir");
        }

        T pop_back(){
            throw ("sin definir");
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
            throw ("sin definir");
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif
