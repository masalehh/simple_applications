/**
    hi_lo.cpp
    Purpose: practice code application
    comment: this is a simple guessing game known as hi-lo game

    @author MA Saleh
*/

#include<iostream>
#include<cstdlib>
#include<random>
#include<ctime>                                                                 //for taking the current time from system

using namespace std;


int getRandomNumber(int min, int max);                                          //this is a function which can generate a random number between min and max (inclusive)
bool playGame(int guesses, int number);                                         //a function for check the user guess and return true if user can guess otherwise false
bool playAgian();                                                               //this function take acknowledgement from user
void gameEngine();


int main()                                                                      //main funtion started
{
    srand(static_cast<unsigned int>(time(0)));                                  //set initial seed value is current time of system

    rand();

    gameEngine();

    cout << "\nThank you for playing the intellegent hi-lo game\n";

    return 0;
}                                                                               //end of main


int getRandomNumber(int min, int max)                                           //this is a function which can generate a random number between min and max (inclusive)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min +1) + min );
}

bool playGame(int guesses, int number)                                          //a function for check the user guess and return bool value if user can guess or not
{
    for(int count =0; count < guesses; count++)                                 //looping through all of guesses
    {
        cout << "Guess#  " << count +1 << " :" ;
        int guess;
        cin >> guess;

        if(guess>number) cout << "Your guess is too high\n";
        else if(guess<number) cout << "Your guess is too low\n";
        else if(guess == number) return true;
    }
    return false;
}


bool playAgian()                                                                //this function take acknowledgement from user
{
    char ch;
    do
    {
        cout << "would you like to paly agian? (Y/N)";
        cin >> ch;

    } while (ch != 'Y' && ch != 'N');                                           //show the options untill user give Y or N

    return (ch == 'Y');
}


void gameEngine()                                                               //nothing return, just operate functions and role to play the game
{
    const int guesses = 7;

    do                                                                          //do while loop started
    {
        int number = getRandomNumber(1, 100);                                    //system randomly choose a number

        cout << "Lets play a game, I am thinking of  a number, you have " << guesses << " tries to what it is? \n";

        bool won = playGame(guesses, number);


        if(won)                                                                    //check user win or not
        {
            cout << "Correct you win!\n";
        }
        else cout << "Sorry! you loose. The correct number was: " << number << endl;
    } while(playAgian());                                                           //do while loop end
}

/**end of the program*/
