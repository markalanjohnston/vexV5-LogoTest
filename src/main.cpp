/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Mark Johnston                                             */
/*    Created:      1/19/2025, 9:17:18 PM                                     */
/*    Description:  Logo Graphics Proof of Concept                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "image.h"

using namespace vex;

vex::brain       Brain;

int main() {
    while(true){
        Brain.Timer.clear();
        Brain.Screen.setPenColor("#FFF");

        // Fly in the West Robotics logo from right to left
        for (int i = 600; i > -700; i-=1) {
            Brain.Screen.setOrigin(i,60); 
            drawWestRobotics();
            wait(8, msec);
            Brain.Screen.clearScreen();
            };

        // Fly in the Apex Ravens raven from left to right
        for (int i = -500; i < 500; i+=1) {
            Brain.Screen.setOrigin(i,0);
            drawRaven();
            wait(1, msec);
            Brain.Screen.clearScreen();
            wait(1, msec);                      // wait while blank to cause flicker as if flapping wings
            };
        
        wait(100,msec);

        // Fly back from right to left faster
        for (int i = 500; i > -500; i-=1) {
            Brain.Screen.setOrigin(i,0);
            drawRaven();
            wait(1, msec);
            Brain.Screen.clearScreen();
            wait(1, msec);                      // wait while blank to cause flicker as if flapping wings
            };

        wait(100,msec);

        Brain.Screen.setOrigin(8,0);            // reset starting point for drawing back to origin with slight compensation

        while(Brain.Timer.time(seconds) < 20){
            for (int i = 1; i < 360; i++) {
                Brain.Screen.setPenColor(i);    // change color
                drawRaven();
                wait(10, msec);
                }
        }
    }

}
