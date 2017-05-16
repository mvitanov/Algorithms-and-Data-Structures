#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>
#include <list>

struct AdjListNode
{
    int dest;
    int weight;
};

class Graph
{
    private:
        int numNodes;
        std::list<struct AdjListNode *> *outgoing;
        std::list<struct AdjListNode *> *incoming;
    public:
        Graph(int V)
        {
            numNodes = V;
            outgoing = new std::list<struct AdjListNode *> [numNodes];
            incoming = new std::list<struct AdjListNode *> [numNodes];
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
            std::list<struct AdjListNode *> nlist;
            nlist = outgoing[src];
            std::list<struct AdjListNode *>::iterator it;
            it = nlist.begin();
            while (it != nlist.end())
            {
                if((*it)->dest == d)
                    return (*it)->weight;
                it++;
            }
            std::cout << "No such edge!" << std::endl;
            exit(1);
        }

        std::list<struct AdjListNode *> incoming_list(int i)
        {
            return incoming[i];
        }

        std::list<struct AdjListNode *> outgoing_list(int i)
        {
            return outgoing[i];
        }

         void addNode()
         {
            std::list<struct AdjListNode *> *newin;
            std::list<struct AdjListNode *> *newout;
            newout = new std::list<struct AdjListNode *> [numNodes + 1];
            newin = new std::list<struct AdjListNode *> [numNodes + 1];
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
                std::list<struct AdjListNode *> out_nlist = outgoing[v];
                std::list<struct AdjListNode *> in_nlist = incoming[v];

                std::cout<<"\nNode " << v << "\n";

                std::list<struct AdjListNode *>::iterator it;

                std::cout << "INCOMING NODES (if any):" << std::endl;
                it = in_nlist.begin();
                while(it != in_nlist.end())
                {
                    std::cout << v << " <- " << (*it)->dest << " with weight = " << (*it)->weight << std::endl;
                    it++;
                }
                std::cout << std::endl;

                it = out_nlist.begin();
                std::cout << "OUTGOING NODES (if any):" << std::endl;
                while(it != out_nlist.end())
                {
                    std::cout << v << " -> " << (*it)->dest << " with weight = " << (*it)->weight << std::endl;
                    it++;
                }
                std::cout << std::endl;
            }
        }
};

#endif // GRAPH_H
