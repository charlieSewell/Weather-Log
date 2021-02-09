#ifndef WINDLOG_H
#define WINDLOG_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <map>
#include <vector>
#include "Vector.h"
#include "BST.h"
#include "WindLogType.h"

using std::cout;
using std::cin;
using std::endl;

/**
    * @class WindLog
    * @brief Stores All Wind Data for a period of time
    * @author Charlie Sewell
    * @version 01
    * @date 30/04/2020
*/

class WindLog
{
    public:
        WindLog();
        virtual ~WindLog();
        /**
        * @brief Inputs all wind Data from a csv file
        * @param fileName - File Name
        * @return void
        */
        void SetWindData(std::string fileName);
        /**
        * @brief Returns average Wind for a specified month of a year
        * @param month - month
        * @param year - year
        * @return float - Average Wind in m/s
        */
        float GetAverageWind(std::string month, int year);
        /**
        * @brief Returns Standard Deviation of Wind for a specified month of a year
        * @param month - month
        * @param year - year
        * @return float - Standard Deviation of Wind in m/s
        */
        float GetWindStdev(std::string month,int year);
        /**
        * @brief Returns total radiaiton for specified month and year
        * @param month - month
        * @param year - year
        * @return float - Total Radiation in kWh/m^2Vect
        */
        float GetTotalRadiation(std::string month,int year);
        /**
        * @brief Returns average Temperature for a specified month of a year
        * @param month - month
        * @param year - year
        * @return float - Average Temperature in degrees C
        */
        float GetAverageAirTemp(std::string month, int year);
        /**
        * @brief Returns Standard Deviation of Temperature for a specified month of a year
        * @param month - month
        * @param year - year
        * @return float - Standard Deviation of Temperature in degrees C
        */
        float GetAirTempStdev(std::string month, int year);

        void ShowMaxRadiation(std::string stringDate);


    protected:

    private:
        std::map<int,std::map<std::string,BST<WindLogType>>> windData;///Array of wind data
};

#endif // WINDLOG_H
