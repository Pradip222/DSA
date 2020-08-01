/*statment */
#include<iostream>
using namespace std; 

 class Node  
{  
    public:
    int data;  
     Node  *link;  
} ;
    
 class Queue  
{  
    private:
     Node  *front,  *rear; 
    public:Queue(){
        front=rear=NULL;
    }
    Node *getFront(){
        return front;
    }
    Node *getRear(){
        return rear;
    }
     void enQueue( int value) 
{ 
     Node *temp = new Node; 
    temp->data = value; 
    if (front == NULL) 
       front = temp; 
    else
        rear->link = temp; 
  
    rear = temp; 
    rear->link = front; 
} 
int deQueue() 
{ 
    if (front == NULL) 
    { 
       cout<<"empty";
        return INT_MIN; 
    } 
    int value;
    if (front == rear) 
    { 
        value = front->data; 
        delete(front); 
        front = NULL; 
        rear = NULL; 
    } 
    else 
    { 
        struct Node *temp = front; 
        value = temp->data; 
        front = front->link; 
        rear->link= front; 
        delete(temp); 
    } 
  
    return value ; 
} 
} ;


