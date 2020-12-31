#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int num1;
int num2;
string ext;
bool extended;
vector<int> nums;

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

/*int multFinder(ostringstream &oss_in, int int_in) {
    int count = 0;
    string toBeFound = to_string(int_in);
    string oStr = oss_in.str();
    const char* cStr2 = toBeFound.c_str();
    const char* cStr = oStr.c_str();
    for(const char* i = cStr; *i != '\0'; ++i) {
        if(*i == cStr2[0] && cStr2[1]) {
            if(*(i + 1) == cStr2[1]) {
                if(*(i - 2) == '*') {
                    count += *(i - 4);
                    cout << "Adding " << *(i - 4) << " to count" << endl;
                }
                else {
                    count += 1;
                }
            }
        }
        if(*i == cStr2[0] && !cStr2[1]) {
            count += 1;
        }
    }
    return count;
}

void findSub(int curr) {
    ostringstream oss;
    ostringstream oss2;
    int counter = 0;
    vector<string> ossVec;
    vector<int> multVec;

    for(int j = (int) nums.size() - 2; j > 0; --j) {
        int mult = (nums.at(j - 1) - (nums.at(j - 1) % nums.at(j)))/nums.at(j);
        cout << nums.at(j + 1) << " = " << nums.at(j - 1) << " - " << mult << " * " << nums.at(j) << endl;
        oss << "(" << nums.at(j - 1) << " - " << mult << " * " << nums.at(j) << ")";
        ossVec.push_back(oss.str());
        multVec.push_back(mult);
        oss.str("");
    }
    for(int j = (int) nums.size() - 2; j > 0; --j) {
        if(counter % 2 == 0) {
            cout << "Even" << endl;
            cout << nums.at(nums.size() - 1) << " = " << nums.at(j - 1) << " - " << multVec.at(counter) << ossVec.at(counter + 1) << endl;
            oss2 << nums.at(nums.size() - 1) << " = " << nums.at(j - 1) << " - " << multVec.at(counter) << ossVec.at(counter + 1);
            cout << multFinder(oss2, 9) << " " << multFinder(oss2, 24) << endl;
        }
        else {
            cout << "Odd" << endl;
            cout << nums.at(nums.size() - 1) << " = " << endl;
        }
        ++counter;
    }
}*/

void findEEA() {
    int counter = 0;
    if(counter % 2 == 0) { 
    }
    else {
    }
}

int main() {
    opener();
    if(num1 < 0 || num2 < 0) {
        cout << "Error! Trying to find the gcd of a negative number!" << endl;
        return 1;
    }
    int gcd = findGcd(num1, num2);
    cout << "The greatest common denominator is " << gcd << "!" << endl;
    if(extended) {
        findEEA();
        //findSub(9);
    }
    return 0;
}