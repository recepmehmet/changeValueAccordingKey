#include <iostream>
#include "conio.h"
#include <thread>
#include <chrono>

const int pressFrequency = 10;


bool getInput(char *c);

int main(void) {
    char key = ' ';
    int defaultTimeConstantWindows = 300;

    while (key != 'q') {
            std::this_thread::sleep_for(
                    std::chrono::milliseconds(1000 / pressFrequency));//When we are taking the input sleep x millisecond
            getInput(&key);

            std::cout << "You Pressed: " << key << std::endl;
            key = ' ';
    }

    std::cout << "You Pressed q, End Of Program" << std::endl;
    return 0;
}

bool getInput(char *c) {
    if (kbhit()) {//press the key and take input without enter function
        *c = getch();//We are taking for press the screen
        return true; // Key Was Hit
    }

    return false; // No keys were pressed
}