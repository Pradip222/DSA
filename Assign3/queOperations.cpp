#include"queue.cpp"
#include<iostream>
using namespace std;
void displayQueueForward( Queue q) 
{ 
    struct Node *temp = q.getFront(); 
    cout<<"\nElements in Circular Queue are: "; 
    while (temp->link != q.getFront()) 
    { 
        cout<<temp->data; 
        temp = temp->link; 
    } 
    cout<<temp->data; 
} 
void displayQueueReverse(Queue q){
    struct Node * temp=q.getRear();
    cout<<"\nElements in Circular Queue are r: "; 
    while(temp->link!=q.getRear()){
        cout<<temp->data;
        temp=temp->link;
    }
    cout<<temp->data;

    
}
int main() 
{ 
    Queue q =  Queue(); 
     
   cout<<""
  
    return 0; 
} 