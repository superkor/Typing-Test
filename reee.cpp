#include <stdio.h>
#include <time.h>
#include <iostream>

//kekw lmao hf
using namespace std;

class firstClass{
    public: 
        int myNum;
        void method(){
            cout << "reached this method\n";
        }
};

int main(){
    int input;
    time_t start_t, end_t;
    double diff_t;
    firstClass firstObject;

    //starts time
    time(&start_t);
    //asks user to input a number and assign the value to the variable input
    cout << "enter a number: ";
    cin >> input;
    cout << "You entered " << input << "\n";
    //ends the time
    time(&end_t);

    //takes the difference of the end and start time
    diff_t = difftime(end_t, start_t);

    //outputs the difference
    cout << "It took " << diff_t << " seconds\n";

    //if input is 69, it calls the method "method()" from the firstObject object of firstClass
    if (input == 69){
        firstObject.method();
    }

    //sets the input value equal to the myNum attribute of firstObject
    firstObject.myNum = input;

    //outputs the myNum attribute value
    cout << firstObject.myNum;

    return 0;
}