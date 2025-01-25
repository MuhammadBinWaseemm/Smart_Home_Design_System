#include<iostream>
#include<windows.h>
#include<MMsystem.h>
#include<cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
#include"Account.cpp"
class Colors
{
	public:	
	    int color=10;
	    int color1;
	    void Design()
	    {
	    	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,color1);
		    cout<<"  ";
	    	
		}
	    const void Default()
	    {
	    	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,color);
		}
	    const void Black()
	    {
	    	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,0);
		    cout<<"  ";
		}
		const void White()
		{
			HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,255);
		    cout<<"  ";
		}
	    const void DarkBlue()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		    SetConsoleTextAttribute(console_color,1);
		    color1=17;
		}
		const void DarkGreen()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,2);
			color1=34;
		}
		const void Red()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
			color1=68;
		}
		const void DarkPurple()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,5);
			color1=85;
		}
		const void Gold()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,6);
			color1=102;
		}
		const void Blue()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,9);
			color1=153;
		}
		const void Green()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
			color1=170;
		}
		const void Turquoise()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,11);
			color1=187;
		}
		const void Coral()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		    SetConsoleTextAttribute(console_color,12);
		    color1=204;
		}
		const void Pink()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,13);
			color1=221;
		}
		const void White1()
		{
			HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,15);
			color1=255;
		}
};
class Theme
{
	public:
		int color1;
		int color2;
		const void Design()
		{
			HANDLE console_color; 
			SetConsoleTextAttribute(console_color,color1);
			cout<<" ";
			SetConsoleTextAttribute(console_color,color2);
			cout<<" ";
		}
		const void Default()
		{
			HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color, 10);
			color1=0;
			color2=170;
		}
		const void Zebra()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_color,240);
            color1=255;
            color2=0;
		}
		const void Aqua()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,177);
			color1=187;
			color2=17;
		}
		const void Buraikan()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_color,96);
            color1=102;
            color2=0;
		}
		const void Blueberry()
		{
		      HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_color,180);
            color1=187;
            color2=68;
		}
		const void Jamun()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_color,219);
            color1=221;
            color2=187;
		}	
};
class Game {
public:
    virtual void play() = 0; // Pure virtual function
};

class NumberGuessingGame : public Game {
private:
    int secretNumber;
    int tries;
    int guess;
    int rangeMin;
    int rangeMax;

public:
    NumberGuessingGame(int min, int max) {
        rangeMin = min;
        rangeMax = max;
        srand(time(nullptr)); // Seed the random number generator
        secretNumber = rand() % (rangeMax - rangeMin + 1) + rangeMin; // Generate random number within range
        tries = 0;
    }

    void play() override {
        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "I have selected a number between " << rangeMin << " and " << rangeMax << ". Guess it!" << endl;

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            ++tries;

            if (guess < secretNumber)
                cout << "Too low! Try again." << endl;
            else if (guess > secretNumber)
                cout << "Too high! Try again." << endl;
            else
                cout << "Congratulations! You guessed the number in " << tries << " tries." << endl;

        } while (guess != secretNumber);
    }
};

class WordGuessingGame : public Game {
private:
    vector<string> words;
    string secretWord;
    int tries;
    string guess;

public:
    WordGuessingGame() {
        words = {"apple", "banana", "orange", "grape", "strawberry"};
        srand(time(nullptr)); // Seed the random number generator
        secretWord = words[rand() % words.size()]; // Choose a random word from the list
        tries = 0;
    }

    void play() override {
        cout << "Welcome to the Word Guessing Game!" << endl;
        cout << "I have selected a word. Guess it!" << endl;

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            ++tries;

            if (guess != secretWord)
                cout << "Incorrect guess! Try again." << endl;
            else
                cout << "Congratulations! You guessed the word \"" << secretWord << "\" in " << tries << " tries." << endl;

        } while (guess != secretWord);
    }
};

class DiceRollingGame : public Game {
private:
    int die1;
    int die2;
    int total;

public:
    DiceRollingGame() {
        srand(time(nullptr)); // Seed the random number generator
    }

    void play() override {
        cout << "Welcome to the Dice Rolling Game!" << endl;
        cout << "Roll two dice. If the total is 7 or 11, you win!" << endl;

        die1 = rand() % 6 + 1; // Roll die 1
        die2 = rand() % 6 + 1; // Roll die 2
        total = die1 + die2;   // Calculate total

        cout << "You rolled: " << die1 << " and " << die2 << " (total: " << total << ")" << endl;

        if (total == 7 || total == 11)
            cout << "Congratulations! You win!" << endl;
        else
            cout << "Sorry, you lose. Better luck next time!" << endl;
    }
};

class CoinFlippingGame : public Game {
public:
    void play() override {
        cout << "Welcome to the Coin Flipping Game!" << endl;
        cout << "I will flip a coin. Guess heads or tails." << endl;

        int guess;
        cout << "Enter your guess (0 for heads, 1 for tails): ";
        cin >> guess;

        int result = rand() % 2; // 0 for heads, 1 for tails

        if (guess == result)
            cout << "Congratulations! You guessed correctly!" << endl;
        else
            cout << "Sorry, you guessed wrong. Better luck next time!" << endl;
    }
};

class RockPaperScissorsGame : public Game {
public:
    void play() override {
        cout << "Welcome to the Rock-Paper-Scissors Game!" << endl;
        cout << "Choose your move (0 for Rock, 1 for Paper, 2 for Scissors)." << endl;

        int playerMove;
        cout << "Enter your move: ";
        cin >> playerMove;

        int computerMove = rand() % 3; // 0 for Rock, 1 for Paper, 2 for Scissors

        cout << "Computer chose: ";
        if (computerMove == 0)
            cout << "Rock";
        else if (computerMove == 1)
            cout << "Paper";
        else
            cout << "Scissors";

        cout << endl;

        if ((playerMove == 0 && computerMove == 2) || (playerMove == 1 && computerMove == 0) || (playerMove == 2 && computerMove == 1))
            cout << "Congratulations! You win!" << endl;
        else if (playerMove == computerMove)
            cout << "It's a draw!" << endl;
        else
            cout << "Sorry, you lose. Better luck next time!" << endl;
    }
};

class LetterGuessingGame : public Game {
private:
    string secretWord;
    string word;
    char guess;
    int tries;

public:
    LetterGuessingGame() {
        vector<string> words = {"hello", "world", "programming", "challenge", "game"};
        srand(time(nullptr)); // Seed the random number generator
        secretWord = words[rand() % words.size()]; // Choose a random word from the list
        word = string(secretWord.length(), '-'); // Initialize word to display dashes
        tries = 0;
    }

    void play() override {
        cout << "Welcome to the Letter Guessing Game!" << endl;
        cout << "Try to guess the letters in the word." << endl;

        do {
            cout << "Word: " << word << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            ++tries;

            bool found = false;
            for (int i = 0; i < secretWord.length(); ++i) {
                if (secretWord[i] == guess) {
                    word[i] = guess;
                    found = true;
                }
            }

            if (!found)
                cout << "Incorrect guess! Try again." << endl;

        } while (word != secretWord);

        cout << "Congratulations! You guessed the word \"" << secretWord << "\" in " << tries << " tries." << endl;
    }
};

class AnimalGuessingGame : public Game {
private:
    vector<string> animals;
    string secretAnimal;
    string guess;
    int tries;

public:
    AnimalGuessingGame() {
        animals = {"dog", "cat", "elephant", "lion", "tiger"};
        srand(time(nullptr)); // Seed the random number generator
        secretAnimal = animals[rand() % animals.size()]; // Choose a random animal from the list
        tries = 0;
    }

    void play() override {
        cout << "Welcome to the Animal Guessing Game!" << endl;
        cout << "I have selected an animal. Guess it!" << endl;

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            ++tries;

            if (guess != secretAnimal)
                cout << "Incorrect guess! Try again." << endl;

        } while (guess != secretAnimal);

        cout << "Congratulations! You guessed the animal \"" << secretAnimal << "\" in " << tries << " tries." << endl;
    }
};

class CountryGuessingGame : public Game {
private:
    vector<string> countries;
    string secretCountry;
    string guess;
    int tries;

public:
    CountryGuessingGame() {
        countries = {"USA", "Canada", "Brazil", "China", "India"};
        srand(time(nullptr)); // Seed the random number generator
        secretCountry = countries[rand() % countries.size()]; // Choose a random country from the list
        tries = 0;
    }

    void play() override {
        cout << "Welcome to the Country Guessing Game!" << endl;
        cout << "I have selected a country. Guess it!" << endl;

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            ++tries;

            if (guess != secretCountry)
                cout << "Incorrect guess! Try again." << endl;

        } while (guess != secretCountry);

        cout << "Congratulations! You guessed the country \"" << secretCountry << "\" in " << tries << " tries." << endl;
    }
};

class TicTacToe : public Game {
private:
    vector<vector<char>> board;
    char currentPlayer;
    bool gameOver;

public:
    TicTacToe() {
        board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        currentPlayer = 'X';
        gameOver = false;
    }

    void printBoard() {
        cout << "  1 2 3" << endl;
        cout << " -------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << "|";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << "|";
            }
            cout << endl << " -------" << endl;
        }
    }

    bool checkWin(char player) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ')
                    return false; // If any empty cell found, game is not draw
            }
        }
        return true; // All cells are filled, game is draw
    }

    void play() override {
        cout << "Welcome to Tic Tac Toe!" << endl;
        cout << "Player 1: X, Player 2: O" << endl;

        while (!gameOver) {
            printBoard();

            int row, col;
            cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move! Try again." << endl;
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWin(currentPlayer)) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw()) {
                printBoard();
                cout << "It's a draw!" << endl;
                gameOver = true;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
};
class MyComputer
{
	protected:
		char choose;
		char choose2;
		char choose3;
		static bool status;
		Colors C;
		Theme T;
	public:
		virtual void display()=0;
};

