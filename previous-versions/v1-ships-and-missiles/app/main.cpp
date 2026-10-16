#include <vector>
#include "PlayerSea.h"

using std::vector;
using GameObjects::PlayerSea;


#include "init.h"
#include "game.h"
#include "test.h"


int main()
{
    if (testPassed()) {
        vector<PlayerSea> playerSeas;
        initializePlayerSeasWithShips(playerSeas);
        gameLoop(playerSeas);
    }
    return 0;
}
