#include <iostream>
#include "conio.h"
#include <thread>
#include <chrono>

const int pressFrequency = 50;
const int keyArrowUp = 72;
const int keyArrowDown = 80;
const int keyArrowRight = 77;
const int keyArrowLeft = 75;


bool getInput(char *c);

int main(void) {
    char key = ' ';
    int analogValue = 255;

    while (key != 'q') {
        std::this_thread::sleep_for(
                std::chrono::milliseconds(1000 / pressFrequency));//When we are taking the input sleep x millisecond
        getInput(&key);

        switch (key) {
            case keyArrowUp:
                if (analogValue < 255) {
                    analogValue += 1;
                    //std::cout << analogValue << std::endl;
                } else {
                    analogValue = 255;
                    //std::cout << analogValue << std::endl;
                }
                break;

            case keyArrowDown:
                if (analogValue > 1) {
                    analogValue -= 1;
                    //std::cout << analogValue << std::endl;
                } else {
                    analogValue = 0;
                    //std::cout << analogValue << std::endl;
                }
                break;

            case keyArrowRight:
                if (analogValue < 255) {

                    analogValue += 10;
                    //std::cout << analogValue << std::endl;
                } else {
                    analogValue = 255;
                    //std::cout << analogValue << std::endl;
                }
                break;

            case keyArrowLeft:
                if (analogValue >= 10) {

                    analogValue -= 10;
                    //std::cout << analogValue << std::endl;
                } else {
                    analogValue = 0;
                    //std::cout << analogValue << std::endl;
                }
                break;
        }

        std::cout << "Current VAlue: " << analogValue << std::endl;
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