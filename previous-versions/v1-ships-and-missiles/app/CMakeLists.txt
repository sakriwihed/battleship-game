# TODO Aufgabe 1:
#  Fügt dem Projekt die Anwendung `Battleship` hinzu, mit den Dateien im Verzeichnis src/app/ und der Bibliothek `GameObjects`.

add_executable(Battleship game.cpp init.cpp main.cpp test.cpp)

target_link_libraries(Battleship PRIVATE GameObjects Sea)