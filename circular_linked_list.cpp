#include<iostream>

using namespace std;

class Node{
    
    public:
    
    int data;
    int n;
    int count=0;
    Node *start=NULL;
    Node *temp;
    Node *New;
    Node *add;
    
    void create(){
        if(start!=NULL){
            cout<<"List already created!"<<endl;
        }
        else{
            cout<<"Enter your element: ";
            cin>>n;
            start=new Node();
            start->data=n;
            start->add=start;
            
            temp=start;
            count++;
            
            char choice;
            cout<<"Do you want to enter more element? if yes press 'y' else 'n'"<<endl;
            cin>>choice;
            
            while(choice=='y' || choice=='Y'){
                cout<<"Enter your element: ";
                cin>>n;
                New=new Node();
                temp->add=New;
                New->data=n;
                New->add=start;
                
                temp=New;
                count++;
                
                cout<<"Do you want to enter more element? if yes press 'y' else 'n'"<<endl;
                cin>>choice;
            }
            
        }
    }
    
    void insert(){
        int pos;
        cout<<"Enter postition to insert: "<<endl;
        cin>>pos;
        if(pos>count+1 || pos<=0){
            cout<<"Position should be greater than zero or less than and equal to "<<count+1<<endl;
        }
        else{
            cout<<"Enter your data: ";
            cin>>n;
            New=new Node();
            New->data=n;
            
            if(pos==1){
                temp=start;
                while(temp->add!=start){
                    temp=temp->add;
                }
                temp->add=New;
                New->add=start;
                start=New;
            }
            else if(pos==count+1){
                temp=start;
                while(temp->add!=start){
                    temp=temp->add;
                }
                temp->add=New;
                New->add=start;
            }
            else{
                int i=1;
                temp=start;
                while(i<pos-1){
                    temp=temp->add;
                    i++;
                }
                New->add=temp->add;
                temp->add=New;
            }
            
            count++;
        }
    }
    
    void Delete(){
        if(start==NULL){
            cout<<"List not created, create a list first!"<<endl; 
        }
        else{
            int pos;
            cout<<"Enter position to delete: "<<endl;
            cin>>pos;
            if(pos>count || pos<=0){
                cout<<"Position should be greater than zero or less than and equal to "<<count+1<<endl;
            }
            else{
                if(start->add==start){
                    start=NULL;
                }
                else if(pos==1){
                    Node *d=start;
                    cout<<"Deleted element is: "<<d->data<<endl;
                    temp=start;
                    while(temp->add!=start){
                        temp=temp->add;
                    }
                    start=start->add;
                    temp->add=start;
                    delete d;
                }
                else if(pos==count){
                    temp=start;
                    while(temp->add->add!=start){
                        temp=temp->add;
                    }
                    Node *d=temp->add;
                    temp->add=start;
                    cout<<"Deleted element is: "<<d->data<<endl;
                    delete d;
                }
                else{
                    int i=1;
                    temp=start;
                    while(i<pos-1){
                        temp=temp->add;
                        i++;
                    }
                    Node *d=temp->add;
                    temp->add=temp->add->add;
                    cout<<"Deleted element "<<d->data<<endl;
                    delete d;
                }
                count--;
            }
        }
    }
    
    void display(){
        if(start==NULL){
            cout<<"List does not exist!"<<endl;
        }
        else{
            temp=start;
            do{
                cout<<temp->data<<"  ";
                temp=temp->add;
            }while(temp!=start);
            cout<<endl;
        }
    }
    
};

int main(){
    
    Node l;
    
    int ch=0;
    
    do{
        cout<<"Press 1 for create "<<endl;
        cout<<"Press 2 for insert "<<endl;
        cout<<"Press 3 for Delete "<<endl;
        cout<<"Press 4 for display "<<endl;
        cout<<"Press 5 for exit "<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;
        switch(ch){
            case 1: l.create(); break;
            case 2: l.insert(); break;
            case 3: l.Delete(); break;
            case 4: l.display(); break;
            case 5: exit(0); break;
            default: cout<<"You entered invalid choice!"<<endl; break;
        }
    }while(ch!=5);
    
    return 0;
}
