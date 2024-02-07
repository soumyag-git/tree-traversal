#include <iostream>

using namespace std;

class rnode{
     public:
     int data;
     rnode *left;
     rnode *right;
};


class node {
    public:
    rnode *data;
    node *next;
};



class queue{
    node *front,*rear;
    public:
    queue(){
        front =rear=NULL;
    }
    void enqueue(rnode *l);
    rnode  *dequeue();
    void display();
    int isempty();


};


void queue::enqueue(rnode *l)
{
    node *t=new node ;
    t->data=l;
    t->next=NULL;
    if(front== NULL){
        front=rear=t;
    }
    else{
        rear->next=t;
        rear=t;
    }
}

rnode *queue::dequeue(){

    node *t = new node ;
    t=front;
    if(front ==NULL){
        cout<<"queue is null";
    }
    else{
    t->data=front->data;
    front =front->next;
    // cout<<"queue is deleted"<<"\n";
    }
    return t->data;
}

int queue::isempty(){
    if(front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}


void create(){
    rnode *p,*t;
    int x;
    queue q;
    rnode *root;
    root =new rnode;
    cout<<"Enter the value of root : ";
    cin>>x;
    root->data=x;
    q.enqueue(root);
    while(!q.isempty()){
        p=q.dequeue();
        cout<<"Enter Left child: ";
        cin>>x;
        if(x!=-1){
            t=new rnode;
            t->data=x;
            t->left=t->right=NULL;
            p->left=t;
            q.enqueue(t);
        }

        cout<<"Enter right child: ";
        cin>>x;
        if(x!=-1){
            t=new rnode;
            t->data=x;
            t->left=t->right=NULL;
            p->right=t;
            q.enqueue(t);
        }
    }
    cout<<"Travesal has been completed sucessfully";
}

int main(){
    create();
}