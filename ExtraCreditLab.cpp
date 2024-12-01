#include <iostream>
#include <cmath>
#include "string"
#include <iomanip>

using namespace std;

double  extractNumeric(string& input, bool& end){

    double number = 0.0;
    bool decimalFound = false;
    int decimalPlaces = 1;
    bool invalid = false;
    bool negative = false;

    for (int i = 0; i < input.length(); i++){
        if (input == "END"){
            end = true;
            i = input.length();
            break;
        }
        if (input[i] == '-'){
            negative = true;
        }
        else if (input[i] == '+'){
            negative = false;
        }
        else if (input[i] == '.'){
            decimalFound = true;
        }
        else if (isdigit(input[i])){
            if (decimalFound == false){
                number *= 10;
                number = number + double(input[i] - '0');
            }
            else{
                double num = double(input[i] - '0') / pow(10, decimalPlaces);
                decimalPlaces++;
                number += num;
            }
        }
        else{
            cout << "The input is invalid." << endl;
            i = input.length();
            invalid = true;
            return -999999.99;
        }
    }
    if (invalid == false && input != "END"){
        if (negative == true){
            return (number * -1);
        }
        else{
            return number;
        }
    }
}

int main(){
    bool end = false;

    while (end == false){
        string input;

        cout << "Enter a string (or END to quit): ";
        getline(cin, input);

        double extractedNum = extractNumeric(input, end);

        if (extractedNum != -999999.99){
            cout << "The input is: " <<  setprecision(4) << fixed << extractedNum << endl;
        }
        
    }
}