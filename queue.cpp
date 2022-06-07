#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
        int data;
        Node* back;
        Node() {
            this->data=INT_MIN;
            this->back=NULL;
        }
        Node(int num) {
            this->data=num;
            this->back=NULL;
        }
        Node(Node& x) {
            this->data=x.data;
            this->back=x.back;
        }
};

class Queue {
    private:
        Node* front;
        Node* rear;
        int sz;

    public:
        Queue() {
            this->sz=0;
            this->rear=this->front;
        }
        void push(int num) {
            if(this->sz==0) {
                rear=new Node(num);
                front=rear;
                sz++;
                return ;
            }
            rear->back=new Node(num);
            rear=rear->back;
            sz++;
        }
        void pop() {
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
            delete front;
            front=bck;
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
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
}