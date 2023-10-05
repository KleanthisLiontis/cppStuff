#include <iostream>
using namespace std;

void reverse_dig(int &a,int &b)
{
    int reversed_a = 0;
    int reversed_b = 0;

    while (a > 0) {
        int digit = a % 10;
        reversed_a = reversed_a * 10 + digit;
        a /= 10;
    }

    while (b > 0) {
        int digit = b % 10;
        reversed_b = reversed_b * 10 + digit;
        b /= 10;
    }

    a = reversed_a;
    b = reversed_b;
}
void swap(int &a,int &b)
{
     int temp = a;
    a = b;
    b = temp;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
	    cin>>a>>b;
	
	    reverse_dig(a,b);
	    swap(a,b);
	    cout<<a<<" "<<b<<endl;
    }
	return 0;
}