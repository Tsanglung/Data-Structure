#include <iostream>
#include <limits>
using namespace std;
// book p.10 ADT 1.1
class NaturalNumber
{
private:
    unsigned int value; // 無號整數
    static const unsigned int MAXINT = numeric_limits<unsigned int>::max();

public:
    NaturalNumber(unsigned int v = 0)
    {
        if (v <= MAXINT)
            value = v;
        else
            throw out_of_range("value exceeds MAXINT.");
    }
    static NaturalNumber Zero() { return NaturalNumber(0); };
    static bool IsZero(const NaturalNumber &x)
    {
        if (x.value == 0)
            return true;
        else
            return false;
    }
    static NaturalNumber Add(const NaturalNumber &x, const NaturalNumber &y)
    {
        if (x.value < MAXINT - y.value)
            return NaturalNumber(x.value + y.value);
        else
            return NaturalNumber(MAXINT);
    }
    static bool Equal(const NaturalNumber &x, const NaturalNumber &y)
    {
        if (x.value == y.value)
            return true;
        else
            return false;
    }
    static NaturalNumber Successor(const NaturalNumber &x)
    {
        if (x.value == MAXINT)
            return NaturalNumber(x.value);
        else
            return NaturalNumber(x.value + 1);
    }
    static NaturalNumber Subtract(const NaturalNumber &x, const NaturalNumber &y)
    {
        if (x.value < y.value)
            return NaturalNumber(0);
        else
            return NaturalNumber(x.value - y.value);
    }
    static unsigned int GetMAXINT() { return MAXINT; }
    unsigned int GetValue() const { return value; }
};

int main()
{
    NaturalNumber N1(10), N2(20), NM(NaturalNumber::GetMAXINT());

    cout << "Zero: " << NaturalNumber::Zero().GetValue() << endl;

    cout << "IsZero(0): " << (NaturalNumber::IsZero(NaturalNumber::Zero()) ? "true" : "false") << endl;
    cout << "IsZero(10): " << (NaturalNumber::IsZero(N1) ? "true" : "false") << endl;

    cout << "Add(10, 20): " << NaturalNumber::Add(N1, N2).GetValue() << endl;
    cout << "Add(MAXINT, 1): " << NaturalNumber::Add(NM, 1).GetValue() << endl;

    cout << "Equal(10, 10): " << (NaturalNumber::Equal(N1, N1) ? "true" : "false") << endl;
    cout << "Equal(10, 20): " << (NaturalNumber::Equal(N1, N2) ? "true" : "false") << endl;

    cout << "Successor(10): " << NaturalNumber::Successor(N1).GetValue() << endl;
    cout << "Successor(MAXINT): " << NaturalNumber::Successor(NM).GetValue() << endl;

    cout << "Subtract(20, 10): " << NaturalNumber::Subtract(N2, N1).GetValue() << endl;
    cout << "Subtract(10, 20): " << NaturalNumber::Subtract(N1, N2).GetValue() << endl;

    return 0;
}