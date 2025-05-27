#include "Game2048.h"
#include "GameManager.h"

int main() {
    GameManager manager(new Game2048());
    manager.run();
    return 0;
}