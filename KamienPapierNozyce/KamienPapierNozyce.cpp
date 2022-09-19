#include <iostream>
#include "Player.hpp"
#include "HumanPlayer.hpp"
#include "Game.hpp"
#include "ComputerPlayer.hpp"

std::shared_ptr<Player> choosePlayer()
{
    std::shared_ptr<Player> player = nullptr;
    std::cout << "Do you want to play with H- Human, C- Computer? ";
    char choice;
    std::cin >> choice;
    if (choice == 'C' || choice == 'c')
    {
        player = std::make_shared<ComputerPlayer>();
    }
    else
    {
        player = std::make_shared<HumanPlayer>("Marta");
    }

    return player;
}

int main()
{

    std::shared_ptr<Player> player1 = std::make_shared<HumanPlayer>("Anna");
    std::shared_ptr<Player>player2 = choosePlayer();
    Game game(player1 ,player2 ,4);
    game.play();



    
    
}
