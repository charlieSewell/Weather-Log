#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
#include <sstream>
/**
	 * @class Time
	 * @brief Stores and displays the Time
	 * @author Charlie Sewell
	 * @version 01
	 * @date 29/04/2020
*/
class Time
{
    private:
        int hour; ///integer of hour
        int minute; ///integer of minute
    public:
        Time();
        virtual ~Time();
        Time(std::string time);
        /**
        * @brief returns the minute of the hour as an unsigned Int
        * @return minute - minute
        */
        unsigned GetMinute() const;
        /**
        * @brief returns the hour of the day as an unsigned Int
        * @return hour - hour
        */
        unsigned GetHour() const;
        /**
        * @brief returns the time of day as a string
        * @return time - time as string
        */
        std::string GetTime() const;
        /**
        * @brief Sets the Time
        * @param dat - time in the format 00:00
        * @return void
        */
        void SetTime(std::string dat);
        /**
        * @brief Sets the hour
        * @param h - unsigned integer representing hour
        * @return void
        */
        void SetHour(unsigned h);
        /**
        * @brief Sets the minute
        * @param m - unsigned integer representing minute
        * @return void
        */
        void SetMinute(unsigned m);
        bool operator <(const Time& t);
        bool operator >(const Time& t);
        bool operator ==(const Time& t);
};

#endif // TIME_H
