#include "MyTime.h"

Time::Time()
{
    hour=0;
    minute=0;

}
Time::Time(std::string time){
    SetTime(time);
}
Time::~Time()
{
    //dtor
}
unsigned Time::GetMinute()const{
    return minute;
}

unsigned Time::GetHour()const{
    return hour;
}
std::string Time::GetTime() const{
    std::string time = std::to_string(hour) + ":" +std::to_string(minute);
    return(time);
}

void Time::SetTime(std::string dat){
    std::stringstream ss(dat);
    std::string token;
    getline(ss,token,':');
    hour = stoi(token);
    getline(ss,token,':');
    minute = stoi(token);
}
void Time::SetHour(unsigned h){
    hour = h;
}
void Time::SetMinute(unsigned m){
    minute = m;
}
bool Time::operator <(const Time& t) {
    if(hour == t.GetHour()){
        if(minute == t.GetMinute()){
            return false;
        }
        else if(minute < t.GetMinute()){
            return true;
        }
    }
    else if(hour < t.GetHour()) {
        return true;
    }
    return false;
}
bool Time::operator >(const Time& t) {
    if(hour == t.GetHour()){
        if(minute == t.GetMinute()){
            return false;
        }
        else if(minute > t.GetMinute()){
            return true;
        }
    }
    else if(hour > t.GetHour()) {
        return true;
    }
    return false;
}
bool Time::operator ==(const Time& t){
    if(t.GetHour() == hour && t.GetMinute() == minute){
        return true;
    }
    return false;
}

