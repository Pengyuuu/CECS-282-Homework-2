#include <iostream>
#include <iomanip>
#include <random>
#include "travel.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    unsigned int seed;
    
    double angle, gunpowder, time, dist, bombDist;
    
    bool endGame = false;
    
    cout << "Please enter a positive integer seed value " << endl;
    
    cin >> seed;
    
    while (seed < 1){
        
        cout << "Please enter a positive integer seed value " << endl;
        
        cin >> seed;
    }
    
    mt19937 engine{seed};
    
    uniform_real_distribution<double> rangePos(1, 1000);
    
    dist = rangePos(engine);
    
    cout << fixed;
    
    cout << setprecision(2);
    
    cout << "The target is " << dist << " meters away" << endl;
    
    while (!endGame){
    
        angle = getAngle();
        
        gunpowder = getGunpowder();
        
        time = airTime(angle, gunpowder);
        
        bombDist = calculateDistance(angle, gunpowder, time);
                        
        endGame = hitOrMiss(dist, bombDist);
        
    }
            
    return 0;
}

