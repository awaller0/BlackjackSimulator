# CIS7BLACKJACK

1. Group 7, Aaron Waller
2.The project solves the problem of simulating a simplified version of the game Blackjack,providing an interactive gameplay experience for the user.The program implements a solution by utilizing classes and structures to represent the gameelements such as cards, players, and the deck. It incorporates functions for dealing cards,calculating values, and determining advantages, allowing for a functional Blackjack gamesimulation.The program performs calculations such as card counting, determining the player's advantagebased on card values, and calculating probabilities. The algorithms are implemented usingloops, conditional statements, and data structures to manage the game logic and provide thenecessary information to the user.
The program's objective is to simulate a game of Blackjack and provide an interactive
experience for the user. It achieves this by displaying a main menu, allowing the user to start the
game or quit. During gameplay, it provides information about the player's hand, their advantage,
and the probability of getting specific cards, enhancing the overall user experience.
Discrete structures are implemented in the C++ program using classes (Deck and Blackjack)
and structures (Card and Player) to organize and manage the data required for the game. This
approach provides a modular and organized way to represent the various elements and
relationships within the game.
The limitations of the program include the lack of user input validation, absence of full Blackjack
rules, limited number of players, no handling of deck depletion, and absence of bankroll tracking
and betting strategies.
// Pseudocode for the Blackjack game
// Card structure definition
struct Card {
int value
string name
string suit
string color
}
// Player structure definition
struct Player {
string name
int count
string status[2]
float bet
Card cards[10]
}
// Deck class definition
class Deck {
Card cards[NUMBER_OF_SUITS][NUMBER_OF_RANKS]
// Constructor
Deck()
Initialize random number generator
Iterate over suits
Iterate over ranks
Assign suit, value, name, and color to each card
// Destructor
~Deck()
// Method to deal a card
Card deal()
Generate a random card index
Return the card at the generated index
}
// Blackjack class definition
class Blackjack {
Player players[2]
// Constructor
Blackjack(string playerName, float initialBet)
Assign values to dealer and player
Set dealer's bet to a fixed amount
Set player's bet to initial bet
// Destructor
~Blackjack()
// Method to display the main menu
void mainMenu
Prompt the user to start the game or quit
If the user chooses to start
Call the play() method
Otherwise
Display a farewell message
// Method to play the game
void play
Initialize variables
Deal two cards to the dealer and show one card
Deal two cards to the player
Calculate the player's count
Display player's details and cards
Prompt the player to play the hand or quit
If the player chooses to play
Calculate the lucky number
Check if any cards are lucky
Calculate the probability of getting the lucky number
Display player's advantage and the probability
End
// Method to calculate player's advantage
float playerAdvantage(int cardValue)
Initialize advantage variable
Iterate over card values
If the current card value matches the input value
If the card value is 1, set the advantage to -16.0
If the card value is 8, set the advantage to -16.9
Otherwise, set the advantage based on CARD_ADVANTAGES array
Return the advantage
}
// Main function
int main
Initialize playerName and initialBet variables
Create a Deck object called gameDeck
Prompt the user for their name and initial bet
Create a Blackjack object with the provided name and bet
Call the mainMenu() method on the Blackjack object
Return 0
