#ifndef BLATT3_SHIP_H
#define BLATT3_SHIP_H

#include <vector>
#include "Object.h"
#include "Missile.h"


namespace GameObjects {

    class Ship : public Sea::Object {

    public:
        using Sea::Object::Object; // inherit constructors with identical parameters

        bool isInsideSeaBounds() const;
        // TODO Aufgabe 4:
        //  Deklariert die Funktion `bool checkAndUpdateIncomingMissile(Missile & missile)`
        bool checkAndUpdateIncomingMissile(Missile& missile);

        bool isDestroyed() const;

        // Speichert die Koordinaten der Treffer von checkAndUpdateIncomingMissile
        // In isDestroyed wird damit geprüft, ob das Schiff zerstört wurde
    private:
        std::vector<Coordinates> hits;
    };

}


// TODO Aufgabe 4:
//  Entfernt die Kommentar-Zeichen (//), wenn Aufgabe 4 erledigt ist:

#define CLASS_SHIP_COMPLETE


#endif //BLATT3_SHIP_H
