#include <iostream>
#include <math.h>

using namespace std;

int baseBtoDecimal(char);

//Second place functions
int baseBToDecimal(char input){

    if( input>='0' && input <= '9'){
         cout<<"\nbaseBToDecimal:"<<input - '0';
        return (input - '0');

        //More tan 9 for a base
    }
    else{
        input = tolower(input);
        return (int) (input - 'a') + 10;
    }
    // Example: input = 'b', so 'b' in ASCII is  98 (decimal), and 'a' is 97, so ('b'-'a') = 1 + 10 = 11

}



char decimalToBaseB(int input) {
    if (input >= 0 && input <= 9) {
        cout<<"\ndecimalToBaseB\n"<<('0'+input);
        //std::string str = std::string(input);

        return ('0'+input);

        //Example: If input= '10', then -> = 10;

    } else {

        return (char) ('a' + (input - 10));
        //Example: If input is above 9, then 'a'= 97 + (11-10 = 1) = 98 = 'b'
    }
}

int toDecimal(std::string input, int base) {
    int length = input.length();
    int decimal = 0;
    for (int placeValue = 0, index = length - 1; index >= 0; placeValue++, index--) {

        decimal = decimal + baseBToDecimal(input.at(index)) * (int) (pow(base, placeValue));
        std::cout<<"\ndecimal: "<<decimal;
    }
    return decimal;
}

std::string toBaseB(int input, int base) {
    std::string result = "";
    while (input > 0) {
        int remainder = input % base;
        input = input / base;

        cout<<"\n(toBaseB):\n"<<decimalToBaseB(remainder);
        cout<<"\n(result):\n"<<result;

        result = std::string(decimalToBaseB(remainder) + result);
    }
    return result;
}


int main()
{


    std::cout<<"Enter input base: ";
    int inputBase;
    std::cin>>inputBase;

    std::cout<<"Enter number in input base: ";
    std::string inputNumber;
    std::cin>>inputNumber;

    std::cout<<"Enter output base: ";
    int outputBase;
    std::cin>>outputBase;

    int decimal = toDecimal(inputNumber, inputBase);
    std::string output = toBaseB(decimal, outputBase);

    std::cout<<"Result = "<<output;

    char test = '0'+1;
    std::cout<<"test"<<test;
   // cout << "Hello World!" << endl;
    return 0;
}
