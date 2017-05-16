#include <iostream>

#define N 10

using namespace std;

template<typename Type>
class Buffer{
	private:
		Type elements[N];
		int begin;
		int size;
	public:
		Buffer() : begin(0), size(0) {}
		void enqueue(Type newel) {
			if(size == N)
				throw overflow_error("Buffer Overflow!");
			else {
				int pos;
				pos = (begin + size) % N;
				elements[pos] = newel;
				size++;
			}
		}
		Type dequeue() {
			if(size == 0)
				throw underflow_error("Buffer Underflow!");
			else {
				Type temp;
				temp = elements[begin];
				begin = (begin + 1) % N;
				size--;
				return temp;
			}
		}
		bool IsEmpty() {return size == 0;}
};

int main() {
	Buffer<int> x;
	x.enqueue(1);
	x.enqueue(2);
	x.enqueue(3);
	x.enqueue(4);
	x.enqueue(5);
	x.enqueue(6);
	x.enqueue(7);
	x.enqueue(8);
	x.enqueue(9);
	x.enqueue(10);
	while(!x.IsEmpty())
		cout << x.dequeue() << " ";
    cout << endl;
	return 0;
}
