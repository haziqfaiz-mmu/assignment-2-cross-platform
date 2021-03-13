/********************************************
Course : TCP1101 Programming Fundamentals
Session: Trimester 2, 2020/21
Assignment: 2
Lecture Section : TC1V
Tutorial Section: TT1V
Name of Student #1 : MUHAMMAD HAZIQ FAIZ BIN MOHD RIPIN
ID of Student #1: 1201302740
Email of Student #1:1201302740@student.mmu.edu.my
Phone of Student #1:0132061817
Name of Student #2 : KAVIILASAN A/L GANESAN
ID of Student #2: 1181103578
Email of Student #2:1181103578
Phone of Student #2:016-2632704
********************************************/
#ifndef ROVER_H
#define ROVER_H
#include "map.h"
#include "include.h"

enum Direction{
    north = 0,
    east = 1,
    south =2,
    west = 3
};

class Rover{
    private:
        int x,y;
        Direction direction;
        char roverSymbol;
        char objectUnderRover;
        Map *p_mars;//points to the real map
        Map mapper;//map that we actually display
        int gold;
        int totalGoldInMap{0};
        int score;
        int numOfMoves;
        int availableMoves;
        string command;
        int totalCommandSequence;
        bool hillFlag;
        bool trapFlag;
        bool commandFlag{true};
        bool allGoldCollectedFlag;


    public:
    Rover(Map &Mars);//constructor that accept reference to the map
    void land();//done
    void markMap(int x, int y);//mark the mapper with 'I' after visited by rover
    void turnLeft();//done
    void turnRight();//done
    void move();//done
    void displayRealMap();//done
    void displayMapper();
    int calcScore(int gold, int totalCommandSequence, int moves);//done
    int getScore();
    int getAvailableMoves();
    bool getCommandFlag();
    int getTotalGoldInMap();
    int getRemainingGold();
    bool setAllGoldCollectedFlag();

    void executeCommand();
};


#endif