#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int larger;
    int smaller;
    if (a > b)
    {
        larger = a;
        smaller = b;
    }
    else
    {
        larger = b;
        smaller = a;
    }
    int remainder;
    int quotient;
    int s1 = 1; int t1 = 0;
    int s2 = 0; int t2 = 1;
  
    while (smaller != 0)
    {
        remainder = larger % smaller;
        quotient = larger / smaller;
        larger = smaller;
        smaller = remainder;

        int s = s1 - (s2 * quotient);
        s1 = s2;
        s2 = s;

        int t = t1 - (t2 * quotient);
        t1 = t2;
        t2 = t;
    }

    cout << "GCD:" << larger << endl;
    cout << "S : " << s1 << endl;
    cout << "T1 : " << t1 << endl;
    return 0;
}
int main()
{
    int a, b;

    cout << "Enter two numbers for GCD usign extended euclid algorithm :";
    cin >> a >> b;

    int ans = gcd(a, b);
    return 0;
}