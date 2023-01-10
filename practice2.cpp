#include <iostream>
#include <array>

typedef std::array<int , 5> MyArr;

void f(int* a)
{
    *a = 0;
}

int sum(MyArr a)
{
    int r = 0;
    for (int i = 0 ; i < 5 ; ++ i)
        r += a[i];

    return r;
}

int main ()
{
    MyArr a = {1 , 2 , 3 , 4 , 5};
    std::cout << " Sum1 : " << sum ( a ) << "\n";
    f(&a[4]);
    std::cout << " Sum2 : " << sum ( a ) << "\n";
}
