#include <iostream>

using namespace std;

int num1;
int num2;

//REQUIRES: None
//MODIFIES: num1, num2
//EFFECTS: Prompts the user for input and stores the input
void opener() {
    cout << "Welcome to the Euclidean Algorithm Generator!" << endl;
    cout << "Please enter the first number you would like to find the greatest common denominator of: ";
    cin >> num1;
    cout << "Please enter the second number you would like to find the greatest common denomiator of: ";
    cin >> num2;
    cout << endl;
    cout << "Finding the greatest common denominator of " << num1 << " and " << num2 << "!" << endl;
}

//REQUIRES: num_in1 and num_in2 are non-negative
//MODIFIES: None
//EFFECTS: Recursively returns the greatest common divisor of the two inputs
int findGcd(int num_in1, int num_in2) {
    cout << "Finding gcd(" << num_in1 << ", " << num_in2 << ")..." << endl;
    //Base cases to return when remainder is 0
    if(num_in1 == 0) {
        return num_in2;
    }
    if(num_in2 == 0) {
        return num_in1;
    }
    //Recursive case
    return findGcd(num_in2, (num_in1 % num_in2));
}

int main() {
    opener();
    if(num1 < 0 || num2 < 0) {
        cout << "Error! Trying to find the gcd of a negative number!" << endl;
        return 1;
    }
    int gcd = findGcd(num1, num2);
    cout << "The greatest common denominator is " << gcd << "!" << endl;
    return 0;
}