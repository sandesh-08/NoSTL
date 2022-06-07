#include<bits/stdc++.h>
using namespace std;

struct Node {
    private:
        int data;
        Node* next;
    
    public:
        Node(int num) {
            this->data=num;
            this->next=NULL;
        }
        Node(Node& x) {
            this->data=x.data;
            this->next=x.next;
        }
        void addLast(Node* root,int num) {
            while(root->next) root=root->next;
            root->next=new Node(num);
        }
        void removeLast(Node* root) {
            if(!root->next) {
                root=NULL;
                return ;
            }
            while(root->next->next) root=root->next;
            root->next=NULL;
        }
        void addFirst(Node* root,int num) {
            Node* n_head=new Node(num);
            n_head->next=root;
            root=n_head;
        }
        void removeFirst(Node* root) {
            if(!root->next) root=NULL;
            else root=root->next;
        }
        void addIn(Node* root,int num,int ind) {
            if(ind==0) {
                addFirst(root,num);
                return ;
            }
            bool added=0;
            for(int i=0;i<ind-1;i++) {
                if(root->next) root=root->next;
                else break ;
            }
            if(root->next) {
                Node* nxt=root->next;
                root->next=new Node(num);
                root=root->next;
                root->next=nxt;
                return ;
            }
            root->next=new Node(num);
        }
        void removeFrom(Node* root,int num,int ind) {
            if(ind==0) {
                addFirst(root,num);
                return ;
            }
            bool added=0;
            for(int i=0;i<ind-1;i++) {
                if(root->next) root=root->next;
                else break ;
            }
            if(root->next) {
                Node* nxt=root->next;
                root->next=new Node(num);
                root=root->next;
                root->next=nxt;
                return ;
            }
            root->next=new Node(num);
        }
};

int main() {

}