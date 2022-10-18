/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 5, 2022
 * Purpose: Luhn Algorithm 3
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
void genCC(CrdCard,int[],int,int);
bool validCC(int [],int);
void transpose (int [],int,int);
void changeDig(int [],int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    float tValid=0;
    float tInvalid=0;
    float fValid=0;
    float fInvalid=0;
    
    //Explain the Program
    cout<<"The purpose of this program is to validate credit card numbers."<<endl;
    cout<<"The program will choose between American Express, Visa, MasterCard, and Discover."<<endl;
    cout<<"It will generate a valid credit card number for the chosen brand."<<endl;
    cout<<"It will then transpose two random digits and flip two random digits."<<endl;
    cout<<"The validity will be checked after the digits are changed."<<endl;
    cout<<"The program will repeat this process 10,000 times and report the results"<<endl;
    
    //Start the Loop
    for (int j=0;j<10000;j++){
    //Determine the CC Brand
    int size;
    int x=(rand()%5+1);
    
    while (x==5)x=(rand()%4+1);
    if(x==1){
        size=15;
    }
    else{
        size=16;
    }
    
    //Declare Credit Card Array
    int card[size];
    
    //American Express Generator
    if (x==1){
        genCC(American_Express,card,size,x);
        //Validate Initial Card Number
        while(validCC(card,size)==false){
            genCC(American_Express,card,size,x);
        }
        
        //Begin Digit Transposition and Validation
        transpose(card,size,x);
        if (validCC(card,size)==true){
            tValid+=1;
        }
        else{
            tInvalid+=1;
        }
        
        //Begin Digit Flipping and Validation
        changeDig(card,size,x);
        if (validCC(card,size)==true){
            fValid+=1;
        }
        else{
            fInvalid+=1;
        }
    }
    
    //Visa Generator
    else if (x==2){
        genCC(Visa,card,size,x);
        //Validate Initial Card Number
        while(validCC(card,size)==false){
            genCC(Visa,card,size,x);
        }
        
        //Begin Digit Transposition and Validation
        transpose(card,size,x);
        if (validCC(card,size)==true){
            tValid+=1;
        }
        else{
            tInvalid+=1;
        }
        
        //Begin Digit Flipping and Validation
        changeDig(card,size,x);
        if (validCC(card,size)==true){
            fValid+=1;
        }
        else{
            fInvalid+=1;
        }
        
    }
    
    //MasterCard Generator
    else if (x==3){
        genCC(MasterCard,card,size,x);
        //Validate Initial Card Number
        while(validCC(card,size)==false){
            genCC(MasterCard,card,size,x);
        }
        
        //Begin Digit Transposition and Validation
        transpose(card,size,x);
        if (validCC(card,size)==true){
            tValid+=1;
        }
        else{
            tInvalid+=1;
        }
        
        //Begin Digit Flipping and Validation
        changeDig(card,size,x);
        if (validCC(card,size)==true){
            fValid+=1;
        }
        else{
            fInvalid+=1;
        }
        
    }
    
    else if (x==4){
        genCC(Discover,card,size,x);
        //Validate Initial Card Number
        while(validCC(card,size)==false){
            genCC(Discover,card,size,x);
        }
        
        //Begin Digit Transposition and Validation
        transpose(card,size,x);
        if (validCC(card,size)==true){
            tValid+=1;
        }
        else{
            tInvalid+=1;
        }
        
        //Begin Digit Flipping and Validation
        changeDig(card,size,x);
        if (validCC(card,size)==true){
            fValid+=1;
        }
        else{
            fInvalid+=1;
        }
    }
    }
    
    //Final Results
    cout<<endl<<"After 10,000 loops, the final results for transposing are:"<<endl;
    cout<<"Valid Credit Card Numbers:   "<<tValid<<" ("
        <<fixed<<setprecision(2)<<(tValid/10000)*100<<"%)"<<endl;
    cout<<fixed<<setprecision(0)
        <<"Invalid Credit Card Numbers: "<<tInvalid<<" ("
        <<fixed<<setprecision(2)<<(tInvalid/10000)*100<<"%)"<<endl;
    cout<<fixed<<setprecision(0);
    cout<<endl<<"After 10,000 loops, the final results for flipping are:"<<endl;
    cout<<"Valid Credit Card Numbers:   "<<fValid<<" ("
        <<fixed<<setprecision(2)<<(fValid/10000)*100<<"%)"<<endl;
    cout<<fixed<<setprecision(0)
        <<"Invalid Credit Card Numbers: "<<fInvalid<<" ("
        <<fixed<<setprecision(2)<<(fInvalid/10000)*100<<"%)"<<endl;
    //Exit stage right
        return 0;
}

