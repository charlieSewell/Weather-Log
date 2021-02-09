#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <sstream>

/**
	 * @class Date
	 * @brief Stores and displays the date
	 * @author Charlie Sewell
	 * @version 01
	 * @date 27/04/2020
*/
class Date
{
    public:
        Date();
        Date(std::string date);
        virtual ~Date();
        /**
        * @brief returns the day as an unsigned integer
        * @return day - Day of the month
        */
        unsigned GetDay() const;
        /**
        * @brief returns the date as a string
        * @return date - date
        */
        std::string GetDate() const;
        /**
        * @brief returns the month as an unsigned integer
        * @return month - Month of the year
        */
        unsigned GetMonth() const;
        /**
        * @brief returns the year as an unsigned integer
        * @return year- Year
        */
        unsigned GetYear() const;
        /**
        * @brief Gets the Month as a string
        * @return monthString - Month as a string
        */
        std::string GetMonthString() const;
        /**
        * @brief Sets the date
        * @param dat - date in the format 00/00/0000
        * @return void
        */
        void SetDate(std::string dat);
        /**
        * @brief Sets the day
        * @param inputDay - unsigned integer of the day
        * @return void
        */
        void SetDay(unsigned inputDay);
        /**
        * @brief Sets the month
        * @param inputMonth - unsigned integer of the month
        * @return void
        */
        void SetMonth(unsigned inputMonth);
        /**
        * @brief Sets the year
        * @param inputYear - unsigned integer of the year
        * @return void
        */
        void SetYear(unsigned inputYear);
        bool operator <(const Date& d);
        bool operator >(const Date& d);
        bool operator ==(const Date& d);

    protected:

    private:
        unsigned day; ///day of the month as an unsigned integer
        unsigned month; ///month of the year as an unsigned integer
        unsigned year; ///year as an unsigned integer
        std::string monthString; ///month of the year as a string;


        /**
        * @brief Sets the month as a string
        * @param month - unsigned integer of the month
        * @return void
        */
        void SetMonthString(unsigned month);
};
#endif // DATE_H
