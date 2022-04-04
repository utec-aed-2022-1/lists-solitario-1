#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(){ 
        next = new Node<T>(); 
        prev = new Node<T>(); 
    }

    Node(T value){
       this->data = value;
    }

    void killSelf(){
        delete next; 
        delete prev; 
        this->data = NULL; 
    }    
};

#endif
