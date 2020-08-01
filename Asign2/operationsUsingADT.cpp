/* Statement use this ADT for
conversion of infix expression to postfix, and evaluation of postfix and prefix expression.*/
#include"stack.cpp"
#include<iostream>
#include<math.h>

using namespace std;
bool isOperator (char oper)
{

if (oper == '*'
 || oper == '/'
 || oper == '+'
 || oper == '-')
 return true;
else
return false;
}
int priority (char oper){
    if(oper=='^')
    return 3;
    else if (oper == '*' || oper == '/')
    return 2;
    else if (oper == '+' || oper == '-')
    return 1;
    else
    return 0;
}
string infixToPostfix(string expression){ 
    stack stackObj=stack(); 
    int l = expression.length(); 
    string ans; 
    for(int i = 0; i < l; i++){
         if(expression[i] == '(') 
         stackObj.push('(');  
        else if(expression[i] == ')'){ 
            while(!stackObj.isEmpty() && stackObj.top() != '('){ 
                char c = stackObj.top(); 
                stackObj.pop(); 
               ans += c; 
            } 
            if(stackObj.top() == '('){ 
                char c = stackObj.top(); 
                stackObj.pop(); 
            } 
        } 
        else if (isOperator(expression[i])){ 
            while(!stackObj.isEmpty() && priority(expression[i]) <= priority(stackObj.top())){ 
                char c = stackObj.top(); 
                stackObj.pop(); 
                ans += c; 
            } 
            stackObj.push(expression[i]); 
        }
        else{
            ans+=expression[i];
        } 
    } 
    while(!stackObj.isEmpty()) 
    { 
        char c = stackObj.top(); 
        stackObj.pop(); 
        ans += c; 
    } 
   return ans;
  
} 
string infixToPrefix(string expression){
    stack stackObj=stack();
    string ans,reverse;
    for(int i=0;i<expression.length();i++){
        stackObj.push(expression[i]);
    }
    while(!stackObj.isEmpty()){
        reverse+=stackObj.pop();
    }
      for (int i = 0; i <expression.length(); i++) { 
          if (reverse[i] == '(') { 
            reverse[i] = ')'; 
            i++; 
        } 
        else if (reverse[i] == ')') { 
            reverse[i] = '('; 
            i++; 
        } 
    }
    string temp=infixToPostfix(reverse);
    stackObj=stack();
    for(int i=0;i<temp.length();i++){
        stackObj.push(temp[i]);
    }
    while(!stackObj.isEmpty()){
        ans+=stackObj.pop();
    }
    return ans;
}

int evalPostfix(string expression){
    int ans;
    stack st=stack();
    
    for (int i = 0;i<expression.length(); i++)  
    { 
        if (isdigit(expression[i]))  
           st.push(expression[i]-'0');
        else
        {  
            int val1 =st.pop();  
            int val2 = st.pop();
            switch (expression[i])  
            {  
            case '+': st.push(val2 + val1); break;  
            case '-': st.push(val2 - val1); break;  
            case '*': st.push(val2 * val1); break;  
            case '/': st.push(val2/val1); break;  
            case '^':st.push(pow(val2,val1)); break;  
            }  
        }  
    }  
    return st.pop();

}

int main(){
    int ch;
    while(1){   
         string expression; 
        cout<<"\n----------------------------------------------------\n|\t\t\tMENU                       |\n----------------------------------------------------\n|\t1.infix to postfix                         |\n|\t2.infix to prefix                         |\n|\t3.Postfix Evalution                        |\n|\t4.Infix Evalution                          |\n|\t5.exit                                     |\n----------------------------------------------------\n\n";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\n Enter infix Expression\n"<<endl;
                cin>>expression;
                cout<<"\nPostfix of given expression is\n"<<infixToPostfix(expression);break;
            case 2:
                cout<<"\n Enter Postfix Expression\n"<<endl;
                cin>>expression;
                cout<<"\nPrefix of given expression is\n"<<infixToPrefix(expression);break;
            case 3:
                cout<<"\n please enter postfix expression to evaluate\n";
                cin>>expression;
                cout<<"\nvalue after evaluating given expression is\n"<<evalPostfix(expression);break;
            case 4:
                cout<<"\n please enter infix expression to evaluate\n";
                cin>>expression;
                expression=infixToPostfix(expression);
                cout<<"\nvalue after evaluating given expression is\n"<<evalPostfix(expression);break;
            
            case 5:break;

        }
        if(ch==5){
            cout<"bye!";
        break;}
    } 
    
    return 0;


}
