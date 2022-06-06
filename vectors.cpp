#include<bits/stdc++.h>
using namespace std;

class Vector {
    private:
        int *vect;
        int indexPtr;
        int capacity;
    public:
        Vector() {
            this->vect = new int[1];
            this->indexPtr=0;
            this->capacity=1;            
        }

        void display() {
            for(int i=0;i<indexPtr;i++) cout<<vect[i]<<" ";
            cout<<"\n";
        }

        void push(int data) {
            if(indexPtr==capacity) {
                int *tmp = new int[2*capacity];
                for(int i=0;i<capacity;i++) tmp[i]=vect[i];
                delete [] vect;
                vect=tmp;
                capacity*=2;
            }
            vect[indexPtr++]=data;
        }

        void push(int data,int ind) {
            if(ind>capacity) {
                cout<<"Out of bound\n";
                return ;
            }
            if(ind==capacity) push(data);
            else vect[ind]=data;
        }

        int get(int ind) {
            if(ind<indexPtr) return vect[ind];
            return -1;
        }

        int size() {
            return indexPtr;
        }

        int totalCapacity() {
            return capacity;
        }

        void pop() {
            indexPtr--;
        }
};

int main() {
    Vector vect;
    vect.push(10);
    vect.push(20);
    vect.push(30);
    vect.push(40);
    vect.push(10);
    cout<<vect.get(3)<<"\n";
    cout<<vect.size()<<"\n";
    vect.display();
    vect.pop();
    vect.display();
}