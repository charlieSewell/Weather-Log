#ifndef WINDLOGTYPE_H
#define WINDLOGTYPE_H
#include <iostream>
#include "Date.h"
#include "MyTime.h"

/**
	 * @class WindLogType
	 * @brief Stores all Weather Values
	 * @author Charlie Sewell
	 * @version 01
	 * @date 1/05/2020
*/

class WindLogType
{
    public:
        WindLogType();
        virtual ~WindLogType();
        /**
        * @brief Sets the Date of the data
        * @param date - date in the format 00/00/0000
        * @return void
        */
        void SetDate(std::string date);
        /**
        * @brief Sets the Time of the data
        * @param time - Time in the format 00:00
        * @return void
        */
        void SetTime(std::string time);
        /**
        * @brief Sets the Recorded Wind Speed
        * @param spee - Wind speed in m/s
        * @return void
        */
        void SetSpeed(float spee);
        /**
        * @brief Sets the Recorded Air Temperature
        * @param air - Air Temperature degrees C
        * @return void
        */
        void SetAirTemp(float air);
        /**
        * @brief Sets the Solar Radiation Recorded
        * @param solar - Solar Radiation in W/m^2
        * @return void
        */
        void SetSolarRadiation(float solar);
        /**
        * @brief Returns the Date of the Data
        * @return Date - Date of data
        */
        Date GetDate() const;
        /**
        * @brief Returns the Time of the Data
        * @return Time - Time of data
        */
        Time GetTime() const;
        /**
        * @brief Returns the Wind Speed Recorded
        * @return float - Wind speed in m/s
        */
        float GetSpeed() const;
        /**
        * @brief Returns the Air Temperature Recorded
        * @return float - Air Temperature in degrees C
        */
        float GetAirTemp() const;
        /**
        * @brief Returns the Amount of Solar Radiation Recorded
        * @return float - Solar radiation in W/m^2
        */
        float GetSolarRadiation() const;
        bool operator <(const WindLogType& w);
        bool operator >(const WindLogType& w);
        bool operator ==(const WindLogType& w);


    protected:

    private:
        Date d; ///Date of the recorded data
        Time t; ///Time of the recorded data
        float speed; ///Wind Speed in m/s
        float airTemp; /// Air Temperature in degrees C
        float solarRad; /// Amount of solar radiation in W/m^2
};

#endif // WINDLOGTYPE_H
