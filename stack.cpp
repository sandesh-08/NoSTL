#include<bits/stdc++.h>
using namespace std;

class Stack {
    private:
        int top;
        vector<int> arr;

    public:
        Stack() {
            this->top=-1;
        }
        Stack(Stack& st) {
            this->top=st.top;
            for(int i=0;i<st.top;i++) {
                this->arr[i]=st.arr[i];
            }
        }
        void push(int num) {
            if(top==99) {
                cout<<"STACK IS FULL\n";
                return ;
            }
            top++;
            arr[top]=num;
        }
        void pop() {
            if(this->top==-1) {
                cout<<"STACK IS EMPTY\n";
                return ;
            }
            this->top--;
        }
        bool empty() {
            if(this->top==-1) return 1;
            return 0;
        }
        int peek() {
            if(empty()) {
                cout<<"STACK IS EMPTY\n";
                return INT_MIN;
            }
            return arr[top];
        }
        void display() {
            for(int i=0;i<=top;i++) cout<<arr[i]<<" ";
            cout<<"\n";
        }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    st.display();
    cout<<st.peek()<<"\n";
    st.push(40);
    st.push(50);
    st.push(60);
    st.display();   
}