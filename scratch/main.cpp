#include <cstdlib>
#include <ctime>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

const int ROOM_SIZE = 100;
const int TOTAL_BOXES = 100000;
const long long PENALTY = 1000000000LL;

struct Box {
    int x, y;
    int weight;
};

struct Drone {
    int x, y, z;
};

Box room[ROOM_SIZE][ROOM_SIZE][ROOM_SIZE];
int stack_heights[ROOM_SIZE][ROOM_SIZE];  // Changed from 'heights' to 'stack_heights'
Drone current_drone;
Box* picked_box = nullptr;
int total_ops = 0;

unsigned int seed = 0;

int rand() {
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 32768;
}

void init() {
    seed = static_cast<unsigned int>(time(nullptr));
    
    for (int i = 0; i < ROOM_SIZE; ++i) {
        for (int j = 0; j < ROOM_SIZE; ++j) {
            stack_heights[i][j] = 0;  // Updated to use 'stack_heights'
            for (int k = 0; k < ROOM_SIZE; ++k) {
                room[i][j][k] = {0, 0, 0};
            }
        }
    }

    current_drone = {99, 99, 99};
    total_ops = 0;

    for (int i = 0; i < TOTAL_BOXES; ++i) {
        int x = rand() % ROOM_SIZE;
        int y = rand() % ROOM_SIZE;
        int weight = rand() % 1000 + 1;

        if (stack_heights[x][y] < ROOM_SIZE - 1) {  // Updated to use 'stack_heights'
            room[x][y][stack_heights[x][y]] = {x, y, weight};
            stack_heights[x][y]++;  // Updated to use 'stack_heights'
        }
    }
}

bool move(int direction) {
    int new_x = current_drone.x;
    int new_y = current_drone.y;
    int new_z = current_drone.z;

    switch (direction) {
        case 0: new_x++; break; // North
        case 1: new_x--; break; // South
        case 2: new_y++; break; // East
        case 3: new_y--; break; // West
        case 4: new_z++; break; // Up
        case 5: new_z--; break; // Down
        default: return false;
    }

    if (new_x < 0 || new_x >= ROOM_SIZE || 
        new_y < 0 || new_y >= ROOM_SIZE || 
        new_z < 0 || new_z >= ROOM_SIZE ||
        (new_z < stack_heights[new_x][new_y] && room[new_x][new_y][new_z].weight != 0)) {  // Updated to use 'stack_heights'
        return false;
    }

    current_drone = {new_x, new_y, new_z};
    total_ops++;
    return true;
}

bool pick() {
    if (picked_box != nullptr) return false;

    int x = current_drone.x;
    int y = current_drone.y;
    int z = current_drone.z;

    if (z != stack_heights[x][y] - 1) return false;  // Updated to use 'stack_heights'

    picked_box = &room[x][y][z];
    room[x][y][z] = {0, 0, 0};
    stack_heights[x][y]--;  // Updated to use 'stack_heights'
    total_ops++;
    return true;
}

bool drop() {
    if (picked_box == nullptr) return false;

    int x = current_drone.x;
    int y = current_drone.y;
    int z = current_drone.z;

    if (z != stack_heights[x][y] + 1) return false;  // Updated to use 'stack_heights'

    room[x][y][stack_heights[x][y]] = *picked_box;  // Updated to use 'stack_heights'
    stack_heights[x][y]++;  // Updated to use 'stack_heights'
    picked_box = nullptr;
    total_ops++;
    return true;
}

long long verify() {
    for (int x = 0; x < ROOM_SIZE; ++x) {
        for (int y = 0; y < ROOM_SIZE; ++y) {
            for (int z = 0; z < stack_heights[x][y]; ++z) {  // Updated to use 'stack_heights'
                Box& box = room[x][y][z];
                if (box.x != x || box.y != y) return PENALTY;
                if (z > 0 && box.weight > room[x][y][z-1].weight) return PENALTY;
            }
        }
    }
    return 0;
}

extern void process();

int main() {
    const int NUM_TEST_CASES = 20;  
    
    for (int test = 1; test <= NUM_TEST_CASES; ++test) {
        init();
        process();
        
        long long result = verify();
        if (result == PENALTY) {
            printf("Test case %d: PENALTY\n", test);
        } else {
            printf("Test case %d: %d\n", test, total_ops);
        }
    }

    return 0;
}