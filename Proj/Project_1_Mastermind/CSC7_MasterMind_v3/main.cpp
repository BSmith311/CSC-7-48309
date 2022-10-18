/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 15, 2022
 * Purpose: Project 1 Mastermind v3
 *          Set sequence and have AI able to finish game
 * Changes: Program now displays correct position and number
 *          Program now displays correct number but incorrect position
 *          Various bug fixes
 * 
 * To Implement:  1. (Project 2) Have AI use an algorithm to solve puzzle 
 *                   instead letting it know the sequence and guess randomly
 *                2. Overhaul and optimize the positions function since 
 *                   current positions function is a barely functional dumpster fire
 *                3. Add cleaner UI, general improvements (separate some functions for example, and fix bugs
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
void AI(int,int[],bool[],int[]);            //Function for AI's turn
bool eval(int, int[],int[],bool[]);   //Function to evaluate AI's guess
void positions(int[],int[],int);      //Function to calculate and output positions
void options(int&, bool&);            //Function to change options

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int pegs=8;         //Default pegs
    bool dupes=false;   //Default dupes
    int seq[pegs];      //Sequence array (move to start function)
    int guess[pegs];    //AI guess array (move to start function)
    bool check[pegs];   //Bool array to check each digit (move to start function)
    
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
                //Move all cout statements to respective functions for v4
                cout<<"Sequence to be Guessed:"<<endl;
                start(pegs,dupes,seq,check);
                //AI's turn
                    //The current "AI" is fully random, but in Project 2 
                    //the AI will be completely rewritten and use strategy to guess
                cout<<"Time for the AI to play:"<<endl;
                cout<<"Guess     Correct Position  Correct Number"<<endl;
                do{
                    AI(pegs,guess,check,seq);
                    
                    //Display the current game stats
                    positions(seq,guess,pegs);
                
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
    
    //Exit program
        return 0;
}

void start(int pegs,bool dupes,int seq[],bool check[]){
    //Without Dupes (make more efficient)
    if (!dupes){
        for (int i=0; i<pegs; i++){
            seq[i]=rand()%8+1;
        }
        
        for (int i=0; i<pegs; i++){     //Possibly make its own function
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

void AI(int pegs,int guess[],bool check[],int seq[]){
    for (int i=0; i<pegs; i++){
        if (!check[i]){
            guess[i]=rand()%8+1;
        }
        cout<<guess[i];
    }
}

bool eval(int pegs,int seq[],int guess[],bool check[]){
    for (int i=0; i<pegs; i++){
        if (seq[i] == guess[i]){
            check[i]=true;
        }else{      //Not needed?
            check[i]=false;
        }
    }
    for (int i=0; i<pegs; i++){
        if (seq[i]!=guess[i])return false;
        //Add else return true
    }
}

void positions (int seq[], int guess[], int size){
    //Note this entire function will be changed in Project 2 with the proper AI
    int cc=0;       //Correct number and position
    int cw=0;       //Correct number wrong position
    int tempS[size];//Temp seq array copy
    int tempG[size];//Temp guess array copy
    
    //Copy arrays
    for (int i=0; i<size; i++){
        tempS[i]=seq[i];
        tempG[i]=guess[i];
    }
    
    //Check correct positions and numbers
    for (int i=0; i<size; i++){
        if (tempG[i] == seq[i])cc++;
        
        for (int j=0; j<size; j++){
            if (tempG[i] == tempS[j]){
                cw++;
                tempS[j]=0;
                tempG[i]=-1;
            }
        }
    }
    cw-=cc;
    
    //Output results
    if (size == 4){
        cout<<setw(14)<<cc;
        cout<<setw(18)<<cw<<endl;
    }else if (size == 6){
        cout<<setw(12)<<cc;
        cout<<setw(16)<<cw<<endl;
    }else{
        cout<<setw(10)<<cc;
        cout<<setw(14)<<cw<<endl;
    }
}

void options (int &pegs,bool &dupes){
    char choice;
    do{
        cout<<endl<<"Please select one of the following game play options:"<<endl;
        cout<<"A. Change the Sequence Length:"<<endl;       //Add current option to output
        cout<<"B. Choose if duplicates are allowed."<<endl; //Add current option to output
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