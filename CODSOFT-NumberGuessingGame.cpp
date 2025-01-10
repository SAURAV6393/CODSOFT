#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to display the game introduction and instructions
void displayIntro(int minRange, int maxRange) {
    cout << "********************************************" << endl;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "********************************************" << endl;
    cout << "I have chosen a number between " << minRange << " and " << maxRange << "." << endl;
    cout << "Your goal is to guess that number." << endl;
    cout << "You will always have 10 attempts to guess it correctly." << endl;
    cout << "Good luck! Let's begin!" << endl;
    cout << "********************************************" << endl;
}

// Function to handle the guessing game logic
void playGame(int minRange, int maxRange) {
    int targetNumber, playerGuess, attemptsLeft = 10;

    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Pick a random number between minRange and maxRange
    targetNumber = rand() % (maxRange - minRange + 1) + minRange;

    // Main game loop with exactly 10 attempts
    while (attemptsLeft > 0) {
        cout << "\nYou have " << attemptsLeft << " attempts remaining." << endl;
        cout << "Enter your guess: ";
        cin >> playerGuess;

        // Check if the input is valid
        if (cin.fail()) {
            cin.clear(); // Clear the input buffer
            cin.ignore(1000, '\n'); // Ignore invalid characters
            cout << "Oops! That's not a valid number. Please enter a valid number." << endl;
            continue;
        }

        // Provide feedback on the player's guess
        if (playerGuess < targetNumber) {
            cout << "Your guess is too low. Try again!" << endl;
        } else if (playerGuess > targetNumber) {
            cout << "Your guess is too high. Try again!" << endl;
        } else {
            cout << "\nCongratulations! You guessed the correct number: " << targetNumber << "!" << endl;
            break;
        }

        attemptsLeft--; // Decrease attempts after each guess

        if (attemptsLeft == 0) {
            cout << "\nSorry! You've run out of attempts." << endl;
            cout << "The correct number was: " << targetNumber << endl;
        }
    }
}

int main() {
    const int minRange = 1, maxRange = 100;

    // Display the game introduction and instructions
    displayIntro(minRange, maxRange);

    // Start the guessing game with exactly 10 attempts
    playGame(minRange, maxRange);

    return 0;
}
