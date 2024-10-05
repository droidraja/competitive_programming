#include <cstdio>

using namespace std;
#include <iostream>
// Declare external functions from main.cpp
extern bool move(int direction);
extern bool pick();
extern bool drop();
extern void init();
extern long long verify();
extern int total_ops;

// You can add your solution logic here
int heights[100][100];
struct Drone {
    int x, y, z;
} drone;

// Function to move the drone to the bottom


bool moveWrapper(int direction) {
    bool moved = false;
    moved = move(direction);
    if(moved) {
        //update the drone's position
        switch(direction) {
            case 0:
                drone.x++;
                break;
            case 1:
                drone.x--;
                break;
            case 2:
                drone.y++;
                break;
            case 3:
                drone.y--;
                break;
            case 4:
                drone.z++;
                break;
            case 5:
                drone.z--;
                break;
        }
    }
    return moved;
}

void moveToBottom() {
    while (moveWrapper(5)) {
        // Keep moving down (direction 5) until it can't move anymore
    }
}

bool isRowEnd() {
    return (drone.x == 0 && drone.y%2==1) || (drone.x == 99 && drone.y%2==0);
}

void moveToNextRow() {
    bool reached = false;
    while(!reached) {
        if(!reached) {
            moveWrapper(4);
        }
        reached = moveWrapper(2);
    }
}

bool moveToNextColumn(int direction) {
    bool reached = false;
    while(!reached) {
        if(!reached) {
            moveWrapper(4);
        }
        reached = moveWrapper(direction);
    }
    return true;
}

void figureOutHeights() {
    //goto 0,0,99
    //starts at 99,99,99 
    while(drone.x!=0){
        moveWrapper(1);
    }
    while(drone.y!=0){
        moveWrapper(3);
    }

    int direction = 0;
    int visited = 0;
    while(visited!=10000) {
        cout<<drone.x<<","<<drone.y<<","<<drone.z<<endl;
        do {
            moveToBottom();
            visited++;
            heights[drone.x][drone.y] = drone.z;

        } while(!isRowEnd()&&moveToNextColumn(direction));
        if(drone.x==0 && drone.y==99) {break;}
        if(isRowEnd()) {
            //move to next row
            moveToNextRow();
            direction = (direction+1)%2;
        } 
    }
}

void clearHeights() {
    for(int i=0;i<100;i++) {
        for(int j=0;j<100;j++) {
            heights[i][j] = 0;
        }
    }
}

void initUser() {
    drone = {99,99,99};
    clearHeights();
}

void process() {
    initUser();
    figureOutHeights();
}
