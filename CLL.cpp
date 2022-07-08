#include<iostream>
using namespace std;

class CLL{
     struct Node{
         int data;
         Node *next;
     }*start;

     //default constructor
     public:
     CLL(){
         start=NULL;
     }
     
     void create();
     void insert_beg();
     void insert_end();
     void insert_pos(int pos);
     void delete_beg();
     void delete_end();
     void display();
};

int main(){
    CLL lst;
    lst.create();
    lst.display();
    lst.delete_beg();
    // lst.display();
    // lst.delete_end();
    lst.display();
}

//creating CLL
void CLL::create(){
    cout<<"Enter numbers:"<<" ";
    int num;
    cin>>num;
    Node *temp;
    while(num!=-1){
        struct Node *ptr=new Node;
        if(start==NULL){
            start=ptr;
            ptr->data=num;
            ptr->next=start;
            temp=start;
        }
        else{
             ptr->data=num;
             ptr->next=start;
            //  start->next=ptr;
             start=ptr;
             temp->next=start;
            
        }
        cin>>num;
        // start->next=temp;
        
    }

}
void CLL::delete_beg(){
       if(start==NULL){
           cout<<"Empty list"<<endl;
           return;
       }
     // struct Node *first=start;
      struct Node *second=start->next;
      while(second->next!=start){
          second=second->next;
      }
      second->next=start->next;
      start=start->next;
    
      

}

void CLL::delete_end(){
    if(start==NULL){
        cout<<"Empty list"<<endl;
           return;
    }
    struct Node *last=start;
    while(last->next->next!=start){
        last=last->next;
    }
    last->next=start;

    
}
void CLL::display(){
    Node *ptr=start;
    while(ptr->next!=start){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data;
    cout<<endl;
}