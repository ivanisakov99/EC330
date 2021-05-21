#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>

using namespace std;

template <class T>
class Node {
    public:
        // Default constructor
        Node();
        // Constructor
        Node(const T& data, Node<T>* next = NULL);
        // Node data
        T data;
        // Node next pointer
        Node<T>* next;
};

template <class T>
class LinkedList: public Node<T> {
    public:
        // Constructor
        LinkedList();
        // Destructor
        ~LinkedList();
        // Removes and returns content of head
        T deleteFromHead();
        // Removes and returns content of tail
        T deleteFromTail();
        // Removes node with specified data
        void deleteNode(T data);
        // Insert node with data at the head
        void InsertToHead(T data);
        // Insert node with data at the tail
        void InsertToTail(T data);
        // Returns size of linked list
        int getSize();
        // Prints linked list
        void print();
    private:
        // Head of linked list
        Node<T>* head;
};


/******* From here down is the content of the LinkedList.cpp file: *******/

/* Implementation of Node */

template<class T>
Node<T>::Node(){
    
}

template<class T>
Node<T>::Node(const T& data, Node<T>* next){
    this->data = data;
    this->next = next;
}  
 
/* Implementation of linked list */

template <class T>
LinkedList<T>::LinkedList(){
    this->head = NULL;
}  

template <class T>
LinkedList<T>::~LinkedList(){
    Node<T>* current = this->head, *next;
    while(current != NULL){
        next = current->next;
        delete current;
        current = next;
    }
}  

template <class T>
T LinkedList<T>::deleteFromHead(){
    if(this->head != NULL){
        Node<T>* temp = this->head; 
        this->head = this->head->next; 

        return temp->data;
    }

    return 0;
}

template <class T>
T LinkedList<T>::deleteFromTail(){
    if(this->head != NULL){
        
        Node<T> *current = this->head, *prev = NULL;

        while(current->next != NULL){
            prev = current;
            current = current->next;
        }

        if(prev != NULL){
            prev->next = current->next;
        }

        if(current == this->head){
            T data = current->data;
            this->head = NULL;
            return data;
        }
        
        return current->data;
    }
    
    return 0;
}

template <class T>
void LinkedList<T>::deleteNode(T data){
    if(this->head != NULL){
    
        if(this->head->data == data){
            this->head = this->head->next;
            return;
        }
    
        Node<T> *current = this->head, *prev = NULL;

        while(current != NULL && current->data != data){
            prev = current;
            current = current->next;
        }

        if(current == NULL){
            return;
        }

        if(prev != NULL){
            prev->next = current->next;
            current = NULL;
        }

        return;
    }

    return;
}

template <class T>
void LinkedList<T>::InsertToHead(T data){
    Node<T> * newHead = new Node<T>(data, this->head);
    
    this->head = newHead;
    return;
}

template <class T>
void LinkedList<T>::InsertToTail(T data){
    Node<T> *tail = new Node<T>(data, NULL);

    if (this->head == NULL) {
        this->head = tail;
    }
    else{
        Node<T> *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = tail;
    }

    return;
}

template <class T>
int LinkedList<T>::getSize(){
    int count = 0; 
    Node<T>* temp = head; 

    while(temp != NULL){  
        count++;  
        temp = temp->next;  
    }  
    return count;
 }

template <class T>
void LinkedList<T>::print(){
    if(head == NULL){
        cout << "Linked list is empty" << endl;;
        return;
    }

    Node<T> *temp = this->head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return;
}

/* Implementation of Stack */

template <class T>
class StackFromList: public LinkedList<T> {   //Stack
    private:
        Node<T>* top;
    public:
        StackFromList();
        ~StackFromList();
        bool isEmpty();
        void push(T data);
        T pop();
};

template <class T>
StackFromList<T>::StackFromList(){
    this->top = NULL;
}

template <class T>
StackFromList<T>::~StackFromList(){
    while(this->top != NULL){
        Node<T> *q = this->top;
        this->top = this->top->next;
        delete q;
    }
}

template <class T>
bool StackFromList<T>::isEmpty(){
    if(this->top == NULL){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void StackFromList<T>::push(T data){
    Node<T>* temp = new Node<T>(data, this->top);
    this->top = temp;
    return;
}

template <class T>
T StackFromList<T>::pop(){
    if(this->top != NULL){
        Node<T>* temp = this->top;
        this->top = this->top->next;
        return temp->data;
    }
    return 0;
}

/* Implementation of Queue */

template <class T>
class QueueFromList: public LinkedList<T> {    // Queue
    private:
        Node<T>* front;
    public:
        QueueFromList();
        ~QueueFromList();
        bool isEmpty();
        void enqueue(T data);
        T dequeue();
};

template <class T>
QueueFromList<T>::QueueFromList(){
    this->front = NULL;
}
    
template <class T>
QueueFromList<T>::~QueueFromList(){
    while(this->front != NULL){
        Node<T> *q = this->front;
        this->front = this->front->next;
        delete q;
    }
}
    
template <class T>
bool QueueFromList<T>::isEmpty(){
    if(this->front == NULL){
        return true;
    }
    else{
        return false;
    }
}
    
template <class T>
void QueueFromList<T>::enqueue(T data){
    Node<T> *newNode = new Node<T>(data, NULL), *temp = this->front;
    
    if(this->front == NULL){
        this->front = newNode;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    
    return;
}
    
template <class T>
T QueueFromList<T>::dequeue(){
    if(this->front != NULL){
        T data = this->front->data;
        this->front = this->front->next;
        
        return data;
    }
    return 0;
}

#endif /* LinkedList_h */