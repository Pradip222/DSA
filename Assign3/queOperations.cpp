/*do following operations
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display (forward and reverse)*/
#include"queue.cpp"
#include<iostream>
using namespace std;
void displayQueueForward( Queue q) 
{ 
    struct Node *temp = q.getFront(); 
    if(q.getFront()==NULL){
        cout<<"\nEmpty queue!";
        return;
    }
    while (temp->link != q.getFront()) 
    { 
        cout<<temp->data<<"->"; 
        temp = temp->link; 
    } 
    cout<<temp->data; 
} 
void displayQueueReverse(Queue q){
    struct Node * temp=q.getRear();
    if(q.getRear()==NULL){
        cout<<"\nEmpty queue!";
        return;
    }
    while(temp->link!=q.getRear()){
        cout<<temp->data<<"->";
        temp=temp->link;
    }
    cout<<temp->data;

    
}
int main() 
{ 
    Queue q =  Queue(); 
    int ch; 
    int data;
    while (1)
    {
        cout<<"\n\n------------------------MENU------------------------\n|\t1.insert\t\t\t\t   |\n|\t2.delete\t\t\t\t   |\n|\t3.print forward\t\t\t\t   |\n|\t4.print reverse\t\t\t\t   |\n|\t5.exit\t\t\t\t\t   |\n\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
                cout<<"\t\tenter integer to insert\n";
                cin>>data;
                q.enQueue(data);
                cout<<"\n\tInsertion successful!\n";
            break;
        case 2:
                q.deQueue();
                cout<<"\n\tdeletion successful!";
                break;
        case 3:
                cout<<"\n\nqueue in forward is";
                displayQueueForward(q);
                break;
        case 4:
                cout<<"\n\nqueue in Reverse is";
                displayQueueReverse(q);
                break;
        case 5:
                break;
        
        default:
            break;
        }
        if(ch==5){
            cout<<"Bye!";
            break;
        }
    }
    
    
    return 0; 
} 