#include <iostream>

using namespace std;

class Node{
    public:
    Node *st=NULL;
    Node *add, *temp, *New;
    int data, count=0;


void create(){
    if(st!=NULL){
        cout<<"Stack already created!"<<endl;
    }
    else{
        st=new Node();
        int n;
        cout<<"Enter element: ";
        cin>>n;
        st->data=n;
        st->add=NULL;
        temp=st; 
        char ch;
        count++;
        
        cout<<"Do you wants to enter more elements? If yes then press 'y' else 'n'"<<endl;
        cin>>ch;
        while(ch=='y' || ch=='Y'){
            cout<<"Enter your element: ";
            cin>>n;
            New=new Node();
            New->data=n;
            New->add=NULL;
            temp->add=New;
            
            temp=New;
            count++;
            
            cout<<"Do you wants to enter more elements? If yes then press 'y' else 'n'"<<endl;
            cin>>ch;
        }
    }
}
void push(){
    New=new Node();
    if(!New){      //checking heap is full or not
        cout<<"Stack underflow"<<endl;
    }
    else if(st==NULL){
        cout<<"Stack not created, create stack first!"<<endl;
    }
    else{
        int n;
        cout<<"Enter elment: ";
        cin>>n;
        New->data=n;
        New->add=NULL;
        temp=st;
        while(temp->add!=NULL){
            temp=temp->add;
        }
        temp->add=New;
        
        count++;
    }
}

void pop(){
    if(st==NULL){
        cout<<"Underflow, stack does not exist!";
    }
    else{
        temp=st;
        if(temp->add==NULL){
            cout<<"Deleted element: "<<st->data<<endl;
            st=NULL;
        }
        
        else{
            while(temp->add->add!=NULL){
                temp=temp->add;
            }
            cout<<"Deleted element: "<<temp->add->data<<endl;
            delete temp->add;
            temp->add=NULL;
        }
        
        count--;
    }
}

void display(){
    if(st==NULL){
        cout<<"Stack empty!"<<endl;
    }
    else{
        temp=st;   
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->add;
        }
        cout<<endl;
    }
    
}

void Size(){
    cout<<"Size of the stack is: "<<count<<endl;
}

};

int main(){
    
    Node stack;
    
    int choice=0;
    
    while(true){
        cout<<"Press 1 for create"<<endl;
        cout<<"Press 2 for push"<<endl;
        cout<<"Press 3 for pop"<<endl;
        cout<<"Press 4 for display"<<endl;
        cout<<"Press 5 to know the size"<<endl;
        cout<<"Press 6 for exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1: stack.create(); break;
            case 2: stack.push(); break;
            case 3: stack.pop(); break;
            case 4: stack.display(); break;
            case 5: stack.Size(); break;
            case 6: exit(0); break;
            default: cout<<"Please enter the valid choice!"<<endl;
        }
    }
    
    return 0;
}
