#include <iostream>

using namespace std;

template<typename T1, typename T2>
class base {
protected:
    T1 value1;
    T2 value2;
public:
    base(T1 val1, T2 val2)
        : value1{ val1 }, value2{ val2 } {}

    virtual void display() {
        cout << "Value 1 = " << value1 << "\nValue 2 = " << value2 << endl;
    }

    virtual ~base() {}
};

template<typename T1, typename T2, typename T3, typename T4>
class child : public base<T1, T2> {
protected:
    T3 value3;
    T4 value4;
public:
    child(T1 val1, T2 val2, T3 val3, T4 val4)
        : base<T1, T2>(val1, val2), value3{ val3 }, value4{ val4 } {}

    void display() override {
        base<T1, T2>::display();
        cout << "Value 3 = " << value3 << "\nValue 4 = " << value4 << endl;
    }

    ~child() {}
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class child2 : public child<T1, T2, T3, T4> {
    T5 value5;
    T6 value6;
public:
    child2(T1 val1, T2 val2, T3 val3, T4 val4, T5 val5, T6 val6)
        : child<T1, T2, T3, T4>(val1, val2, val3, val4), value5{ val5 }, value6{ val6 } {}

    void display() override {
        child<T1, T2, T3, T4>::display();
        cout << "Value 5 = " << value5 << "\nValue 6 = " << value6 << endl;
    }

    ~child2() {}
};

int main()
{
    child2<int, float, double, char, string, bool> ch2(15, 1.7, 1.2334, 'c', "abc", true);
    ch2.display();
}