/*
g++ -o f -std=c++11 lab2_9.cpp; ./f
*/
#include <iostream>
#include <string>

using namespace std;

// L - length (M + K), M - information bits, K - check bits
const int L = 7, M = 4, K = 3;

void make_bool(bool *a);
void show_right(bool *s, bool *a);

int main()
{
    /*
     input - 7 character string (4 information, 3 check):
     1100100
     output - 7 character string without mistakes:
     1100110
     
     #: 0  1  2  3  4  5  6
  name: r1 r2 i1 r3 i2 i3 i4
   exm: 1  1  0  0  1  0  0
     */
    bool a[L] {};
    make_bool(a);
    
    bool r1r = a[2] ^ a[4] ^ a[6]; // i1 i2 i4
    bool r2r = a[2] ^ a[5] ^ a[6]; // i1 i3 i4
    bool r3r = a[4] ^ a[5] ^ a[6]; // i1 i3 i4
    
    bool s[K] {};
    s[0] = r1r ^ a[0]; // r1r ^ r1
    s[1] = r2r ^ a[1]; // r2r ^ r2
    s[2] = r3r ^ a[3]; // r3r ^ r3
    
    show_right(s, a);
    
    return 0;
}

void make_bool(bool *a)
{
    // input
    string line;
    cin >> line;
    while (cin.get() != '\n')
    {}
    if (line.length() != L)
    { cout << "Wrong input. Stop the programm!\n"; return; }
    // string to bool
    for (int i = 0; i < L; ++i)
    {
        if (line[i] == '0')
        { a[i] = 0; }
        else if (line[i] == '1')
        { a[i] = 1; }
        else
        { cout << "Wrong input. Stop the programm!\n"; return;}
    }
}
void show_right(bool *s, bool *a)
{
    int s_val = 0;
    s[0] ? s_val += 4 : s_val += 0;
    s[1] ? s_val += 2 : s_val += 0;
    s[2] ? s_val += 1 : s_val += 0;
//cout << "s_val: " << bitset<3>(s_val) << endl;
    if (s_val == 0)
    {
        for (int i = 0; i < L; ++i)
        { cout << a[i]; }
        cout << endl;
        return;
    }
    // table of correspondence
    const int IND_TBL[] = {-1, 3, 1, 5, 0, 4, 2, 6};
    a[IND_TBL[s_val]] = a[IND_TBL[s_val]] ? 0 : 1;
    
//    for (int i = 0; i < L; ++i)
//    { cout << a[i]; }
//    cout << endl;
//
    cout << a[2] << a[4] << a[5] << a[6] << endl;
}
