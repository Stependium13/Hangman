#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

vector<string> words={"mother", "church", "membership", "can", "cat", "god", "phone", "laptop", "language", "lion", "tiger"};
vector<char> word={};
vector<char> guess={};
int lives = 5;
char guess_char;

template<typename T>
T getRandomElement(const vector<T>& vec){
    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_int_distribution<> dis(0, vec.size()-1);
    return vec[dis(gen)];

}


void Guess(){
    if (lives != 0){
        cout << endl;
        cin >> guess_char;
        bool guessed = false;
        for (size_t i = 0; i<word.size(); ++i){
            if (guess_char == word[i]){
                guess[i] = guess_char;
                guessed = true;
            }
        }

        if (guessed){
            for (const char& i: guess){
                cout << i << " ";
            }

            bool found = false;
            for (const char& i: guess){
                if (i == '_'){
                    found = true;
                }
            }
            if (found){
                Guess();
            }
            else{
                cout << "\nCongratulations!";
            }
        }

        else{
            lives -= 1;
            cout << "mistake\n";
            for (const char& i: guess){
                cout << i << " ";
            }
            Guess();
        }


    }
    else{
        cout << "\nYou failed" << endl << "The word was: ";
        for (const char& i: word){
            cout << i;
        }
    }
}


int main(){
    string wordToGuess = getRandomElement(words);
    for (const char& i: wordToGuess){
        word.push_back(i);
        guess.push_back('_');
    }
    for (const char& i: guess){
        cout << i << ' ';
    }
    Guess();
};


