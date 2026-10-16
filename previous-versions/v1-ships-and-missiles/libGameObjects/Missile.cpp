#include "Missile.h"

// TODO Aufgabe 3:
//  Definiert die Funktionen der Klasse `Missile`.

namespace GameObjects {

    Missile::Missile(const Coordinates& position)
        :Coordinates(position) {}

    void Missile::hitSomething()
    {
        hit = true;
    }

}

