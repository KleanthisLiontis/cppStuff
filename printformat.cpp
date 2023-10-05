Default Printing Format

No trailing zeros
Precision means total digits(excluding the digits used after e).
Default Precision value is 6.
When value before decimal point does not fit in 6 digits, power format is used. For example - 1234568.3 is printed as 1.23457e+06.
 

#include<iostream>
using namespace std;
int main()
{
    double x = 1.2300;
    cout << x << '\n';
    double y = 1567.56732;
    cout << y << '\n';
    double z = 1244567.45;
    cout << z << '\n';
    double w = 124456.67;
    cout << w << '\n';
    double u = 123e+2;
    cout << u << '\n';
    return 0;
}

Output
1.23
1567.57
1.24457e+06
124457
12300