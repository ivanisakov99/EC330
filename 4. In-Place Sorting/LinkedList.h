#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>

using namespace std;

template <class T>
class Node {
    public:
        Node();                                         // default constructor
        Node(const T& data, Node<T>* next = nullptr);   // donstructor
        T data;                                         // node data
        Node<T>* next;                                  // node next pointer
};

template <class T>
class LinkedList: public Node<T> {
    public:
        LinkedList();                                   // constructor
        ~LinkedList();                                  // destructor
        T deleteFromHead();                             // removes and returns content of head
        T deleteFromTail();                              // removes and returns content of tail
        void deleteNode(T data);                         // removes node with specified data
        void InsertToHead(T data);                      // insert node with data at the head
        void InsertToTail(T data);                      // insert node with data at the tail
        int getSize();                                  // returns size of linked list
        void print();                                   // prints linked list
    private:
        Node<T>* head;                                  // head of linked list
};


    /******* From here down is the content of the LinkedList.cpp file: ***********************/

    /* Implementation of Node */

// default constructor
template<class T>
Node<T>::Node(){

}
 
// constructor
template<class T>
Node<T>::Node(const T& data, Node<T>* next){
    this->data = data;
    this->next = next;
}  
 
    /* Implementation of linked list */

// constructor
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
}  

// destructor
template <class T>
LinkedList<T>::~LinkedList(){
    Node<T>* current = head;
    while( current != 0 ) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}  

template <class T>
T LinkedList<T>::deleteFromHead(){
    if (this->head == nullptr) {
        
    }
    else{
        Node<T>* temp = this->head; 
        this->head = this->head->next; 
  
        return temp->data;
        delete temp; 
    }
}

template <class T>
T LinkedList<T>::deleteFromTail(){
    if(this->head == nullptr){
    
    }
    else{
        if(this->head->next == nullptr){
            Node<T>* temp = this->head;
            delete this->head;
            this->head = nullptr;
            return temp->data;
        }

        Node<T>* currNode = this->head;
        while (currNode->next->next != nullptr){
            currNode = currNode->next;
        }
        Node<T> *s = currNode->next;
        delete currNode->next;
        currNode->next = nullptr;
        return s->data;
    }
    
    
}

template <class T>
void LinkedList<T>::deleteNode(T data){
    Node<T>* prev = head; 
    Node<T>* current = head->next; 
    
    if(this->head->data == data){
        this->head = current;
        delete prev;
        return;
    }
    
    while(current != nullptr) {
        if(current->data == data) { 
            break; 
        }
        else{
            prev = current; 
            current = current->next; 
        }
    }
    if(current == nullptr) { 
        return; 
    } 
    else{
        prev->next = current->next; 
        delete current; 
        return;
    }
}

template <class T>
void LinkedList<T>::InsertToHead(T data){
        Node<T> * newNode = new Node<T>(data, nullptr);
     
    if (head == nullptr)
        head = newNode;
    else{
        newNode->next = head;
        head = newNode;
    }
}

template <class T>
void LinkedList<T>::InsertToTail(T data){
    Node<T> *last = new Node<T>;

    last->data = data;
    last->next = nullptr;

    if (head == nullptr) {
        head = last;
    }
    else{
        Node<T> *temp = new Node<T>;

        temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = last;
    }

    return;

}

template <class T>
int LinkedList<T>::getSize(){
    int count = 0; 
    Node<T>* current = head; 

    while(current != nullptr){  
        count++;  
        current = current->next;  
    }  
    return count;
 }


template <class T>
void LinkedList<T>::print(){
    if(head == nullptr){
        cout << "Linked list is empty" << endl;;
        return;
    }
     
    cout << head->data << " ";
     
    if(head->next == nullptr){
        cout << endl;
        return;
    }
 
    Node<T>* currNode = head->next;
    Node<T>* prevNode = head;
 
     
    while(currNode->next != nullptr){
        cout << currNode->data << " ";
        prevNode = currNode;
        currNode = currNode->next;
    }
 
    cout << currNode->data << endl;
    return;
}


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
    top = nullptr;
}

template <class T>
StackFromList<T>::~StackFromList(){
    while(top != nullptr){
        Node<T> *q = top;
        top = top->next;
        delete(q);
    }
}

template <class T>
bool StackFromList<T>::isEmpty(){
    if(top == nullptr){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void StackFromList<T>::push(T data){
    Node<T>* temp = new Node<T>;
    temp->data = data;
    temp->next = top;
    top = temp;
}

template <class T>
T StackFromList<T>::pop(){
    if (top == nullptr) {
    
    }
    else{
        Node<T>* temp = top;
        top = top->next;
        T s = temp->data;
        temp->next = nullptr;
        delete temp;
        return s;
    }
}

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
    front = nullptr;
}
    
template <class T>
QueueFromList<T>::~QueueFromList(){
    while(front != nullptr){
        Node<T> *q = front;
        front = front->next;
        delete(q);
    }
}
    
template <class T>
bool QueueFromList<T>::isEmpty(){
    if(front == nullptr){
        return true;
    }
    else{
        return false;
    }
}
    
template <class T>
void QueueFromList<T>::enqueue(T data){
    Node<T> * newNode = new Node<T>(data, nullptr);
     
    if (front == nullptr){
        front = newNode;
    }
    else{
        newNode->next = front;
        front = newNode;
    }
}
    
template <class T>
T QueueFromList<T>::dequeue(){
    if(front == nullptr){
        return;
    }
    else{
        if(front->next == nullptr){
            Node<T>* temp = front;
            delete front;
            front = nullptr;
            return temp -> data;
        }

        Node<T>* currNode = front;
        while (currNode -> next -> next != nullptr){
            currNode = currNode -> next;
        }
        Node<T> *s = currNode -> next;
        delete currNode -> next;
        currNode -> next = nullptr;
        return s -> data;
    }
    
}

#endif /* LinkedList_h */