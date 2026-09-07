#include <iostream>
#include <string>
using namespace std;

// Template class for GameScoreboard
template <typename TScore, typename TLevel>
class GameScoreboard {
private:
    string playerName;
    TScore playerScore;
    TLevel gameLevel;

public:
    // Function to set player details
    void setPlayerDetails(string name, TScore score, TLevel level) {
        playerName = name;
        playerScore = score;
        gameLevel = level;
    }

    // Function to update the score by adding points
    void updateScore(TScore points) {
        playerScore += points;
    }

    // Function to display the player's current status
    void displayStatus() {
        cout << "Player Name: " << playerName << endl;
        cout << "Player Score: " << playerScore << endl;
        cout << "Game Level: " << gameLevel << endl;
    }
};

int main() {
    // Create a GameScoreboard object for int score and level
    GameScoreboard<int, int> player1;
    player1.setPlayerDetails("Alice", 500, 2);
    cout << "Initial status of Player 1:" << endl;
    player1.displayStatus();

    player1.updateScore(100);
    cout << "\nAfter updating score of Player 1:" << endl;
    player1.displayStatus();

    // Create a GameScoreboard object for double score and level
    GameScoreboard<double, int> player2;
    player2.setPlayerDetails("Bob", 1200.5, 3);
    cout << "\nInitial status of Player 2:" << endl;
    player2.displayStatus();

    player2.updateScore(250.75);
    cout << "\nAfter updating score of Player 2:" << endl;
    player2.displayStatus();

    return 0;
}
