#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"
using namespace std;

template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
    public:

    DoubleList() : List<T>() {
             this->head = nullptr;
             this->tail = nullptr;
             nodes=0;
         }
    void clear() override
          {
            while(head!=nullptr)
             {
              Node<T>* aux = head;
              head =head->next;
              delete aux;
              nodes--;
      }
             head = nullptr;
          }
        ~DoubleList(){
              clear();
              delete head;
              delete tail;
        }
    T front() override
         {
             return head->data;
         }

         T back() override
         {
             return tail->data;
         }


    void push_front(T value)  override
     {
     /* if (is_empty()){
                 head = new Node<T>(value);
                 head->next = nullptr;
                 head->prev = nullptr;
                 tail = head;
                 nodes++;
               return;
       }
      Node<T> *p = new Node<T>(value);
      p->next = head;
      p->prev = nullptr;
      head = p;*/
      // p->next->prev = p;
      // p->prev->next = p;
              if (is_empty()){
                  cout << "R";
                  head = new Node<T>(value);
                  head->data=value;
                  head->next = NULL;
                  head->prev = NULL;
                  tail = head;
                  nodes++;
                  return;
              }
                else{
                  cout << "T";
              Node<T>* newHead = new Node<T>(value);
              newHead->next = head;
              newHead->data=value;
              head->prev = newHead;
              tail = head;
              head=newHead;
              head->prev = NULL;
              tail->next = NULL;
              nodes++;
              }

         }
     void push_back(T value) override
         {
           if(head->next==NULL){
             //tail=head;
                 tail->data = value;
                 tail->prev = head;
             }
             Node<T>* aux = new Node<T>(value);
             aux->data = value;
             tail->next =aux;
             aux->prev = tail;
             tail = aux;
             tail->next = NULL;
             nodes++;
         }
     T pop_front() override
         {
             if (nodes == 0){
                 std::cerr<<"La lista esta vacia"<<std::endl;
             }
             Node<T>* aux =head;
             head = aux->next;
             auto aux_1 = aux->data;
             delete aux;
             nodes--;
             return aux_1;
         }

   T pop_back() override
         {
             Node<T>* aux = tail;
             tail = aux->prev;
             auto aux_1= aux->data;
             delete aux;
             nodes--;
             return aux_1;
         }



    void insert(T value, int pos) override
         {
             if (pos > nodes || pos < 0 )
                 std::cerr<<"No permitido"<<std::endl;
             else{
             Node<T>* nodo =new Node<T>(value);
             Node<T>*aux = head;
             int i = 0;
             while (i++ < pos - 1)
                 aux = aux->next;
             nodo->next=aux->next;
             aux->next->prev=nodo;
             nodo->prev=aux;
             aux->next=nodo;
             nodes++;
          }
         }

    T& operator[](int pos) override
         {
             if ( pos < 0 || pos > nodes)
                std::cerr<<"No permitido"<<std::endl;
               Node<T>* aux = head;
               for(int i = 0; i< pos ; i++)
                   aux= aux->next;
               return aux->data;

         }
    void remove(int pos) override
         {
             if(pos>nodes|| pos < 0)
                 std::cerr<<"No permitido"<<std::endl;
             else{
             Node<T>* aux = head;
             int i = 0;
             while(i++<pos-1)
                 aux=aux->next;
             delete aux->next;
             aux->next = aux->next->next;
             aux->next->next->prev=aux;
             nodes--;
             }
         }


    int size() override
    { return nodes; }

    bool is_empty() override
         {
             if(head == nullptr){
                 return true;
             }
            return false;
         }

    bool is_sorted() override
         {
             Node<T>* aux = head;

             while (aux) {
                 Node<T>* min = aux;
                 Node<T>* aux_1 = aux->next;

                 while (aux_1) {
                     if (min->data > aux_1->data)
                         return false;

                     aux_1 = aux_1->next;
                 }
             }
             return true;
         }

    void sort() override
         {
             if (size() == 1 || is_empty() || is_sorted())
                 return;
             else{
                 Node<T>* aux = head;

                 while (aux) {
                     Node<T>* min = aux;
                     Node<T>* aux = aux->next;

                     while (aux) {
                         if (min->data > aux->data)
                             min = aux;

                         aux = aux->next;
                     }

                     int aux_1 = aux->data;
                     aux->data = min->data;
                     min->data = aux_1;
                     aux = aux->next;
                  }
                }
              }
    void reverse() override
         {
             Node<T>* aux = new Node<T>();
             Node<T>* ptrActual = head;

             while (ptrActual != NULL)
             {
                 aux = ptrActual->prev;
                 ptrActual->prev = ptrActual->next;
                 ptrActual->next = aux;
                 ptrActual = ptrActual->prev;
             }

             if(aux != NULL )
                 head = aux->prev;
         }

     std::string name(){
            return "DoubleList";
        }
};
#endif
