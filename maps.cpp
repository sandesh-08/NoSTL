#include<bits/stdc++.h>
using namespace std;

struct Node {
    private:
        int key;
        int data;
        Node *left,*right;
    public:
        Node(int key,int data) {
            this->key=key;
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
        Node(Node& node) {
            this->key=node.key;
            this->data=node.data;
            this->left=node.left;
            this->right=node.right;
        }

        void print(Node* root) {
            if(!root) return ;
            print(root->left);
            cout<<root->key<<": "<<root->data<<" ";
            print(root->right);
        }

        Node* add(Node* root,int key,int data) {
            if(!root) {
                Node* newNode= new Node(key,data);
                return newNode;
            }
            if(root->key>key) {
                root->left=add(root->left,key,data);
                return root;
            }
            else if(root->key<key) {
                root->right=add(root->right,key,data);
                return root;
            }
            else {
                root->data=data;
                return root;
            }
        }

        Node* maxLeft(Node* root) {
            while(root->right) root=root->right;
            return root;
        }

        Node* deleteNode(Node* root,int key) {
            if(!root) return root;
            if(root->key>key) root->left=deleteNode(root->left,key);
            else if(root->key<key) root->right=deleteNode(root->right,key);
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
                    Node* maxi=maxLeft(root->left);
                    root->data=maxi->data;
                    root->key=maxi->key;
                    root->left=deleteNode(root->right,maxi->key);
                    return root;
                }
            }
            return root;
        }

        bool find(Node *root,int key) {
            if(!root) return 0;
            if(root->key==key) return 1;
            if(key>root->key) return find(root->right,key);
            return find(root->left,key);
        }

        int getData(Node *root,int key) {
            if(!root) return 0;
            if(root->key==key) return root->data;
            if(key>root->key) return getData(root->right,key);
            return getData(root->left,key);
        }
};

class Map {
    private:
        Node* root;

    public: 
        Map() {
            root=NULL;
        }
        Map(Map& copySet) {
            this->root=copySet.root;
        }
        void put(int key,int num) {
            root=root->add(root,key,num);
        }
        void display() {
            cout<<"{ ";
            root->print(root);
            cout<<" }\n";
        }
        void remove(int key) {
            if(!root->find(root,key)) return ;
            root=root->deleteNode(root,key);
        }
        bool search(int key) {
            return (root->find(root,key));
        }
        int get(int key) {
            if(!root->find(root,key)) return 0;
            return root->getData(root,key);
        }
};

int main() {
    Map mp;
    for(int i=1;i<=5;i++) mp.put(i,i);
    mp.display();
    cout<<mp.get(5)<<"\n";
    mp.put(5,10);
    cout<<mp.get(5)<<"\n";
    mp.display();
    for(int i=1;i<=5;i++) {
        mp.remove(i);
        mp.display();
    }
    mp.remove(10);
}