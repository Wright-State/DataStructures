#include <iostream>
#include <cassert>
using namespace std;

class node{
    public:
        node(int item, node* nxt=nullptr){
            itm = item;
            next = nxt;
        }
    private:
        int itm;
        node* next;
    friend class myStack;
};

class myStack{

    public:
        myStack(){
            topItem = nullptr;
        }

        void push(int item){
            // insert an item in the begining of the list and move the old topitem to next to new top item
            topItem = new node(item, topItem);
            cout << "inserting" << item << endl;
        }

        int peek() const{
            // if stack is empty, we throw an error and program exits
            assert(topItem != nullptr);
            return topItem->itm;
        }

        void pop(){
            // this should remove the current topItem and point topiten to the one next to topitem
            assert(topItem !=  nullptr);
            // get the current topItem ref to delete it later from memory
            node* temp = topItem;
            topItem = topItem->next;
            delete temp;
        }

        bool empty() const{ 
            // add const if the fun doesn't manipulate anything inside it's body
            return topItem == nullptr;
        }

        void print() const{
            node* tmp = topItem;
            while(tmp != nullptr){
                cout << tmp->itm << ",";
                tmp = tmp->next;
            }

        }
    private:
        node* topItem;

};



int main(int count, char* argv[]){
    myStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.print();
    cout << endl;
    cout << boolalpha << st.empty() <<endl;
    cout << st.peek() << endl;
}
