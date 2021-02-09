#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Vector.h"
#include "WindLog.h"

/**
	 * @file Menu.h
	 * @brief Menu functions
	 * @author Charlie Sewell
	 * @version 01
	 * @date 1/05/2020
*/

using std::cout;
using std::cin;
using std::endl;

/**
* @brief Returns name of month string from int input
* @param mont - Month as an integer
* @return monthStrings[i] - Month as a string
*/
std::string GetMonthFromInt(int mont);
/**
* @brief Converts year string to int
* @param rawYear - year as a string
* @return int - year
*/
int ConvertYearInputToInt(std::string rawYear);
/**
* @brief User selection on menu
* @param &windlog - Wind Data
* @return void
*/
void selectMenu(WindLog &windlog);
/**
* @brief Displays average wind for input year and month
* @param &windlog - Wind Data
* @return void
*/
void displayAvgWindForYear(WindLog &windlog);
/**
* @brief Displays average Air Temperature for input year
* @param &windlog - Wind Data
* @return void
*/
void displayAvgAmbientForYear(WindLog &windlog);
/**
* @brief Displays Total Radiation for input year
* @param &windlog - Wind Data
* @return void
*/
void displayTotalRadiaton(WindLog &windlog);
/**
* @brief Displays Highest Radiation for specified date
* @param &windlog - Wind Data
* @return void
*/
void maxRadForDate(WindLog &windlog);
/**
* @brief Outputs data to CSV file for given year
* @param &windlog - Wind Data
* @return void
*/
void outputToCSV(WindLog &windlog);
/**
* @brief Displays Menu
* @return void
*/
void displayMenu();

#endif // MENU_H_INCLUDED
