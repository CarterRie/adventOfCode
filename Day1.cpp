//Advent of code Day 1 Challenge 1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream ElfCal;
    int setNum = 0;
    int maxCal1 = 0;
    int maxCal2 = 0;
    int maxCal3 = 0;
    int num;

   
    ElfCal.open("ElfCalorieInput.txt",ios::in); //open a file to perform read operation using the file object
    if (ElfCal.is_open()){
        string line;

        while(getline(ElfCal, line)){  //read data from the object



        //cout << line << " ";
        if(line==""){
            if(setNum > maxCal1){
                maxCal3 = maxCal2;
                maxCal2 = maxCal1;
                maxCal1 = setNum;
            } else if(setNum > maxCal2){
                maxCal3 = maxCal2;
                maxCal2 = setNum;
            } else if(setNum > maxCal3){
                maxCal3 = setNum;
            }
            //cout << setNum << " ";            
            setNum = 0;
            cout << maxCal1 << " " << maxCal2 << " " << maxCal3 <<endl;
            //system("pause");            

        } else{
            num = stoi(line);
            setNum = setNum + num;
        }


        }
        ElfCal.close();
    }
    int totalCal = maxCal1 + maxCal2 + maxCal3;
    cout << totalCal << endl;
    system("pause");

    return 0;
}