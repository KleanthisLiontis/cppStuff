/ Code implementation showing the use of left, right, setfill, setw

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << left << setw(10) << setfill('-') << "Apple" << endl;  // Output: Apple----
    cout << right << setw(10) << setfill('-') << "Orange" << endl;  // Output: ----Orange

/**
 * 
The left manipulator causes the output to be left-aligned within the specified width. The right manipulator causes the output to be right-aligned within the specified width.

The setw manipulator sets the width of the output field, and the setfill manipulator sets the character that should be used to fill any unused space in the output field.

In the example above, the setw manipulator was used to set the width of the output field to 10 characters, and the setfill manipulator was used to set the fill character to a dash. The left manipulator caused the word "Apple" to be left-aligned within the field, and the right manipulator caused the word "Orange" to be right-aligned within the field. This caused the output to be aligned in two neat columns.

Cout uses flags to do many things
*/

// Code implementation showing the use of hex, dec and oct

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << hex << 123 << endl;      // Outputs: 7b
    cout << oct << 456 << endl;      // Outputs: 710
    cout << dec << 789 << endl;      // Outputs: 789
}


#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    cout << setprecision(4);
    double x = 15.5683, y = 34267.1;
    cout << x << ' ' << y << ' ' << '\n';
    double z = 1.23;
    cout << showpoint << z << '\n';
    cout << showpos   << z << '\n';
    cout << uppercase << y << '\n';
    return 0;
}

include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double x = 1.23, y = 1122456.453;
    cout << std::fixed;
    cout << x << "\n"
         << y << "\n";
    cout << std::setprecision(2);
    cout << x << "\n"
         << y << "\n";
    double z = 1.2e+7;
    cout << z;
    return 0;
}

Output
1.230000
1122456.453000
1.23
1122456.45
12000000.00