#include <iostream>
#include <queue>

#include "graph.h"

using namespace std;

bool list_contain(list<int> newlist, int element)
{
    list<int>::iterator it;
    for(it = newlist.begin(); it != newlist.end(); it++)
    {
        if ((*it) == element)
            return true;
    }
    return false;
}

bool queue_contain(queue<int> q, int element)
{
    queue<int> newqueue;
    newqueue = q;
    while (!newqueue.empty())
    {
        int i;
        i = newqueue.front();
        if(i == element)
            return true;
        newqueue.pop();
    }
    return false;
}

list<int> BFS(Graph G, int start)
{
    int i;
    list<int> reachable;
    reachable.clear();
    queue<int> horizon;
    horizon.push(start);
    while (!horizon.empty())
    {
        i = horizon.front();
        horizon.pop();
        reachable.push_front(i);
        list<int> templist;
        list<struct AdjListNode *> outlist;
        outlist = G.outgoing_list(i);
        list<struct AdjListNode *>::iterator it;
        for (it = outlist.begin(); it != outlist.end(); it++)
        {
            templist.push_back((*it)->dest);
        }
        list<int>::iterator it2;
        for (it2 = templist.begin(); it2 != templist.end(); it2++)
        {
            int el;
            el = (*it2);
            if ((!list_contain(reachable, el)) && (!queue_contain(horizon, el)))
                horizon.push(el);
        }
    }
    reachable.reverse();
    return reachable;
}

// simple test for graph and BFS
int main()
{
    Graph test(10);
    test.addEdge(0, 1, 3);
    test.addEdge(0, 2, 6);
    test.addEdge(0, 6, 8);
    test.addEdge(0, 7, 9);
    test.addEdge(1, 3, 4);
    test.addEdge(2, 1, 1);
    test.addEdge(2, 3, 1);
    test.addEdge(3, 5, 8);
    test.addEdge(3, 8, 11);
    test.addEdge(4, 3, 3);
    test.addEdge(5, 4, 5);
    test.addEdge(5, 9, 9);
    test.addEdge(6, 0, 10);
    test.addEdge(6, 7, 1);
    test.addEdge(7, 3, 12);
    test.addEdge(7, 6, 2);
    test.addEdge(7, 8, 4);
    test.addEdge(8, 9, 4);
    test.addEdge(9, 3, 13);
    test.addEdge(9, 4, 7);
    test.addEdge(9, 7, 9);

    test.addNode(); // adding the last 11th node

    test.addEdge(9, 10, 1);

    test.printGraph();

    list<int> testBFS;
    testBFS = BFS(test, 0); // I choose the search to begin from node 0

    list<int>::iterator it;
    cout << "BFS list: ";
    for(it = testBFS.begin(); it != testBFS.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
