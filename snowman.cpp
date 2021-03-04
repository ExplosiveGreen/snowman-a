#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include "snowman.hpp"

namespace ariel{
    string snowman(int number){
        string output="";
	string map[9][4]={//the maping matrix for turning the numbers to the output
	{""," ___ ","  _"," ___"},
	{",",".","_"," "},
	{".","o","O","-"},
	{".","o","O","-"},
	{"<","\\","/",""},
	{">","/","\\",""},
	{" : ","] [","> <","   "},
	{" : ","\" \"","___","   "},
	{"_===_","....."," /_\\","(_*_)"}};
	//array that containt each choise for each leter |0|1|2|3|4|5|6|7|
	//						 |H|N|L|R|X|Y|T|B|
        int code[8]; 
	int number1=number;
	//puting the choises from the number to the code array and checking that the number is valid
        for(int i=7;i>=0;i--){
            code[i]=number%10;
	    if(number%10<1||number%10>4)
		throw std::invalid_argument{"Invalid code '"+std::to_string(number1)+"'"};
            number /= 10;
        }
	if(number>0)throw std::invalid_argument{"Invalid code '"+std::to_string(number1)+"'"};
	//cheack if its the first head then there no need for second level
	if(code[0]!=1){
	output+=(code[4]==4?"":" ")+map[0][code[0]-1]+"\n";
	}
	//add the head for the output and check if there left hand then add extra space
        output+=(code[4]==4?"":" ")+map[8][code[0]-1]+"\n";
	//check what kind of left hand there is if it upword hand then add it or if it downword hand then add space 
	if(code[4]==2) output+=map[4][code[4]-1];
	else if (code[4]==1||code[4]==3) output+=" ";
	//add the first body layer
	output+="(";
	output+=map[2][code[2]-1]+map[1][code[1]-1]+map[3][code[3]-1];
	//check if it a upword right hand and if it is add it to the output
	output+=")"+(code[5]%2==0?map[5][code[5]-1]:"")+"\n";
	//check waht kind of left hand there is if it downword hand then add it or if it upword then add space
	if(code[4]==2)output+=" ";
	else if(code[4]==1||code[4]==3) output+=map[4][code[4]-1];
        output+="(";
	//add the second body layer
	output+=map[6][code[6]-1];
	//check if it a donword right hand then add it
	output+=")"+(code[5]%2==1?map[5][code[5]-1]:"")+"\n";
	//add the last body layer
	if(code[4]!=4)output+=" ";
	output+="("+map[7][code[7]-1]+")";
        return output;
    }
}
