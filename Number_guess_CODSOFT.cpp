#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int main(){
    srand(time(nullptr));
    int randomNumber = rand()%100 + 1;
    int userguess;
    int numguesses = 0;
    cout << " lets play a number guessing game !!" <<endl;
    do {
        cout <<  "enter your number ( between 1-100): ";
        cin>> userguess;
        numguesses++;
        if(userguess > randomNumber){
            cout << " too high! try again" << endl;
        }else if(userguess < randomNumber){
            cout<<"too low !, try again." <<endl;
        }else{
            cout<< "congratulations !! you guessed the right number " << randomNumber <<" in "<< numguesses << " guesses" <<endl;
        }
    }while(userguess!= randomNumber);
    return 0;
}