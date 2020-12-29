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

int findMult(int &num_in1, int &num_in2) {
    if(num_in2 > num_in1) {
        int tempInt = num_in1;
        num_in1 = num_in2;
        num_in2 = tempInt;
    }
    int mult = 0;
    while(num_in1 >= num_in2) {
        num_in1 -= num_in2;
        ++mult;
    }
    return mult;
}

int findRemainder(int &num_in1, int &num_in2) {
    int remainder;
    int mult = findMult(num1, num2);
    if(num_in2 > num_in1) {
        int tempInt = num_in1;
        num_in1 = num_in2;
        num_in2 = tempInt;
    }
        remainder = num_in1 - (mult * num_in2);
        cout << num_in1 << " = " << mult << " x " << num_in2 << " + " << remainder << endl;
    return remainder;
}

void findGCD(int num_in1, int num_in2) {
    int remainder = 1;
    while(remainder != 0) {
        remainder = findRemainder(num_in1, num_in2);
        num_in1 = num_in2;
        num_in2 = remainder;
    }
    cout << "The greatest common denominator found by the euclidean alogirthm is " << num_in1 << "!" << endl;
}

int main() {
    opener();
    if(num1 < 0 || num2 < 0) {
        cout << "Error! Trying to find the gcd of a negative number!" << endl;
        return 1;
    }
    findGCD(num1, num2);
    cout << "Thank you for using the Euclidean Algorithm Generator!" << endl;
    return 0;
}