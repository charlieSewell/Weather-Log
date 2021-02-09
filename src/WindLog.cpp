#include "WindLog.h"

WindLog::WindLog()
{
    //ctor
}

WindLog::~WindLog()
{
    //dtor
}
void WindLog::SetWindData(std::string fileName){
    int inc =0;

    std::ifstream metFile;
    metFile.open("data/"+fileName);
    if (!metFile) {
        cout << "Unable to open file: "<< fileName << endl;
        exit(0);
    }
    while(std::getline(metFile,fileName)){
        std::ifstream infile;
        infile.open("data/"+fileName);
        if (!infile) {
            cout << "Unable to open file: "<< fileName << endl;
            exit(0);
        }
        std::string temp;
        std::getline(infile,temp);

        std::vector<std::string> dataArr(18);
        while(std::getline(infile,temp)){
            if(temp != ",,,,,,,,,,,,,,,,,"){
                std::stringstream ss(temp);
                int i =0;
                while( ss.good() ){
                    std::getline(ss,dataArr[i],',');
                    i++;
                }
                WindLogType toBeInput;
                try{
                    toBeInput.SetSpeed(std::stof(dataArr[10]));
                    toBeInput.SetSolarRadiation(std::stof(dataArr[11]));
                    toBeInput.SetAirTemp(std::stof(dataArr[17]));
                    std::stringstream dt(dataArr[0]);
                    getline(dt,temp,' ');
                    toBeInput.SetDate(temp);
                    getline(dt,temp,' ');
                    toBeInput.SetTime(temp);
                    windData[toBeInput.GetDate().GetYear()][toBeInput.GetDate().GetMonthString()].Insert(toBeInput);
                }catch(std::invalid_argument e){
                    //std::cout << "Invalid Data" <<std::endl;
                }
            }
        }
        infile.close();
    }

    metFile.close();
}
float WindLog::GetAverageWind(std::string month, int year){
    int denom=0;
    float totalWind=0;
    windData[year][month].InOrderTraversal([&](WindLogType& x) {
        if(x.GetDate().GetMonthString() == month &&x.GetDate().GetYear() == year){
            totalWind += x.GetSpeed();
            denom++;
        }
    });
    if(denom ==0)
        return NULL;
    return(totalWind/denom);
}

float WindLog::GetWindStdev(std::string month,int year){
    float stDev = 0;
    int len = 0;
    float avg = GetAverageWind(month,year);
    windData[year][month].InOrderTraversal([&](WindLogType& x) {
        if(x.GetDate().GetMonthString() == month &&x .GetDate().GetYear() == year){
            stDev += (x.GetSpeed()-avg)*(x.GetSpeed()-avg);
            len++;
        }
    });
    if(len == 0)
        return NULL;
    stDev = stDev/(len-1);
    return(sqrt(stDev));
}
float WindLog::GetAverageAirTemp(std::string month, int year){
    int denom=0;
    float air=0;
    windData[year][month].InOrderTraversal([&](WindLogType& x) {
        if(x.GetDate().GetMonthString() == month &&x.GetDate().GetYear() == year){
            air += x.GetAirTemp();
            denom++;
        }
    });
    if(denom ==0)
        return NULL;
    return(air/denom);
}
float WindLog::GetAirTempStdev(std::string month,int year){
    float stDev = 0;
    int len = 0;
    float avg = GetAverageAirTemp(month,year);
    windData[year][month].InOrderTraversal([&](WindLogType& x) {
        if(x.GetDate().GetMonthString() == month && x.GetDate().GetYear() == year){
            stDev += (x.GetAirTemp()-avg)*(x.GetAirTemp()-avg);
            len++;
        }
    });
    if(len == 0)
        return NULL;
    stDev = stDev/(len-1);
    return(sqrt(stDev));
}
float WindLog::GetTotalRadiation(std::string month,int year){
    float total=0;
    windData[year][month].InOrderTraversal([&](WindLogType& x) {
        if(x.GetDate().GetMonthString() == month && x.GetDate().GetYear() == year && x.GetSolarRadiation() >= 100){
             total += x.GetSolarRadiation();
        }
    });
    return((total/6)/1000);
}
void WindLog::ShowMaxRadiation(std::string stringDate){
    Date date(stringDate);
    std::vector<Time> maxTimes;
    float maxRad =0;
    windData[date.GetYear()][date.GetMonthString()].InOrderTraversal([&](WindLogType& x){
        if( x.GetDate() == date){
            if(x.GetSolarRadiation() > maxRad){
                maxRad = x.GetSolarRadiation();
            }
        }
    });
    windData[date.GetYear()][date.GetMonthString()].InOrderTraversal([&](WindLogType& x){
        if( x.GetDate() == date){
            if(x.GetSolarRadiation() >= maxRad){
                maxRad = x.GetSolarRadiation();
                maxTimes.push_back(x.GetTime());
            }
        }
    });
    if(maxTimes.size() != 0){
      std::cout << "Time(s): " << std::endl;
        for(int i=0;i < maxTimes.size();i++){
            std::cout << maxTimes[i].GetTime() << std::endl;
        }
    }
    else{
        std::cout << "Date has no data or is invalid" << std::endl;
    }

}
