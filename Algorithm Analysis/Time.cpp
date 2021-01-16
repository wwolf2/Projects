/*
 * Time.cpp
 * Implementation of Time class
 * Author: Billy Wolf
 * Created: April 15, 2019
 * Current: April 17, 2019
 */

#include <time.h>
#include <iostream>

using namespace std;


void DisplayTime(clock_t t){ // Displays the Time
    t = clock() - t;
    cout <<"Time in Seconds: " << ((float)t)/CLOCKS_PER_SEC << endl;
 
}