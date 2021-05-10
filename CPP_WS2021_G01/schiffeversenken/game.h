#ifndef GAME_H
#define GAME_H

#include "player.h"

/**
 * @brief Takes care of players and the status of the game
 */
class Game
{
public:
    /**
     * @brief Initializes a new game with two players, which are opponent to each other
     */
    Game();
    /**
     * @brief Starts a command line interface for testing purposes
     */
    void startCli();
    /**
     * @brief Retrieves the player, whose turn it is to place his shot
     */
    const std::shared_ptr<Player> getCurrentPlayer() const;
    /**
     * @brief Retrieves the first player
     */
    const std::shared_ptr<Player> getPlayer1() const;
    /**
     * @brief Retrieves the second playerr
     */
    const std::shared_ptr<Player> getPlayer2() const;
    /**
     * @brief Ends the current round and starts the next one, if there are ships left to be shot at.
     * @return true if the next round could be started, false otherwise
     */
    bool nextRound();
    /**
     * @brief Retrieves the winner after the game has ended
     * @return A shared pointer to the winner, nulptr if no one hat one the game yet
     */
    const std::shared_ptr<Player> getWinner() const;

private:
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Player> currPlayer;
};

#endif // GAME_H
