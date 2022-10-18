/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 7, 2022
 * Purpose: Project 1 Mastermind v1
 *          Set sequence and have AI able to finish game
 * Future:  Implement modifications
 *          Have AI use algorithm to check (Project 2)
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

//Function Prototypes
void start(int, bool,int[],bool[]);   //
void AI(int,int[],bool[]);
bool eval(int, int[],int[],bool[]);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int pegs=4;
    bool dupes=false;
    
    int seq[pegs];
    int guess[pegs];
    bool check[pegs];
    
    //Initialize Variables
    
    //Set up the game
    cout<<"Sequence to be Guessed:"<<endl;
    start(pegs,dupes,seq,check);
    cout<<endl;
    //AI's turn
    cout<<"Time for the AI to play:"<<endl;
    do{
        AI(pegs,guess,check);
        cout<<endl;
    }while(eval(pegs,seq,guess,check)==false);
    
    //Exit stage right
        return 0;
}

void start(int pegs,bool dupes,int seq[],bool check[]){
    for (int i=0; i<pegs; i++){
        seq[i]=rand()%8;
        cout<<seq[i];
        check[i]=false;
    }
}

void AI(int pegs,int guess[],bool check[]){
    for (int i=0; i<pegs; i++){
        if (check[i]==false){
            guess[i]=rand()%8;
        }
        cout<<guess[i];
    }
}

bool eval(int pegs,int seq[],int guess[],bool check[]){
    for (int i=0; i<pegs; i++){
        if (seq[i]==guess[i]){
            check[i]=true;
        }
        else{
            check[i]=false;
        }
    }
    for (int i=0; i<pegs; i++){
        if (seq[i]!=guess[i])return false;
    }
}