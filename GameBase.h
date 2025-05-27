#ifndef GAMEBASE_H
#define GAMEBASE_H

const int SIZE = 4;

class GameBase {
protected:
    int board[SIZE][SIZE];

public:
    GameBase();
    virtual void initialize() = 0;
    virtual void display() = 0;
    virtual bool move(char direction) = 0;
    virtual bool isGameOver() = 0;
    virtual ~GameBase() {}
};

#endif