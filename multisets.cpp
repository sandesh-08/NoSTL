#include<bits/stdc++.h>
using namespace std;

struct Node {
    private:
        int data;
        int cnt;
        Node *left,*right;
    public:
        Node(int val) {
            this->data=val;
            this->cnt=1;
            this->left=NULL;
            this->right=NULL;
        }

        void print(Node* root) {
            if(!root) return ;
            print(root->left);
            for(int i=0;i<root->cnt;i++) cout<<root->data<<" ";
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
            else {
                root->cnt=1+root->cnt;
                return root;
            }
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
                root->cnt--;
                if(root->cnt==0) {
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

class MultiSet {
    private:
        Node* root;
        int sz;

    public: 
        MultiSet() {
            root=NULL;
            sz=0;
        }
        MultiSet(MultiSet& copyMultiSet) {
            this->root=copyMultiSet.root;
            this->sz=copyMultiSet.sz;
        }
        void insert(int num) {
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
        bool search(int num) {
            return (root->find(root,num));
        }
};

int main() {
    MultiSet st;
    st.insert(10);
    st.display();
    st.insert(10);
    st.display();
    st.insert(10);
    st.display();
    st.insert(10);
    st.insert(5);
    st.display();
    cout<<st.size()<<"\n";
    st.remove(5);
    st.display();
    cout<<st.size()<<"\n";
    cout<<st.search(10)<<"\n";
    cout<<st.search(10000)<<"\n";
}