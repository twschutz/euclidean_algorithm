#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int num1;
int num2;
int counter = 0;
string ext;
bool extended;
vector<int> nums;
vector<string> replacements;
vector<int> multVec;
ostringstream oss;

//REQUIRES: None
//MODIFIES: num1, num2
//EFFECTS: Prompts the user for input and stores the input
void opener() {
    cout << "Welcome to the Euclidean Algorithm Generator!" << endl;
    cout << "Please enter the first number you would like to find the greatest common denominator of: ";
    cin >> num1;
    cout << "Please enter the second number you would like to find the greatest common denomiator of: ";
    cin >> num2;
    cout << "Use the Extended Euclidean Algorithm to find the linear combination of " << num1 
    << " and " << num2 << "? (True or False)" << endl;
    cin >> ext;
    if(ext == "True") {
        extended = 1;
    }
    else {
        extended = 0;
    }
    cout << "Finding the greatest common denominator of " << num1 << " and " << num2 << "!" << endl;
}

//REQUIRES: num_in1 and num_in2 are non-negative
//MODIFIES: None
//EFFECTS: Recursively returns the greatest common divisor of the two inputs
int findGcd(int num_in1, int num_in2) {
    cout << "Finding gcd(" << num_in1 << ", " << num_in2 << ")..." << endl;
    nums.push_back(num_in1);
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

/*int multFinder(string &string_in, int int_in) {
    int count = 0;
    string toBeFound = to_string(int_in);
    const char* cStr2 = toBeFound.c_str();
    const char* cStr = string_in.c_str();
    for(const char* i = cStr; *i != '\0'; ++i) {
        if(*i == cStr2[0] && cStr2[1]) {
            if(*(i + 1) == cStr2[1]) {
                count += multVec.at(counter);
                if(*(i - 2) == '*') {
                    count += (multVec.at(counter) * stoi(i - 4)) - (multVec.at(counter) - 1);
                }
            }
        }
        else if(*i == cStr2[0] && !cStr2[1]) {
            count += multVec.at(counter);
            if(*(i - 2) == '*') {
                count += (multVec.at(counter) * stoi(i - 4)) - multVec.at(counter);
            }
        }
    }
    return count;
}*/

void printEquals() {
    for(int j = (int) nums.size() - 2; j > 0; --j) {
        int mult = (nums.at(j - 1) - (nums.at(j - 1) % nums.at(j)))/nums.at(j);
        cout << nums.at(j + 1) << " = " << nums.at(j - 1) << " - " << mult << " * " << nums.at(j) << endl;
        oss << nums.at(j - 1) << " - " << mult << " * " << nums.at(j) << endl;
        replacements.push_back(oss.str());
        multVec.push_back(mult);
        oss.str("");
    }
}

/*void factor() {
    ostringstream oss;
    ostringstream oss2;

    for(int j = (int) nums.size() - 2; j > 0; --j) {
        int mult = (nums.at(j - 1) - (nums.at(j - 1) % nums.at(j)))/nums.at(j);
        cout << nums.at(j + 1) << " = " << nums.at(j - 1) << " - " << mult << " * " << nums.at(j) << endl;
        oss << "(" << nums.at(j - 1) << " - " << mult << " * " << nums.at(j) << ")";
        ossVec.push_back(oss.str());
        multVec.push_back(mult);
        oss.str("");
    }

    for(int j = (int) nums.size() - 2; j > 1; --j) {
        if(counter % 2 == 0) {
            cout << "Even" << endl;
            cout << nums.at(nums.size() - 1) << " = " << nums.at(j - 1) << " - " << multVec.at(counter) << ossVec.at(counter + 1);
            oss2.str("");
            oss2 << nums.at(j - 1) << " - " << multVec.at(counter) << ossVec.at(counter + 1);
            cout << " = " << multFinder(oss2, nums.at(j - 1)) << " * " << nums.at(j - 1) 
            << " - " << multFinder(oss2, nums.at(j - 2)) << " * " <<  nums.at(j - 2) << endl;
            oss2 << multFinder(oss2, nums.at(j - 1)) << " * " << nums.at(j - 1) 
            << " - " << multFinder(oss2, nums.at(j - 2)) << " * " <<  nums.at(j - 2);
            multVec.at(counter + 1) = multFinder(oss2, nums.at(j - 1));
        }
        else {
            cout << "Odd" << endl;
            cout << oss2.str() << endl;
            cout << nums.at(nums.size() - 1) << " = " << multVec.at(counter) << ossVec.at(counter + 1) << " - " << nums.at(j - 1);
            oss2.str("");
            oss2 << multVec.at(counter) << ossVec.at(counter + 1) << " - " << nums.at(j - 1);
            cout << " = " << multFinder(oss2, nums.at(j - 2)) << " * " << nums.at(j - 2) 
            << " - " << multFinder(oss2, nums.at(j - 1)) << " * " <<  nums.at(j - 1) << endl;
            oss << multFinder(oss2, nums.at(j - 2)) << " * " << nums.at(j - 2) 
            << " - " << multFinder(oss2, nums.at(j - 1)) << " * " <<  nums.at(j - 1);
            multVec.at(counter + 1) = multFinder(oss2, nums.at(j - 2));
        }
        ++counter;
    }
}*/

int main() {
    opener();
    if(num1 < 0 || num2 < 0) {
        cout << "Error! Trying to find the gcd of a negative number!" << endl;
        return 1;
    }
    int gcd = findGcd(num1, num2);
    cout << "The greatest common denominator is " << gcd << "!" << endl;
    if(extended) {
        //printEquals();
    }
    return 0;
}