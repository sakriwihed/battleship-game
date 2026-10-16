#include "game.h"

// TODO Aufgabe 7:
//  Bringe die `include`- und `using`-Anweisungen in eine sinnvolle Ordnung.

#include <iostream>
#include <vector>

#include "Coordinates.h"
#include "PlayerSea.h"
#include "init.h"

// using-Anweisungen – zuerst für std
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// dann andere Namespaces
using Sea::Coordinates;
using GameObjects::PlayerSea;



// TODO Aufgabe 7:
//  Zerlege die Funktion `gameLoop(..)` in sinnvolle, kürzere Teilfunktionen.

void GameStart() {
    cout << endl << "Los geht's!" << endl;
}

void processPlayerTurn(GameObjects::PlayerSea & currentPlayer, GameObjects::PlayerSea & otherPlayerSea){
    Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayer);
    bool hit = currentPlayer.sendMissileTo(otherPlayerSea, targetCoordinates);
    cout << (hit ? "Treffer!" : "Daneben!") << endl;
  }

bool checkGameFinished(GameObjects::PlayerSea & currentPlayer, GameObjects::PlayerSea & otherPlayerSea){
    if (otherPlayerSea.allShipsDestroyed()) {
        cout << "Das letzte Schiff von " << otherPlayerSea.getPlayerName() << " ist versenkt. "
             << currentPlayer.getPlayerName() << " hat gewonnen." << endl;
        return true;
    }
    return false;
  }

void gameLoop(vector<PlayerSea> & playerSeas)
{
    GameStart();

    for (unsigned int round = 0;; ++round) {
        PlayerSea & currentPlayerSea = playerSeas[round % 2];
        PlayerSea & otherPlayerSea = playerSeas[(round + 1) % 2];
        processPlayerTurn(currentPlayerSea, otherPlayerSea);

        if (checkGameFinished(currentPlayerSea, otherPlayerSea)) {
            break;
        }
    }
}

Coordinates inputMissileTargetCoordinates(PlayerSea const & currentPlayerSea)
{
    while (true) {
        cout << endl << currentPlayerSea.getPlayerName() << " zielt auf" << endl;
        Coordinates targetCoordinates = inputCoordinates();

        if (currentPlayerSea.missileAlreadySentTo(targetCoordinates)) {
            cout << "Diese Koordinaten hast du schon probiert." << endl;
            continue;
        }
        return targetCoordinates;
    }
}
