//Advent of code Day 3 Challenge 1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream RS;
    int totalCount = 0;

    RS.open("Rucksack.txt",ios::in); //open a file to perform read operation using the file object
    if (RS.is_open()){
        std::string line;


        while(getline(RS, line)){  //read data from the object
            int len = line.length();
            std::string comp1 = line.substr(0,len/2);
            std::string comp2 = line.substr(len/2,len/2);

            int freq1[52] = {0};
            int freq2[52] = {0};

            for(int i=0; i<len/2; i++){
                if(comp1[i]-'a'>=0){
                freq1[comp1[i]-'a']++;  //'a'-'a' = 0, 'b'-'a' = 1, 'A'-'a' = -32, 'B' - 'a' = -31
                }
                else{
                    freq1[comp1[i]-'a'+ 58]++;
                }

            }

            for(int i = 0; i<52;i++){
                cout << freq1[i];
            }

            cout << endl;

            for(int i=0; i<len/2; i++){
                if(comp2[i]-'a'>=0){
                freq2[comp2[i]-'a']++;  //'a'-'a' = 0, 'b'-'a' = 1, 'A'-'a' = -32, 'B' - 'a' = -31
                }
                else{
                    freq2[comp2[i]-'a'+ 58]++;
                }

            }

            for(int i = 0; i<52;i++){
                cout << freq2[i];
            }
            cout << endl;
            cout << "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
            int count = 0;

            bool noMatch = true;
            while(noMatch){
                cout<< freq1[count]*freq2[count] << endl;
                cout << count << endl;
                if(freq1[count]*freq2[count] > 0){
                    noMatch = false;
                }
                    count++;                
            }

            cout << comp1 << endl << comp2 << endl;

            cout << count << endl;
            totalCount += count;
            cout << totalCount << endl;
            //std::system("pause");
        }
    }
    RS.close();
    
    cout << "Total sum: " << totalCount << endl;
    std::system("pause");

    return 0;
}