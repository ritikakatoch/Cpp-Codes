#include<iostream>
using namespace std;

class LL{
     struct Node{
       int info;
       Node *next;
     }*start=NULL;

     public:
     
     void create();
     void move_pos();
     void show();
};
int main(){
    LL lst;
    lst.create();
  //  lst.move_pos();
    lst.show();
}

void LL::create(){
    cout<<"Enter elements;";
    int num;
    cin>>num;
    while(num!=-1){
        struct Node *ptr=new Node;
        ptr->info=num;
        ptr->next=start;
        start=ptr;
    }
}

void LL::move_pos(){
    int max=0;
    int min=0;
    
    
    struct Node *ptr=start;
    if(start==NULL){
        return;
    }
    struct Node *save1=start;
    struct Node *save2=start;

    while(ptr!=NULL){
        if(ptr->next->info<min){
            min=ptr->next->info;
            save1=ptr;
            
        }
        if(ptr->info>max){
            max=ptr->next->info;
            save2=ptr;
        }
        ptr=ptr->next;

    }
    save1->next=save1->next->next;
    save2->next=save2->next->next;

    struct Node *first=new Node;
    first->info=min;
    first->next=start;
    start=first;

    struct Node *last=start;
    while(last->next!=NULL){
        last=last->next;
    }
    struct Node *last_el=new Node ;
    last_el->info=max;
    last->next=NULL;

    last->next=last_el;
    

}

void LL::show(){
    if(start==NULL){
        cout<<"Empty LL"<<endl;
        return;

    }
    struct Node *head=start;
    cout<<"Display LL:";
    while(head!=NULL){
        cout<<head->info<<" ";
        head=head->next;
    }
}