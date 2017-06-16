// reading a text file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () { //this is done(hex ascii to char), but better input method

  char str[256];

  std::cout << "Enter the name of the text file to be converted: "; //change this appearance, match example by Nemo
  std::cin.get (str,256);    // get c-string

  std::ifstream is(str);     // open file
  //end of new code

  string inputConditions;
  std::cout<< "Please enter flags:bin or xin, and bout or xout. Otherwise the default bin and xout is applied ";
  cin.ignore(); //fixes getline glitch
  getline(cin,inputConditions);



if( (inputConditions.find("xin") != string::npos) && (inputConditions.find("bout") != string::npos) ){
  string line; //xin, bout
  //ifstream myfile ("hexExample.txt"); //replaced all myfile with is
  if (is.is_open())
  {

    while ( getline (is,line, ' ') )
    {   //convert 2 digit strings to int
        int lineInt = atoi(line.c_str());

        if(41 <= lineInt <= 46 || 61 <= lineInt <= 66 || 30 <= lineInt <= 39){ //for letters
          if(lineInt==41){ //Capital Letters
            cout << 'A';
          }
          else if(lineInt==42){
            cout << 'B';
          }
          else if(lineInt==43){
            cout << 'C';
          }
          else if(lineInt==44){
            cout << 'D';
          }
          else if(lineInt==45){
            cout << 'E';
          }
          else if(lineInt==46){
            cout << 'F';
          }

          else if(lineInt==61){ //Lowercase Letters
            cout << 'a';
          }
          else if(lineInt==62){
            cout << 'b';
          }
          else if(lineInt==63){
            cout << 'c';
          }
          else if(lineInt==64){
            cout << 'd';
          }
          else if(lineInt==65){
            cout << 'e';
          }
          else if(lineInt==66){
            cout << 'f';
          }

        /*}

        else if(30 <= lineInt <= 39){ //for numbers */

          else if(lineInt==30){
            cout << '0';
          }
          else if(lineInt==31){
            cout << 1;
          }
          else if(lineInt==32){
            cout << 2;
          }
          else if(lineInt==33){
            cout << 3;
          }
          else if(lineInt==34){
            cout << 4;
          }
          else if(lineInt==35){
            cout << 5;
          }
          else if(lineInt==36){
            cout << 6;
          }
          else if(lineInt==37){
            cout << 7;
          }
          else if(lineInt==38){
            cout << 8;
          }
          else if(lineInt==39){
            cout << 9;
          }
        }

        else{
          cout<< "Not an appropriate ASCII hex value"<<endl;
        }


    }
    cout<< '\n';
    is.close(); //end of myfile
  }


} //end of xin bout

else if( ((inputConditions.find("bin") != string::npos) && (inputConditions.find("xout") != string::npos)) || (inputConditions.empty()) ){ //include the empty inputConditions default!!!!!!!!

  char c; //bin xout
  while (is.get(c))          // loop getting single characters
    std::cout<< std::hex <<(int)c << " ";

  is.close();                // close file


}

else if(((inputConditions.find("xin") != string::npos) && (inputConditions.find("xout") != string::npos)) || ((inputConditions.find("bin") != string::npos) && (inputConditions.find("bout") != string::npos)) ){

  string printStatement;

  while(getline (is,printStatement)){
    //getline (is,printStatement);
    cout<< printStatement <<endl;
  }

  is.close();
}



  else cout << "Unable to open file";

  return 0;
}
