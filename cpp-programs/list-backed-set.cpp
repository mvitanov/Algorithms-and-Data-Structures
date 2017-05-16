#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

template <class T>
class SetIterator {

    private:
        list<T> iter;

    public:
        SetIterator<T> (list<T> elements) {iter = elements;}
        bool hasNext()
        {
            if(iter.empty())
                return false;
            else {return true;}
        }

        T getNext()
        {
            T x = iter.front();
            iter.pop_front();
            return x;
        }


        int length()
        {
            if(!hasNext())
                return 0;
            else
            {
                T a = getNext();
                return 1+length();
            }
        }

        bool contains(T a)
        {
            if(!hasNext())
                return false;
            else
            {
                T x = getNext();
                if(x == a)
                    return true;
                else
                    return contains(a);
            }
        }

        T get(int n)
        {
            if(!hasNext())
            {
                cout << "No element at position " << n << endl;
                exit(1);
            }
            else
            {
                T a = getNext();
                if(n == 0) {return a;}
                else {return get(n-1);}
            }
        }

        int index(T a)
        {
            if(!hasNext())
            {
                cout << "No such element!" << endl;
                exit(1);
            }
            else
            {
                T x = getNext();
                if(x == a)
                    return 0;
                else
                    return 1+index(a);
            }
        }

        T findd(bool (*funptr) (T))
        {
            if(!hasNext())
            {
                cout << "Empty Container!" << endl;
                exit(1);
            }
            else
            {
                T a = getNext();
                if(funptr(a)) {return a;}
                else {findd(funptr);}
            }
        }

        bool contain(bool (*funptr) (T))
        {
            if(!hasNext())
                return false;
            else
            {
                T a = getNext();
                return funptr(a) || contain(funptr);
            }
        }

        bool forall(bool (*funptr) (T))
        {
            if(!hasNext())
                return true;
            else
            {
                T a = getNext();
                return funptr(a) && forall(funptr);
            }
        }

        bool exists(bool (*funptr) (T))
        {
            if(!hasNext())
                return false;
            else
            {
                T a = getNext();
                return funptr(a) || exists(funptr);
            }
        }

        void foreach(void (*funptr) (T))
        {
            if(!hasNext()) {return;}
            else
            {
                T a = getNext();
                funptr(a);
                return foreach(funptr);
            }
        }
};

template <class T>
class ListSet {

    private:
        list<T> elements;

    public:

        SetIterator<T> iterat()
        {
            SetIterator<T> newit(elements);
            return newit;
        }

        bool contain(T x)
        {
            return this->iterat().contains(x);
        }

        void insertt(T x)
        {
            if(iterat().contains(x))
                return;
            else
                elements.push_back(x);
        }

        void delette(T x)
        {
            elements.remove(x);
        }

};
template <class T>
void print(T x)
{
    cout << x << " ";
}

// simple test main
int main()
{
    ListSet<int> test;
    test.insertt(4);
    test.insertt(2);
    test.insertt(4);

    void (*fptr) (int);
    fptr = print;

    test.iterat().foreach(fptr);

    cout << endl << "Contains 4: " << test.contain(4) << endl;
    cout << "Contains 10: " << test.contain(10) << endl;

    return 0;
}
