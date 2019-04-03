SRC_DIR := ../ChessCore/src
OBJ_DIR := ../ChessCore/obj
BIN_DIR := ../ChessCore/bin
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

FLAGS := -lsfml-graphics -lsfml-window -lsfml-system

main: $(OBJ_FILES) $(OBJ_DIR)/main.o
					g++ -std=c++11 -o $@ $^ $(FLAGS)
					mv main $(BIN_DIR)

$(OBJ_DIR)/main.o: main.cpp
					g++ -std=c++11 -c -o main.o main.cpp
					mv main.o $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
					g++ -std=c++11 -c -o $@ $<