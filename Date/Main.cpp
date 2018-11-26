#include"Date.cpp"
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    Date a;
    a.set_day(10);
    printf("%d\n",a.get_dat_from_start());
    Date b=a+10;
    b.print();
    cout << (b-a) << endl;
    cout << int(b) << endl;
    return 0;
}