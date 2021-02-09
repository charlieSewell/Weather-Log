#include "WindLogType.h"

WindLogType::WindLogType()
{
    //ctor
}

WindLogType::~WindLogType()
{
    //dtor
}
void WindLogType::SetDate(std::string date){
    d.SetDate(date);
}
void WindLogType::SetTime(std::string time){
    t.SetTime(time);
}
void WindLogType::SetSpeed(float spee){
    speed = spee;
}
void WindLogType::SetAirTemp(float air){
    airTemp = air;
}
void WindLogType::SetSolarRadiation(float solar){
    solarRad = solar;
}
Date WindLogType::GetDate() const{
    return d;
}
Time WindLogType::GetTime() const{
    return t;
}
float WindLogType::GetSpeed()const{
    return speed;
}
float WindLogType::GetAirTemp()const{
    return airTemp;
}
float WindLogType::GetSolarRadiation()const{
    return solarRad;
}
bool WindLogType::operator <(const WindLogType& w){
    if(d == w.GetDate()){
        if(t == w.GetTime()){
            return false;
        }
        else if(t < w.GetTime()){
            return true;
        }
    }
    else if(d < w.GetDate()) {
        return true;
    }
    return false;
}
bool WindLogType::operator >(const WindLogType& w){
    if(d == w.GetDate()){
        if(t == w.GetTime()){
            return false;
        }
        else if(t > w.GetTime()){
            return true;
        }
    }
    else if(d > w.GetDate()) {
        return true;
    }
    return false;
}
bool WindLogType::operator ==(const WindLogType& w){
    //rationale: 2 windlogs are the same when there date and time are the same
    //I have chosen to do this because although the data may be differant the time
    //it was captured is the exact same
    if(d == w.GetDate() && t == w.GetTime()){
        return true;
    }
    else{
        return false;
    }
}

