#include<iostream>
#include<string.h>
using namespace std;

struct Student { 
    char* name; 
    int roll; 
    float sgpa; 
}; 
void display(struct Student arr[], int n){
    for (int i = 0; i < n; i++) { 
        cout<<"roll ="<< arr[i].roll<<", Name = "<<arr[i].name <<", sgpa = "<<arr[i].sgpa<<endl;    
    } 
} 
void sortUsingRole(struct Student  arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)   
    for (j = 0; j < n-i-1; j++) {
         if (arr[j].roll > arr[j+1].roll) {
             struct Student temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
             
         } 
            
    } 
  display(arr,n);
}

void sortUsingName(struct Student arr[], int n)  
{  
    int i, j;
    struct Student key;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        
        while (j >= 0 && strcmp(arr[j].name , key.name)>0) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  

}

 int partition (struct Student arr[], int low, int high)  
{  
    float pivot = arr[high].sgpa;  
    int i = (low - 1);   
  
    for (int j = low; j <= high - 1; j++)  
    {  
       
        if (arr[j].sgpa < pivot)  
        {  
            i++;   
              
            struct Student temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }  
    }  
    struct Student temp=arr[i+1];
            arr[i+1]=arr[high];
            arr[high]=temp;  
    return (i + 1);  
}   
void get10Toppers(struct Student arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);   
        get10Toppers(arr, low, pi - 1);  
        get10Toppers(arr, pi + 1, high);  
    }  
}  
void printToppers(struct Student arr[],int n){
    cout<<"10 toppers are"<<endl;
    for (int i = n-1; i >=0; i--) { 
        cout<<"roll ="<< arr[i].roll<<", Name = "<<arr[i].name <<", sgpa = "<<arr[i].sgpa<<endl;    
    } 
}

int find(struct Student  arr[], int l, int r, string x) 
{ 
  while (l <= r) 
  { 
    int m = l + (r-l)/2; 
    if (arr[m].name == x)  
        return m;      
    if (arr[m].name < x)  
        l = m + 1;    
    else 
         r = m - 1;  
  } 
  return -1;  
} 

int main(){
    int i = 0, n = 16; 
    struct Student arr[n]; 
      arr[0].roll = 5; 
    arr[0].name = "Rahul"; 
    arr[0].sgpa = 9.26; 
  
    arr[1].roll = 2; 
    arr[1].name = "Pradip"; 
    arr[1].sgpa = 8.22; 
  
    arr[2].roll = 3; 
    arr[2].name = "Sanket"; 
    arr[2].sgpa = 7.88; 
  
    arr[3].roll = 4; 
    arr[3].name = "Prathamesh"; 
    arr[3].sgpa = 9.96; 

    arr[4].roll = 1; 
    arr[4].name = "Gaurav"; 
    arr[4].sgpa = 5.56; 

    arr[5].roll = 6; 
    arr[5].name = "Sanjay"; 
    arr[5].sgpa = 5.59;

    arr[6].roll = 20; 
    arr[6].name = "Pratik"; 
    arr[6].sgpa = 8.12;

    arr[7].roll = 19; 
    arr[7].name = "Sulbha"; 
    arr[7].sgpa = 5.88;

    arr[8].roll = 18; 
    arr[8].name = "Sujit"; 
    arr[8].sgpa = 9.25;

    arr[9].roll = 17; 
    arr[9].name = "Sanjana"; 
    arr[9].sgpa = 5.64;

    arr[10].roll = 7; 
    arr[10].name = "Kanchan"; 
    arr[10].sgpa = 7.54;
    
    arr[11].roll = 8; 
    arr[11].name = "Jagadish"; 
    arr[11].sgpa = 7.44;

    arr[12].roll = 9; 
    arr[12].name = "Rajesh"; 
    arr[12].sgpa = 6.28;

    arr[13].roll = 10; 
    arr[13].name = "Rajan"; 
    arr[13].sgpa = 5.86;

    arr[14].roll = 11; 
    arr[14].name = "Priti"; 
    arr[14].sgpa = 7.55;

    arr[15].roll = 12; 
    arr[15].name = "Pradip"; 
    arr[15].sgpa = 9.89;
    int ch;
    string name;
    int pos;

    while (1)
    {
       cout<<"\n\n------------------------MENU------------------------\n| 1.Arrange Assending using roll number \t   |\n| 2.Arrange using Names\t\t\t\t   |\n| 3.Print 10 Toppers\t\t\t\t   |\n| 4.search Student by name\t\t\t   |\n| 5.Exit\t\t\t\t\t   |\n\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
                sortUsingRole(arr,n);
            break;
        case 2: sortUsingName(arr,n);
                display(arr,n);
            break;
        case 3: get10Toppers(arr,0,n-1);
                printToppers(arr,n);
                break;
        case 4: sortUsingName(arr,n);
                cout<<"Enter Student Name to Search\n";
                
                cin>>name;
                pos=find(arr,0,n-1,name);
                if(pos==-1){
                    cout<<"Student Not found!";
                }
                else{
                    cout<<"fond something \n";
                    do{
                        cout<<"roll ="<< arr[pos].roll<<", Name = "<<arr[pos].name <<", sgpa = "<<arr[pos].sgpa<<endl;
                          pos=find(arr,pos+1,n-1,name); 
                    }while(pos!=-1);
                }
                break;
        case 5: 
                break;
        
       
        }
        if (ch==5)
        {cout<<"Bye!";
        break;
        }
        
    }
    
   
    
}
