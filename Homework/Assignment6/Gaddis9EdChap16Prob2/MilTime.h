/* 
 * File:   MilTime.h
 * Author: Cameron Hartling
 * Created on December 4th 2022 5:00pm
 * Purpose: Holds MilTime Class
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"
#include <iostream>
using namespace std;
class Miltime :public Time
{
    private:
        int milHrs;
        int milSec;
    public:
        Miltime(int mh, int ms) {
            setTime(mh,ms);
        }
            
        void setTime(int mh, int ms) {
            if (mh < 0 || mh > 2359) {
                throw BadHour();
            }
            else if (ms < 0 || ms > 59){
                throw BadSeconds();
            }
            else {
                milHrs = mh;
                milSec = ms;
                hour = milHrs / 100;
                min = milHrs % 100;
                sec = milSec;
            }
        }
        
        //Exception classes
        class BadHour{};
        class BadSeconds{};
        
        int getHr() {
            return milHrs;
        }
        
        int getStandHr() {
            return hour;
        }
};

#endif