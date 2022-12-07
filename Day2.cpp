//Advent of code Day 2 Challenge 1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream RPS;
    int totalPoints = 0;

    RPS.open("RockPaperScissors.txt",ios::in); //open a file to perform read operation using the file object
    if (RPS.is_open()){
        std::string line;
        int points;

        while(getline(RPS, line)){  //read data from the object
            
            points = 0;
            std::string enemy = line.substr(0,1);
            std::string play = line.substr(2,1);

            //Evaluating points based on enemy and player input. I could generate a function to feed it the two plays as arguments instead, but this works for now.

            if(enemy == "A"){
                //evaluate your play based on A
                if(play == "X"){
                    points = 1+3;  //1 point for playing rock, 3 points for draw
                }
                else if(play == "Y"){
                    points = 2+6;  //2 points for playing paper, 6 points for winning
                }
                else if(play == "Z"){
                    points = 3+0;  //3 points for playing scissors, 0 points for draw
                }
                else{
                    std::cout << "Player choice error";
                }
                                                
            }

            else if(enemy == "B"){
                //evaluate your play based on B
                if(play == "X"){
                    points = 1+0;  //1 point for playing rock, 0 points for losing
                }
                else if(play == "Y"){
                    points = 2+3;  //2 points for playing paper, 3 points for draw
                }
                else if(play == "Z"){
                    points = 3+6;  //3 points for playing scissors, 6 points for winning
                }
                else{
                    std::cout << "Player choice error";
                }              
            }

            else if(enemy == "C"){
                //evaluate your play based on C
                if(play == "X"){
                    points = 1+6;  //1 point for playing rock, 6 points for winning
                }
                else if(play == "Y"){
                    points = 2+0;  //2 points for playing paper, 0 points for losing
                }
                else if(play == "Z"){
                    points = 3+3;  //3 points for playing scissors, 3 points for draw
                }
                else{
                    std::cout << "Player choice error";
                }                  
            } 
            else{
                std::cout << "Enemy choice error";
            }           
            //std::cout << "They chose: " << enemy << " You chose: " << play << endl;

            totalPoints = totalPoints + points;

            //std::cout << "Round points: " << points << endl;
            //std::cout << "Total points: " << totalPoints << endl;

            //std::system("pause"); //paused for debug
        }


        }
    RPS.close();
    
    std::cout << "Total Score: " << totalPoints << endl;
    system("pause");

    return 0;
}