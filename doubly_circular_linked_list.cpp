#include<iostream>

using namespace std;

class Node{

    public:

    int data;
    int pos;
    int count=0;
    Node *start=NULL;
    Node *ladd;
    Node *radd;
    Node *temp;
    Node *New;
    
    void create(){
        if(start!=NULL){
            cout<<"List  already created!"<<endl;
        }
        else{
            int n;
            start=new Node();
            cout<<"Enter element: ";
            cin>>n;
            start->data=n;
            start->ladd=start;
            start->radd=start;

            temp=start;
            count++;

            cout<<"If you want to enter more elements press 'y' otherwise 'n'"<<endl;
            char ch;
            cin>>ch;
            while(ch=='y' || ch=='Y') {
                cout<<"Enter element: ";
                cin>>n;
                New=new Node();
                New->data=n;
                start->ladd=New;
                New->radd=start;
                New->ladd=temp;
                temp->radd=New;

                temp=New;

                cout<<"If you want to enter more elements press 'y' otherwise 'n'"<<endl;
                cin>>ch;

                count++;
            }
        }
    }

    void insert(){
        if(start==NULL){
            cout<<"List not created!"<<endl;
        }
        else{
            cout<<"Enter position to insert: ";
            cin>>pos;
            if(pos>count+1){
                cout<<"Invalid position, position should be greater than 0 and less than or equal to "<<count+1<<endl;
            }
            else{
                temp=start;
                int n;
                cout<<"Enter element: ";
                cin>>n;
                New=new Node();
                New->data=n;

                if(pos==1){
                    New->ladd=start->ladd;
                    start->ladd->radd=New;
                    start->ladd=New;
                    New->radd=start;

                    start=New;

                }
                else if(pos==count+1){
                    New->ladd=start->ladd;
                    New->radd=start;
                    start->ladd->radd=New;
                    start->ladd=New;
                }
                else{
                    temp=start;
                    int i=2;
                    while(i<pos){
                        temp=temp->radd;
                        i++;
                    }
                    New->ladd=temp;
                    New->radd=temp->radd;
                    temp->radd->ladd=New;
                    temp->radd=New;
                }

                count++;
            }
        }
    }
    
    void Delete(){
        if(start==NULL){
            cout<<"List not created, create a list first!"<<endl;
        }
        else{
            cout<<"Enter position to delete: ";
            cin>>pos;
            if(pos>count){
                cout<<"Invalid position, position should be greater than 0 and less than or equal to "<<count<<endl;
            }
            else{
                temp=start;

                if(start->radd==start){
                    cout<<"Deleted data: "<<start->data<<endl;
                    start=NULL;
                }
                else if(pos==1){
                    start=start->radd;
                    start->ladd=temp->ladd;
                    temp->ladd->radd=start;
                    cout<<"Deleted Data: "<<temp->data<<endl;
                    delete temp;
                }
                else if(pos==count){
                    temp=start->ladd;
                    cout<<"Deleted data: "<<temp->data<<endl;
                    start->ladd->ladd->radd=start;
                    start->ladd=temp->ladd; 
                    delete temp;
                }
                else{
                    int i=1;
                    while(i<pos){
                        temp=temp->radd;
                        i++;
                    }
                    temp->radd->ladd=temp->ladd;
                    temp->ladd->radd=temp->radd;
                    cout<<"Deleted element: "<<temp->data<<endl; 
                    delete temp;
                }

                count--; 
            }
        }
    }
    
    void display() {
        if(start==NULL){
            cout<<"List doest not exist!"<<endl;
        }
        else{
            temp=start;
            do{
                cout<<temp->data<<"  ";
                temp=temp->radd;
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
