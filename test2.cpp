#include <iostream>
using namespace std;

int main()
{
    string binaryNumber = "1010";
    
    cout << stoi(binaryNumber, 0, 2);

    return 0;
}