// Naszir L. Merritt 11\13\2020



// Hold the recruit's name in a var, and address them by it throughout the simulation.






















// Otherwise










#include<iostream> 
#include<string>
#include<cstdlib>
#include <ctime>
using namespace std;

void rules();
string playeranswer;
string checkpoint();
int simulation = 1;
int wordcount = 0;
int main ()
{

	string answer;
	do
	{
		// welcome user 
		cout << "\t\t\tWelcome to Keywords 2.\n\n";
		
		
		rules();
		
		cout << "Please give us something to call you.\n";




		//store user name
		string name;
		cin >> name;
		
		
		


		//explanation of the game
		cout << "Welcome, " << name << ", Keywords 2 is basically hangman. Your current simulation number is: " << simulation << endl;
		cout << "You guess what letters are in the given blanks of said words within the 3 guesses you have.\n";


		// Stores the 10 words for the key word test 
		enum fields { WORD, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS] =

		{
		{"target"},
		{"gun"},
		{"laser"},
		{"suit"},
		{"Googles"},
		{"handgun"},
		{"chopper"},
		{"jet"},
		{"poison"},
		{"sneak"},
		};


		

		
		
		do 
		{



			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD];
			string guessedLetters;
			string guess(theWord.length(), '_');
			string guessLetter;
			int incorrect = 0;

		  cout << "\nYour Current word number: " << wordcount << endl;
		  cout << "Your word is: " << guess << ".";
		  cout << " Total incorrect guesses 3/" << incorrect << ".";
		  cout << "\nThe letters already guessed: " << guessedLetters << " ";
		  cout << "\n\n Your guess: ";

		
		
		  while (guess != theWord && incorrect < 3)
		  {
			cin >> guessLetter;
			

			while (guessedLetters.find(guessLetter) != string::npos)
			{

				cin >> guessLetter;
				
			}

			if (theWord.find(guessLetter) != string::npos)
			{
				//letter correct 
				for (int i = 0; i < theWord.length(); i++)
				{
					if (theWord[i] == guessLetter[0])
					{
						guess[i] = guessLetter[0];
						
						cout << "Correct!";
						cout << "\nTotal incorrect guesses 3/" << incorrect << ".";
						cout << "\nThe letters already guessed: " << guessedLetters << " .";
						cout << "\nYour Current word number: " << wordcount << endl;
						cout << "\nYour word is: " << guess << ".";
						cout << "\n\nYour guess: ";

					}


				}
			}
			else
			{
				incorrect++;
				
				cout << "Incorrect.";
				cout << "\nTotal incorrect guesses 3/" << incorrect << ".";
				cout << "\nThe letters already guessed: " << guessedLetters << " .";
				cout << "\nYour Current word number: " << wordcount << endl;
				cout << "\nYour word is: " << guess << ".";
				cout << "\n\nYour guess: ";

			}
			
			

			if (guess == theWord)
			{
				cout << "\n\nCongratulations that is the word!";
			}
			else
			{
				cout << "\n\nYou have failed to guess the word.";


			}
		  }

		  wordcount++;
		} while (wordcount <= 3);


		cout << "\nWould you like to play again? y/n ";
		cin >> answer;
		simulation++;

	} while (answer != "n");









	return 0;


}




void  rules()
{

	cout << "\n\t\t\t\tRules:\n";
	cout << "\n\t\t\t\tNo uppercase\n";
	cout << "\n\t\t\t\tNo spaces\n";

	cout << "\nOverview: This game is basically jeopardy. Ill give you a word to guess.\n";
	cout << "Then you will only be able to make three errors as you try to guess each letter for the word.\n";
	cout << "If you make three incorrect guesses for the letters of the word the game will move onto the second word.\n";
	cout << "You have a total of three words to guess and only can make up to three mistakes on each word.\n";
	cout << "If you win, the game you will be congratulated. If you lose, the game is over.\n";
	cout << "The game will then ask you if you want to play again.\n";
	
	checkpoint();


	

}


string checkpoint()
{
	 

	do {

		cout << "\nDo you understand?\n";
		cin >> playeranswer;







	} while (playeranswer != "y" );



	return playeranswer;




}






