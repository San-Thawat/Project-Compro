#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameBase.h"

class GameManager {
private:
    GameBase* game;

public:
    GameManager(GameBase* g);
    void run();
    ~GameManager();
};

#endif