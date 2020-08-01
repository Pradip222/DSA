/* Statement: Implement stack as an abstract data type using singly linked list */
#include<iostream>
#include<malloc.h>
struct Node {
   char data;
   struct Node *next;
};
class stack{
    private:
    int Size;
    struct Node* Top;
    public:
        stack(){
            Top=NULL;
            Size=0;
        }
void push(char val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = Top;
   Top = newnode;
   Size++;
}
char  pop() {
   
      Node * temp=Top;
      Top = Top->next;
      return temp->data;
  
}
char top(){
    if(!isEmpty()){
        return Top->data;
    }
}
bool isEmpty(){
    if(Top==NULL)
    return true;
    else
    {
        return  false;
    }
    
}
int size(){
    return Size;
}


};
