#include <iostream>
#include <cassert>
#include <string>
using namespace std;

template <typename T>
class node
{
  public:
    node(T item, node *nxt = nullptr)
    {
        itm = item;
        next = nxt;
    }

  private:
    T itm;
    node<T> *next;
    template <typename U> friend class myStack;
};

template <typename T>
class myStack
{

  public:
    myStack<T>()
    {
        topItem = nullptr;
    }
    // creating copy constructor
    // to avoid duplicate stack copies in memory
    myStack(const myStack &ref)
    {   
        cout << "calling copy constructor" << endl;
        // ref to refernce of the stack object
        // copy the ref rather than copy by value
        node<T> *tmpFirst;
        node<T> *tmpLast;
        if (ref.empty())
        {
            topItem = nullptr;
        }
        else
        {
            tmpFirst = tmpLast = new node<T>(ref.topItem->itm);
            //iterate through ref and copy and assign it to topItem
            for (node<T> *tmp = ref.topItem->next; tmp != nullptr; tmp = tmp->next)
            {
                tmpLast->next = new node<T>(tmp->itm);
                tmpLast = tmpLast->next;
            }
            topItem = tmpFirst;
            // dont we have to delete it here???
            // if u delete tmpFirst ref is gone
            // delete tmpLast;
        }
    }

    // destructor

    ~myStack(){
        cout << "calling destructor" << endl;
        cout << this << endl;
        clear();
    }
    
    void push(T item)
    {
        // insert an item in the begining of the list and move the old topitem to next to new top item
        topItem = new node<T>(item, topItem);
        cout << "inserting" << item << endl;
    }

    T peek() const
    {
        // if stack is empty, we throw an error and program exits
        assert(topItem != nullptr);
        return topItem->itm;
    }

    void pop()
    {
        // this should remove the current topItem and point topiten to the one next to topitem
        assert(topItem != nullptr);
        // get the current topItem ref to delete it later from memory
        node<T> *temp = topItem;
        topItem = topItem->next;
        delete temp;
    }

    bool empty() const
    {
        // add const if the fun doesn't manipulate anything inside it's body
        return topItem == nullptr;
    }

    void print() const
    {
        node<T> *tmp = topItem;
        while (tmp != nullptr)
        {
            cout << tmp->itm << ",";
            tmp = tmp->next;
        }
    }
    void clear(){
        // delete each item by traversing
        while(topItem != nullptr){
            node<T>* doomed = topItem;
            topItem = topItem->next;
            delete doomed;
        }
    }

    void copy(const myStack& ref){
        node<T>* first; node<T>* last;
        if(ref.empty()){
            topItem = nullptr;
        }else{
            first = last = new node<T>(ref.topItem->itm);
            for(node<T>* tmp = ref.topItem->next; tmp!=nullptr ; tmp = tmp->next){
                last->next = new node<T>(ref.topItem->itm);
                last = last->next;
            }
            topItem = first;
        }
    }

    myStack& operator= (const myStack& rhs){
        cout << "operator = overloaded" << endl;
        // while using assignement operator 
        // if the rhs already has some data, it needs to be cleared
        // if a = a is given, it will clear a and the data in a is lost, so we avoid clearing if the same ref is passed
        if(this != &rhs){
            clear();
            copy(rhs);
        }
        return *this;
    }

  private:
    node<T> *topItem;
};

void funB(myStack<int> dupStk)
{
    // this is pass by value
    // dupstk is created in runtimestack and disposed off after the fn execution
    // creates a memory leak , as the copy would be some where in the memory 
    // and is never cleared as the ref to it is lost.
    dupStk.push(50);
    dupStk.push(60);
}

// int main(int count, char *argv[])
// {
//     myStack<int> st;
//     cout << "address of st " << &st << endl;
//     st.push(10);
//     st.push(20);
//     st.push(30);
//     st.push(40);
//     //funB(st);
//     st.print();
//     cout << endl;
//     cout << boolalpha << st.empty() << endl;
//     cout << st.peek() << endl;

//     // testing operator overloading
//     // myStack hold = st; doesnt call the operator = as its construction but not assignment.
//     myStack<int> hold;
//     cout << "address of hold " << &hold << endl;
//     // this calls the operator over riding
//     hold = st;

//     myStack<string> str ;
//     str.push("preetham");
//     str.push("kushal");
//     str.push("dinesh");
//     str.push("kaushik");
//     str.print();
    
// }

