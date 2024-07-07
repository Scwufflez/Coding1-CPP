#include <iostream>
#include <string>
#include<ctime>    
#include<cstdlib>  
using namespace std;

 int main() {    //sets up the main program 
   string a="begin";
   string program="active";
   string Answer="";
   string Games[10];
   string name;
   string Commands[5]{"Add","Edit","Remove","Show","Quit"}; //testing out lists
cout<<"Hello Player, this is a program which was created in order to identify your favorite games. This list will only allow the player to input up to their top 10 games.\n";
while(program=="active" & a=="begin"){    //allows the player to start their list
  a="end";
  for(int game=0;game<2;game++){
    getline(cin, Games[game]);
}
  while (program=="active"){
    cout<<"What would you like to do to your list: Add, Edit, Remove, Show, Quit\n";
    cin>>Answer;
    if(Answer=="Add"){
      cout<<"What game would you like to add to your list? (This game will be added to the end of your list)\n";
      getline(cin>>ws,name); //I honestly dont know what the ws is but it made the code actually work 
      int counter=0;
      while (counter<10){
        if(Games[counter]==""){
          Games[counter]=name;
          break;
        }
        counter++;
      }//end of Add
    }
    else if(Answer=="Edit"){
      cout<<"What game would you like to edit? (This game will be replaced with the game you choose)\n";
      int counter=0;
      while (counter<10){
        if(Games[counter]==""){
          counter++;
          continue;
        }
        cout<<Games[counter]<<"\n";
        counter++;
      }
      getline(cin>>ws,name);
       counter=0;
      while (counter<10){
        if(Games[counter]==name){
          cout<<"What would you like to replace this game with?\n";
          getline(cin>>ws,name);
          Games[counter]=name;
          break;
        }
        counter++;
        if(counter==9){
          cout<<"That game is not in your list\n";
        }
      }
    }
    else if(Answer=="Show"){
    int counter=0;
    while (counter<10){
      if(Games[counter]==""){
        counter++;
        continue;
      }
      cout<<Games[counter]<<"\n";
      counter++;
    }
    }
    else if(Answer=="Remove"){
      cout<<"what game would you like to remove? (This game will be removed from your list)\n";
      int counter=0;
      while (counter<10){
        if(Games[counter]==""){
          counter++;
          continue;
        }
        cout<<Games[counter]<<"\n";
        counter++;
      }
      getline(cin>>ws,name);
      counter=0;
      while(counter<10){
        if(Games[counter].find(name) != string::npos){
          Games[counter].erase(counter);
      }
      counter++;
      }
    }
     else if(Answer=="Quit"){
      cout<<"Would you like to exit the list? (Yes or No)\n";
      cin>>Answer;
      if(Answer=="Yes"){
        program="end";
        cout<<"Thank you for using this program\n";
      }
    }
  }    //while==active
}
}
