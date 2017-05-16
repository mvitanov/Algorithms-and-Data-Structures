#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

struct AdjListNode
{
    int dest;
    int weight;
};

class Graph
{
    private:
        int numNodes;
        list<struct AdjListNode *> *outgoing;
        list<struct AdjListNode *> *incoming;
    public:
        Graph(int V)
        {
            numNodes = V;
            outgoing = new list<struct AdjListNode *> [numNodes];
            incoming = new list<struct AdjListNode *> [numNodes];
            for (int i = 0; i < numNodes; i++)
            {
                outgoing[i].clear();
                incoming[i].clear();
            }

        }

        struct AdjListNode* newAdjListNode(int d, int w) //Creating New Adjacency List Node
        {
            struct AdjListNode* newNode = new AdjListNode;
            newNode -> dest = d;
            newNode -> weight = w;
            return newNode;
        }

        int getEdge(int src, int d)
        {
            list<struct AdjListNode *> nlist;
            nlist = outgoing[src];
            list<struct AdjListNode *>::iterator it;
            it = nlist.begin();
            while (it != nlist.end())
            {
                if((*it)->dest == d)
                    return (*it)->weight;
                it++;
            }
            cout << "No such edge!" << endl;
            exit(1);
        }

        list<struct AdjListNode *> incoming_list(int i)
        {
            return incoming[i];
        }

        list<struct AdjListNode *> outgoing_list(int i)
        {
            return outgoing[i];
        }

         void addNode()
         {
            list<struct AdjListNode *> *newin;
            list<struct AdjListNode *> *newout;
            newout = new list<struct AdjListNode *> [numNodes + 1];
            newin = new list<struct AdjListNode *> [numNodes + 1];
            for (int i = 0; i < numNodes; i++)
            {
                newin[i] = incoming[i];
                newout[i] = outgoing[i];
            }
            newin[numNodes].clear();
            newout[numNodes].clear();

            numNodes++;
            outgoing = newout;
            incoming = newin;
         }

        void addEdge(int src, int dest, int weight)
        {
            struct AdjListNode* newNode = newAdjListNode(dest, weight);
            outgoing[src].push_back(newNode);
            newNode = newAdjListNode(src, weight);
            incoming[dest].push_back(newNode);
        }

        void printGraph()
        {
            int v;
            for (v = 0; v < numNodes; v++)
            {
                list<struct AdjListNode *> out_nlist = outgoing[v];
                list<struct AdjListNode *> in_nlist = incoming[v];

                cout<<"\nNode " << v << "\n";

                list<struct AdjListNode *>::iterator it;

                cout << "INCOMING NODES (if any):" << endl;
                it = in_nlist.begin();
                while(it != in_nlist.end())
                {
                    cout << v << " <- " << (*it)->dest << " with weight = " << (*it)->weight << endl;
                    it++;
                }
                cout<<endl;

                it = out_nlist.begin();
                cout << "OUTGOING NODES (if any):" << endl;
                while(it != out_nlist.end())
                {
                    cout << v << " -> " << (*it)->dest << " with weight = " << (*it)->weight << endl;
                    it++;
                }
                cout<<endl;
            }
        }
};

// simple test main
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

    return 0;
}
