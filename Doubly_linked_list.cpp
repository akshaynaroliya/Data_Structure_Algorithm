#include<iostream> 

using namespace std;

class Node{

    public: 
    
    Node *start=NULL;
    Node *ladd;
    Node *radd;
    Node *temp;
    Node *New;
    int data;
    int p;
    int count=0;
    
    // creating the list
    void create(){
        if(start!=NULL){
            cout<<"List already created"<<endl;
        }
        else{
            cout<<"Enter your element: "<<endl;
            cin>>data;
            start=new Node();   
            start->data=data;
            start->ladd=NULL;
            start->radd=NULL;
            temp=start; 
            
            count++;
            
            char choice;
            cout<<"Do you want more elements? Press 'y' if yes else 'n'"<<endl;
            cin>>choice;
            while(choice=='y'){
                cout<<"Enter element: "<<endl;
                cin>>data;
                New = new Node();
                New->data=data;
                temp->radd=New;
                New->radd=NULL;
                New->ladd=temp;
                
                temp=New;
                
                cout<<"Do you want more elements? Press 'y' if yes else 'n'"<<endl;
                cin>>choice;
                
                count++;
            
            }
        }
    }
    
    //inserting the node into the list
    void insert(){
        int pos, i=1;
        if(start==NULL){
            cout<<"Create a list first!"<<endl;
        }
        else{
            cout<<"Enter position: ";
            cin>>pos;
            if(pos>count+1 || pos<=0){
                cout<<"Enter the position greater than 0 or less than and equal to "<<count+1<<endl;
            }
            else{
                cout<<"Enter element: "<<endl;
                cin>>data;
                New = new Node();
                New->data = data;
                New->ladd = NULL;
                New->radd = NULL;
                
                if(pos==1){
                    New->radd=start;
                    start->ladd=New;
                    start=New;
                }
                
                else if(pos==count+1){
                    temp = start;
                    while(temp->radd!=NULL){
                        temp=temp->radd;
                    }
                    temp->radd=New;
                    New->ladd=temp;
                }
                
                else{
                    temp=start;
                    while(i<pos){
                        temp=temp->radd;
                        i++;
                    }
                    temp->ladd->radd=New;
                    New->ladd=temp->ladd;
                    temp->ladd=New;
                    New->radd=temp;
                }
                
                count++; 
            }
        }
    }
    
    //deleting the node
    void Delete(){
        int pos, i=1;
        if(start==NULL){
            cout<<"List does not exist!"<<endl;
        }
        else{
            
            cout<<"Enter position: ";
            cin>>pos;
            if(pos>count || pos<=0){
                cout<<"Invalid, posiion Please enter the positon greater than 0 or less than and equal to "<<count<<endl;
            }
            
            else{
                
                temp=start;
                
                if(start->radd==NULL){
                    cout<<"Deleted element is: "<<start->data<<endl;
                    start=NULL;
                }
                else if(pos==1){
                    cout<<"Deleted element is: "<<temp->data<<endl;
                    Node *d=temp;
                    start=start->radd;
                    start->ladd=NULL;
                    // free(temp);
                    // delete temp;
                    delete d;
                }
                
                else if(pos==count){
                    while(temp->radd!=NULL){
                        temp=temp->radd;
                    }
                    Node *d=temp;
                    temp->ladd->radd=NULL;
                    // temp->radd=NULL;
                    cout<<"Deleted element is: "<<d->data<<endl;
                    // free(d);
                    delete d;
                }
                
                else{
                    while(i<pos){
                        temp=temp->radd;
                        i++;
                    }
                    Node *d=temp;
                    temp->ladd->radd=temp->radd;
                    temp->radd->ladd=temp->ladd;
                    cout<<"Deleted element "<<d->data<<endl;
                    // free(d);
                    delete d;
                }
                count--; 
            }
        }
    }
    
    //Displaying the List
    void display(){
        if(start==NULL){
            cout<<"List not created!"<<endl;
        }
        else{
            temp=start;
            while(temp!=NULL){
                cout<<temp->data<<"  ";
                temp=temp->radd; 
            }
            cout<<endl;
        }
    }
};

int main(){
    
    Node l;
    
    int ch=0;

    // Taking choice from user
    do{
        cout<<"Press 1 for create"<<endl;
        cout<<"Press 2 for insert"<<endl;
        cout<<"Press 3 for delete"<<endl;
        cout<<"Press 4 for display"<<endl;
        cout<<"Press 5 for exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1: l.create(); break;
            case 2: l.insert(); break;
            case 3: l.Delete(); break;
            case 4: l.display(); break;
            case 5: exit(0); break;
            default: cout<<"Please enter valid choice!"<<endl; 
        }
    }while(ch!=5);
    
    return 0;
}