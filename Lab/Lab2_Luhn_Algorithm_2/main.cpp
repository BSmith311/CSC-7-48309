/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 17, 2022
 * Purpose: Luhn Algorithm 2
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//User Libraries

//Enumerator
enum CrdCard{American_Express=1, Visa=2, MasterCard=3, Discover=4, ALL=5};

//Function Prototypes
void genCC(CrdCard,int[],int);
bool validCC(int [],int);
void flipDig(int [],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Determine the CC Brand
    int size;
    int x=(rand()%5+1);
    
    if(x==1){
        size=15;
    }
    else if (x==6)
    {
        size=rand()%2+15;
        cout<<size<<endl;
    }
    else{
        size=16;
    }
    
    //Declare Variables
    int card[size];
    int valid=0;
    int invalid=0;
    
    //Explain the Program
    cout<<"The purpose of this program is to validate credit card numbers."<<endl;
    cout<<"The program will repeat this process 10,000 times and report the results"<<endl<<endl;
    
    //Call the Function to Create a Valid Credit Card
    if (x==1){
        genCC(American_Express,card,size);
        //Validate Initial Card Number
        if (validCC(card,size)==false){
            genCC(American_Express,card,size);
        }
        
        cout<<"The initial card is American Express: ";
        for (int i=0;i<size;i++){   //Outputs CC digits
            cout<<card[i];
        }
        cout<<endl; 
        
        //Begin Digit Flipping and Validation
        cout<<endl<<"The program will now flip one digit at a time and test the validity."
        <<endl<<"The result will be recorded and repeated 10,000 times."<<endl;
        for (int j=0;j<10000;j++){
            flipDig(card,size);
            if (validCC(card,size)==true){
                valid+=1;
            }
            else{
                invalid+=1;
            }
        }
    }
    
    else if (x==2){
        genCC(Visa,card,size);
        //Validate Initial Card Number
        if (validCC(card,size)==false){
            genCC(Visa,card,size);
        }
        
        cout<<"The initial card is Visa: ";
        for (int i=0;i<size;i++){   //Outputs CC digits
            cout<<card[i]; 
        }
        cout<<endl; 
        
        //Begin Digit Flipping and Validation
        cout<<endl<<"The program will now flip one digit at a time and test the validity."
        <<endl<<"The result will be recorded and repeated 10,000 times."<<endl;
        for (int j=0;j<10000;j++){
            flipDig(card,size);
            if (validCC(card,size)==true){
                valid+=1;
            }
            else{
                invalid+=1;
            }
        }
    }
    
    else if (x==3){
        genCC(MasterCard,card,size);
        //Validate Initial Card Number
        if (validCC(card,size)==false){
            genCC(MasterCard,card,size);
        }
        
        cout<<"The initial card is MasterCard: ";
        for (int i=0;i<size;i++){   //Outputs CC digits
            cout<<card[i];
        }
        cout<<endl; 
        
        //Begin Digit Flipping and Validation
        cout<<endl<<"The program will now flip one digit at a time and test the validity."
        <<endl<<"The result will be recorded and repeated 10,000 times."<<endl;
        for (int j=0;j<10000;j++){
            flipDig(card,size);
            if (validCC(card,size)==true){
                valid+=1;
            }
            else{
                invalid+=1;
            }
        }
    }
    
    else if (x==4){
        genCC(Discover,card,size);
        //Validate Initial Card Number
        if (validCC(card,size)==false){
            genCC(Discover,card,size);
        }
        
        cout<<"The initial card is Discover: ";
        for (int i=0;i<size;i++){   //Outputs CC digits
            cout<<card[i];
        }
        cout<<endl; 
        
        //Begin Digit Flipping and Validation
        cout<<endl<<"The program will now flip one digit at a time and test the validity."
        <<endl<<"The result will be recorded and repeated 10,000 times."<<endl;
        for (int j=0;j<10000;j++){
            flipDig(card,size);
            if (validCC(card,size)==true){
                valid+=1;
            }
            else{
                invalid+=1;
            }
        }
    }
    
    else{
        genCC(ALL,card,size);
        //Validate Initial Card Number
        if (validCC(card,size)==false){
            genCC(ALL,card,size);
        }
        
        cout<<"The initial card is Unknown: ";
        for (int i=0;i<size;i++){   //Outputs CC digits
            cout<<card[i];
        }
        cout<<endl; 
        
        //Begin Digit Flipping and Validation
        cout<<endl<<"The program will now flip one digit at a time and test the validity."
        <<endl<<"The result will be recorded and repeated 10,000 times."<<endl;
        for (int j=0;j<10000;j++){
            flipDig(card,size);
            if (validCC(card,size)==true){
                valid+=1;
            }
            else{
                invalid+=1;
            }
        }
    }
    
    //Final Results
    cout<<endl<<"After 10,000 loops, the final results are:"<<endl;
    cout<<"Valid Credit Card Numbers:   "<<valid<<endl;
    cout<<"Invalid Credit Card Numbers: "<<invalid<<endl;
    //Exit stage right
        return 0;
}

//Functions
void genCC(CrdCard,int card[],int size){
    for (int i=0;i<size;i++){
        card[i]=(rand()%10);   //Assigns random value for CC digit
    }
}

bool validCC(int card[],int size){
    int sum=0;
    for (int i=0;i<size;i++){
        if (i%2==1){           //Doubles every other digit
            card[i]*=2;
            if (card[i]>9){    //If doubled digit is over 10, adds digits
                card[i]=(card[i]/10)+(card[i]%10);
            }
        }
        sum+=card[i];          //Adds new digit to sum
    }
    
    if (sum%10!=0){
        return false;
    }
    else{
        return true;
    }
}

void flipDig(int card[],int size){
    int i=rand()%size;
    if (card[i]<9){
        card[i]+=1;
    }
    else{
        card[i]=0;
    }
}