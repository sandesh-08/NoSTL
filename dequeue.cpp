#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
        int data;
        Node *back,*next;
        Node() {
            this->data=INT_MIN;
            this->back=NULL;
            this->next=NULL;
        }
        Node(int num) {
            this->data=num;
            this->back=NULL;
            this->next=NULL;
        }
        Node(Node& x) {
            this->data=x.data;
            this->back=x.back;
            this->next=x.next;
        }
};

class Dequeue {
    private:
        Node* front;
        Node* rear;
        int sz;

    public:
        Dequeue() {
            this->sz=0;
            this->rear=this->front;
        }
        void pushFront(int num) {
            if(this->sz==0) {
                rear=new Node(num);
                front=rear;
                sz++;
                return ;
            }
            Node* add=new Node(num);
            front->next=add;
            add->back=front;
            front=add;
            sz++;
        }
        void pushBack(int num) {
            if(this->sz==0) {
                rear=new Node(num);
                front=rear;
                sz++;
                return ;
            }
            Node* add=new Node(num);
            add->next=rear;
            rear->back=add;
            rear=add;
            sz++;
        }
        void popFront() {
            if(front==NULL) {
                cout<<"QUEUE IS EMPTY\n";
                return ;
            }
            sz--;
            if(front==rear) {
                front=NULL;
                rear=NULL;
                return ;
            }
            Node* bck=front->back;
            bck->next=NULL;
            delete front;
            front=bck;
        }
        void popBack() {
            if(front==NULL) {
                cout<<"QUEUE IS EMPTY\n";
                return ;
            }
            sz--;
            if(front==rear) {
                front=NULL;
                rear=NULL;
                return ;
            }
            Node* nxt=rear->next;
            nxt->back=NULL;
            delete rear;
            rear=nxt;
        }
        void display() {
            if(sz==0) {
                cout<<"QUEUE IS EMPTY\n";
                return ;
            }
            Node* cpy=front;
            while(cpy) {
                cout<<cpy->data<<"->";
                cpy=cpy->back;
            }
            cout<<"\n";
        }
        int size() {
            return this->sz;
        }
};

int main() {
    Dequeue q;
    q.pushFront(10);
    q.pushFront(20);
    q.display();
    q.pushBack(30);
    q.pushBack(40);
    q.display();
    q.popFront();
    q.display();
    q.popBack();
    q.display();
    q.popFront();
    q.display();
    q.popBack();
    q.display();
    q.popBack();
    q.display();
    q.popFront();
    q.display();
}