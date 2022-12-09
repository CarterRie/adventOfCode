//Advent of code Day 4 Challenge 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream file;
    int totalCount = 0;

    file.open("Campsite.txt",ios::in); //open a file to perform read operation using the file object
    if (file.is_open()){
        std::string line;


        while(getline(file, line)){  //read data from the object
            int len = line.length();
            std::size_t pos = line.find(",");

            std::string site1 = line.substr(0,pos);
            std::string site2 = line.substr(pos);


            std::size_t subPos = site1.find("-");

            std::string min1 = site1.substr(0,subPos);
            std::string max1 = site1.substr(subPos+1);

            int minSite1 = stoi(min1);
            int maxSite1 = stoi(max1);

            subPos = site2.find("-");

            std::string min2 = site2.substr(1,subPos-1);
            std::string max2 = site2.substr(subPos+1);          

            int minSite2 = stoi(min2);
            int maxSite2 = stoi(max2);          

            //cout << minSite1 << " " << maxSite1 << endl;
            //cout << minSite2 << " " << maxSite2 << endl;

            if(((minSite1 <= maxSite2) && (maxSite1 >= minSite2)) || ((minSite2 <= maxSite1) && (maxSite2 >= minSite1))){
                totalCount++;
            }

            //cout << totalCount << endl;
            //std::system("pause");
            

        }
    }
    file.close();
    
    cout << "Total sum: " << totalCount << endl;
    std::system("pause");

    return 0;
}