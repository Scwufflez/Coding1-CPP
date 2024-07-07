// Alex Dempsey June 6, 2024
// Week 1 assignment

#include <iostream>
#include <string>
#include<ctime>    //for seeding the random number generation
#include<cstdlib>  //for generating random numbers with rand()
using namespace std;

int main() {
  srand(time(0));
  int PHealth=10, EHealth=5, attack,eattack, block, heal, turns=0,OP=0;    // sets up the game
  string Answer="", active;     
  cout<< "You are trying to join a gang, but you need to prove your worth"<<endl<< "You will need to take down at least 3 members otherwise you will be rejected"<<endl<< "Would you like to attempt to join the gang? (y/n)"<<endl;      // Game story 
  cin>>Answer;
  if(Answer == "y"){        // Allows the player ot attempt joining the gang
    active="True";
  }
  else{
    active="False";
  }
  while(active=="True"){    //Starts the gang fight
    if(PHealth>0 & turns<5){
      if(turns==0){
        cout<<"A new gang member has appeared"<<endl;
      }
      turns++;
      cout<<"You have "<<PHealth<<" health"<<endl<<"The gang member has "<<EHealth<<" health"<<endl<<"Would you like to Attack or Block? (a/b)"<<endl;
      cin>>Answer;
      if(Answer=="a"){        //Allows the player to attack the gang member
        attack= rand() % 4 +1, eattack= rand() % 4 +1; 
        cout<<"You attacked for "<<attack<<" damage"<<endl<< "The gang member attacked for "<<eattack<<" damage"<<endl;
        EHealth=EHealth-attack;
        PHealth=PHealth-eattack;
      }
      else if(Answer=="b"){    //allows the player to block/heal against the gang member
        block= rand() % 4 +1, eattack= rand() % 4 +1;
        if(block>eattack){
          heal= rand() % 3 +1;
          cout<<"You blocked the attack"<<endl<< "You healed "<<heal<<" health"<<endl;
          PHealth=PHealth+heal;
        }
        else{
          PHealth=PHealth-eattack;
          cout<<"You failed to block the attack"<<endl<<"You lost "<<eattack<<" health"<<endl;
        }
      }
    if(OP>3&EHealth<=0){      //checks if the player has beaten all the gang fights or just an individual member
      cout<< "You have been accepted into the gang with "<<PHealth<<" health"<<endl<<" remaining.";
    }
    else if(EHealth<=0 & PHealth>=0){      //checks if the player has been defeated
      cout<<"You have defeated the gang member"<<endl<<"Would you like to keep going? (y/n)";
      cin>>Answer;
      OP++;
      if(Answer=="n"){
        active="False";
      }
      else{
        turns=0,EHealth=5;
      }
    }
      }
      if(turns>=5){    //sets a timer so the player does not stall out the fight
        cout<<"The leader decided you took to long to beat a simple gang member, you were rejected"<<endl;
        active="False";
    }
  else if(PHealth<=0){    //makes the player lose
    cout<<"You were defeated by the gang member and were rejected"<<endl;
    active="False";
    }
  }
  if(active=="False"){    //ends the game
    cout<<"You ran away from the gang ashamed at your failed attempt"<<endl;
  }
  }