#ifndef BLATT3_GAME_H
#define BLATT3_GAME_H



#include <vector>

#include "Coordinates.h"

#include "PlayerSea.h"
// diese Funktionen werden in gameLoop verwendet
void GameStart();
void processPlayerTurn(GameObjects::PlayerSea & currentPlayer, GameObjects::PlayerSea & otherPlayerSea);
bool checkGameFinished(GameObjects::PlayerSea & currentPlayer, GameObjects::PlayerSea & otherPlayerSea);

void gameLoop(std::vector<GameObjects::PlayerSea> & playerSeas);


Sea::Coordinates inputMissileTargetCoordinates(GameObjects::PlayerSea const & currentPlayerSea);


#endif //BLATT3_GAME_H
