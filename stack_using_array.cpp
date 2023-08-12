#include <iostream>

using namespace std;

#define MAX 5
int top=-1;
int stack[MAX];

void push(){
    if(top==MAX-1){
        cout<<"Stack overflow!"<<endl;
    }
    else{
        int n;
        cout<<"Enter element: ";
        cin>>n;
        top++;
        stack[top]=n;
    }
}

void pop(){
    if(top==-1){
        cout<<"Stack underflow!"<<endl;
    }
    else{
        cout<<stack[top]<<endl;
        top--;
    }
}

void display(){
    if(top==-1){
        cout<<"Stack is empty!"<<endl;
    }
    else{
        for(int i=0; i<=top; i++){
            cout<<stack[i]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    int choice=0;
    while(true){
        cout<<"Press 1 for push"<<endl;
        cout<<"Press 2 for pop"<<endl;
        cout<<"Press 3 for display"<<endl;
        cout<<"Press 4 for exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0); break;
            default: cout<<"Please enter the valid choice!"<<endl;
        }
    }
    
    return 0;
}



