#include <iostream>

using namespace std;

int num1;
int num2;

void opener() {
    cout << "Welcome to the Euclidean Algorithm Generator!" << endl;
    cout << "Please enter the first number you would like to find the greatest common denominator of: ";
    cin >> num1;
    cout << "Please enter the second number you would like to find the greatest common denomiator of: ";
    cin >> num2;
    cout << endl;
    cout << "Finding the greatest common denominator of " << num1 << " and " << num2 << "!" << endl;
}

int findGcd(int num_in1, int num_in2) {
    cout << "Finding gcd(" << num_in1 << ", " << num_in2 << ")..." << endl;
    if(num_in1 == 0) {
        return num_in2;
    }
    if(num_in2 == 0) {
        return num_in1;
    }
    return findGcd(num_in2, (num_in1 % num_in2));
}

int main() {
    opener();
    int gcd = findGcd(num1, num2);
    cout << "The greatest common denominator is " << gcd << "!" << endl;
    return 0;
}