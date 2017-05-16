#include <iostream>

using namespace std;

template<class A>
class Node
{
public:
    A data;
    Node<A> * next;
    Node<A>(const A& d):data(d), next() {}
    Node<A>(const Node<A>& copyNode) : data(copyNode.data), next() {}
};

template<class A>
class LinkedList
{
public:

    Node<A> * head;
    Node<A> * tail;

    LinkedList(const LinkedList&);
    LinkedList(): head(NULL), tail(NULL) {}
    LinkedList(Node<A> * nNode) : head(nNode), tail(nNode) {}
    ~LinkedList();

    void add_end(A);
    void add_begin(A);
    void print();
    LinkedList reverse_list();
    LinkedList concat(LinkedList&);
};

template<class A>
LinkedList<A>::LinkedList(const LinkedList<A>& listt) : head(NULL), tail(NULL)
{
    const Node<A> * current = listt.head;

    if (!head && current)
    {
        head = new Node<A>(current -> data);
        tail = head;
        current = current -> next;
    }

    while (current)
    {
        Node<A> * nNode = new Node<A>(current -> data);
        tail -> next = nNode;
        tail = nNode;
        current = current -> next;
    }
}

template<class A>
LinkedList<A>::~LinkedList()
{
    Node<A> * current = head;
    while (head)
    {
        head = head -> next;
        delete current;
        current = head;
    }
}

template<class A>
void LinkedList<A>::add_end(A newel)
{
    Node<A> * nNode = new Node<A>(newel);
    if (tail == NULL)
    {
        nNode -> next = tail;
        tail = nNode;
        head = nNode;
        return;
    }
    tail -> next = nNode;
    tail = tail->next;
}

template<class A>
void LinkedList<A>::add_begin(A newel)
{
    Node<A> * nNode = new Node<A>(newel);
    nNode -> next = head;
    head = nNode;
    if (head -> next == NULL)
        tail = nNode;
}

template<class A>
void LinkedList<A>::print()
{
    Node<A> * current = head;
    while (current)
    {
        cout << current -> data << " ";
        current = current -> next;
    }
    cout << endl;
}

template<class A>
LinkedList<A> LinkedList<A>::reverse_list()
{
    Node<A> * current;
    LinkedList reversed(new Node<A>(head -> data));
    current = head -> next;
    while (current)
    {
        reversed.add_begin(current -> data);
        current = current -> next;
    }
    current = reversed.head;
    return reversed;
}

template<class A>
LinkedList<A> LinkedList<A>::concat(LinkedList& con_list)
{
    Node<A> *h1, *h2;

    h1 = head;
    h2 = con_list.head;

    while(h1 -> next != NULL)
        h1 = h1 -> next;

    h1 -> next = h2;

    return *this;
}

int main()
{
    cout << "Using the class LinkedList with chars:" << endl;
    LinkedList<char> list1(new Node<char>('a'));
    list1.add_end('l');
    list1.add_end('g');
    list1.add_end('o');
    list1.add_end('r');
    list1.add_end('i');
    list1.add_end('t');
    list1.add_end('h');
    list1.add_end('m');
    list1.add_end('s');

    LinkedList<char> list2(new Node<char>('a'));
    list2.add_begin('t');
    list2.add_begin('a');
    list2.add_begin('d');

    list1.print();
    list2.print();
    list2.reverse_list().print();
    list1.concat(list2).print();

    cout << "\nUsing the class LinkedList with ints:" << endl;
    LinkedList<int> list3(new Node<int>(1));
    list3.add_end(2);
    list3.add_end(3);
    list3.add_end(4);
    list3.add_end(5);

    LinkedList<int> list4(new Node<int>(10));
    list4.add_begin(9);
    list4.add_begin(8);
    list4.add_begin(7);

    list3.print();
    list4.print();
    list4.reverse_list().print();
    list3.concat(list4).print();

    return 0;
}
