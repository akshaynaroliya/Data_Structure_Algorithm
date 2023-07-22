#include<iostream> 

using namespace std;


class Node{

    public: 
    
    Node *start=NULL;
    Node *add;
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
            start->add=NULL;
            
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
                temp->add=New;
                New->add=NULL;

                temp=New;
                
                cout<<"Do you want more elements? Press 'y' if yes else 'n'"<<endl;
                cin>>choice;
                
                count++;
            
            }
        }
    }
    
    //inserting the data into the list
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
                
                if(pos==1){
                    New->add=start;
                    start=New;
                    
                    temp=start;
                }
                else if(pos==count+1){
                    temp = start;
                    while(temp->add!=NULL){
                        temp=temp->add;
                    }
                    temp->add=New;
                    New->add=NULL;
                }
                else{
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
    }
    
    //deleting data
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
                if(pos==1){
                    temp=start;
                    cout<<"Deleted element is: "<<temp->data<<endl;
                    start=start->add;
                    free(temp);
                }
                else if(pos==count){
                    temp=start;
                    while(temp->add->add!=NULL){
                        temp=temp->add;
                    }
                    cout<<"Deleted element: "<<temp->add->data<<endl;
                    free(temp->add);
                    temp->add=NULL;
                    
                }
                else{
                    temp=start;
                    while(i<pos-1){
                        temp=temp->add;
                        i++;
                    }
                    cout<<"Deleted element: "<<temp->add->data<<endl;
                    Node *t=temp->add;
                    temp->add=temp->add->add;
                    free(t);
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
                temp=temp->add;
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
