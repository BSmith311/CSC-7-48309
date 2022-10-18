/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 15, 2022
 * Purpose: Project 1 Mastermind v2
 *          Set sequence and have AI able to finish game
 * Changes: Program now features modifications
 * 
 * To Implement:  (Project 2) Have AI use an algorithm to solve puzzle 
 *                instead letting it know the sequence and guessing randomly
 *                Fix AI, 6 and 8 pegs breaks it
 *                Display how many correct guess and correct position
 *                Display how many correct guess but wrong position
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

//Function Prototypes
void start(int, bool,int[],bool[]);   //Function for game setup
void AI(int,int[],bool[]);            //Function for AI's turn
bool eval(int, int[],int[],bool[]);   //Function to evaluate AI's guess
void options(int&, bool&);            //Function to change options

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int pegs=4;         //Default pegs
    bool dupes=false;   //Default dupes
    int seq[pegs];      //Sequence array
    int guess[pegs];    //AI guess array
    bool check[pegs];   //Bool array to check each digit
    
    //Game Menu
    char choice;
    cout<<"Be sure to use capital letters for the input.";  //Automatically capitalize input for user?
    do{
        cout<<endl<<"Please select one of the following options:"<<endl;
        cout<<"A. Begin the game."<<endl;
        cout<<"B. Open the game options."<<endl;
        cout<<"C. Placeholder"<<endl;
        cout<<"D. Quit program."<<endl;
        cin>>choice;
        switch(choice){
            case 'A':
                //Set up the game
                cout<<"Sequence to be Guessed:"<<endl;
                start(pegs,dupes,seq,check);
                
                //AI's turn
                    //The current "AI" is full of bugs, but in Project 2 
                    //the AI will be completely rewritten 
                    //will patch most bugs in v3
                cout<<"Time for the AI to play:"<<endl;
                do{
                    AI(pegs,guess,check);
                    cout<<endl;
                }while(eval(pegs,seq,guess,check)==false);
                break;
            
            case 'B':
                options(pegs,dupes);
                break;
            
            case 'C':
                cout<<"This is a placeholder (maybe display stats?)"<<endl;
                break;
            
            default:
                cout<<"Quitting Program."<<endl;
                break;
        }
    }while (choice == 'A' || choice == 'B' || choice == 'C');
    
    //Exit stage right
        return 0;
}

void start(int pegs,bool dupes,int seq[],bool check[]){
    //Without Dupes
    if (!dupes){
        for (int i=0; i<pegs; i++){
            seq[i]=rand()%8+1;
        }
        
        for (int i=0; i<pegs; i++){
            for (int j=0; j<pegs; j++){
                if (seq[i] == seq[j] && j != i){
                    seq[i]=rand()%8+1;
                    j=0;
                    i=0;
                }
            }
        }
    }
    
    //With Dupes
    else{
        for (int i=0; i<pegs; i++){
            seq[i]=rand()%8+1;
        }
    }
    
    //Display Sequence
    for (int i=0; i<pegs; i++){
        cout<<seq[i];
        
        //Temporary line to set the AI's check to false by default
        //Will remove when implementing a full AI
        check[i]=false;
    }
    
    cout<<endl;
}

void AI(int pegs,int guess[],bool check[]){
    for (int i=0; i<pegs; i++){
        if (check[i]==false){
            guess[i]=rand()%8+1;
        }
        cout<<guess[i];
    }
}

bool eval(int pegs,int seq[],int guess[],bool check[]){
    for (int i=0; i<pegs; i++){
        if (seq[i]==guess[i]){
            check[i]=true;
        }else{
            check[i]=false;
        }
    }
    for (int i=0; i<pegs; i++){
        if (seq[i]!=guess[i])return false;
    }
}

void options (int &pegs,bool &dupes){
    char choice;
    do{
        cout<<endl<<"Please select one of the following game play options:"<<endl;
        cout<<"A. Change the Sequence Length:"<<endl;
        cout<<"B. Choose if duplicates are allowed."<<endl;
        cout<<"C. Exit Options."<<endl;
        cin>>choice;
        switch(choice){
            case 'A':
                //Get new length and validate input
                cout<<"The current length is "<<pegs<<"."<<endl;
                cout<<"Enter the new desired length (Options are 4, 6, or 8)."<<endl;
                cin>>pegs;
                while (pegs != 4 && pegs != 6 && pegs != 8){
                    cout<<"Invalid length, please select 4, 6, or 8."<<endl;
                    cin>>pegs;
                }
                cout<<"The new length is "<<pegs<<"."<<endl;
                break;
            
            case 'B':
                //Swap dupes bool and output new rule
                if (dupes){
                    dupes=false;
                    cout<<"Duplicates are no longer allowed."<<endl;
                }else{
                    dupes=true;
                    cout<<"Duplicates are now allowed."<<endl;
                }
                break;
            
            default:
                cout<<"Exiting options."<<endl;
                break;
        }
    }while (choice == 'A' || choice == 'B');
}