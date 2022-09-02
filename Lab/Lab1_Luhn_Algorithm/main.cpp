/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on August 30, 2022
 * Purpose: Luhn Algorithm
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes
void genCC(const int,int[]);        //Generates credit card number randomly
void outCC(const int,int[]);        //Outputs credit card number
void luhnA(const int, int[],int&);  //Performs the Luhn Algorithm
void valid(int);                    //Checks the validity and outputs results
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=16;      //Size of credit card
    int cCard[SIZE];        //Credit card number array
    int sum=0;              //Sum of digits
    
    //Credit Card Information
    genCC(SIZE,cCard);          //Calls CC Generator function
    cout<<"Testing the validity of credit card number:"<<endl;
    outCC(SIZE,cCard);          //Calls CC output function
    cout<<endl;
    
    //Luhn Algorithm
    luhnA(SIZE,cCard,sum);      //Calls the Luhn Algorithm function
    cout<<"Double every other digit starting from the last digit. "<<endl
        <<"If the product is more than 9, add the two digits together."<<endl;
    outCC(SIZE,cCard);          //Calls CC output function
    cout<<"The sum of the digits is "<<sum<<endl;
    
    //Final Results
    valid(sum);                 //Calls the validity output function
    
    //Exit stage right
        return 0;
}

//Functions
void genCC(const int SIZE,int cCard[]){    //Generates random CC number
    for (int i=0;i<SIZE;i++){
        cCard[i]=(rand()%10);   //Assigns random value for CC digit
    }
}

void outCC(const int SIZE,int cCard[]){    //Outputs the CC number
    
    for (int i=0;i<SIZE;i++){
        cout<<cCard[i];         //Outputs CC digit
    }
    cout<<endl;
}

void luhnA(const int SIZE,int cCard[],int& sum){    //Doubles (and adds) every other digit
    for (int i=0;i<SIZE;i++){
        if (i%2==1){            //Doubles every other digit
            cCard[i]*=2;
            if (cCard[i]>9){    //If doubled digit is over 10, adds digits
                cCard[i]=(cCard[i]/10)+(cCard[i]%10);
            }
        }
        sum+=cCard[i];          //Adds new digit to sum
    }
}

void valid(int sum){
    cout<<endl;
    if (sum%10==0){
        cout<<"The credit card number is valid."<<endl;
    }
    else{
        cout<<"The credit card number is not valid"<<endl;
    }
}