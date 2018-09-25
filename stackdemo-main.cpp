#include <iostream>
#include <string>
// where does it search, need to include any path?
#include "stack.h"

int main(int count, char* argv[]){
    myStack<string> st;
    st.push("Preetham");
    st.push("Kushal");
    st.push("Dinesh");
    st.push("Kaushik");
    st.print();
}
