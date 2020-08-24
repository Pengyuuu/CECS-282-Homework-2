#include "travel.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double getAngle(){
    
    double angle;
    
    cout << "Please choose a angle between 0 and 90 degrees " << endl;
    
    cin >> angle;
    
    while (angle < 0 || angle > 90){
        
        cout << "Invalid input. Please choose a angle between 0 and 90 degrees " << endl;
        
        cin >> angle;
    }
    
    return angle;
}

double getGunpowder(){
    
    double gunpowder;
    
    cout << "Please input some gunpowder in kilograms " << endl;
    
    cin >> gunpowder;
    
    while (gunpowder < 0){
        
        cout << "Invalid input. Please input some gunpowder in kilograms " << endl;
        
        cin >> gunpowder;
    }
        
    return gunpowder;
}

double airTime(double angle, double gunpowder){
    
    double g = 9.81, pi = 3.141592653589793238463;
        
    double initialV = (gunpowder * 30.0) * (sin(angle * (pi/180)));
    
    double finalV = -initialV;
    
    double changeV = finalV - initialV;
    
    double totalTime = changeV / -g;
    
    return totalTime;
}

double calculateDistance(double angle, double gunpowder, double totalTime){
    
    double pi = 3.141592653589793238463;
    
    double initialX = (gunpowder * 30.0) * (cos(angle * (pi/180)));
    
    double totalX = initialX * totalTime;
    
    return totalX;
}

bool hitOrMiss(double distance, double projDistance ){
    
    
    if ((projDistance - distance) > 0.0 && (projDistance - distance) < 1.0){
        
        cout << "It's a hit!" << endl;
        
        return true;
    }
    else if ((projDistance - distance) < 0.0 ){
        
        cout << "You were " << -(projDistance - distance) << " meters short" << endl;
        
        return false;
    }
    
    else if ((projDistance - distance) > 1.0){
        
        cout << "You were " << (projDistance - distance) << " meters long" << endl;
        
        return false;
    }
    
    return false;
}
