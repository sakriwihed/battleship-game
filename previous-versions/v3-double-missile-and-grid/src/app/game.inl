
// Hinweis: Da diese .inl-Datei in einer h-Datei inkludiert wird, darf/sollte hier (im Vergleich zu cpp-Dateien) kein `using ..` verwendet werden.


// TODO Aufgabe 2:
//  Implementiert hier die Template-Funktion `sendMissile<MissileType>(..)`.


template<typename MissileType>

bool sendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea) {

     //Ermittelt den Namen des Raketentyps
     std::string missileType = MissileType::getName();

     //Fragt Spieler nach Zielkoordinaten
     Sea::Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea, missileType);

    //Rakete mit Typen und Koordinaten wird erzeugt
     std::shared_ptr<MissileType> missile = std::make_shared<MissileType>(targetCoordinates);

    //Rakete wird auf Gegner gefeuert und Treffer wird verarbeitet
     bool hit = currentPlayerSea.sendMissileTo(otherPlayerSea, missile);


     return hit;

 }