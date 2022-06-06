#include<bits/stdc++.h>
using namespace std;

struct Node {
    private:
        int data;
        Node *left,*right;
    public:
        Node(int val) {
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }

        void print(Node* root) {
            if(!root) return ;
            print(root->left);
            cout<<root->data<<" ";
            print(root->right);
        }

        Node* add(Node* root,int num) {
            if(!root) {
                Node* newNode= new Node(num);
                return newNode;
            }
            if(root->data>num) {
                root->left=add(root->left,num);
                return root;
            }
            else if(root->data<num) {
                root->right=add(root->right,num);
                return root;
            }
            else return root;
        }

        int maxLeft(Node* root) {
            while(root->right) root=root->right;
            return root->data;
        }

        Node* deleteNode(Node* root,int num) {
            if(!root) return root;
            if(root->data>num) root->left=deleteNode(root->left,num);
            else if(root->data<num) root->right=deleteNode(root->right,num);
            else {
                if(!root->left && !root->right) {
                    delete root;
                    return NULL;
                }
                else if(!root->left) {
                    Node* ret=root->right;
                    delete root;
                    return ret;
                }
                else if(!root->right) {
                    Node* ret=root->left;
                    delete root;
                    return ret;
                }
                else {
                    int maxi=maxLeft(root->left);
                    root->data=maxi;
                    root->left=deleteNode(root->right,maxi);
                    return root;
                }
            }
            return root;
        }

        bool find(Node *root,int num) {
            if(!root) return 0;
            if(root->data==num) return 1;
            if(num>root->data) return find(root->right,num);
            return find(root->left,num);
        }
};

class Set {
    private:
        Node* root;
        int sz;

    public: 
        Set() {
            root=NULL;
            sz=0;
        }
        Set(Set& copySet) {
            this->root=copySet.root;
            this->sz=copySet.sz;
        }
        void insert(int num) {
            if(root->find(root,num)) return ;
            root=root->add(root,num);
            this->sz++;
        }
        void display() {
            cout<<"{ ";
            root->print(root);
            cout<<" }\n";
        }
        void remove(int num) {
            if(!root->find(root,num)) return ;
            root=root->deleteNode(root,num);
            this-sz--;
        }
        int size() {
            return this->sz;
        }
};

int main() {
    Set st;
    st.insert(10);
    st.insert(100);
    st.insert(5);
    st.insert(4);
    st.insert(5);
    st.display();
    cout<<st.size()<<"\n";
    st.remove(5);
    st.display();
    cout<<st.size()<<"\n";
}