#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

const int NUMBER_OF_SUITS = 4;
const int NUMBER_OF_RANKS = 13;
const float CARD_ADVANTAGES[NUMBER_OF_RANKS] = { 9.8f, 13.4f, 18.0f, 23.2f, 23.9f, 14.3f, 5.4f, -4.3f,
    -16.9f, -16.9f, -16.9f, -16.9f, -16.0f };
const int CARD_VALUES[NUMBER_OF_RANKS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
const string RANK_NAMES[NUMBER_OF_RANKS] = { "ACE", "2", "3", "4", "5", "6", "7", "8", "9", "10", "JACK", "QUEEN", "KING" };
const string SUIT_NAMES[NUMBER_OF_SUITS] = { "HEARTS", "DIAMONDS", "CLUBS", "SPADES" };
const string CARD_COLORS[2] = { "RED", "BLACK" };


struct Card {
   int value = 0;
   string name;
   string suit;
   string color;
};

struct Player {
   string name;
   int count = 0;
   string status[2] = { "waiting...", "playing..." };
   float bet = 0;
   Card cards[10];
};

class Deck {
private:
   Card cards[NUMBER_OF_SUITS][NUMBER_OF_RANKS];

public:
   Deck() {
      srand(static_cast<int>(time(0)));
      for (int i = 0; i < NUMBER_OF_SUITS; ++i) {
         for (int j = 0; j < NUMBER_OF_RANKS; ++j) {
            cards[i][j].suit = SUIT_NAMES[i];
            cards[i][j].value = CARD_VALUES[j];
            cards[i][j].name = RANK_NAMES[j];
            if ((cards[i][j].suit == "DIAMONDS") || (cards[i][j].suit == "HEARTS"))
               cards[i][j].color = CARD_COLORS[0];
            else if ((cards[i][j].suit == "CLUBS") || (cards[i][j].suit == "SPADES"))
               cards[i][j].color = CARD_COLORS[1];
         }
      }
   }

   ~Deck() {}

   Card deal() {
      Card hand;
      hand = cards[rand() % NUMBER_OF_SUITS][rand() % NUMBER_OF_RANKS];
      return hand;
   }
};

class Blackjack {
private:
   Player players[2];

public:
   Blackjack(string playerName, float initialBet) {
      this->players[0].name = "DEALER";
      this->players[1].name = playerName;
      this->players[0].bet = 100000.0f;
      this->players[1].bet = initialBet;
   }

   ~Blackjack() {}

   void mainMenu(Deck gameDeck) {
      short int choice = 0;
      cout << "\nWelcome to the Ultimate Blackjack Experience!\nPress 1 and enter to enter the thrilling realm of Blackjack or press any\n other number and enter to quit:  \n ";
      cin >> choice;
      switch (choice) {
      case 1: play(gameDeck);
         break;
      default: cout << "\n\n\tOkay, until next time!";
         break;
      }
   }

   void play(Deck gameDeck) {
      int choice = 1;
      int luckyNumber = 0;
      int showingCards = 3;
      float numLucky = 0;
      float probability = 0;
      switch (choice) {
      case 1:
         players[0].cards[0] = gameDeck.deal();
         players[0].cards[1] = gameDeck.deal();
         players[0].count = players[0].cards[0].value + players[0].cards[1].value;
         cout << "\n\nPlayer: " << players[0].name << "\nCount: ***" << "\nStatus: " << players[0].status[1] << "\nBank: $" << fixed << setprecision(2) << players[0].bet;
         cout << "\n\n" << players[0].name << "\'s hand: " << players[0].cards[1].name << " of " << players[0].cards[1].suit << " and [HIDDEN CARD]";
         cout << "\n\n\tPress 1 and enter to play this hand or press any other number and enter to quit:  ";
         cin >> choice;
         if (choice != 1) {
            cout << "\n\n\tOkay, until next time!";
            break;
         }
         players[1].cards[0] = gameDeck.deal();
         players[1].cards[1] = gameDeck.deal();
         players[1].count = players[1].cards[0].value + players[1].cards[1].value;
         cout << "\n\nPlayer: " << players[1].name << " (YOU)\nCount: " << players[1].count << "\nStatus: " << players[1].status[1] << "\nBank: $" << fixed << setprecision(2) << players[1].bet;
         cout << "\n\n" << players[1].name << "\'s hand: " << players[1].cards[0].name << " of " << players[1].cards[0].suit << " and " << players[1].cards[1].name << " of " << players[1].cards[1].suit;
         luckyNumber = 21 - players[1].count;
         if (luckyNumber > 10) {
            luckyNumber = 10;
         }
         for (int i = 0; i < 2; ++i) {
            if ((players[0].cards[i].value == luckyNumber) || (players[1].cards[i].value == luckyNumber)) {
               numLucky++;
            }
         }
         probability = 4 - numLucky;
         probability /= (52 - showingCards);
         cout << "\n\n\t\tYour advantage vs. the dealer based on the dealer's up card:  " << fixed << setprecision(2) << playerAdvantage(players[0].cards[1].value) << "%.";
         cout << "\n\n\t\tThe probability of you getting " << luckyNumber << " as your next card is " << fixed << setprecision(3) << (probability * 100) << "%.";
         break;
      }
   }

   float playerAdvantage(int cardValue) {
      float advantage = 0;
      for (int i = 0; i < NUMBER_OF_RANKS; ++i) {
         if (cardValue == CARD_VALUES[i]) {
            if (CARD_VALUES[i] == 1) {
               advantage = -16.0f;
            }
            else if (CARD_VALUES[i] == 8) {
               advantage = -16.9f;
            }
            else {
               advantage = CARD_ADVANTAGES[i - 1];  // Adjust index here
            }
         }
      }
      return advantage;
   }
};

int main(int argc, char** argv) {
   string playerName;
   float initialBet = 0.0f;
   Deck gameDeck = Deck();
   cout << "\nWhat is your name, brave gambler:  ";
   cin >> playerName;
   cout << "\nHow much are you willing to bet today:  $";
   cin >> initialBet;
   Blackjack newBlackjack = Blackjack(playerName, initialBet);
   newBlackjack.mainMenu(gameDeck);

   return 0;
}