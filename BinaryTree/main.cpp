#include <iostream>

using namespace std;

template<typename T>
class tnode {
public:
    tnode(T d, tnode *l = nullptr, tnode *r = nullptr) {
        data = d;
        left = l;
        right = r;
    }

    template<typename U> friend
    class BTree;

private:
    T data;
    tnode<T> *left;
    tnode<T> *right;
};


template<typename T>
class BTree {
public:
    BTree() {
        mRoot = nullptr;
    }

    BTree(T data) {
        mRoot = new tnode<T>(data, nullptr, nullptr);
    }

    BTree(T data, const BTree &tLeft, const BTree &tRight) {
        mRoot = new tnode<T>(data, tLeft.mRoot, tRight.mRoot);
    }

    void preOrder() {
        preOrder(mRoot);
    }

    void postOrder() {
        postOrder(mRoot);
    }

    void inOrder() {
        inOrder(mRoot);
    }

private:
    void preOrder(tnode<T> *root) {
        // root, left and right
        // termination condition or base case
        if (root != nullptr) {
            cout << root->data << endl;
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(tnode<T> *root) {
        //left right root
        if (root != nullptr) {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << endl;
        }
    }

    void inOrder(tnode<T> *root) {
        //left, root , right
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->data << endl;
            inOrder(root->right);

        }
    }

private:
    tnode<T> *mRoot;

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    BTree<int> t1(10), t2(20);
    BTree<int> t3(30, t1, t2);
    //30, 10, 20
    cout << "PreOrder" << endl;
    t3.preOrder();
    //10, 20, 30
    cout << "PostOrder" << endl;
    t3.postOrder();
    //10, 30, 20
    cout << "inOrder" << endl;
    t3.inOrder();
    return 0;
}
