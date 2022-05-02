CC = g++
TARGET = game
$(TARGET): main.cpp game.cpp texturemanager.cpp object.cpp player.cpp background.cpp building.cpp coin.cpp text.cpp LTexture.cpp eagle.cpp
	$(CC) main.cpp game.cpp texturemanager.cpp object.cpp player.cpp background.cpp building.cpp coin.cpp text.cpp LTexture.cpp eagle.cpp -o ./$(TARGET) -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

