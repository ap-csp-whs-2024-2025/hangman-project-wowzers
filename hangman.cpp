/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<std::string> hint = std::vector<std::string>(8, "_");    // Note that hint is globally available; we want it to be like this for this project

bool getHint(std::string secret, char guessLetter)
{
    bool correctGuess = false;
    int index = 0;
    while (index < length(hint))
    {
        if (secret[index] == guessLetter)
        {
            hint[index] = guessLetter;
            correctGuess = true;
        }
        index = index + 1;
    }   
    return correctGuess;
}


int main()
{
    srand(time(0)); // seeding the random number generator

    // Creating a word bank
    std::vector<std::string> wordList = {
        "education",
        "solution",
        "mountain",
        "platinum",
        "qlphabet",
        "necklace",
        "elevator",
        "diamonds",
        "fragrant",
        "velocity",
        "graduate",
        "nebraska",
        "tropical",
        "evidence",
        "involved",
        "shopping",
        "baseball",
        "kangaroo",
        "horrible",
        "animals"
    };
    
    // answer is a random word from the word bank
    std::string answer = wordList[rand() % length(wordList)];
    char letterGuess;
    std::string wordGuess = "";
    int lives = 10;

    std::cout << "Welcome to Hangman!\n";
    
    while (wordGuess != answer && lives > 0) 
    {
        std::cout << "\nEnter your guess: ";
        std::cin >> letterGuess;
        
        
        if (getHint(answer, letterGuess) == false)
        {
            lives = lives - 1;
        }
        std::cout << "Number of lives:" << lives << std::endl;
        display(hint);
        
        std::cout << "Would you like to guess the word (y/n)?\n";
        std::string choice;
        std::cin >> choice;
        if (choice == "y") {
            std::cout << "Guess the word\n";
            std::cin >> wordGuess;

            if (wordGuess != answer) {
                lives = lives -1;
            }
        }
    }

    if (lives <= 0) {
        std::cout << "Game Over" << std::endl;
    } else {
        std::cout << "You Win!" << std::endl;
    }
    return 0;
}
