#include <iostream>
#include <list>
using namespace std;

list<int> newlist;

class SetIterator {

    private:
        list<int> iter;

    public:

        SetIterator (list<int> elements) {iter = elements;}
        bool hasNext()
        {
            if(iter.empty())
                return false;
            else {return true;}
        }

        int getNext()
        {
            int x = iter.front();
            iter.pop_front();
            return x;
        }


        int length()
        {
            if(!hasNext())
                return 0;
            else
            {
                int a = getNext();
                return 1+length();
            }
        }

        int get(int n)
        {
            if(!hasNext())
            {
                cout << "No element at position " << n << endl;
                exit(1);
            }
            else
            {
                int a = getNext();
                if(n == 0) {return a;}
                else {return get(n-1);}
            }
        }

        int index(int a)
        {
            if(!hasNext())
            {
                cout << "No such element!" << endl;
                exit(1);
            }
            else
            {
                int x = getNext();
                if(x == a)
                    return 0;
                else
                    return 1+index(a);
            }
        }

        int findd(bool (*funptr) (int))
        {
            if(!hasNext())
            {
                cout << "Empty Container!" << endl;
                exit(1);
            }
            else
            {
                int a = getNext();
                if(funptr(a)) {return a;}
                else {findd(funptr);}
            }
        }

        bool contain(bool (*funptr) (int))
        {
            if(!hasNext())
                return false;
            else
            {
                int a = getNext();
                return funptr(a) || contain(funptr);
            }
        }

        bool forall(bool (*funptr) (int))
        {
            if(!hasNext())
                return true;
            else
            {
                int a = getNext();
                return funptr(a) && forall(funptr);
            }
        }

        bool exists(bool (*funptr) (int))
        {
            if(!hasNext())
                return false;
            else
            {
                int a = getNext();
                return funptr(a) || exists(funptr);
            }
        }

        void foreach(void (*funptr) (int))
        {
            if(!hasNext()) {return;}
            else
            {
                int a = getNext();
                funptr(a);
                return foreach(funptr);
            }
        }
};


class Node {
    public:

        int value;
        Node *left;
        Node *right;

        Node() {value = 0; left = NULL; right = NULL;}
        Node(int el) {
            value = el;
        }

        Node(int el, Node *l, Node *r) {
            value = el;
            left = l;
            right = r;
        }
};

class IntBST {

    private:
        Node *root;

        void addHelper(Node *root, Node *newnode) {

            if (root->value > newnode->value) {
                if (!root->left) {
                    root->left = newnode;
                } else {
                    addHelper(root->left, newnode);
                }
            } else {
                if (!root->right) {
                    root->right = newnode;
                } else {
                    addHelper(root->right, newnode);
                }
            }
        }

        bool deleteValueHelper(Node* parent, Node* current, int value) {
            if (!current)
                return false;
            if (current->value == value) {
                if (current->left == NULL || current->right == NULL) {
                    Node* temp = current->left;
                    if (current->right)
                        temp = current->right;
                    if (parent) {
                        if (parent->left == current) {
                            parent->left = temp;
                        } else {
                            parent->right = temp;
                        }
                    } else {
                        root = temp;
                    }
                } else {
                    Node* validSubs = current->right;
                    while (validSubs->left) {
                        validSubs = validSubs->left;
                    }
                    int temp = current->value;
                    current->value = validSubs->value;
                    validSubs->value = temp;
                    return deleteValueHelper(current, current->right, temp);
                }
                delete current;
                return true;
            }
            return deleteValueHelper(current, current->left, value) ||
                deleteValueHelper(current, current->right, value);
        }

    public:

        IntBST() {root = NULL;}

        void insertt(int val) {
            Node *newnode = new Node;
            newnode->value = val;
            if (root) {
                addHelper(root, newnode);
            } else {
                root = newnode;
            }
        }

        bool delette(int value) {
            return deleteValueHelper(NULL, root, value);
        }

        bool containsHelper(int val, Node *root){
            if((val < root->value) && (root->left != NULL)) {
                containsHelper(val, root->left);
            }
            else if(val > root->value && root->right != NULL) {
                containsHelper(val, root->right);
            }
            else { //theyre equal
                return true;
            }
            return false;
        }

        bool contains(int x)
        {
            return containsHelper(x, root);
        }

        void setList(Node *root) {
            if (!root) return;
            setList(root->left);
            newlist.push_back(root->value);
            setList(root->right);
        }

        SetIterator iterat()
        {
            newlist.clear();
            setList(root);
            SetIterator newit(newlist);
            return newit;
        }
};

void print(int x)
{
    cout << x << " ";
}

// test main
int main() {
    IntBST test;
    test.insertt(11);
    test.insertt(1);
    test.insertt(75);
    test.insertt(-75);
    test.insertt(6);
    test.insertt(12);
    test.insertt(10);
    test.insertt(100);
    cout<<endl;

    void (*fptr) (int);
    fptr = print;

    test.iterat().foreach(fptr);
    cout << endl;
    cout << "Contains 11: " << test.contains(11) << endl;

    test.delette(11);
    test.delette(1);
    test.delette(12);
    test.delette(6);
    test.delette(10);
    test.delette(100);

    test.iterat().foreach(fptr);
    cout << endl;
    cout << "Contains 11: " << test.contains(11) << endl;

    cout << endl;

    return 0;
}
