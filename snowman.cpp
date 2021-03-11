#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
using namespace std;

#include "snowman.hpp"
namespace ariel{
    string snowman(int number){
        string output;
        array<array<string,MAXCHOISE>,NUMLETTERS+1>map{//the maping matrix for turning the numbers to the output
        array<string,MAXCHOISE>{""," ___ ","  _"," ___"},
        array<string,MAXCHOISE>{",",".","_"," "},
        array<string,MAXCHOISE>{".","o","O","-"},
        array<string,MAXCHOISE>{".","o","O","-"},
        array<string,MAXCHOISE>{"<","\\","/",""},
        array<string,MAXCHOISE>{">","/","\\",""},
        array<string,MAXCHOISE>{" : ","] [","> <","   "},
        array<string,MAXCHOISE>{" : ","\" \"","___","   "},
        array<string,MAXCHOISE>{"_===_","....."," /_\\","(_*_)"}};
        //array that containt each choise for each leter |0|1|2|3|4|5|6|7|
        //                                               |H|N|L|R|X|Y|T|B|
        array<int,NUMLETTERS> code{};
        int number1=number;
        //puting the choises from the number to the code array and checking that the number is valid
        for(int i=NUMLETTERS-1;i>=0;i--){
            code.at(i)=number%DIV;
            if(number%DIV<MINCHOISE||number%DIV>MAXCHOISE){
                throw std::invalid_argument{"Invalid code '"+std::to_string(number1)+"'"};
            }
            number /= DIV;
        }
        if(number>MINCHOISE-1){throw std::invalid_argument{"Invalid code '"+std::to_string(number1)+"'"};}
        //cheack if its the first head then there no need for second level
        if(code[HUP]!=NOUP){
        output+=(code[X]==NOLEFT?"":" ")+map[HUP][code[HUP]-1]+"\n";
        }
        //add the head for the output and check if there left hand then add extra space
        output+=(code[X]==NOLEFT?"":" ")+map[HDOWN][code[HUP]-1]+"\n";
        //check what kind of left hand there is if it upword hand then add it or if it downword hand then add space
        if(code[X]==LEFTUP){ output+=map[X][code[X]-1];}
        else if (code[X]==LEFTDOWN1||code[X]==LEFTDOWN2){ output+=" ";}
        //add the first body layer
        output+="(";
        output+=map[L][code[L]-1]+map[N][code[N]-1]+map[R][code[R]-1];
        //check if it a upword right hand and if it is add it to the output
        output+=")"+(code[Y]%MOD==ZUGI?map[Y][code[Y]-1]:"")+"\n";
        //check waht kind of left hand there is if it downword hand then add it or if it upword then add space
        if(code[X]==LEFTUP){output+=" ";}
        else if(code[X]==LEFTDOWN1||code[X]==LEFTDOWN2){ output+=map[X][code[X]-1];}
        output+="(";
        //add the second body layer
        output+=map[T][code[T]-1];
        //check if it a donword right hand then add it
        output+=")"+(code[Y]%MOD==IZUGI?map[Y][code[Y]-1]:"")+"\n";
        //add the last body layer
        if(code[X]!=NOLEFT){output+=" ";}
        output+="("+map[B][code[B]-1]+")";
        return output;
    }
}
