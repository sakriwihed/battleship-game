#include "TumblingMissile.h"

#include <iostream>
using std::cout;
using std::endl;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <algorithm>
using std::clamp;
#include <string>
using std::to_string;


#include "Coordinates.h"
using Sea::Coordinates;

#include "Constants.h"


namespace GameObjects
{
    TumblingMissile::TumblingMissile(Coordinates const & coordinates): Missile(coordinates)
    {
        std::tie(offsetX, offsetY) = randomizedMissileOffset();
        cout << " ... (Tumbling Missile | " << toString() << ")";
    }

    TumblingMissile::TumblingMissile(TumblingMissile const & missile):
    Missile(missile), offsetX(missile.offsetX), offsetY(missile.offsetY)
    {}

    Offset TumblingMissile::randomizedMissileOffset()
    {
        static random_device randomNumberInitializer;
        static mt19937 randomNumbers(randomNumberInitializer());
        static uniform_int_distribution<int> intMinus1to1(-1, 1);

        int x = intMinus1to1(randomNumbers);
        int y = intMinus1to1(randomNumbers);

        int X = static_cast<int>(Coordinates::getX()) + x;
        int Y = static_cast<int>(Coordinates::getY()) + y;
        if (X < 0 || X >= static_cast<int>(Constants::seaSizeX))
            x = 0;
        if (Y < 0 || Y >= static_cast<int>(Constants::seaSizeY))
            y = 0;

        return {x, y};
    }

    // TODO Aufgabe 3:
    //  Definiert die Funktionen `getX()`, `getY()` und `toString()`.



     unsigned int TumblingMissile::getX() const
    {
        //Ursprüngliche X-Koordinate mit zufälligen Offset addiert
        int result = static_cast<int>(Missile::getX()) + offsetX; // static_cast andert den Typ(unsigned int )von der Variable

        //Rückgabe als unsigned, weil negative Zahlen keine Koordinaten sein sollen
        return static_cast<unsigned int>(result);
    }

    unsigned int TumblingMissile::getY() const
    {
        int result = static_cast<int>(Missile::getY())+ offsetY;
        return static_cast<unsigned int>(result);
    }

    std::string TumblingMissile::toString() const {

        //Originale Koordinaten
        unsigned int OrgX = Missile::getX();
        unsigned int OrgY = Missile::getY();

        //Abweichende Koordinaten
        unsigned int AbwX = getX();
        unsigned int AbwY = getY();

        std::string Org = "(" + std::to_string(OrgX) + "," + std::to_string(OrgY) + ")";
        std::string Abw = "(" + std::to_string(AbwX) + "," + std::to_string(AbwY) + ")";

        //Gibt beide Koordinaten an
        return "Ziel ohne Abweichung: " + Org +  "|  Ziel mit Abweichung: " + Abw;
    }

}
