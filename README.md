# Blackjack Simulator

This project solves the problem of simulating a simplified version of the game Blackjack, providing an interactive gameplay experience for the user. The program implements a solution by utilizing classes and structures to represent the game elements such as cards, players, and the deck. It incorporates functions for dealing cards, calculating values, and determining advantages, allowing for a functional Blackjack game simulation.

The program performs calculations such as card counting, determining the player's advantage based on card values, and calculating probabilities. The algorithms are implemented using loops, conditional statements, and data structures to manage the game logic and provide the necessary information to the user.

The program's objective is to simulate a game of Blackjack and provide an interactive experience for the user. It achieves this by displaying a main menu, allowing the user to start the game or quit. During gameplay, it provides information about the player's hand, their advantage, and the probability of getting specific cards, enhancing the overall user experience.

Discrete structures are implemented in the C++ program using classes (Deck and Blackjack) and structures (Card and Player) to organize and manage the data required for the game. This approach provides a modular and organized way to represent the various elements and relationships within the game.

The limitations of the program include the lack of user input validation, limited number of players, handling of deck depletion, and bankroll tracking and betting strategies.

## Pseudocode

```cpp
// Pseudocode for the Blackjack game

// Card structure definition
struct Card {
  int value;
  string name;
  string suit;
  string color;
}

// Player structure definition
struct Player {
  string name;
  int count;
  string status[2];
  float bet;
  Card cards[10];
}

// Deck class definition
class Deck {
  Card cards[NUMBER_OF_SUITS][NUMBER_OF_RANKS];

  // Constructor
  Deck();
  
  // Destructor
  ~Deck();
  
  // Method to deal a card
  Card deal();
}

// Blackjack class definition
class Blackjack {
  Player players[2];
  
  // Constructor
  Blackjack(string playerName, float initialBet);
  
  // Destructor
  ~Blackjack();
  
  // Method to display the main menu
  void mainMenu();
  
  // Method to play the game
  void play();
  
  // Method to calculate player's advantage
  float playerAdvantage(int cardValue);
}

// Main function
int main() {
  string playerName;
  float initialBet;
  Deck gameDeck;
  
  // Prompt the user for their name and initial bet
  // Create a Blackjack object with the provided name and bet
  // Call the mainMenu() method on the Blackjack object
  
  return 0;
}
```
