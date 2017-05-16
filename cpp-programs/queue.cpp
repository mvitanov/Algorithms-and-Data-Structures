#include <iostream>

using namespace std;

template<typename Type>
struct Node{
    Type item;
    Node* next;
    Node(Type nel, Node* ptr = NULL): item(nel), next(ptr){}
};


template<typename Type>
class Queue{
    private:
        Node<Type> *front;
        Node<Type> *rear;
        int count;

    public:
        Queue(): front(NULL), rear(NULL), count(0) {}
        void enqueue(Type newel){
            if(count == 0) {
                front = new Node<Type>(newel);
                rear = front;
                count++;
            }
            else {
                rear->next = new Node<Type>(newel);
                rear = rear->next;
                count++;
            }
        }
        void dequeue(){
			if(!this->IsEmpty()){
				Node<Type> * temp;
				temp = front;
				front = front->next;
				delete temp;
			}
			if(count == 1)
			{
				front = NULL;
				rear = NULL;
			}
			count--;
        }
        void first_el(){
           if(front != NULL) cout<< front->item << " ";
        }
        bool IsEmpty(){
            return rear == NULL;
        }
};

// simple test main
int main(){
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.first_el();
    while(q.IsEmpty() == false)
    {
		q.dequeue();
		q.first_el();
	}
	cout << endl;
	return 0;
}
