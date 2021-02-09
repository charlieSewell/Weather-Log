#include "Menu.h"
std::string GetMonthFromInt(int mont){
        Vector<std::string> monthStrings;
        monthStrings[0] = "January";
        monthStrings[1] = "February";
        monthStrings[2] = "March";
        monthStrings[3] = "April";
        monthStrings[4] = "May";
        monthStrings[5] = "June";
        monthStrings[6] = "July";
        monthStrings[7] = "August";
        monthStrings[8] = "September";
        monthStrings[9] = "October";
        monthStrings[10] = "November";
        monthStrings[11] = "December";
        return monthStrings[mont-1];
}
int ConvertYearInputToInt(std::string rawYear){
    try{
        return(std::stoi(rawYear)); //validates that input is an integer
    }catch(std::exception e){ //catches error in the case that it isnt an integer
        cout << "Year provided wasn't a number try again" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        return(0000);
    }
}
void displayMenu(){
    cout << "1. Average wind speed and sample deviation for a given month and year" << endl;
    cout << "2. Average ambient air temperature and sample deviation for every month of a given year" << endl;
    cout << "3. Total solar radiation in kWh/m^2 for each month of a given year" << endl;
    cout << "4. Output all results to CSV file." << endl;
    cout << "5. Highest Solar radiation for specified date." << endl;
    cout << "6. Quit Program" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "Enter selection: ";
}
void displayAvgWindForYear(WindLog &windlog){
    std::string month = "",yearRaw="";
    int year=0;
    float avg=0,stdev=0;
    while(year ==0){
        cout << "Enter month and year e.g. February 2020: " ;
        cin >> month >> yearRaw;
        year= ConvertYearInputToInt(yearRaw);
    }
    avg = windlog.GetAverageWind(month,year);//gets average of wind and stdev for a month and year
    stdev = windlog.GetWindStdev(month,year);
    if(avg ==0){
       cout << month << " "<< year << ": No Data"<<endl;
    }
    else{
        cout << month << " "<< year << ":"<<endl;
        cout << "Average Speed: " << avg << " km/h"<<endl;
        cout << "Sample stdev: " << stdev <<endl;
    }
    cout << "---------------------------------------------------------------------------------------" << endl;
}
void displayAvgAmbientForYear(WindLog &windlog){
    std::string yearRaw="";
    int year=0;
    float airTemp,stDev;
    while(year ==0){
        cout << "Enter year e.g. 2020: ";
        cin >> yearRaw;
        year= ConvertYearInputToInt(yearRaw);
    }
    cout<< year << endl;
    for(int i=1; i <= 12;i++){ //loops through the months getting average of ambient air and stdev
        airTemp = windlog.GetAverageAirTemp(GetMonthFromInt(i),year);
        stDev = windlog.GetAirTempStdev(GetMonthFromInt(i),year);
        if(airTemp == 0){
            cout << GetMonthFromInt(i)<< ": No Data"<< endl;
        }
        else{
            cout << GetMonthFromInt(i)<< ": average: "<< airTemp<< " degrees C, stdev: "<< stDev << endl;
        }
    }
    cout << "---------------------------------------------------------------------------------------" << endl;
}
void displayTotalRadiaton(WindLog &windlog){
    float rad=0;
    std::string yearRaw="";
    int year=0;
    while(year ==0){
         cout << "Enter year e.g. 2020: ";
        cin >> yearRaw;
        year= ConvertYearInputToInt(yearRaw); //input validation check
    }
    cout<< year << endl;
    for(int i=1; i <= 12;i++){ //loops through the months getting value of radiation
        rad = windlog.GetTotalRadiation(GetMonthFromInt(i),year);
        if(rad == 0){
            cout << GetMonthFromInt(i)<< ": No Data"<< endl;
        }
        else{
            cout << GetMonthFromInt(i)<< ": "<< rad<< " kWh/m^2"<< endl;
        }
    }
    cout << "---------------------------------------------------------------------------------------" << endl;
}
void maxRadForDate(WindLog &windlog){
    std::string date="";
    cout << "Enter date e.g. 12/12/2010: ";
    cin >> date;
    windlog.ShowMaxRadiation(date);
    cout << "---------------------------------------------------------------------------------------" << endl;
}
void outputToCSV(WindLog &windlog){
    int year=0,monthCount=0;
    float avgWind=0,windStdev=0,rad=0,avgAirTemp=0,airStdev=0;
    std::string yearRaw="";
    std::ofstream csvFile;
    csvFile <<std::fixed <<std::setprecision(1);
    csvFile.open("WindTempSolar.csv");
    while(year ==0){
        cout << "Enter year e.g. 2020: ";
        cin >> yearRaw;
        year= ConvertYearInputToInt(yearRaw); //input validation check
    }
    csvFile << year <<endl;
    for(int i=1; i <= 12;i++){
        avgWind = windlog.GetAverageWind(GetMonthFromInt(i),year);
        windStdev = windlog.GetWindStdev(GetMonthFromInt(i),year);
        rad = windlog.GetTotalRadiation(GetMonthFromInt(i),year);
        avgAirTemp = windlog.GetAverageAirTemp(GetMonthFromInt(i),year);
        airStdev = windlog.GetAirTempStdev(GetMonthFromInt(i),year);
        if(avgWind != NULL && windStdev != NULL && rad != NULL && avgAirTemp != NULL && airStdev != NULL){ //checking to see if the month has any data
            csvFile << GetMonthFromInt(i);
            csvFile << ",";
            if(avgWind  != NULL && windStdev != NULL) //checking to see if there is wind data
                csvFile << avgWind <<"("<< windStdev<<")";
            csvFile << ",";
            if(avgAirTemp != NULL && airStdev != NULL) //checking to see if there is air data
                csvFile << avgAirTemp <<"("<< airStdev<<")";
            csvFile << ",";
            if(rad != NULL) //checking to see if there is radiation data
                csvFile << rad;
            csvFile << endl;
            monthCount++;
        }
    }
    if(monthCount ==0){
         csvFile <<"No Data" <<endl;
    }
    cout << "Finished Output to WindTempSolar.csv" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
}
void selectMenu(WindLog &windlog){
    cout <<std::fixed <<std::setprecision(1);
    char option;
    while(option != '6'){
        displayMenu(); // displays menu options
        cin >> option;
        cin.sync(); // clears input stream
        if(option == '6')
            break; // exits execution if option is 5
        switch(option){
            case '1':
                displayAvgWindForYear(windlog);
            break;
            case '2':
                displayAvgAmbientForYear(windlog);
            break;
            case '3':
                displayTotalRadiaton(windlog);
            break;
            case '4':
                outputToCSV(windlog);
            break;
            case '5':
                maxRadForDate(windlog);
            break;
            default:
                cout << "Invalid Option! Please enter a number between 1-5" << endl;
        }
    }
}
