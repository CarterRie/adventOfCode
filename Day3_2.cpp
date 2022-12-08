//Advent of code Day 3 Challenge 2
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

            std::string Elf1 = line;
            getline(RS,line);
            std::string Elf2 = line;
            getline(RS,line);
            std::string Elf3 = line;


            int freq1[52] = {0};
            int freq2[52] = {0};
            int freq3[52] = {0};

            for(int i=0; i<Elf1.length(); i++){
                if(Elf1[i]-'a'>=0){
                freq1[Elf1[i]-'a']++;  //'a'-'a' = 0, 'b'-'a' = 1, 'A'-'a' = -32, 'B' - 'a' = -31
                }
                else{
                    freq1[Elf1[i]-'a'+ 58]++;
                }

            }
            for(int i = 0; i<52;i++){
                cout << freq1[i];
            }
            cout << endl;


            for(int i=0; i<Elf2.length(); i++){
                if(Elf2[i]-'a'>=0){
                freq2[Elf2[i]-'a']++;  //'a'-'a' = 0, 'b'-'a' = 1, 'A'-'a' = -32, 'B' - 'a' = -31
                }
                else{
                    freq2[Elf2[i]-'a'+ 58]++;
                }
            }
            for(int i = 0; i<52;i++){
                cout << freq2[i];
            }
            cout << endl;


            for(int i=0; i<Elf3.length(); i++){
                if(Elf3[i]-'a'>=0){
                freq3[Elf3[i]-'a']++;  //'a'-'a' = 0, 'b'-'a' = 1, 'A'-'a' = -32, 'B' - 'a' = -31
                }
                else{
                    freq3[Elf3[i]-'a'+ 58]++;
                }
            }
            for(int i = 0; i<52;i++){
                cout << freq3[i];
            }
            cout << endl;


            cout << "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
            int count = 0;

            bool noMatch = true;
            while(noMatch && count <= 52){
                if(freq1[count]*freq2[count]*freq3[count] > 0){
                    noMatch = false;
                }
                //cout<< freq1[count]*freq2[count]*freq3[count] << endl;  
                //cout << count << endl;  
                count++;                
            }


            totalCount += count;
            cout << "Total count so far: " << totalCount << endl;
            //std::system("pause");
        }
    }
    RS.close();
    
    cout << "Total sum: " << totalCount << endl;
    std::system("pause");

    return 0;
}