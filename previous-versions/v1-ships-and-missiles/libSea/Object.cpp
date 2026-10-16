#include "Object.h"
#include "Coordinates.h"

namespace Sea {

    Object::Object(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Coordinates(newCoordinates), size(newSize), orientation(newOrientation)
    {
    }

    bool Object::atCoordinates(Coordinates const & coordinates) const
    {
        // TODO Aufgabe 2:
        //  Nutzt die Funktionalität von `Coordinates`, um zu bestimmen, ob ein Teil dieses Objekts auf den übergebenen Koordinaten (`coordinates`) liegt.

        for (unsigned int i = 0; i < size; ++i) {  // Prüft alle Felder, die das Objekt belegt

                unsigned int x = getX() + (orientation == Orientation::X ? i : 0);
                unsigned int y = getY() + (orientation == Orientation::Y ? i : 0);

                if (coordinates.samePositionAs(x, y)) {
                    return true;
                }
            }

                return false;
    }


    bool Object::intersectsWith(Object const & otherObject) const {
        // TODO Aufgabe 2:
        //  Nutzt die Funktion `atCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt (`otherObject`) überschneiden.
        for (unsigned int i = 0; i < size; ++i) {  /// Prüft alle belegten Felder auf Überschneidung

            // Berechnet die Koordinaten des aktuellen Feldes (je nach Ausrichtung)
            unsigned int x = getX() + (orientation == Orientation::X ? i : 0);
            unsigned int y = getY() + (orientation == Orientation::Y ? i : 0);

            // Position als Coordinates-Objekt speichern
            Coordinates FeldCoordinates(x, y);

            if (otherObject.atCoordinates(FeldCoordinates)) //Prüft ob Position besetzt ist
            {
                return true;
            }
        }

        return false;

    }

}