//Functions
void genCC(CrdCard,int card[],int size, int x){
    //American Express Generator
    if (x==1){
        //Generate First two set digits
        card[0]=3;
        int temp=(rand()%2+1);
        if (temp==1)card[1]=4;
        else card[1]=7;
        //Generate remaining digits
        for (int i=2;i<size;i++){
            card[i]=(rand()%10);   //Assigns random value for CC digit
        }
    }
    //Visa
    else if (x==2){
        //Generate First set digit
        card[0]=4;
        //Generate remaining digits
        for (int i=1;i<size;i++){
            card[i]=(rand()%10);   //Assigns random value for CC digit
        }
    }
    
    //MasterCard
    else if (x==3){
        //Generate First set digit
        card[0]=5;
        //Generate remaining digits
        for (int i=1;i<size;i++){
            card[i]=(rand()%10);   //Assigns random value for CC digit
        }
    }
    
    //Discover
    else if (x==4){
        //Generate First four set digit
        card[0]=6;
        card[1]=0;
        card[2]=1;
        card[3]=1;
        //Generate remaining digits
        for (int i=4;i<size;i++){
            card[i]=(rand()%10);   //Assigns random value for CC digit
        }
    }
}

void transpose (int card[],int size,int x){
    int temp;
    if (x==1){
        //Transpose Digits
        int i=rand()%(size-2)+2;
        int j=rand()%(size-2)+2;
        while (j==i)j=rand()%(size-2)+2;
        
        temp=card[i];
        card[i]=card[j];
        card[j]=temp;
    }
    
    else if (x==2){
        //Transpose Digits
        int i=rand()%(size-1)+1;
        int j=rand()%(size-1)+1;
        while (j==i)j=rand()%(size-1)+1;
        
        temp=card[i];
        card[i]=card[j];
        card[j]=temp;
    }
    
    else if (x==3){
        //Transpose Digits
        int i=rand()%(size-1)+1;
        int j=rand()%(size-1)+1;
        while (j==i)j=rand()%(size-1)+1;
        
        temp=card[i];
        card[i]=card[j];
        card[j]=temp;
    }
    
    else if (x==4){
        //Transpose Digits
        int i=rand()%(size-4)+4;
        int j=rand()%(size-4)+4;
        while (j==i)j=rand()%(size-4)+4;
        
        temp=card[i];
        card[i]=card[j];
        card[j]=temp;
    }
}

void changeDig(int card[],int size,int x){
    int temp;
    if (x==1){
        //Transpose Digits
        int i=rand()%(size-2)+2;
        int j=rand()%(size-2)+2;
        while (j==i)j=rand()%(size-2)+2;
        
        temp=card[i];
        card[i]=card[j];
        card[j]=temp;
        
        //Flip Digits
        i=rand()%(size-2)+2;
        j=rand()%(size-2)+2;
        
        card[i]=(rand()%10);
        card[j]=(rand()%10);
    }
    
    else if (x==2){
        //Transpose Digits
        int i=rand()%(size-1)+1;
        int j=rand()%(size-1)+1;
        while (j==i)j=rand()%(size-1)+1;
        
        temp=card[i];
        card[i]=card[j];
        card[j]=temp;
        
        //Flip Digits
        i=rand()%(size-1)+1;
        j=rand()%(size-1)+1;
        
        card[i]=(rand()%10);
        card[j]=(rand()%10);
    }
    
    else if (x==3){
        //Transpose Digits
        int i=rand()%(size-1)+1;
        int j=rand()%(size-1)+1;
        while (j==i)j=rand()%(size-1)+1;
        
        temp=card[i];
        card[i]=card[j];
        card[j]=temp;
        
        //Flip Digits
        i=rand()%(size-1)+1;
        j=rand()%(size-1)+1;
        
        card[i]=(rand()%10);
        card[j]=(rand()%10);
    }
    
    else if (x==4){
        //Transpose Digits
        int i=rand()%(size-4)+4;
        int j=rand()%(size-4)+4;
        while (j==i)j=rand()%(size-4)+4;
        
        temp=card[i];
        card[i]=card[j];
        card[j]=temp;
        
        //Flip Digits
        i=rand()%(size-4)+4;
        j=rand()%(size-4)+4;
        
        card[i]=(rand()%10);
        card[j]=(rand()%10);
    }
}

bool validCC(int card[],int size){
    //Copy the CC Number
    int copy[size];
    for (int i=0;i<size;i++){
        copy[i]=card[i];
    }
    //Perform Luhn Algorithm
    int sum=0;
    
    if(size==15){
        for (int i=0;i<size;i++){
        if (i%2==1){           //Doubles every other digit
            copy[i]*=2;
            if (copy[i]>9){    //If doubled digit is over 10, adds digits
                copy[i]=(copy[i]/10)+(copy[i]%10);
            }
        }
        sum+=copy[i];          //Adds new digit to sum
        }
    }
    else{
        for (int i=0;i<size;i++){
        if (i%2==0){           //Doubles every other digit
            copy[i]*=2;
            if (copy[i]>9){    //If doubled digit is over 10, adds digits
                copy[i]=(copy[i]/10)+(copy[i]%10);
            }
        }
        sum+=copy[i];          //Adds new digit to sum
        }
    }
    
    if (sum%10==0)return true;
    else return false;
}

