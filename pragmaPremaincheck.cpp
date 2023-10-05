//does not work with gcc
/*Output is 
Inside func1()
Inside main()
Inside func2()
*/

#include <bits/stdc++.h>
using namespace std;
      
void func1();
void func2();
 
#pragma startup func1
#pragma exit func2
 
void func1()
{
    cout << "Inside func1()\n";
}
 
void func2()
{
    cout << "Inside func2()\n";
}
 
int main()
{
    void func1();
    void func2();
    cout << "Inside main()\n";
 
    return 0;
}

// This code is contributed by shivanisinghss2110

//works With gcc
#include <iostream>
using namespace std;

void func1();
void func2();

void __attribute__((constructor)) func1();
void __attribute__((destructor)) func2();

void func1()
{
    printf("Inside func1()\n");
}

void func2()
{
    printf("Inside func2()\n");
}

// Driver code
int main()
{
    printf("Inside main()\n");

    return 0;
}

// This code is contributed by Shivani