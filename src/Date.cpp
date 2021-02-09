#include "date.h"
Date::Date()
{
    day=0,month=0,year=0;
}
Date::~Date()
{

}
Date::Date(std::string date)
{
    SetDate(date);
}
std::string Date::GetDate() const
{
    std::string date = std::to_string(day)+ "/" + std::to_string(month) + "/" + std::to_string(year);
    return(date);
}
void Date::SetDay(unsigned inputDay)
{
    day = inputDay;
}
void Date::SetMonth(unsigned inputMonth)
{
    month = inputMonth;
    SetMonthString(month);
}
void Date::SetMonthString(unsigned inputMonth)
{
    switch(inputMonth){
        case 1:
            monthString = "January";
        break;
        case 2:
            monthString = "February";
        break;
        case 3:
            monthString = "March";
        break;
        case 4:
            monthString = "April";
        break;
        case 5:
            monthString = "May";
        break;
        case 6:
            monthString = "June";
        break;
        case 7:
            monthString = "July";
        break;
        case 8:
            monthString = "August";
        break;
        case 9:
            monthString = "September";
        break;
        case 10:
            monthString = "October";
        break;
        case 11:
            monthString = "November";
        break;
        case 12:
            monthString = "December";
        break;
    }
}

void Date::SetYear(unsigned inputYear)
{
    year = inputYear;
}
unsigned Date::GetDay() const
{
    return day;
}
unsigned Date::GetMonth() const
{
    return month;
}

unsigned Date::GetYear() const
{
    return year;
}
std::string Date::GetMonthString() const
{
    return monthString;
}

void Date::SetDate(std::string dat){
    try{
        std::stringstream ss(dat);
        std::string token;
        getline(ss,token,'/');
        day = stoi(token);
        getline(ss,token,'/');
        month = stoi(token);
        SetMonthString(month);
        getline(ss,token,'/');
        year = stoi(token);
    }catch(std::exception e){
        SetDate("0/0/0");
    }

}
bool Date::operator <(const Date& d) {
    if(year == d.GetYear()){
        if(month == d.GetMonth()){
            if(day == d.GetDay()){
                return false;
            }
            else if(day < d.GetDay()){
                return true;
            }
        }
        else if(month < d.GetMonth()){
            return true;
        }
    }
    else if(year < d.GetYear()) {
        return true;
    }
    return false;
}
bool Date::operator >(const Date& d) {
    if(year == d.GetYear()){
        if(month == d.GetMonth()){
            if(day == d.GetDay()){
                return false;
            }
            else if(day > d.GetDay()){
                return true;
            }
        }
        else if(month > d.GetMonth()){
            return true;
        }
    }
    else if(year > d.GetYear()) {
        return true;
    }
    return false;
}
bool Date::operator ==(const Date& d){
    if(d.day == day && d.month == month && d.year == year){
        return true;
    }
    return false;
}
