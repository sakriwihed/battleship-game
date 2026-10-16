#include "Ship.h"
#include "Missile.h"
#include "Constants.h"
#include "Coordinates.h"


// TODO Aufgabe 7:
//  Warum ist die folgende using-Anweisung hier unnötig?
// weil GameObjects wurde bereits im Namespace befunden .
// Also Alle Klassen, Funktionen und Konstanten aus GameObjects sind direkt verfügbar, ohne using .
using GameObjects::Constants;


namespace GameObjects {

    bool Ship::isInsideSeaBounds() const
    {
        if (x < Constants::seaSizeX && y < Constants::seaSizeY) {
            auto orientationAsInt = static_cast<unsigned int>(orientation);
            unsigned int
                shipEndX = x + (1 - orientationAsInt) * (size - 1),
                shipEndY = y + orientationAsInt * (size - 1);
            return  shipEndX < Constants::seaSizeX &&
                    shipEndY < Constants::seaSizeY;
        }
        return false;
    }

    // TODO Aufgabe 4:
    //  Definiert die Funktion `checkAndUpdateIncomingMissile(..)`.
    //  Nutzt die Funktionen von `Sea::Object`, um zu prüfen, ob die übergebene Rakete (`missile`) dieses Schiff trifft.
    //  Bei einem Treffer, markiert `missile` entsprechend.
     bool Ship::checkAndUpdateIncomingMissile(Missile& missile) {

        // Prüft, ob die Rakete das Schiff an einer seiner Koordinaten trifft
        if (atCoordinates(missile)) {
            missile.hitSomething();
            hits.push_back(missile);
                return true;
        }
            return false;
    }

    bool Ship::isDestroyed() const {

        // TODO Aufgabe 4:
        //  Prüft, ob alle Felder des Schiffs einmal getroffen wurden.
        //  (Tipp: Es können nie mehrere Raketen auf die gleichen Koordinaten geschossen werden.)
        int shipLength = size;
        int numberOfHits = static_cast<int>(hits.size()); //Zählt die gespeicherten Treffer auf das Schiff

        // Gibt true zurück, wenn das Schiff vollständig getroffen wurde, sonst false
        return (numberOfHits == shipLength);


    }
}


