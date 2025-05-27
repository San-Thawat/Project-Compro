#ifndef GAME2048_H
#define GAME2048_H

#include "GameBase.h"
#include <vector>
#include <utility>

class Game2048 : public GameBase {
public:
    void initialize() override;
    void display() override;
    bool move(char direction) override;
    bool isGameOver() override;

private:
    void spawnTile();
};

#endif