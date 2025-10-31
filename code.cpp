#include<iostream>
using namespace std;

struct Patient{
    int patientID;
    Patient *prev;
    Patient *next;
};

class ERQueue{
    public:
    Patient *head;
    Patient *tail;
    
    ERQueue(){
        head=NULL;
        tail=NULL;
    }
    
    // insert at beginning function
    void insertAtBeginning(int id){
        Patient *newNode = new Patient;
        newNode->patientID = id;
        newNode->prev = NULL;
        newNode->next = NULL;
        
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        cout<<"Patient "<<id<<" added at beginning"<<endl;
    }
    
    // insert at end function
    void insertAtEnd(int id){
        Patient *newNode = new Patient;
        newNode->patientID = id;
        newNode->prev = NULL;
        newNode->next = NULL;
        
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        cout<<"Patient "<<id<<" added at end"<<endl;
    }
    
    // insert at specific position
    void insertAtPosition(int id, int pos){
        if(pos==1){
            insertAtBeginning(id);
            return;
        }
        
        Patient *newNode = new Patient;
        newNode->patientID = id;
        
        Patient *temp = head;
        int count=1;
        
        while(temp!=NULL && count<pos-1){
            temp=temp->next;
            count++;
        }
        
        if(temp==NULL || temp->next==NULL){
            insertAtEnd(id);
            return;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        
        cout<<"Patient "<<id<<" inserted at position "<<pos<<endl;
    }
    
    // delete from beginning
    void deleteFromBeginning(){
        if(head==NULL){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        
        Patient *temp = head;
        int id = temp->patientID;
        
        if(head==tail){
            head=NULL;
            tail=NULL;
        }
        else{
            head=head->next;
            head->prev=NULL;
        }
        
        delete temp;
        cout<<"Patient "<<id<<" removed"<<endl;
    }
    
    void display(){
        if(head==NULL){
            cout<<"Empty queue"<<endl;
            return;
        }
        Patient *temp=head;
        cout<<"Queue: ";
        while(temp!=NULL){
            cout<<temp->patientID;
            if(temp->next!=NULL)
                cout<<" <-> ";
            temp=temp->next;
        }
        cout<<endl;
    }
    
    void displayReverse(){
        if(tail==NULL){
            cout<<"Empty queue"<<endl;
            return;
        }
        Patient *temp=tail;
        cout<<"Reverse: ";
        while(temp!=NULL){
            cout<<temp->patientID;
            if(temp->prev!=NULL)
                cout<<" <-> ";
            temp=temp->prev;
        }
        cout<<endl;
    }
};

int main(){
    ERQueue q;
    
    cout<<"Hospital ER Queue System"<<endl;
    cout<<"========================"<<endl<<endl;
    
    cout<<"Step 1:"<<endl;
    q.insertAtEnd(101);
    q.display();
    cout<<endl;
    
    cout<<"Step 2:"<<endl;
    q.insertAtEnd(102);
    q.display();
    cout<<endl;
    
    cout<<"Step 3:"<<endl;
    q.insertAtBeginning(200);
    q.display();
    cout<<endl;
    
    cout<<"Step 4:"<<endl;
    q.insertAtPosition(150,2);
    q.display();
    cout<<endl;
    
    cout<<"Step 5:"<<endl;
    q.deleteFromBeginning();
    q.display();
    cout<<endl;
    
    cout<<"Step 6:"<<endl;
    q.insertAtEnd(300);
    q.display();
    cout<<endl;
    
    cout<<"Final Answers:"<<endl;
    cout<<"a) Head: "<<q.head->patientID<<endl;
    cout<<"b) Tail: "<<q.tail->patientID<<endl;
    cout<<"c) ";
    q.display();
    cout<<"d) ";
    q.displayReverse();
    
    return 0;
}