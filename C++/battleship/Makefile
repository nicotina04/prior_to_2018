CC = g++
TARGET = BattleShip
SOURCES = 	./engine/main.cpp \
			./engine/GameManager.cpp \
			./engine/Player.cpp \
			./engine/Map.cpp \
			./ships/Ship.cpp \
			./engine/CBattleShipApp.cpp \
			./UI/Pane.cpp \
			./engine/CBattleShipMap.cpp \
			./UI/StatPane.cpp \
			./UI/InputPane.cpp \
			./ships/Carrier.cpp \
			./ships/Battleship.cpp \
			./ships/Cruiser.cpp \
			./ships/Destroyer.cpp
LDFLAGS = -lncurses

all:
	$(CC) -std=c++11 -o $(TARGET) $(SOURCES) $(LDFLAGS)

run:
	$(CC) -std=c++11 -o $(TARGET) $(SOURCES) $(LDFLAGS) && ./$(TARGET)

clean:
	rm -rf *.o $(TARGET)
