#ifndef BSTMAZE_H
#define BSTMAZE_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct mazeRoom{
    int index;
    int funcIndex;
    mazeRoom* right;
    mazeRoom* left;
    mazeRoom* parent;

    mazeRoom(){
        right = NULL;
        left = NULL;
        parent = NULL;
    };
    mazeRoom(int x, int fI){
        index = x;
        funcIndex = fI;
        right = NULL;
        left = NULL;
        parent = NULL;
    }
    bool operator<(const mazeRoom & B){
        return (index<B.index);
    }
};

class BSTMaze{
    public:
        mazeRoom BSTMazeCreate(int rooms);
        BSTMaze();
        ~BSTMaze();
        bool battle(int, int, int); //if 1, left turn.  if 0, right turn.
        bool accuracyCheck(int, int);
        bool criticalCheck(int, int, int);
        void traverseTree(mazeRoom*& curr, bool win);
        void generateRoom(int funcIndex);
        int action(string input, int funcIndex);
        int hexToDec(int);
        mazeRoom* mazeBuild(int rooms);
        void addRoomNode(int index,int fI);
    private:
        int health;
        int attack;
        int defence;
        mazeRoom *root = NULL;
        void BSTDelete(mazeRoom*);
        mazeRoom* sortTree(vector<mazeRoom*> ourRooms, int start, int end);
        int leftTurns;
        int numberOfRooms;

};
#endif // BSTMAZE_H