class MyWork:public MyComputer
{
	private:
		string student="u2023403";
		string pass="12345";
		string st;
		string p;
		struct teacher
		{
			int total;
			char type;
			char A1;
			char A2;
			char A3;
			char A4;
			char A5;
			char A6;
			char A7;
			char A8;
			char A9;
			char A10;
			string name;
			string Q1;
			string Q2;
			string Q3;
			string Q4;
			string Q5;
			string Q6;
			string Q7;
			string Q8;
			string Q9;
			string Q10;
		}T[5];
		struct student
		{
			char A1;
			char A2;
			char A3;
			char A4;
			char A5;
			char A6;
			char A7;
			char A8;
			char A9;
			char A10;
		    int marks=0;
		}S[5];
		struct attempt
		{
			char ch;
		}C[5];
		public:
			friend class Printer;
			int ch1[5];
			int total[5];
			int Quiz=0;
			int Remaining=5;
			int count=0;
			void display()
		{
			if(status==1)
			{	
				portal1:system("cls");
				cout<<"\n\t\tOnline Portal\n ";
				cout<<"\n\t\t1.Teacher\n ";
				cout<<"\n\t\t2.Student ";
				cout<<"\n\nReturn(R)";
				cout<<"\n\n\tChoose from (1-2) : ";
				cin>>choose;
				switch(choose)
				{
					while(1)
					{
						case '1':
							portal:system("cls");;
							system("cls");
							cout<<"\n\t\tTeacher Portal\n";
							cout<<"\n\t1.Make Quiz ";
							cout<<"\n\t2.View Quiz Results";
							cout<<"\n\nReturn(R)";
							cin>>choose2;
							switch(choose2)
							{
								case '1':
									Quizz:system("cls");
									if(Remaining==0 )
									{
										cout<<"\n\t\tSorry You have already created 5 Quizzez";
										system("pause");
										goto portal1;
									}
									cout<<"\n\t\tQuizzez";
									cout<<"\n\t\tHow many quizzez do you want to make?(1-5)";
									cout<<"Remaining:"<<Remaining;
									cout<<"\n\t\tNote:Mcq's and True/false quizzez of total 10 marks are available : ";
									Quizz0:;
									cin>>Quiz;
									if(Quiz>Remaining)
									{
										cout<<"\n\t\tYou have only "<<Remaining<<" remaining";
										goto Quizz0;
									}
									if(Quiz!=5 && Quiz!=1 && Quiz!=4 && Quiz!=3 && Quiz!=2)
							       {
									    	cout<<"\nInvalid number";
									    	goto Quizz0;
									}
									for(int i=0,n=0  ; n<Quiz ; n++)
									{
										if(Remaining!=5)
										{
										    i=5-Remaining;
										}
										Quizzz:;
										cout<<"\n\t1.MCQ'S";
										cout<<"\n\t2.True/False";     
										cin>>choose3;    
									    if(choose3!='1' && choose3!='2' )
									        goto Quizzz;
										T[i].type=choose3;             
										system("cls");           
										cout<<"\n\t\tQuiz Name : ";
										cin>>T[i].name;
										cout<<"\n\tPlease Terminate every question with a Question Mark ";
										cout<<"\n\tFor MCQS your answer should be a/b/c/d";
										cout<<"\n\tFor True/False your answer should be t/f";
										cout << "\nQuestion 1 : ";
										Remaining--;
										getline(cin,T[i].Q1, '?');
										A1:;
										cout << "\nAnswer 1 : ";
										cin >> T[i].A1;
										if (T[i].A1 != 'a' && T[i].A1 != 'A' && T[i].A1 != 'b' && T[i].A1 != 'B' && T[i].A1 != 'c' && T[i].A1 != 'C' && T[i].A1 != 'd' && T[i].A1 != 'D' && T[i].A1 != 't' && T[i].A1 != 'T' && T[i].A1 != 'f' && T[i].A1 != 'F')
										    {
										    	cout<<"\nYou can only input a/b/c/d or T/F";
										    	goto A1;
											}
										
										cout << "\nQuestion 2 : ";
										getline(cin,T[i].Q2, '?');
										A2:;
										cout << "\nAnswer 2 : ";
										cin >> T[i].A2;
										if (T[i].A2 != 'a' && T[i].A2 != 'A' && T[i].A2 != 'b' && T[i].A2 != 'B' && T[i].A2 != 'c' && T[i].A2 != 'C' && T[i].A2 != 'd' && T[i].A2 != 'D' && T[i].A2 != 't' && T[i].A2 != 'T' && T[i].A2 != 'f' && T[i].A2 != 'F')
										    {
											    cout<<"\nYou can only input a/b/c/d or T/F";
										        goto A2;
										    }
										
										cout << "\nQuestion 3 : ";
										getline(cin,T[i].Q3, '?');
										A3:;
										cout << "\nAnswer 3 : ";
										cin >> T[i].A3;
										if (T[i].A3 != 'a' && T[i].A3 != 'A' && T[i].A3 != 'b' && T[i].A3 != 'B' && T[i].A3 != 'c' && T[i].A3 != 'C' && T[i].A3 != 'd' && T[i].A3 != 'D' && T[i].A3 != 't' && T[i].A3 != 'T' && T[i].A3 != 'f' && T[i].A3 != 'F')
										    {
											    cout<<"\nYou can only input a/b/c/d or T/F";
										        goto A3;
										    }
										cout << "\nQuestion 4 : ";
										getline(cin,T[i].Q4, '?');
										A4:;
										cout << "\nAnswer 4 : ";
										cin >> T[i].A4;
										if (T[i].A4 != 'a' && T[i].A4 != 'A' && T[i].A4 != 'b' && T[i].A4 != 'B' && T[i].A4 != 'c' && T[i].A4 != 'C' && T[i].A4 != 'd' && T[i].A4 != 'D' && T[i].A4 != 't' && T[i].A4 != 'T' && T[i].A4 != 'f' && T[i].A4 != 'F')
										    {
											    cout<<"\nYou can only input a/b/c/d or T/F";
										   		goto A4;
										   	}
										cout << "\nQuestion 5 : ";
										getline(cin,T[i].Q5, '?');
										A5:;
										cout << "\nAnswer 5 : ";
										cin >> T[i].A5;
										if (T[i].A5 != 'a' && T[i].A5 != 'A' && T[i].A5 != 'b' && T[i].A5 != 'B' && T[i].A5 != 'c' && T[i].A5 != 'C' && T[i].A5 != 'd' && T[i].A5 != 'D' && T[i].A5 != 't' && T[i].A5 != 'T' && T[i].A5 != 'f' && T[i].A5 != 'F')
										    {
											    cout<<"\nYou can only input a/b/c/d or T/F";
										   		goto A5;
											}
										cout << "\nQuestion 6 : ";
										getline(cin,T[i].Q6, '?');
										A6:;
										cout << "\nAnswer 6 : ";
										cin >> T[i].A6;
										if (T[i].A6 != 'a' && T[i].A6 != 'A' && T[i].A6 != 'b' && T[i].A6 != 'B' && T[i].A6 != 'c' && T[i].A6 != 'C' && T[i].A6 != 'd' && T[i].A6 != 'D' && T[i].A6 != 't' && T[i].A6 != 'T' && T[i].A6 != 'f' && T[i].A6 != 'F')
										    {
												cout<<"\nYou can only input a/b/c/d or T/F";
										   		goto A6;
											}
										cout << "\nQuestion 7 : ";
										getline(cin,T[i].Q7, '?');
										A7:;
										cout << "\nAnswer 7 : ";
										cin >> T[i].A7;
										if (T[i].A7 != 'a' && T[i].A7 != 'A' && T[i].A7 != 'b' && T[i].A7 != 'B' && T[i].A7 != 'c' && T[i].A7 != 'C' && T[i].A7 != 'd' && T[i].A7 != 'D' && T[i].A7 != 't' && T[i].A7 != 'T' && T[i].A7 != 'f' && T[i].A7 != 'F')
										    {
												cout<<"\nYou can only input a/b/c/d or T/F";
												goto A7;
											}
										cout << "\nQuestion 8 : ";
										getline(cin,T[i].Q8, '?');
										A8:;
										cout << "\nAnswer 8 : ";
										cin >> T[i].A8;
										if (T[i].A8 != 'a' && T[i].A8 != 'A' && T[i].A8 != 'b' && T[i].A8 != 'B' && T[i].A8 != 'c' && T[i].A8 != 'C' && T[i].A8 != 'd' && T[i].A8 != 'D' && T[i].A8 != 't' && T[i].A8 != 'T' && T[i].A8 != 'f' && T[i].A8 != 'F')
										    {
											   cout<<"\nYou can only input a/b/c/d or T/F";
		    							   		goto A8;
											}
										cout << "\nQuestion 9 : ";
										getline(cin,T[i].Q9, '?');
										A9:;
										cout << "\nAnswer 9 : ";
										cin >> T[i].A9;
										if (T[i].A9 != 'a' && T[i].A9 != 'A' && T[i].A9 != 'b' && T[i].A9 != 'B' && T[i].A9 != 'c' && T[i].A9 != 'C' && T[i].A9 != 'd' && T[i].A9 != 'D' && T[i].A9 != 't' && T[i].A9 != 'T' && T[i].A9 != 'f' && T[i].A9 != 'F')
										   {
											    cout<<"\nYou can only input a/b/c/d or T/F";
										   		goto A9;
											}
										cout << "\nQuestion 10 : ";
										getline(cin,T[i].Q10, '?');
										A10:;
										cout << "\nAnswer 10 : ";
										cin >> T[i].A10;
										if (T[i].A10 != 'a' && T[i].A10 != 'A' && T[i].A10 != 'b' && T[i].A10 != 'B' && T[i].A10 != 'c' && T[i].A10 != 'C' && T[i].A10 != 'd' && T[i].A10 != 'D' && T[i].A10 != 't' && T[i].A10 != 'T' && T[i].A10 != 'f' && T[i].A10 != 'F')
											{
											    cout<<"\nYou can only input a/b/c/d or T/F";
										   		goto A10;
											} 
										cout<<"\n\t\tCompleted";
										system("pause");
			   							system("cls");
								    	}
								    	cout<<"\n\t\tFollowing are the quizzez you created : ";
								    	for(int i=0 ; i<5-Remaining ; i++)
								    	{
								    		cout<<"\n\t"<<i+1<<"."<<T[i].name<<"\t(";
								    		if(T[i].type=='1')
								    		    cout<<"MCQ's)";
								    		else
								    		    cout<<"True/False)";
										}
										system("pause");
										system("cls");
								        break;
							    case '2' :
							    	
							   	    cout<<"\n\tSR.NO"<<"\t\tName"<<"\t\tQuiz"<<"\t\tType"<<"\t\tMarks";
							       	for(int i=0;i<5-Remaining;i++)
							       	{
							       		if(ch1[i]!=0)
							       		        S[i].marks=total[i];
						        		cout<<"\n\t"<<i+1<<".\t\t"<<student<<"\t"<<T[i].name<<"\t\t(";
										if(T[i].type=='1')
							    		    cout<<"MCQ's)\t";
							    		else
							    		    cout<<"True/Flase)";
										cout<<"\t"<<S[i].marks<<"/10";
						        		if(ch1[i]==0)
					        		    	cout<<"(Not Attempted)";
						        	}
						        	system("pause");
					        		system("cls");
					        		goto portal;
						        case 'R' :
					            case 'r' :
					            	goto portal1;
						        default:
						        	cout<<"\n\t\tInvalid Command";
						        	goto portal;
						        	
				        }
						}
					    case '2':
					    	cout<<"\n\t\tStudent Portal";
					        system("cls");
					    	while(1)
					        {
								cout<<"\n\t\tUsername : ";
								cin>>st;
								if(st!=student)
								{
									PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"),NULL,SND_FILENAME | SND_SYNC);
									cout<<"\nUser not found.";
									continue;
								}
								break;
					        }
							while(1)
							{
							cout<<"\n\t\tPassword : ";
					        cin>>p;
					        if(p!=pass)
						    {
						    	PlaySound(TEXT("C:/Users/PC/Downloads/Denied.wav"),NULL,SND_FILENAME | SND_SYNC);
						    	cout<<"\nWrong Password.";
						    	continue;
						    }
						    break;
		    	     		}
		    	     		if(Remaining==5)
		    	     		{
		    	     			cout<<"\n\tThere are no quizzez at the moment . \n\t\tLogging you out.";
		    	     			system("pause");
		    	     			system("cls");
		    	     			goto portal1;
							}
							system("cls");
		    	     		while(1)
		    	     		{
		    	     			cout<<"\n\t\tStudent Portal ";
		    	     			for(int i=0 ; i<5-Remaining ; i++)
		    	     			{
								 	cout<<"\n\t"<<i+1<<"."<<T[i].name<<"\t(";
							    	if(T[i].type=='1')
							    	    cout<<"MCQ's)";
							    	else
							    	    cout<<"True/False)";
								}
			        			if(count==5-Remaining )
								{
									cout<<"\n\tSince you have already attempted every quiz , we are logging you out ";
									system("pause");
									goto portal1;
								}
								number:;
		    	     			cout<<"\n\tChoose the Quiz you want to answer : ";
		    	     			cin>>choose3;
		    	     			switch (choose3) 
								{
							        case '1':
							            Answer(1-1);
							            continue;
							        case '2':
							            Answer(2-1);
							            continue;
							        case '3':
							            Answer(3-1);
							            continue;
							        case '4':
							            Answer(4-1);
							            continue;
							        case '5':
							           Answer(5-1);
							        	continue;
							        default:
							        	cout<<"\n\tNo Such Quiz";
							        	goto number;
	                            }
		    	     			break;
							 }
					    case 'r':
					    case'R':
					    	break;
		    	     	default:
		    	     		cout<<"\n\t\tInvalid Command ! ";
		    	     		system("cls");
		    	     		goto portal1;
		    	        	break;
	    	    }
	    	        
	        	}
	    	else
	    	{
	    		cout<<"\n\t\tSorry can't access the device.The device is out of range or switched off.";
	    		system("pause");
			}
		}
		int Answer(int x)
		{
			system("cls");
			if(T[x].type!='1' && T[x].type!='2')
			{
				cout<<"\n\t\tNo Such Quiz";
				return 0;
			}
			if(C[x].ch==choose3)
			{
				cout<<"\n\t\tYou have already given response ";
				return 0;
			}
			C[x].ch=choose3;
			count++;
			cout<<"\nQuiz Name : ";
			cout<<T[x].name;
			cout<<"\nQuestion 1 : "<<T[x].Q1;
			cout<<"\nAnswer 1 : ";
			cin>>S[x].A1;
			cout<<"\nQuestion 2 : "<<T[x].Q2;
			cout<<"\nAnswer 2 : ";
			cin>>S[x].A2;
			cout<<"\nQuestion 3 : "<<T[x].Q3;
			cout<<"\nAnswer 3 : ";
			cin>>S[x].A3;
			cout<<"\nQuestion 4 : "<<T[x].Q4;
			cout<<"\nAnswer 4 : ";
			cin>>S[x].A4;
			cout<<"\nQuestion 5 : "<<T[x].Q5;
			cout<<"\nAnswer 5 : ";
			cin>>S[x].A5;
			cout<<"\nQuestion 6 : "<<T[x].Q6;
			cout<<"\nAnswer 6 : ";
			cin>>S[x].A6;
			cout<<"\nQuestion 7 : "<<T[x].Q7;
			cout<<"\nAnswer 7 : ";
			cin>>S[x].A7;
			cout<<"\nQuestion 8 : "<<T[x].Q8;
			cout<<"\nAnswer 8 : ";
			cin>>S[x].A8;
			cout<<"\nQuestion 9 : "<<T[x].Q9;
			cout<<"\nAnswer 9 : ";
			cin>>S[x].A9;
			cout<<"\nQuestion 10 : "<<T[x].Q10;
			cout<<"\nAnswer 10 : ";
			cin>>S[x].A10;
			ch1[x]=1;
			if(S[x].A1==T[x].A1 || S[x].A1+32==T[x].A1 || S[x].A1-32==T[x].A1)
				S[x].marks++;
			if(S[x].A2==T[x].A2 || S[x].A2+32==T[x].A2 || S[x].A2-32==T[x].A2)
			    S[x].marks++;
			if(S[x].A3==T[x].A3 || S[x].A3+32==T[x].A3 || S[x].A3-32==T[x].A3)
				S[x].marks++;
			if(S[x].A4==T[x].A4 || S[x].A4+32==T[x].A4 || S[x].A4-32==T[x].A4)
				S[x].marks++;
			if(S[x].A5==T[x].A5 || S[x].A5+32==T[x].A5 || S[x].A5-32==T[x].A5)
				S[x].marks++;
			if(S[x].A6==T[x].A6 || S[x].A6+32==T[x].A6 || S[x].A6-32==T[x].A6)
				S[x].marks++;
			if(S[x].A7==T[x].A7 || S[x].A7+32==T[x].A7 || S[x].A7-32==T[x].A7)
				S[x].marks++;
			if(S[x].A8==T[x].A8 || S[x].A8+32==T[x].A8 || S[x].A8-32==T[x].A8)
				S[x].marks++;
			if(S[x].A9==T[x].A9 || S[x].A9+32==T[x].A9 || S[x].A9-32==T[x].A9)
				S[x].marks++;
			if(S[x].A10==T[x].A10 || S[x].A10+32==T[x].A10 || S[x].A10-32==T[x].A10)
				S[x].marks++;
				total[x]=S[x].marks;
			cout<<"\n\t\tYour Quiz has ended ";
			system("pause");
			cout<<"\nYour Score : "<<S[x].marks<<"/10";
			system("pause");
			system("cls");
			return 0;
		}
	};
	class Printer
{
	private:
		MyWork P;
		char choose;
		char choose2;
		int quant;
		int T;
		int pages=50;
		bool status1=1;
		
