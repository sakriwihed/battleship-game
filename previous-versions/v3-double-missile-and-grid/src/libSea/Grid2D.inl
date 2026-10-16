
// Siehe Hinweis in 'game.inl'

#include <stdexcept>


// TODO Aufgabe 3:
//  Implementiert den Konstruktor von Grid2D.
//  Stellt mithilfe von Exceptions sicher, dass kein Grid2D mit einer ungültigen Größe (< 1x1) erstellt werden kann.
//  Tipp: Zur Initialisierung stellt `std::vector` einen entsprechenden Konstruktor zur Verfügung: `std::vector<ElementTyp>(Anzahl, initElement)`
//        Dieser wurde auch schon für `gridOwnSea` in 'PlayerSea.h' verwendet.

 namespace Sea
 {
  template <typename T>

  Grid2D<T>::Grid2D(size_t sizeX, size_t sizeY, const T& initElement)
   : grid(sizeY, std::vector<T>(sizeX, initElement)) {

   if (sizeX == 0 || sizeY == 0 )
   {
    throw std::invalid_argument("Grid2D: sizeX und sizeY müssen größer als 0 sein");
   }

  }


  // TODO Aufgabe 3:
  //  Implementiert `sizeX()` und `sizeY()`.
  //  Erinnerung: die Größe in X-Richtung entspricht dabei der Anzahl der Elemente (vom Typ `T`) in den "inneren" Vektoren.
  //                           Y-Richtung ist die Größe des "außeren" Vektors `grid`.

  //Gibt die Anzahl Spalten (X-Richtung) zurück
  template <typename T>
  size_t Grid2D<T>::sizeX() const {
   return grid[0].size();
  }

  //Gibt die Anzahl Zeilen (Y-Richtung) zurück
  template <typename T>
  size_t Grid2D<T>::sizeY() const {
   return grid.size();
  }

  // TODO Aufgabe 3:
  //  Implementiert die 4 Operator-Überladungen.
  //  Stellt sicher, dass Exceptions geworfen werden, wenn ungültige Koordinaten übergeben wurden.

  //Zugriff über Coordinates-Objekt
  //Prüft, ob x und y innerhalb der gültigen Grenzen liegen
  template <typename T>
  T& Grid2D<T>::operator[](const Coordinates& coords) {
   size_t x = coords.getX();
   size_t y = coords.getY();

   //Fehlermeldung, wenn diese außerhalb sind
   if (y >= grid.size() || x >= grid[0].size()) {
    throw std::out_of_range("Grid2D: Zugriff außerhalb der Grenzen");
   }

   return grid[y][x];
  }

  //Zugriff über Coordinates-Objekt(const)
  //Prüft, ob x und y innerhalb der gültigen Grenzen liegen
  template <typename T>
  const T& Grid2D<T>::operator[](const Coordinates& coords) const {
   size_t x = coords.getX();
   size_t y = coords.getY();

   if (y >= grid.size() || x >= grid[0].size()) {
    throw std::out_of_range("Grid2D: Zugriff außerhalb der Grenzen");
   }

   return grid[y][x];
  }

  //Direkter Zugriff über x und Y Koordinaten
  template <typename T>
  T& Grid2D<T>::operator()(size_t x, size_t y) {

   if (y >= grid.size() || x >= grid[0].size()) {
    throw std::out_of_range("Grid2D: Zugriff außerhalb der Grenzen");
   }
   return grid[y][x];
  }

  //Direkter Zugriff über x und Y Koordinaten (const)
  template <typename T>
  const T& Grid2D<T>::operator()(size_t x, size_t y) const {

   if (y >= grid.size() || x >= grid[0].size()) {
    throw std::out_of_range("Grid2D: Zugriff außerhalb der Grenzen");
   }
   return grid[y][x];
  }
 }
