#include <iostream>
using namespace std;

int gcd (int a, int b) {
    while (a != b) {
       if (a > b) {
        a = a-b;
       } else if (b > a) {
            b = b-a; 
       }
        return a;
    }
}

int main() {

    int number1;
    int number2;
    int a;
    int b;
    
    cout << "Enter two integers: ";
    cin >> number1 >> number2;

    int sum = gcd(a, b);

    cout << "The gcd is: " << sum << '\n';
    

}