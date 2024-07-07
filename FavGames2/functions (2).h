#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string a="begin";
   string program="active";
   string Answer="";
   string Games[10];
   string name;
vector<string>Vect;
   int counter;
void Begin(){
    cout<<"Hello Player, this is a program which was created in order to identify your favorite games. This list will only allow the player to input up to their top 10 games.\n";
    for(int game=0;game<2;game++){
        getline(cin, Games[game]);
    }
}

void Initiate(){
    ofstream file;
    file.open("GameList.txt");
    file.close();
}
void Show(){
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

void Remove(){
    cout<<"what game would you like to remove? (This game will be removed from your list)\n";
      Show();
      getline(cin>>ws,name);
      counter=0;
      while(counter<10){
        if(Games[counter].find(name) != string::npos){
          Games[counter].erase(counter);
      }
      counter++;
      }
}

void Edit(){
    cout<<"What game would you like to edit? (This game will be replaced with the game you choose)\n";
      Show();
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

void Add(){
    cout<<"What game would you like to add to your list? (This game will be added to the end of your list)\n";
      getline(cin>>ws,name); //I honestly dont know what the ws is but it made the code actually work 
      int counter=0;
      while (counter<10){
        if(Games[counter]==""){
          Games[counter]=name;
          break;
        }
        counter++;
      }
}

void Quit(){
    
    cout<<"Would you like to save this list? (Y/N)\n";
    getline(cin,Answer);
    if(Answer=="N"){
        a="end";
    }
    else if(Answer=="Y"){    
        ofstream file;
        file.open("GameList.txt");
        counter=0;
        while(counter<10){
            Vect.push_back(Games[counter]);
            counter++;
        }
            counter=0;
        while(counter<10){
            file<<Vect[counter]<<"\n";
            counter++;
        }
        file.close();
        a="end";
    }
}

void Load(){
    ofstream file("GameList.txt");
    if(file.is_open()){
        counter=0;
        while(counter<10){
            Vect.push_back(Games[counter]);
            counter++;
        }
        for(int i=0;i<Vect.size();i++){
         file<<Vect[i]<<"\n";   
        }
    file.close();
    }
    else{
        Begin();
    }
}

void Options(){
    cout<<"What would you like to do to your list: Add, Edit, Remove, Show, Quit\n";
    getline(cin,Answer);
    if(Answer=="Add"){
        Add();
    }
    else if(Answer=="Edit"){
        Edit();
    }
    else if (Answer=="Remove"){
        Remove();
    }
    else if(Answer=="Show"){
        Show();
    }
    else if(Answer=="Quit"){
        Quit();
    }
}