#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"
using namespace std;

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;

    public:
        void clear() override{
          while(head!=NULL){
          Node<T>*temp=head;
          head=head->next;
          delete temp;
          nodes --;
          }
            head=nullptr;
        }

        ForwardList() : List<T>() {}

        ~ForwardList()
        {
         	clear();
          delete head;
        }
        T front() override
        {
            return head->data;
        }

        T back(){
            auto temp = this->head;
          while(temp->next!=NULL)
              temp = temp->next;
          return temp->data;
        }

        bool is_empty() override{
            if (head==nullptr){
            return true;
            }
            return false;
        }

        void push_front(T value) override {
if(is_empty()){
head = new Node<T>(NULL);
head->data =value;
nodes++;
}
else{
Node<T>* nodo = new Node<T>(value);
nodo->next = head;
head= nodo;
nodes++;
}
}

        void push_back(T value) override{
Node<T>*nodo=new Node<T>(value);
Node<T>*temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=nodo;
nodo->next=NULL;
nodes++;
}

       T pop_front()override{
            if(nodes==0){
            std::cout<<"No hay elementos en la lista"<<std::endl;
            }
             Node<T>*temp=head;
             head=head->next;
             auto ptrCola=temp->data;
             delete temp;
             return ptrCola;
}

        T pop_back() override{
          T value;
          if(is_empty()) return value;
           if(head->next == NULL)
           {
             value = head->data;
             delete head;
             head = NULL;
             nodes--;
           }
           else{
             Node<T>* temp=head;
             while(temp->next->next!=NULL)
                 temp=temp->next;
             value = temp->next->data;
             delete temp->next;
             temp->next=NULL;
             nodes--;
           }
           return value;
         }

        void insert(T data, int pos) override{
            Node<T>*nodo=new Node<T>(data);
            Node<T>*temp=head;
            int i=0 ;
               while(i++<pos-1)
                   temp=temp->next;
                   nodo->next=temp->next;
                   temp->next=nodo;
                   nodo++;
        }

        void remove(int pos) override{
            Node<T>*temp=head;
             int i=0;
            while(i++<pos-1)
                temp=temp->next;
                delete temp->next;
                temp->next=temp->next->next;
            temp--;
        }

        T& operator[](int pos) override {
          if(pos>nodes || pos<0)
           throw;
          Node<T> *temp = head;
          for(int i=0;i<pos;i++){
            temp = temp->next;}
          return temp->data;
        }


        int size() override{
            return nodes;
        }



        void sort() override{
            if(size()==1 ||is_empty()|| is_sorted())
                return;
            else{
            Node<T>*temp=head;
             while (temp){
             Node<T>*menor=temp;
             Node<T>*aux=temp;
                 while(aux){
                 if(menor->data>aux->data)
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

        bool is_sorted() override{
        Node<T>* temp = head;
	      for(int i = 0; i<size()-1; i++) {
		      if(temp->data > temp->next->data)
			      return false;
		      temp = temp->next;
        }
	      return true;
      }


        void reverse() override{
            Node<T>*ptrAct=head;
            Node<T>*prev=NULL;
            Node<T>*next=NULL;
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
