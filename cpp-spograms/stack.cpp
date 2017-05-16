#include <iostream>

using namespace std;

template <class Type>
class Stack {
    private:
        struct StackNode {                 // linked list node
            Type item;                     // item at this node
            StackNode *next;               // next node in list

            // StackNode constructor for both elements of the struct
            StackNode(const Type& newel, StackNode *nextNode)
                : item(newel), next(nextNode) {}
        };

        StackNode *top_element;            // top of stack


    public:
        Stack():top_element(NULL) {}
        ~Stack() {
            while (!isEmpty())
                pop();
        }

        void push (const Type& object);
        Type pop();
        const Type* top();
        bool isEmpty();
};

template <class Type>
void Stack<Type>::push(const Type& newel) {
    top_element = new StackNode(newel, top_element);
}

template <class Type>
Type Stack<Type>::pop() {
    if (!isEmpty()) {
        StackNode *topNode;
        topNode = top_element;
        top_element = top_element->next;
        Type data = topNode->item;
        delete topNode;
        return data;
    }
    throw underflow_error("Empty Stack");
}

template <class Type>
const Type* Stack<Type>::top() {
    if (!isEmpty()) {
        return &top_element->item;
    }
    else
        return NULL;
}

template <class Type>
bool Stack<Type>::isEmpty() {
    if (top_element == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// simple test main
int main()
{
	Stack<int> test;
	test.push(4);
	test.push(5);
	test.push(2);
	while(test.top())
		cout << test.pop() << " ";
    cout << endl;
    return 0;
}