	public:
		void control()
		{
			status1=0;
		}
		void control1()
		{
			status1=1;
		}

		void set(MyWork &MW)
		{
			P=MW;
		}
		void display()
		{
			s:system("cls");
			HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			cout<<"\n\t1.SwitchOn/Off       ";
  				if(status1==1)
  				{
  				        SetConsoleTextAttribute(console_color,255);
  				        cout<<"  ";
  				}
  			SetConsoleTextAttribute(console_color,10);
  			cout<<"\n\t2.Print Quizzez";
  			cout<<"\n\nReturn(R)";
  			cout<<"\n\nChoose between (1-2) : ";
  			cin>>choose2;
  			switch(choose2)
  			{
  				case '1':
  					if(status1==1)
  				         	status1=0;
  				        else
  				          	status1=1;
  				    goto s;
  					break;
  				case '2':
  					if(status1==1)
  					{
  					print:system("cls");
			T=0;
            cout<<"\n\t\tYour Quizzez";
			for(int i=0 ; i<5-P.Remaining ; i++)
	    	{
	    		cout<<"\n\t"<<i+1<<"."<<P.T[i].name<<"\t(";
	    		if(P.T[i].type=='1')
	    		    cout<<"MCQ's)";
	    		else
	    		    cout<<"True/False)";
			}
			cout<<"\n\nReturn(R)";
			cout<<"\n\n\tSelect the quiz you want to print : " ;
			ch1:;
			cin>>choose;
			switch(choose)
			{
				case '1':
					if(P.T[0].name!="\0")
						{
							system("cls");
							cout<<"\n\t\tQuiz : "<<P.T[0].name;
							cout<<"\n\n\t\tEnter The number of copies to be printed : ";
							cin>>quant;
							if(quant>pages)
							{
								cout<<"\n\t\tSorry there aren't enough pages left ";
								system("pause");
								goto print;
							}
							cout<<"\n\t\t"<<quant<<" copies of "<<P.T[0].name<<" quiz are being printed";
							T=quant;
							pages=pages-quant;
							cout<<"\n\t\tIt will take about "<<T<<" seconds";
							system("pause");
							goto print;
						}
					else
						cout<<"\n\t\tNo such quiz";
					goto ch1;	
					break;
				case '2':
					if(P.T[1].name!="\0")
						{
							system("cls");
							cout<<"\n\t\tQuiz : "<<P.T[1].name;
							cout<<"\n\t\tEnter The number of copies to be printed : ";
							cin>>quant;
							cout<<"\n\t\t"<<quant<<" copies of "<<P.T[1].name<<" quiz are being printed";
							T=quant;
							cout<<"\nIt will take about "<<T<<" seconds";
							system("pause");
							goto print;
						}
					else
						cout<<"\n\t\tNo such quiz";
					goto ch1;	
					break;
				case '3':
					if(P.T[2].name!="\0")
						{
							system("cls");
							cout<<"\n\t\tQuiz : "<<P.T[2].name;
							cout<<"\n\t\tEnter The number of copies to be printed : ";
							cin>>quant;
							cout<<"\n\t\t"<<quant<<" copies of "<<P.T[2].name<<" quiz are being printed";
							T=quant;
							cout<<"\nIt will take about "<<T<<" seconds";
							system("pause");
							goto print;
						}
					else
						cout<<"\n\t\tNo such quiz";
					goto ch1;	
					break;
				case '4':
					if(P.T[3].name!="\0")
						{
							system("cls");
							cout<<"\n\t\tQuiz : "<<P.T[3].name;
							cout<<"\n\t\tEnter The number of copies to be printed : ";
							cin>>quant;
							cout<<"\n\t\t"<<quant<<" copies of "<<P.T[3].name<<" quiz are being printed";
							T=quant;
							cout<<"\nIt will take about "<<T<<" seconds";
							system("pause");
							goto print;
						}
					else
						cout<<"\n\t\tNo such quiz";
					goto ch1;	
					break;
				case '5':
					if(P.T[4].name!="\0")
						{
							system("cls");
							cout<<"\n\t\tQuiz : "<<P.T[4].name;
							cout<<"\n\t\tEnter The number of copies to be printed : ";
							cin>>quant;
							cout<<"\n\t\t"<<quant<<" copies of "<<P.T[4].name<<" quiz are being printed";
							T=quant;
							cout<<"\nIt will take about "<<T<<" seconds";
							system("pause");
							goto print;
						}
					else
						cout<<"\n\t\tNo such quiz";
					goto ch1;	
					break;
				case 'R':
				case 'r':
					goto s;
					break;
				default:
					cout<<"\n\t\tInvalid Command";
					goto ch1;
					break;
				}}
				else
				{
					cout<<"\n\t\tSorry the device is switched off or out of range";
					system("pause");
					goto s;
				}
			break;
			case 'r':
			case 'R':
				break;
			default:
				cout<<"\n\t\tInvalid Command ";
				system("pause");
				goto s;	
			}
			
			}
			
			
			
		
};
class ComputerGames:public MyComputer
{
	private:
		char ch;
	public:
		void display()
	{
		if(status==1)
		{	
		    G:system("cls");
			cout<<"\n\t\tGames";
		    cout << "\n\t1. Number Guessing Game" << endl;
		    cout << "\n\t2. Word Guessing Game" << endl;
		    cout << "\n\t3. Dice Rolling Game" << endl;
		    cout << "\n\t4. Coin Flipping Game" << endl;
		    cout << "\n\t5. Rock-Paper-Scissors Game" << endl;
		    cout << "\n\t6. Letter Guessing Game" << endl;
		    cout << "\n\t7. Animal Guessing Game" << endl;
		    cout << "\n\t8. Country Guessing Game" << endl;
		    cout << "\n\t9. Tic Tac Toe Game " << endl;
		    cout<<"\n\nReturn(R)";
		    cout << "\tEnter your choice: ";
		    cin >> ch;
		
		    Game *game;
			system("cls");
		    switch (ch) 
			{
		        case '1':
		            game = new NumberGuessingGame(1, 100);
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '2':
		            game = new WordGuessingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '3':
		            game = new DiceRollingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '4':
		            game = new CoinFlippingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '5':
		            game = new RockPaperScissorsGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '6':
		            game = new LetterGuessingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '7':
		            game = new AnimalGuessingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '8':
		            game = new CountryGuessingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '9':
		        	game = new TicTacToe();
		        	game->play();
		        	system("pause");
		            goto G;
		        	break;
		        case 'R':
		        case 'r':
		        	break;
		        default:
		            cout << "Invalid choice!" << endl;
		            system("pause");
		            goto G;
		    }
		}
	else
	    	{
	    		cout<<"\n\t\tSorry can't access the device.The device is out of range or switched off.";
	    		system("pause");
			}
	 		
	}
};
class Settings : public MyComputer
{
	public:
		void Set()
		{
			C.Default();
		}
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			while(1)
			{
				settings:system("cls");
				cout<<"\n\t\tSettings\n";
				cout<<"\n\t1.SwitchOn/Off       ";
  				if(status==1)
  				{
  				    if(C.color==240)
  				        C.Black();
  				    else
  				        C.White();
  				}
				C.Default();
				cout<<"\n\t2.Text Color";
				cout<<"\n\t3.Theme";
				cout<<"\n\nReturn(R)";
				cout<<"\n\n\tChoose between (1-3):";
				choice2:;
				cin>>choose;
				switch(choose)
				{
					case '1':
  				        if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				        goto settings;
  				        break;
  				    case '2':
  				    		Text:system("cls");
  				    		cout<<"\n\t\tText Color(Black Background)";
  				    		cout<<"\n\n\t1.Red            ";
		  			C.Red();
		  			C.Design();
		  			C.Default();
		  			cout<<"\n\n\t2.DarkPurple     ";
		  			C.DarkPurple();
		  			C.Design();
		  			C.Default();
		  			cout<<"\n\n\t3.Gold           ";
		    		C.Gold();
		    		C.Design();
		    		C.Default();
		    		cout<<"\n\n\t4.Blue           ";
		    		C.Blue();
		    		C.Design();
		    		C.Default();
		    		cout<<"\n\n\t5.Green          ";
		    		C.Green();
		    		C.Design();
					C.Default();
					cout<<"\n\n\t6.Turquoise      ";
					C.Turquoise();
					C.Design();
					C.Default();
					cout<<"\n\n\t7.Coral          ";
					C.Coral();
					C.Design();
					C.Default();
					cout<<"\n\n\t8.Pink          ";
					C.Pink();
					C.Design();
					C.Default();
					cout<<"\n\n\t9.White         ";
					C.White1();
					C.Design();
					C.Default();
					cout<<"\n\nReturn(R)";
					cout<<"\n\n\tChoose between (1-9) : ";
					choice1:;
					cin>>choose2;
					switch(choose2)
					{
			    		case '1':
			    			C.Red();
			    			C.color=4;
			    			break;
			    		case '2':
							C.DarkPurple();
							C.color=5;
			    			break;
			    		case '3':
			    			C.Gold();
			    			C.color=6;
			    			break;
			    		case '4':
			    			C.Blue();
			    			C.color=9;
			    			break;
			    		case '5':
			    			C.Green();
			    			C.color=10;
			    			break;
			    		case '6':
			    			C.Turquoise();
			    			C.color=11;
			    			break;
			    		case '7':
			    			C.Coral();
			    			C.color=12;
			    			break;
			    		case '8':
			    			C.Pink();
			    			C.color=13;
			    			break;
			    		case '9':
			    	        C.White1();
			    	        C.color=15;
			    			break;
			    		case 'R':
			    		case 'r':
			    			goto settings;
			    			break;
			    		default:
			    			cout<<"\n\t\tInvalid Choice";
			    			goto choice1;
			    			break;
					       }
					         goto Text;
						     break;				    		
  				    case '3':
	  				    	Themes:system("cls");
	  				    	C.Default();
	  				    	cout<<"\n\n\t1.Default        ";
	  				    	T.Default();
	  				    	T.Design();
	  				    	C.Default();
	  				    	cout<<"\n\n\t2.Zebra          ";
	  				    	T.Zebra();
	  				    	T.Design();
	  				    	C.Default();
	  				    	cout<<"\n\n\t3.Aqua           ";
	  				    	T.Aqua();
	  				    	T.Design();
	  				    	C.Default();
	  				    	cout<<"\n\n\t4.Buraikan       ";
	  				    	T.Buraikan();
	  				    	T.Design();
	  				    	C.Default();
	  				    	cout<<"\n\n\t5.Blueberry      ";
	  				    	T.Blueberry();
	  				    	T.Design();
	  				    	C.Default();
	  				    	cout<<"\n\n\t6.Jamun          ";
	  				    	T.Jamun();
	  				    	T.Design();
	  				    	C.Default();
	  				    	cout<<"\n\nReturn(R)";
	  				    	cout<<"\n\n\tChoose from (1-6) : ";
	  				    	choice:;
	  				    	cin>>choose3;
	  				    	switch(choose3)
	  				    	{
	  				    		case '1':
	  				    			T.Default();
	  				    			C.color=10;
	  				    			break;
	  				    		case '2':
	  				    			T.Zebra();
	  				    			C.color=240;
	  				    			break;
	  				    		case '3':
	  				    			T.Aqua();
	  				    			C.color=177;
	  				    			break;
	  				    		case '4':
	  				    			T.Buraikan();
	  				    			C.color=96;
	  				    			break;
	  				    		case '5':
	  				    			T.Blueberry();
	  				    			C.color=180;
	  				    			break;
	  				    		case '6':
	  				    			T.Jamun();
	  				    			C.color=219;
	  				    			break;
	  				    		case 'R':
	  				    		case 'r':
	  				    			goto settings;
	  				    			break;
	  				    		default:
	  				    			cout<<"\n\t\tInvalid Choice";
	  				    			goto choice;
	  				    			break;
	  				    	}
							  goto Themes;
							  break;  	
  				        case 'R':
					    case 'r':
					    	break;
					    default:
					    	cout<<"\n\t\tInvalid choice";
					    	goto choice2;
					    	break;
				}
				if(choose=='R' || choose=='r')
					break;
						
	}
		}
};
class light:public Colors 
{
	private:
		bool status=1;
		char choose;
		char choose2;
		char choose3;
		string star={"*"};
		int Br=1;
	public:
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			LED:system("cls");
			Default();
			cout<<"\n\t1.SwitchOn/Off       ";
  			if(status==1)
  				White();
			Default();
			cout<<"\n\t2.LED light color";
			cout<<"\n\t3.Adjust Brightness   _ "<<Br;
			cout<<"\n\nReturn(R)";
			cout<<"\n\n\tChoose Between (1-3) : ";
			ch1:;
			cin>>choose;
			switch(choose)
			{
				case '1':
					if(status==1)
  				        status=0;
  				    else
  				        status=1;
  				    goto LED;
  				    break;
				case '2':
					Light:system("cls");
					cout<<"\n\t\tLED light Color";
		  			cout<<"\n\n\t1.Red            ";
		  			Red();
		  			Design();
		  			Default();
		  			cout<<"\n\n\t2.DarkPurple     ";
		  			DarkPurple();
		  			Design();
		  			Default();
		  			cout<<"\n\n\t3.Gold           ";
		    		Gold();
		    		Design();
		    		Default();
		    		cout<<"\n\n\t4.Blue           ";
		    		Blue();
		    		Design();
		    		Default();
		    		cout<<"\n\n\t5.Green          ";
		    		Green();
		    		Design();
					Default();
					cout<<"\n\n\t6.Turquoise      ";
					Turquoise();
					Design();
					Default();
					cout<<"\n\n\t7.Coral          ";
					Coral();
					Design();
					Default();
					cout<<"\n\n\t8.Pink           ";
					Pink();
					Design();
					Default();
					cout<<"\n\n\t9.White          ";
					White1();
					Design();
					Default();
					cout<<"\n\nReturn(R)";
					cout<<"\n\n\tChoose between (1-9) : ";
					choice1:;
					cin>>choose2;
					switch(choose2)
					{
			    		case '1':
			    			Red();
			    			color=4;
			    			break;
			    		case '2':
							DarkPurple();
							color=5;
			    			break;
			    		case '3':
			    			Gold();
			    			color=6;
			    			break;
			    		case '4':
			    			Blue();
			    			color=9;
			    			break;
			    		case '5':
			    			Green();
			    			color=10;
			    			break;
			    		case '6':
			    			Turquoise();
			    			color=11;
			    			break;
			    		case '7':
			    			Coral();
			    			color=12;
			    			break;
			    		case '8':
			    			Pink();
			    			color=13;
			    			break;
			    		case '9':
			    	        White1();
			    	        color=15;
			    			break;
			    		case 'R':
			    		case 'r':
			    			goto LED;
			    			break;
			    		default:
			    			cout<<"\n\t\tInvalid Choice";
			    			goto choice1;
			    			break;
			       }
			         goto Light;
				     break;
				case '3':
					Brightness:system("cls");
					cout<<"\n\t\tBrightness Level ";
					cout<<"\n\n\t1------2------3------4------5";
					cout<<"\n\t"<<star;
					cout<<"\n\nReturn(R)";
					cout<<"\n\t\tChoose Between (1-5)";
					ch:
					cin>>choose3;
					switch(choose3)
					{
						case '1':
							star={"*"};
							Br=1;
							break;
						case '2':
							star={"       *"};
							Br=2;
							break;
						case '3':
							star={"              *"};
							Br=3;
							break;
						case '4':
							star={"                     *"};
							Br=4;
							break;
						case '5':
							star={"                            *"};
							Br=5;
							break;
						case 'r':
						case 'R':
							goto LED;
							break;
						default:
							cout<<"\n\t\tInvalid Choice";
							goto ch;
							break;		
					}
					goto Brightness;
					break;
				case 'R':
				case 'r':
					break;
				default:
					cout<<"\n\t\tInvalid choice";
					goto ch1;	
					break;
			}
		}
};
class Fan
{
	private:
		bool status=1;
		char choose;
		char choose2;
		string star={"*"};
		int speed=1;
	public:
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			FAN:system("cls");
			HANDLE console_color; 
    	    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			LED:system("cls");
			cout<<"\n\t1.SwitchOn/Off       ";
  			if(status==1)
  			{
				SetConsoleTextAttribute(console_color,255);
			    cout<<"  ";
			}
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\t2.Adjust Speed   _ "<<speed;
			cout<<"\n\nReturn(R)";
			cout<<"\n\n\tChoose Between (1-2) : ";
			ch1:;
			cin>>choose;
			switch(choose)
			{
				case '1':
					if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				    goto FAN;
  				    break;
  				case '2':
  					speed:system("cls");
  					cout<<"\n\t\tFan's' Speed";
					cout<<"\n\n\t1------2------3------4------5";
					cout<<"\n\t"<<star;
					cout<<"\n\nReturn(R)";
					cout<<"\n\t\tChoose Between (1-5)";
					ch:;
					cin>>choose2;
					switch(choose2)
					{
						case '1':
							star={"*"};
							speed=1;
							break;
						case '2':
							star={"       *"};
							speed=2;
							break;
						case '3':
							star={"              *"};
							speed=3;
							break;
						case '4':
							star={"                     *"};
							speed=4;
							break;
						case '5':
							star={"                            *"};
							speed=5;
							break;
						case 'r':
						case 'R':
							goto FAN;
							break;
						default:
							cout<<"\n\t\tInvalid Choice";
							goto ch;
							break;	
					}
					goto speed;
					break;	
				case 'R':
				case 'r':
					break;
				default:
					cout<<"\n\t\tInvalid choice";
					goto ch1;	
					break;	
			}
		}
};
class ExhaustFan
{
	private:
		bool status=1;
		char choose;
		char choose2;
		string star={"*"};
		int speed=1;
	public:
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			FAN:system("cls");
			HANDLE console_color; 
    	    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			LED:system("cls");
			cout<<"\n\t1.SwitchOn/Off       ";
  			if(status==1)
  			{
				SetConsoleTextAttribute(console_color,255);
			    cout<<"  ";
			}
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\t2.Adjust Speed   _ "<<speed;
			cout<<"\n\nReturn(R)";
			cout<<"\n\n\tChoose Between (1-2) : ";
			ch1:;
			cin>>choose;
			switch(choose)
			{
				case '1':
					if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				    goto FAN;
  				    break;
  				case '2':
  					speed:system("cls");
  					cout<<"\n\t\tExhaust Fan's' Speed";
					cout<<"\n\n\t1------2------3------4------5";
					cout<<"\n\t"<<star;
					cout<<"\n\nReturn(R)";
					cout<<"\n\t\tChoose Between (1-5)";
					ch:;
					cin>>choose2;
					switch(choose2)
					{
						case '1':
							star={"*"};
							speed=1;
							break;
						case '2':
							star={"       *"};
							speed=2;
							break;
						case '3':
							star={"              *"};
							speed=3;
							break;
						case '4':
							star={"                     *"};
							speed=4;
							break;
						case '5':
							star={"                            *"};
							speed=5;
							break;
						case 'r':
						case 'R':
							goto FAN;
							break;
						default:
							cout<<"\n\t\tInvalid Choice";
							goto ch;
							break;	
					}
					goto speed;
					break;	
				case 'R':
				case 'r':
					break;
				default:
					cout<<"\n\t\tInvalid choice";
					goto ch1;	
					break;	
			}
		}
};
class Geyser
{
	private:
		bool status=1;
		char choose;
		char choose2;
		string star={"*"};
		int speed=30;
	public:
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			FAN:system("cls");
			HANDLE console_color; 
    	    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			LED:system("cls");
			cout<<"\n\t1.SwitchOn/Off       ";
  			if(status==1)
  			{
				SetConsoleTextAttribute(console_color,255);
			    cout<<"  ";
			}
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\t2.Adjust Temperature   _ "<<speed<<"C   ";
			SetConsoleTextAttribute(console_color,255);
			cout<<"  ";
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\nReturn(R)";
			cout<<"\n\n\tChoose Between (1-2) : ";
			ch1:;
			cin>>choose;
			switch(choose)
			{
				case '1':
					if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				    goto FAN;
  				    break;
  				case '2':
  					speed:system("cls");
  					cout<<"\n\t\tGeyser's Temperature";
					cout<<"\n\n\t30C----40C----50C----60C----70C";
					cout<<"\n\t"<<star;
					cout<<"\n\nReturn(R)";
					cout<<"\n\n\tNote : It will take some time to reach to the selected temperature";
					cout<<"\n\t\tChoose Between (1-5)";
					ch:;
					cin>>choose2;
					switch(choose2)
					{
						case '1':
							star={" *"};
							speed=30;
							break;
						case '2':
							star={"        *"};
							speed=40;
							break;
						case '3':
							star={"               *"};
							speed=50;
							break;
						case '4':
							star={"                      *"};
							speed=60;
							break;
						case '5':
							star={"                             *"};
							speed=70;
							break;
						case 'r':
						case 'R':
							goto FAN;
							break;
						default:
							cout<<"\n\t\tInvalid Choice";
							goto ch;
							break;	
					}
					goto speed;
					break;	
				case 'R':
				case 'r':
					break;
				default:
					cout<<"\n\t\tInvalid choice";
					goto ch1;	
					break;	
			}
		}
};
class AC
{
	private:
		bool status=1;
		char choose;
		char choose2;
		char choose3;
		string star={" *"};
		int temp=15;
		bool mode=1;
	public:
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			ACs:system("cls");
			HANDLE console_color; 
    	    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			LED:system("cls");
			cout<<"\n\t\tAir Conditioner";
			cout<<"\n\n\t1.SwitchOn/Off       ";
  			if(status==1)
  			{
				SetConsoleTextAttribute(console_color,255);
			    cout<<"  ";
			}
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\n\t2.Mode :Hot/Cool     ";
			if(mode==1)
  			{
  				SetConsoleTextAttribute(console_color,187);
			  	cout<<"  ";
			}
			if(mode==0)
			{
				SetConsoleTextAttribute(console_color,68);
	   			cout<<"  ";
			}
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\n\t3.Adjust Temperature   _ "<<temp<<"C   ";
			cout<<"\n\nReturn(R)";
			cout<<"\n\n\tChoose Between (1-3) : ";
			ch1:;
			cin>>choose;
			switch(choose)
			{
				case '1':
					if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				    goto ACs;
  				    break;
  				case '2':
  					modes:system("cls");
  					cout<<"\n\tMode";
  					cout<<"\n\t\t1.Cool     ";
  					if(mode==1)
  					{
  						SetConsoleTextAttribute(console_color,187);
			   			cout<<"  ";
					}
					SetConsoleTextAttribute(console_color,10);
					cout<<"\n\t\t2.Hot      ";
					if(mode==0)
					{
						SetConsoleTextAttribute(console_color,68);
			   			cout<<"  ";
					}
					SetConsoleTextAttribute(console_color,10);
					cout<<"\n\nReturn(R)";
					cout<<"\n\n\tChoose the mode(1-2) : ";
					select:;
					cin>>choose2;
					switch(choose2)
					{
						case '1':
							mode=1;
							temp=15;
							break;
						case '2':
							mode=0;
							temp=30;
							break;
						case 'R':
						case 'r':
							goto ACs;
							break;
						default:
							cout<<"\n\t\tInvalid Command";
							goto select;
							break;
					}
					goto modes;
					break;
					case '3':
						speed:system("cls");
						cout<<"\n\t\tAC's' Temperature";
						if(mode==0)
							cout<<"\n\n\t30C----40C----50C----60C----70C";
						else
						    cout<<"\n\n\t10C----15C----20C----22C----25C";
						cout<<"\n\t"<<star;
						cout<<"\n\nReturn(R)";
						cout<<"\n\n\t\tChoose Between (1-5)";
						ch:;
						cin>>choose3;
						switch(choose3)
						{
							case '1':
								star={" *"};
								if(mode==0)
									temp=30;
								else
									temp=10;
								break;
							case '2':
								star={"        *"};
								if(mode==0)
									temp=40;
								else
									temp=15;
								break;
							case '3':
								star={"               *"};
								if(mode==0)
									temp=50;
								else
									temp=20;
								break;
							case '4':
								star={"                      *"};
								if(mode==0)
									temp=60;
								else
									temp=22;
								break;
							case '5':
								star={"                             *"};
								if(mode==0)
									temp=70;
								else
									temp=25;
								break;
							case 'r':
							case 'R':
								goto ACs;
								break;
							default:
								cout<<"\n\t\tInvalid Choice";
								goto ch;
								break;	
						}
						goto speed;
						break;	
					case 'R':
					case 'r':
						break;
					default:
						cout<<"\n\t\tInvalid choice";
						goto ch1;	
						break;
						}
					}
						
};
class Freezer
{
	private:
		bool status=1;
		char choose;
		char choose2;
		string star={"*"};
		int speed=0;
	public:
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			FAN:system("cls");
			HANDLE console_color; 
    	    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			LED:system("cls");
			cout<<"\n\t1.SwitchOn/Off       ";
  			if(status==1)
  			{
				SetConsoleTextAttribute(console_color,255);
			    cout<<"  ";
			}
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\t2.Adjust Temperature   _ "<<speed<<"C   ";
			SetConsoleTextAttribute(console_color,187);
			cout<<"  ";
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\nReturn(R)";
			cout<<"\n\n\tChoose Between (1-2) : ";
			ch1:;
			cin>>choose;
			switch(choose)
			{
				case '1':
					if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				    goto FAN;
  				    break;
  				case '2':
  					speed:system("cls");
  					cout<<"\n\t\tFreezer's Temperature";
					cout<<"\n\n\t0C___-5C___-10C___-15C___-20C";
					cout<<"\n\t"<<star;
					cout<<"\n\nReturn(R)";
					cout<<"\n\n\tNote : It will take some time to reach to the selected temperature";
					cout<<"\n\t\tChoose Between (1-5)";
					ch:;
					cin>>choose2;
					switch(choose2)
					{
						case '1':
							star={"*"};
							speed=0;
							break;
						case '2':
							star={"      *"};
							speed=-5;
							break;
						case '3':
							star={"             *"};
							speed=-10;
							break;
						case '4':
							star={"                    *"};
							speed=-15;
							break;
						case '5':
							star={"                           *"};
							speed=-20;
							break;
						case 'r':
						case 'R':
							goto FAN;
							break;
						default:
							cout<<"\n\t\tInvalid Choice";
							goto ch;
							break;	
					}
					goto speed;
					break;	
				case 'R':
				case 'r':
					break;
				default:
					cout<<"\n\t\tInvalid choice";
					goto ch1;	
					break;	
			}
		}
	
};
class CoffeeMaker
{
	private:
		char Flavor;
		int Flavors[8]={2,5,3,6,8,9,4,1};
		bool check;
		int time=3;
		int cups;
		bool status =1;
		char choose2;
		public:
			void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
			void showSelection()                                                      //Function for showing menu
			{
				s:system("cls");
				HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			cout<<"\n\t1.SwitchOn/Off       ";
  				if(status==1)
  				{
  				        SetConsoleTextAttribute(console_color,255);
  				        cout<<"  ";
  				}
  			SetConsoleTextAttribute(console_color,10);
  			cout<<"\n\t2.Make Coffee";
  			cout<<"\n\nReturn(R)";
  			cout<<"\n\nChoose between (1-2) : ";
  			cin>>choose2;
  			switch(choose2)
  			{
  				case '1':
  					if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				    goto s;
  					break;
  				case '2':
  					if(status==1)
  					{
				Coff:system("cls");
				time=3;
				cout<<"\n\t\tCoffee Machine\n"<<"Flavours :\n";
		        cout<<"\n\t1.Caramel\n";
				cout<<"\n\t2.Vanilla\n";
				cout<<"\n\t3.Chocolate\n";                                                      //Different Flavors
				cout<<"\n\t4.Cappucino\n";
				cout<<"\n\t5.Latte\n";
				cout<<"\n\t6.Toffee Nut\n";
				cout<<"\n\t7.Irish\n";
				cout<<"\n\t8.Ice Coffee\n";
				cout<<"\n\nReturn(R)";
				cout<<"\n\n\tChoose from the flavor you want by entering(1-8) : ";
				f:;
				cin>>Flavor;
			    switch(Flavor)
			    {
			    	case '1':
			    		system("cls");
			    		cout<<"\n\t\tHow many cups you want to make : ";
			    		cin>>cups;
			    		if(cups<=Flavors[0])
			    		{
			    			cout<<"\nThe coffee is available ";
			    			time=time*cups;
					        cout<<"\nThe coffee will get ready in "<<time<<" minutes";
					        system("pause");
					        Flavors[0]=Flavors[0]-cups;
					        goto Coff;
						}
						else
						{
					        cout<<"\nSorry the coffee isn't available .Try another flavor.";
					        system("pause");
					        goto Coff;
						}
						break;
					case '2':
						system("cls");
			    		cout<<"\n\t\tHow many cups you want to make : ";
			    		cin>>cups;
			    		if(cups<=Flavors[1])
			    		{
			    			cout<<"\nThe coffee is available ";
					        time=time*cups;
					        cout<<"\nThe coffee will get ready in "<<time<<" minutes";
					        system("pause");
					        Flavors[1]=Flavors[1]-cups;
					        goto Coff;
						}
						else
						{
					        cout<<"\nSorry the coffee isn't available .Try another flavor.";
					        system("pause");
					        goto Coff;
						}
						break;
					case '3':
						system("cls");
			    		cout<<"\n\t\tHow many cups you want to make : ";
			    		cin>>cups;
			    		if(cups<=Flavors[2])
			    		{
			    			cout<<"\nThe coffee is available ";
			    			time=time*cups;
					        cout<<"\nThe coffee will get ready in "<<time<<" minutes";
					        system("pause");
					        Flavors[2]=Flavors[2]-cups;
					        goto Coff;
						}
						else
						{
					        cout<<"\nSorry the coffee isn't available .Try another flavor.";
					        system("pause");
					        goto Coff;
						}
						break;
					case '4':
						system("cls");
			    		cout<<"\n\t\tHow many cups you want to make : ";
			    		cin>>cups;
			    		if(cups<=Flavors[3])
			    		{
			    			cout<<"\nThe coffee is available ";
			    			time=time*cups;
					        cout<<"\nThe coffee will get ready in "<<time<<" minutes";
					        system("pause");
					        Flavors[3]=Flavors[3]-cups;
					        goto Coff;
						}
						else
						{
					        cout<<"\nSorry the coffee isn't available .Try another flavor.";
					        system("pause");
					        goto Coff;
						}
						break;
					case '5':
						system("cls");
			    		cout<<"\n\t\tHow many cups you want to make : ";
			    		cin>>cups;
			    		if(cups<=Flavors[4])
			    		{
			    			cout<<"\nThe coffee is available ";
			    			time=time*cups;
					        cout<<"\nThe coffee will get ready in "<<time<<" minutes";
					        system("pause");
					        Flavors[4]=Flavors[4]-cups;
					        goto Coff;
						}
						else
						{
					        cout<<"\nSorry the coffee isn't available .Try another flavor.";
					        system("pause");
					        goto Coff;
						}
						break;
					case '6':
						system("cls");
			    		cout<<"\n\t\tHow many cups you want to make : ";
			    		cin>>cups;
			    		if(cups<=Flavors[5])
			    		{
			    			cout<<"\nThe coffee is available ";
			    			time=time*cups;
					        cout<<"\nThe coffee will get ready in "<<time<<" minutes";
					        system("pause");
					        Flavors[5]=Flavors[5]-cups;
					        goto Coff;
						}
						else
						{
					        cout<<"\nSorry the coffee isn't available .Try another flavor.";
					        system("pause");
					        goto Coff;
						}
						break;
					case '7':
						system("cls");
			    		cout<<"\n\t\tHow many cups you want to make : ";
			    		cin>>cups;
			    		if(cups<=Flavors[6])
			    		{
			    			cout<<"\nThe coffee is available ";
			    			time=time*cups;
					        cout<<"\nThe coffee will get ready in "<<time<<" minutes";
					        system("pause");
					        Flavors[6]=Flavors[6]-cups;
					        goto Coff;
						}
						else
						{
					        cout<<"\nSorry the coffee isn't available .Try another flavor.";
					        system("pause");
					        goto Coff;
						}
						break;
					case '8':
						system("cls");
			    		cout<<"\n\t\tHow many cups you want to make : ";
			    		cin>>cups;
			    		if(cups<=Flavors[7])
			    		{
			    			cout<<"\nThe coffee is available ";
			    			time=time*cups;
					        cout<<"\nThe coffee will get ready in "<<time<<" minutes";
					        system("pause");
					        Flavors[7]=Flavors[7]-cups;
					        goto Coff;
						}
						else
						{
					        cout<<"\nSorry the coffee isn't available .Try another flavor.";
					        system("pause");
					        goto Coff;
						}
						break;
					case 'r':
					case 'R':
						goto s;
					default:
						cout<<"\n\t\tNo Such Coffee";
						goto f;
						break;
					}}
					else
					{
						cout<<"\n\t\tSorry the device is out of range or switched off";
						system("pause");
						goto s;
					}
					break;
				case 'R':
				case 'r':
					break;
				default:
					cout<<"\n\t\tInvalid Command";
					system("pause");
					break;
				
				}
			
	}
};
class Refrigerator
{
	private:
		bool status=1;
		char choose;
		char choose2;
		string star={"                            *"};
		int speed=5;
	public:
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			FAN:system("cls");
			HANDLE console_color; 
    	    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			LED:system("cls");
			cout<<"\n\t1.SwitchOn/Off       ";
  			if(status==1)
  			{
				SetConsoleTextAttribute(console_color,255);
			    cout<<"  ";
			}
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\t2.Adjust Temperature   _ "<<speed<<"C   ";
			SetConsoleTextAttribute(console_color,187);
			cout<<"  ";
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\nReturn(R)";
			cout<<"\n\n\tChoose Between (1-2) : ";
			ch1:;
			cin>>choose;
			switch(choose)
			{
				case '1':
					if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				    goto FAN;
  				    break;
  				case '2':
  					speed:system("cls");
  					cout<<"\n\t\tRefrigerator's Temperature";
					cout<<"\n\n\t1C_____2C_____3C_____4C_____5C";
					cout<<"\n\t"<<star;
					cout<<"\n\nReturn(R)";
					cout<<"\n\n\tNote : It will take some time to reach to the selected temperature";
					cout<<"\n\t\tChoose Between (1-5)";
					ch:;
					cin>>choose2;
					switch(choose2)
					{
						case '1':
							star={"*"};
							speed=1;
							break;
						case '2':
							star={"        *"};
							speed=2;
							break;
						case '3':
							star={"               *"};
							speed=3;
							break;
						case '4':
							star={"                      *"};
							speed=4;
							break;
						case '5':
							star={"                             *"};
							speed=5;
							break;
						case 'r':
						case 'R':
							goto FAN;
							break;
						default:
							cout<<"\n\t\tInvalid Choice";
							goto ch;
							break;	
					}
					goto speed;
					break;	
				case 'R':
				case 'r':
					break;
				default:
					cout<<"\n\t\tInvalid choice";
					goto ch1;	
					break;	
			}
		}
	
};
class Stove
{
	private:
		bool status=1;
		string star={"*"};
		int pressure=1;
		char st;
		char choose;
		char choose2;
	public:
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			FAN:system("cls");
			HANDLE console_color; 
    	    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			LED:system("cls");
			SetConsoleTextAttribute(console_color,4);
			cout<<"\n\t";
			if(status==1)
				cout<<"|||";
			SetConsoleTextAttribute(console_color,6);
			cout<<"\n\t o ";
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\t1.SwitchOn/Off       ";
  			if(status==1)
  			{
				SetConsoleTextAttribute(console_color,68);
			    cout<<"  ";
			}
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\t2.Adjust Pressure   _ "<<pressure<<"   ";
			SetConsoleTextAttribute(console_color,255);
			cout<<"  ";
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\nReturn(R)";
			cout<<"\n\n\tChoose Between (1-2) : ";
			ch1:;
			cin>>choose;
			switch(choose)
			{
				case '1':
					if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				    goto FAN;
  				    break;
  				case '2':
  					speed1:system("cls");
  					cout<<"\n\t\tBurner's Pressure'";
					cout<<"\n\n\t1_____2_____3_____4_____5";
					cout<<"\n\t"<<star;
					cout<<"\n\nReturn(R)";
					cout<<"\n\t\tChoose Between (1-5)";
					cha:;
					cin>>choose2;
					switch(choose2)
					{
						case '1':
							star={"*"};
							pressure=1;
							goto speed1;
							break;
						case '2':
							star={"      *"};
							pressure=2;
							goto speed1;
							break;
						case '3':
							star={"            *"};
							pressure=3;
							goto speed1;
							break;
						case '4':
							star={"                  *"};
							pressure=4;
							goto speed1;
							break;
						case '5':
							star={"                        *"};
							pressure=5;
							goto speed1;
							break;
						case 'r':
						case 'R':
							goto FAN;
							break;
						default:
							cout<<"\n\t\tInvalid Choice";
							goto cha;
							break;	
					}
					goto speed1;
					break;	
				case 'R':
				case 'r':
						break;
				default:
					cout<<"\n\t\tInvalid choice";
					goto ch1;	
					break;	
			}
					
			}
};
class TV
{
	protected:
		char choose;
		char choose2;
		char choose3;
		Colors C2;
		Theme T2;
	public:
		virtual void display()=0;
};
class SETTING:public TV
{
	private:
		bool status=1;
	public:
		bool Stat()
		{
			return status;
		}
		void Set()
		{
			C2.Default();
		}
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			while(1)
			{
				settings:system("cls");
				cout<<"\n\t\tSettings\n";
				cout<<"\n\t1.SwitchOn/Off       ";
  				if(status==1)
  				{
  				    if(C2.color==240)
  				        C2.Black();
  				    else
  				        C2.White();
  				}
				C2.Default();
				cout<<"\n\t2.Text Color";
				cout<<"\n\t3.Theme";
				cout<<"\n\nReturn(R)";
				cout<<"\n\n\tChoose between (1-3):";
				choice2:;
				cin>>choose;
				switch(choose)
				{
					case '1':
  				        if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				        goto settings;
  				        break;
  				    case '2':
  				    		Text:system("cls");
  				    		cout<<"\n\t\tText Color(Black Background)";
  				    		cout<<"\n\n\t1.Red            ";
		  			C2.Red();
		  			C2.Design();
		  			C2.Default();
		  			cout<<"\n\n\t2.DarkPurple     ";
		  			C2.DarkPurple();
		  			C2.Design();
		  			C2.Default();
		  			cout<<"\n\n\t3.Gold           ";
		    		C2.Gold();
		    		C2.Design();
		    		C2.Default();
		    		cout<<"\n\n\t4.Blue           ";
		    		C2.Blue();
		    		C2.Design();
		    		C2.Default();
		    		cout<<"\n\n\t5.Green          ";
		    		C2.Green();
		    		C2.Design();
					C2.Default();
					cout<<"\n\n\t6.Turquoise      ";
					C2.Turquoise();
					C2.Design();
					C2.Default();
					cout<<"\n\n\t7.Coral          ";
					C2.Coral();
					C2.Design();
					C2.Default();
					cout<<"\n\n\t8.Pink           ";
					C2.Pink();
					C2.Design();
					C2.Default();
					cout<<"\n\n\t9.White          ";
					C2.White1();
					C2.Design();
					C2.Default();
					cout<<"\n\nReturn(R)";
					cout<<"\n\n\tChoose between (1-9) : ";
					choice1:;
					cin>>choose2;
					switch(choose2)
					{
			    		case '1':
			    			C2.Red();
			    			C2.color=4;
			    			break;
			    		case '2':
							C2.DarkPurple();
							C2.color=5;
			    			break;
			    		case '3':
			    			C2.Gold();
			    			C2.color=6;
			    			break;
			    		case '4':
			    			C2.Blue();
			    			C2.color=9;
			    			break;
			    		case '5':
			    			C2.Green();
			    			C2.color=10;
			    			break;
			    		case '6':
			    			C2.Turquoise();
			    			C2.color=11;
			    			break;
			    		case '7':
			    			C2.Coral();
			    			C2.color=12;
			    			break;
			    		case '8':
			    			C2.Pink();
			    			C2.color=13;
			    			break;
			    		case '9':
			    	        C2.White1();
			    	        C2.color=15;
			    			break;
			    		case 'R':
			    		case 'r':
			    			goto settings;
			    			break;
			    		default:
			    			cout<<"\n\t\tInvalid Choice";
			    			goto choice1;
			    			break;
					       }
					         goto Text;
						     break;				    		
  				    case '3':
	  				    	Themes:system("cls");
	  				    	C2.Default();
	  				    	cout<<"\n\n\t1.Default        ";
	  				    	T2.Default();
	  				    	T2.Design();
	  				    	C2.Default();
	  				    	cout<<"\n\n\t2.Zebra          ";
	  				    	T2.Zebra();
	  				    	T2.Design();
	  				    	C2.Default();
	  				    	cout<<"\n\n\t3.Aqua           ";
	  				    	T2.Aqua();
	  				    	T2.Design();
	  				    	C2.Default();
	  				    	cout<<"\n\n\t4.Buraikan       ";
	  				    	T2.Buraikan();
	  				    	T2.Design();
	  				    	C2.Default();
	  				    	cout<<"\n\n\t5.Blueberry      ";
	  				    	T2.Blueberry();
	  				    	T2.Design();
	  				    	C2.Default();
	  				    	cout<<"\n\n\t6.Jamun          ";
	  				    	T2.Jamun();
	  				    	T2.Design();
	  				    	C2.Default();
	  				    	cout<<"\n\nReturn(R)";
	  				    	cout<<"\n\n\tChoose from (1-6) : ";
	  				    	choice:;
	  				    	cin>>choose3;
	  				    	switch(choose3)
	  				    	{
	  				    		case '1':
	  				    			T2.Default();
	  				    			C2.color=10;
	  				    			break;
	  				    		case '2':
	  				    			T2.Zebra();
	  				    			C2.color=240;
	  				    			break;
	  				    		case '3':
	  				    			T2.Aqua();
	  				    			C2.color=177;
	  				    			break;
	  				    		case '4':
	  				    			T2.Buraikan();
	  				    			C2.color=96;
	  				    			break;
	  				    		case '5':
	  				    			T2.Blueberry();
	  				    			C2.color=180;
	  				    			break;
	  				    		case '6':
	  				    			T2.Jamun();
	  				    			C2.color=219;
	  				    			break;
	  				    		case 'R':
	  				    		case 'r':
	  				    			goto settings;
	  				    			break;
	  				    		default:
	  				    			cout<<"\n\t\tInvalid Choice";
	  				    			goto choice;
	  				    			break;
	  				    	}
							  goto Themes;
							  break;  	
  				        case 'R':
					    case 'r':
					    	break;
					    default:
					    	cout<<"\n\t\tInvalid choice";
					    	goto choice2;
					    	break;
				}
				if(choose=='R' || choose=='r')
					break;
						
	}
		}
};
class game:public TV
{
	private:
		char ch;
		SETTING S;
		bool ch2;
	public:
		void get(SETTING &S1)
		{
			S=S1;
		}
		void display()
	{
		ch2=S.Stat();
		if(ch2==1)
		{	
			G:system("cls");
			cout<<"\n\t\tGames";
		    cout << "\n\t1. Number Guessing Game" << endl;
		    cout << "\n\t2. Word Guessing Game" << endl;
		    cout << "\n\t3. Dice Rolling Game" << endl;
		    cout << "\n\t4. Coin Flipping Game" << endl;
		    cout << "\n\t5. Rock-Paper-Scissors Game" << endl;
		    cout << "\n\t6. Letter Guessing Game" << endl;
		    cout << "\n\t7. Animal Guessing Game" << endl;
		    cout << "\n\t8. Country Guessing Game" << endl;
		    cout << "\n\t9. Tic Tac Toe Game " << endl;
		    cout<<"\n\nReturn(R)";
		    cout << "\tEnter your choice: ";
		    cin >> ch;
		
		    Game *game;
			system("cls");
		    switch (ch) 
			{
		        case '1':
		            game = new NumberGuessingGame(1, 100);
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '2':
		            game = new WordGuessingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '3':
		            game = new DiceRollingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '4':
		            game = new CoinFlippingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '5':
		            game = new RockPaperScissorsGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '6':
		            game = new LetterGuessingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '7':
		            game = new AnimalGuessingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '8':
		            game = new CountryGuessingGame();
		            game->play();
		            system("pause");
		            goto G;
		            break;
		        case '9':
		        	game = new TicTacToe();
		        	game->play();
		        	system("pause");
		            goto G;
		        	break;
		        case 'R':
		        case 'r':
		        	break;
		        default:
		            cout << "Invalid choice!" << endl;
		            system("pause");
		            goto G;
		    }
		}
	else
	    	{
	    		cout<<"\n\t\tSorry can't access the device.The device is out of range or switched off.";
	    		system("pause");
			}
	 		
	}
};
class WashingMachine
{
	private:
		bool status=1;
		char choose;
		int mode;
		int level;
		char decision;
		int SURF=1000;
		int surf;
	public:
		void control()
		{
			status=0;
		}
		void control1()
		{
			status=1;
		}
		void display()
		{
			wash:system("cls");
			HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			cout<<"\n\t1.SwitchOn/Off       ";
		  			if(status==1)
		  			{
						SetConsoleTextAttribute(console_color,255);
					    cout<<"  ";
					}
			SetConsoleTextAttribute(console_color,10);
			cout<<"\n\t2.Wash Clothes";
			cout<<"\n\nReturn(R)";
			cout<<"\n\t\tChoose between (1-2) : ";
			ch1:;
			cin>>choose;
			system("cls");
			switch(choose)
			{
				case '1':
					if(status==1)
  				         	status=0;
  				        else
  				          	status=1;
  				    goto wash;
  				    break;
				case '2':
					if(status==1)
					{
						cout<<"\n\t\tModes : ";
						cout<<"\n\t1.Full Wash";
						cout<<"\n\t2.Rinse";
						cout<<"\n\t3.Dry";
						cout<<"\n\t4.Spin";
						cout<<"\n\t\tYour Choice : ";
						mode1:;
						cin>>mode;
						if(mode!=1 && mode!=2 && mode!=3 && mode!=4)
						{
							cout<<"\n\t\tInvalid ";
							goto mode1;
						}
						system("cls");
						cout<<"\n\t\tWater Level : ";
						cout<<"\n\n\tFrom (1-10) : ";
						l:;
						cin>>level;
						if(level!=1 && level!=2 && level!=3&&level!=4 && level!=5 && level!=6 && level!=7 && level!=8 &&level!=9 && level!=10)
						{
							cout<<"\n\t\tInvalid ";
							goto l;
						}
						system("cls");
						cout<<"\n\t\tSurf : ";
						cout<<"\n\t\tSelect the amount of surf (1-1000g) : ";
						S:;
						cin>>surf;
						if(surf>SURF)
						{
							cout<<"\n\t\tSorry choose another amount because Remaining Surf : "<<SURF;
							goto S;
						 } 
						system("cls");
						cout<<"\n\t\tWashing Criteria";
						cout<<"\n\t1.Mode : ";
						if(mode==1)
							cout<<"Full Wash";
						if(mode==2)
							cout<<"Rinse";
						if(mode==3)
							cout<<"Dry";
						if(mode==4)
							cout<<"Spin";	
						cout<<"\n\t2.Water Level : "<<level;
						cout<<"\n\t3.Surf : "<<surf<<"g";
						cout<<"\n\tUse washing machine with such modes and feed ?(y/n)";
						cin>>decision;				
						if(decision=='n'||decision =='N')
							goto wash;
						cout<<"\n\t\tWashing is in process";
						SURF=SURF-surf;
						system("pause");
						goto wash;	
					}
					else
					{
						cout<<"\n\t\tSorry , the device is out of range or switched off ";
						system("pause");
						goto wash;
					}
				case 'R':
				case 'r':
					break;
				default:
					cout<<"\n\t\tInvalid Command";
					goto ch1;
			}
		}
};
class Armory
{
	private:
		char choose;
	public:
		void display()
		{
			p:;
			cout<<"\n\t\tChoose your weapon : ";
			cout<<"\n1.Pistol\n\t\t";  
			cout<<"          _________________________                        -    _  \n\t";
			cout<<" 		/                      () /                         -  - \n\t\t";
			cout<<"         \\    ___-_______________/       \n\t\t";   
			cout<<"         /  /  /___//\n\t\t";
			cout<<"        /  /_-/  /         \n\t\t";
			cout<<"       /_-/\n\t\t";
			cout<<"\n2.Rifle\n\t\t";
			cout<<" _______________/][\\______________\n\t\t";
			cout<<"|    _____________|---------------|=====\n\t\t";
			cout<<"|_ /      //_\\ \\ \n\t\t";
			cout<<"         //   \\ \\ \n\t\t";
			cout<<"\n3.Sword\n\t\t";
			cout<<"\n\tOxxxxx||===============>>>>> \n\t\t";
			cout<<"\n\nReturn(R)";
			cout<<"\n\t\tYour Choice : ";
			cin>>choose;
			switch(choose)
			{
				case '1':
					cout<<"\n\t\tHeres your pistol\n\t\t";
					cout<<"          _________________________                        -    _  \n\t";
					cout<<" 		/                      () /                         -  - \n\t\t";
					cout<<"         \\    ___-_______________/       \n\t\t";   
					cout<<"         /  /  /___//\n\t\t";
					cout<<"        /  /_-/  /         \n\t\t";
					cout<<"       /_-/\n\t\t";
					system("pause");
					break;
				case '2':
					cout<<"\n\t\tHeres your rifle\n\t\t";
					cout<<" _______________/][\\______________\n\t\t";
					cout<<"|    _____________|---------------|=====\n\t\t";
					cout<<"|_ /      //_\\ \\ \n\t\t";
					cout<<"         //   \\ \\ \n\t\t";
					system("pause");
					break;
				case '3':
					cout<<"\n\t\tHeres your sword\n\t";
					cout<<"\nOxxxxx||===============>>>>> ";
					system("pause");
					break;
				case 'r':
				case 'R':
					break;
				default:
					cout<<"\n\t\tInvalid";
					goto p;
			}
		}
};
bool::MyComputer::status=1;
int main()
{
	MyWork MW;
	ComputerGames G;
	Settings S;
	MyComputer *MC[3];
	MC[0]=&MW;
	MC[1]=&G;
	MC[2]=&S;
	Printer P;
	light L1,L2,L3,L4,L5;
	Fan F1,F2,F3,F4,F5;
	ExhaustFan EF1,EF2;
	Geyser G2;
	AC A2,A3,A4,A5;
	Freezer F;
	Refrigerator R;
	CoffeeMaker CF;
	Armory A;
	Stove St1,St2,St3,St4,St5,St6;
	TV *T[2];
	game G4,G5;
	SETTING S4,S5;
	T[0]=&G4;
	T[1]=&S4;
	T[2]=&G5;
	T[3]=&S5;
	WashingMachine WM;
	HANDLE console_color; 
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 10);
	char room;
	char choice,choice1,choice2,choice3,choice4,choice5;
	int status;
	Acc:system("cls");
	PlaySound(TEXT("C:/Users/PC/Downloads/Start.wav"),NULL,SND_FILENAME | SND_SYNC);
	Account A1;
    A1.input();
    Sign:system("cls");
    status=A1.Signin();
    if(!status)
    	goto Acc;
    while(1)
    {
    	start:system("cls");
        cout<<"\n\t\t\tWelcome to Smart House System\n\n";
        cout<<"\t\t\tSecurity mode disabled\n\n";
        cout<<"\n1.Kitchen\t\t\t\t2.Washroom\t\t\t\t3.Office";
        cout<<"\n.LED light.\t\t\t\t.LED light.\t\t\t\t.LED light.";
        cout<<"\n.Stove.\t\t\t\t\t.Fan.\t\t\t\t\t.Fan.";
        cout<<"\n.Refrigerator.\t\t\t\t.AC.\t\t\t\t\t.AC.";
        cout<<"\n.Coffe Maker.\t\t\t\t.Exhaust Fan.\t\t\t\t.My Computer.";
        cout<<"\n.Fan.\t\t\t\t\t.Washing Machine.\t\t\t.Printer.";
        cout<<"\n.Exhaust Fan.\t\t\t\t.Geyser.";
        cout<<"\n.Freezer.";
        cout<<"\n\n\t\t4.Dining Room\t\t\t\t.5.Bed Room";
        cout<<"\n\t\t.LED light.\t\t\t\t.LED light.";
		cout<<"\n\t\t.Fan.\t\t\t\t\t.Fan.";
        cout<<"\n\t\t.AC.\t\t\t\t\t.AC.";
        cout<<"\n\t\t.LED TV.\t\t\t\t.LED TV.";
        cout<<"\n\nSwitchOff(F)\t\t\t\t\t\t\t\tSwitchOn(O)";
        cout<<"\n\n\nLogout(L)\t\t\t\t\t\t\t\tShutDown(D)";
        invalid:;
        cout<<"\n\n\t\t\tChoose the room (1-5) :";
        cin>>room;
        if(room>='1' && room<='5' || room =='l' || room=='L')
            system("cls");
        switch(room)
        {
        	case '1':
        		{
        			Room1:system("cls");
					system("color 0A");
	        		cout<<"\n\t\t\t.Kitchen.";
	        		cout<<"\n\t\t\t1.LED light";
	        		cout<<"\n\t\t\t2.Stove";
	        		cout<<"\n\t\t\t3.Refrigerator";
	        		cout<<"\n\t\t\t4.Coffe Maker";
	        		cout<<"\n\t\t\t5.Fan";
	        		cout<<"\n\t\t\t6.Exhaust Fan";
	        		cout<<"\n\t\t\t7.Freezer";
	        		cout<<"\n\nReturn(R)";
	        		cout<<"\n\n\tChoose a Device/Appliance/Machine :";
	        		Room1c:;
	        		cin>>choice1;
	        		switch(choice1)
	        		{
	        			case '1':
	        				L1.display();
	        				goto Room1;
	        				break;
	        			case '2':
	        				st:system("cls");
	        				cout<<"\n\t\t\tStove";
	        				SetConsoleTextAttribute(console_color,4);
							cout<<"\n\n\t|||\t\t|||\t\t|||";
							SetConsoleTextAttribute(console_color,6);
							cout<<"\n\t o \t\t o \t\t o  ";
							SetConsoleTextAttribute(console_color,4);
							cout<<"\n\n\t|||\t\t|||\t\t|||";
							SetConsoleTextAttribute(console_color,6);
							cout<<"\n\t o \t\t o \t\t o  ";
							SetConsoleTextAttribute(console_color,10);
	        				cout<<"\n\nReturn(R)";
	        				cout<<"\n\nSelect a stove burner(1-6) : ";
	        				cin>>choice2;
	        				switch(choice2)
	        				{
	        					case '1':
	        						St1.display();
	        						goto st;
	        					case '2':
	        						St2.display();
	        						goto st;
	        					case '3':
	        						St3.display();
	        						goto st;
	        					case '4':
	        						St4.display();
	        						goto st;
	        					case '5':
	        						St5.display();
	        						goto st;
	        					case '6':
	        						St6.display();
	        						goto st;
	        					case 'r':
	        					case 'R':
									goto Room1;
									break;
								default:
									cout<<"\n\t\tInvalid Command";
									system("pause");
									goto st;	    
									break;    						
							}
	        				goto Room1;
	        				break;
	        			case '3':
	        				R.display();
	        				goto Room1;
	        				break;
	        			case '4':
	        				CF.showSelection();
	        				goto Room1;
							break;
	        		    case '5':
	        		    	F1.display();
	        		    	goto Room1;
	        				break;
	        			case '6':
	        				EF1.display();
	        				goto Room1;
	        				break;
	        			case '7':
	        				F.display();
	        			case 'R' :
	        			case 'r' :
	        				goto start;
	        			    break;
	        			default : 
	        			    cout<<"\n\t\tInvalid choice";
	        			    goto Room1c;
	        			    break;
	        	    }
	        		break;
        	    }
        	case '2':
        			Room2:system("cls");
					system("color 0A");
	        		cout<<"\n\t\t\t.Washroom.";
	        		cout<<"\n\t\t\t1.LED light";
	        		cout<<"\n\t\t\t2.Fan";
	        		cout<<"\n\t\t\t3.AC";
	        		cout<<"\n\t\t\t4.Exhaust Fan";
	        		cout<<"\n\t\t\t5.Washing Machine";
	        		cout<<"\n\t\t\t6.Geyser";
	        		cout<<"\n\nReturn(R)";
	        		cout<<"\n\n\t\tChoose a Device/Appliance/Machine :";
	        		Room2c:;
	        		cin>>choice1;
	        		switch(choice1)
	        		{
	        			case '1':
	        				L2.display();
	        				goto Room2;
	        				break;
	        			case '2':
	        				F2.display();
	        				goto Room2;
	        				break;
	        			case '3':
	        				A2.display();
	        				goto Room2;
	        				break;
	        			case '4':
	        				EF2.display();
	        				goto Room2;
							break;
	        		    case '5':
	        		    	WM.display();
	        		    	goto Room2;
	        				break;
	        			case '6':
	        				G2.display();
	        				goto Room2;
	        				break;
	        			case 'R' :
	        			case 'r' :
	        				goto start;
	        			    break;
	        			default : 
	        			    cout<<"\n\t\tInvalid choice";
	        			    goto Room2c;
	        			    break;
	        	    }
	        		break;
        	case '3':
        			Room3:system("cls");
					system("color 0A");
	        		cout<<"\n\t\t\t.Office.";
	        		cout<<"\n\t\t\t1.LED light";
	        		cout<<"\n\t\t\t2.Fan";
	        		cout<<"\n\t\t\t3.AC";
	        		cout<<"\n\t\t\t4.My Computer";
	        		cout<<"\n\t\t\t5.Printer";
	        		cout<<"\n\nReturn(R)";
	        		cout<<"\n\n\tChoose a Device/Appliance/Machine :";
	        		Room3c:;
	        		cin>>choice1;
	        		system("cls");
	        		switch(choice1)
	        		{
	        			case '1':
	        				L3.display();
	        				goto Room3;
	        				break;
	        			case '2':
	        				F3.display();
	        				goto Room3;
	        				break;
	        			case '3':
	        				A3.display();
	        				goto Room3;
	        				break;
	        			case '4':
	        			{
		        				Computers:system("cls");
		        				S.Set();
		        				cout<<"\t\tMy Computer ";
		        				cout<<"\n\t1.My Work";
		        				cout<<"\n\t2.Games ";
		        				cout<<"\n\t3.Settings";
		        				cout<<"\n\nReturn(R)";
		        				cout<<"\n\n\tChoose from (1-3) : ";
		        				Com:;
		        				cin>>choice2;
		        				system("cls");
		        				switch(choice2)
		        				{
		        					case '1':
		        						MC[0]->display();
										goto Computers;
				        				break;
				        			case '2':
				        				MC[1]->display();
				        				goto Computers;
				        				break;
				        				
				        			case '3':
				        				MC[2]->display();
				        				goto Computers;
				        				break;
				        			case 'R':
									case 'r':	
										goto Room3;
									    break;		
									default:
										cout<<"\n\t\tInvalid Choice";
										goto Com;
									    break;	
							}
						}
							break;
	        		    case '5':
	        		    	P.set(MW);
	        		    	P.display();
	        		    	goto Room3;
	        				break;
	        			case 'R' :
	        			case 'r' :
	        				goto start;
	        			    break;
	        			default : 
	        			    cout<<"\n\t\tInvalid choice";
	        			    goto Room3c;
	        			    break;
	        	    }
				break;
			case '4':
					Room4:system("cls");
					system("color 0A");
		       		cout<<"\n\t\t\t.Dining Room.";
		       		cout<<"\n\t\t\t1.LED light";
		       		cout<<"\n\t\t\t2.Fan";
		       		cout<<"\n\t\t\t3.AC";
	        		cout<<"\n\t\t\t4.LED TV";
	        		cout<<"\n\nReturn(R)";
	        		cout<<"\n\n\tChoose a Device/Appliance/Machine :";
	        		Room4c:;
	        		cin>>choice1;
	        		switch(choice1)
	        		{
	        			case '1':
	        				L4.display();
	        				goto Room4;
	        				break;
	        			case '2':
	        				F4.display();
	        				goto Room4;
	        				break;
	        			case '3':
	        				A4.display();
	        				goto Room4;
	        				break;
	        			case '4':
	        			{
		        				TV:system("cls");
		        				S4.Set();
		        				cout<<"\t\tLED TV ";
		        				cout<<"\n\t1.Games ";
		        				cout<<"\n\t2.Settings";
		        				cout<<"\n\nReturn(R)";
		        				cout<<"\n\n\tChoose from (1-2) : ";
		        				tv:;
		        				cin>>choice2;
		        				system("cls");
		        				switch(choice2)
		        				{
		        					case '1':
		        						G4.get(S4);
		        						T[0]->display();
										goto TV;
				        				break;
				        			case '2':
				        				T[1]->display();
										goto TV;
				        				break;
				        			case 'R':
									case 'r':	
										goto Room4;
									    break;		
									default:
										cout<<"\n\t\tInvalid Choice";
										system("pause");
										goto TV;
									    break;	
							}
						}
							break;
	        			case 'R' :
	        			case 'r' :
	        				goto start;
	        			    break;
	        			default : 
	        			    cout<<"\n\t\tInvalid choice";
	        			    goto Room4c;
	        			    break;
	        	    }
	        		break;
        	case '5':
        		{
        			Room5:system("cls");
					system("color 0A");
					cout<<"\n\t\t\t.Bed Room.";
	        		cout<<"\n\t\t\t1.LED light";
	        		cout<<"\n\t\t\t2.Fan";
	        		cout<<"\n\t\t\t3.AC";
	        		cout<<"\n\t\t\t4.LED TV";
	        		cout<<"\n\nReturn(R)";
	        		cout<<"\n\n\tChoose a Device/Appliance/Machine :";
	        		Room5c:;
	        		cin>>choice1;
	        		switch(choice1)
	        		{
	        			case '1':
	        				L5.display();
	        				goto Room5;
	        				break;
	        			case '2':
	        				F5.display();
	        				goto Room5;
	        				break;
	        			case '3':
	        				A5.display();
	        				goto Room5;
	        				break;
	        			case '4':
	        			{
		        				TV1:system("cls");
		        				S5.Set();
		        				cout<<"\t\tLED TV ";
		        				cout<<"\n\t1.Games ";
		        				cout<<"\n\t2.Settings";
		        				cout<<"\n\nReturn(R)";
		        				cout<<"\n\n\tChoose from (1-2) : ";
		        				tv1:;
		        				cin>>choice2;
		        				system("cls");
		        				switch(choice2)
		        				{
		        					case '1':
		        						G5.get(S5);
		        						T[2]->display();
										goto TV1;
				        				break;
				        			case '2':
				        				T[3]->display();
										goto TV1;
				        				break;
				        			case 'R':
									case 'r':	
										goto Room5;
									    break;		
									default:
										cout<<"\n\t\tInvalid Choice";
										system("pause");
										goto TV1;
									    break;	
							}
						}
							break;
	        			case 'R' :
	        			case 'r' :
	        				goto start;
	        			    break;
	        			default : 
	        			    cout<<"\n\t\tInvalid choice";
	        			    goto Room5c;
	        			    break;
	        	    }
				}
	        		break;
        	case 'l':
        	case 'L':
	        		cout<<"\n\t\tDo you really want to Signout?(y/n)";
	        		cin>>choice;
	        		if(choice=='y'||choice=='Y')
	        		    goto Sign;
	        		break;
	        case 'D':
	        case 'd':
	        	return 0;
	        	break;
	        case 'F':
	        case 'f':
	        	S.control();
	            P.control();
	            L1.control();
	            L2.control();
	            L3.control();
	            L4.control();
	            L5.control();
				F1.control();
				F2.control();
				F3.control();
				F4.control();
				F5.control();
				EF1.control();
				EF2.control();
				G2.control();
				A2.control();
				A3.control();
				A4.control();
				A5.control();
				F.control();
				R.control();
				CF.control();
				S4.control();
				S5.control();
				WM.control();
				St1.control();
	            St2.control();
	            St3.control();
	            St4.control();
	            St5.control();
	            cout<<"\n\t\tAll devices have been turned Off ";
	            system("pause");
	            goto start;
	        	break;
	        case 'O':
	        case 'o':
	        	S.control1();
	            P.control1();
	            L1.control1();
	            L2.control1();
	            L3.control1();
	            L4.control1();
	            L5.control1();
				F1.control1();
				F2.control1();
				F3.control1();
				F4.control1();
				F5.control1();
				EF1.control1();
				EF2.control1();
				G2.control1();
				A2.control1();
				A3.control1();
				A4.control1();
				A5.control1();
				F.control1();
				R.control1();
				CF.control1();
				S4.control1();
				S5.control1();
				WM.control1();
				St1.control1();
	            St2.control1();
	            St3.control1();
	            St4.control1();
	            St5.control1();
	            cout<<"\n\t\tAll devices have been turned On ";
	            system("pause");
	            goto start;
	        	break;
	        case '*':
	        	A.display();
	        	break;
        	default:
	        		PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"),NULL,SND_FILENAME | SND_SYNC);
	        		cout<<"\n\t\t\tInvalid Command";
	        		goto invalid;
	        		break;
        	}
		}
}
