#include <iostream>
#include <string>

using namespace std;

template <class Type>
class DynArray
{
public:
    void add(const Type &toAdd)
    {
        if (count == size)
        {
            size = (size + 1) * 2;
            Type *bigger = new Type[size];
            for (int i = 0; i < count; ++i)
                bigger[i] = data[i];
            delete[] data;
            data = bigger;
        }
        data[count] = toAdd;
        count++;
    }
    void print(ostream &out)
    {
        for (int i = 0; i < count; ++i)
        {
            out << data[i];
            if (i != count - 1)
                out << ' ';
        }
        out << '\n';
    }
    ~DynArray()
    {
        delete[] data;
    }

private:
    int count = 0;
    int size = 0;
    Type *data = nullptr;
};

class NoDefCtor
{
public:
    int a;
    NoDefCtor(int b = 0)
        : a(b)
    {
    }
};

int main()
{
    DynArray<int> integers;
    integers.add(1);
    integers.add(2);
    integers.add(3);
    integers.print(cout);
    DynArray<double> rationals;
    rationals.add(3.14);
    rationals.add(4.2);
    rationals.print(cout);
    DynArray<string> words;
    words.add("apple");
    words.add("orange");
    words.add("banana");
    words.print(cout);
    DynArray<NoDefCtor> err;
    NoDefCtor obj(42);
    err.add(obj);
}