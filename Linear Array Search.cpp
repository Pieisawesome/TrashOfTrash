#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Returns true is value is found in array
// Changes value of foundIndex
bool SearchList(int stdList[], unsigned numElems, int searchValue, unsigned& foundIndex) {
    foundIndex = 0;
    bool found = false;

    while (foundIndex < numElems && found == false) {
        if (stdList[foundIndex] == searchValue) {
            found = true;
            break;
        }
        foundIndex++;
    }
    return found;
}

int main() {

    //LSSTANDARD
    const unsigned maxNumOfNum = 100;
    int lssArr[maxNumOfNum];
    int numOflssArr = 0;                // Number of how many elements are in LSStandard Array

    ifstream ifsLSStandard;
    ifsLSStandard.open("LSStandard.txt");

    int tempNum = 0;
    for (; ifsLSStandard >> tempNum; numOflssArr++) {
        lssArr[numOflssArr] = tempNum;
    }

    ifsLSStandard.close();

    //LSTEST
    const unsigned maxNumInt = 50;
    int lstArr[maxNumInt];
    int numOflstArr = 0;                // Number of how many elements are in LSTest Array

    ifstream ifsLSTest;
    ifsLSTest.open("LSTest.txt");

    for (; ifsLSTest >> tempNum; numOflstArr++) {
        lstArr[numOflstArr] = tempNum;
    }

    ifsLSTest.close();

    unsigned int fndInd = 0;            // Index of number if found

    for (int i = 0; i < numOflstArr; i++) {
        bool numInList = SearchList(lssArr, numOflssArr, lstArr[i], fndInd);

        if (numInList) {
            cout << "Number " << i + 1 << " (" << lstArr[i] << ") was located at index " << fndInd << "." << endl;
        }
        else {
            cout << "Number " << i + 1 << " (" << lstArr[i] << ") was not in the file." << endl;
        }

    }

}

// Errors Found in Code:
// - You set the max of the LSTest array to 23? When it should be 50
// - You should set a counter to see how many are stored in the array instead of changing those values
// - Should not use 'pos' global variable as fndInd has a '&' reference to it so it changes and returns the value
// - Should use names that better reflect what they are at first glance
// - Found index is never set back to zero so it keeps on adding on and on and on