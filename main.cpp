#include <iostream>
#include "Menu.h"
#include "WindLog.h"
#include "WindLogType.h"
using namespace std;

int main(){
    WindLog windlog;  //Creates windlog object
    windlog.SetWindData("met_index.txt");//takes windlog data from test2.csv which is located in the folder data
    selectMenu(windlog);//displays the menu and allows user to make input
    return 0;
}

