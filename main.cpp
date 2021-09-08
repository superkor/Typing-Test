#include <time.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

class typeTest{
    int value = 1;
    string text;
    vector <string> dictionary;
    int v1;
    int length;
    vector<string> used;
    vector<string> enteredWords;
    int correctCharacters = 0;
    int wrongCharacters = 0;
    int w =0,n=0;

    public:
        void setup(){
            //creates a vector list of the words in the text document
            ifstream myFile ("wordList.txt");
            while (getline (myFile, text)){
                dictionary.push_back(text);
            }
        }
        string getWord(){
            string word;
            //generates a "random" number between 0 and but not including, the length of dictionary vector
            v1 = rand() % dictionary.size();
            word = dictionary[v1];
            used.push_back(word);
            return word;
        }
        void randLength(){
            //return a random number between 20 and 100 inclusive (will be amount of words the user will be required to type)
            length = (rand()%80)+20;
        }
        void addInput(string s){
            enteredWords.push_back(s);
        }

        //lmao
        void check(){
            //NESTED WHILE LOOPS???????
            while(true){
                while (true){
                   // cout << "used LETTER: " << used[n][w] << endl;
                   // cout << "enteredWords LETTER: " << enteredWords[n][w] << endl;
                    if (used[n][w]!=enteredWords[n][w]){
                        //cout << "wrong" << endl;
                        wrongCharacters++;
                    } else {
                        //cout << "right" << endl;
                        correctCharacters++;
                    }
                    if (w >= used[n].size()-1){
                        break;
                    } else {
                        w++;
                        //cout << "SIZE W " << w << endl;
                    }

                }
                if (n >= used.size()-1){
                    break;
                }else{
                    n++;
                    w = 0;
                    //cout << "SIZE N " << n << endl;
                }                                                              
            }
        }   

        int getWrong(){
            return wrongCharacters;
        }

        int getRight(){
            return correctCharacters;
        }

        double accuracy(){
            return double ((correctCharacters)/(wrongCharacters+correctCharacters))*100;
        }

        double WPM(double time){
            double wpm = length/time;
            return wpm;
        }

        int getLength(){
            return length;
        }

        void setLength(int a){
            length = a;
        }
};

int main(){
    time_t start_t, end_t;
    double diff_t;
    typeTest test;
    string input;
    int right,wrong,a;
    string cycle ="";
    //set seed with srand() with current time
    srand((unsigned) time(0));
    
    cout << "Typing Test in C++ by Justin Chow and Mike Kim" << endl;
    cout << "Created on July 24, 2021" << endl;
    cout << "Simply type the word on the screen and press enter when finished." << endl;

    test.setup();

    while (true){
        cout << "How many words? Enter -1 to get a random number of words to type: ";
        cin >> a;
        if (a > 0){
            test.setLength(a);
        } else {
            test.randLength();
            cout << "There will be "<< test.getLength() << " words" << endl;
        };

        cout << "The test will begin when you press any key!" << endl;
        system("pause");

        //starts time
        time(&start_t);

        for (int x = 0; x < test.getLength(); x++){
            cout << test.getWord() << endl;
            cin >> input;
            test.addInput(input);
        }
        
        //ends the time
        time(&end_t);

        test.check();

        wrong = test.getWrong();
        right = test.getRight();

        cout << "Your accuracy is: " << test.accuracy() << "%" << endl;

        cout << "You got: " << test.WPM(diff_t) << " WPM and took " << diff_t << " seconds" << endl;

        cout << "Retry? (y - Yes, n - No)";
        cin >> cycle;
        if (cycle == "n"){
            cout << "Thank you!" << endl;
            break;
        };
    };
    system("pause");
}