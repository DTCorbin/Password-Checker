#include <iostream>
#include <string>
#include <cstring>
#include <regex>
#include <math.h>

int evaluate(std::string password) {
    int total = 0;
    int range = 0;
    if (std::regex_search(password, std::regex("[a-z]"))) total += 1;       
    if (std::regex_search(password, std::regex("[A-Z]"))) total += 2;       
    if (std::regex_search(password, std::regex("[0-9]"))) total +=4;        
    if (std::regex_search(password, std::regex("[!\"#\$%&\'\(\)\*\+,-\./:;<=>\?@\[\\\]\^_`{\|}~]"))) total +=8;
    switch (total){
        case 1:
            range = 26;
            break;
        case 2:
            range = 26;
            break;
        case 3:
            range = 52;
            break;
        case 4:
            range = 10;
            break;
        case 5:
            range = 36;
            break;
        case 6:
            range = 36;
            break;
        case 7:
            range = 62;
            break;
        case 8:
            range = 14;
            break;
        case 9:
            range = 40;
            break;
        case 10:
            range = 40;
            break;
        case 11:
            range = 66;
            break;
        case 12:
            range = 24;
            break;
        case 13:
            range = 50;
            break;
        case 14:
            range = 50;
            break;
        case 15:
            range = 76;
            break;
    }
    return range;
}

double calcEntropy (int range, int length) {
    double entropy = length * (log2(range));
    return entropy;
}


int main (void) {
    std::string test;
    std::cout << "Please enter a password to evaluate: ";
    std::cin >> test;
    int result = evaluate(test);
    double strength = calcEntropy(result, test.length());
    if (strength < 60) {
        std::cout << "This password is \x1b[31mtoo weak\x1b[0m!";
    } else if (strength < 75){
        std::cout << "Password strength is \x1b[33maverage\x1b[0m.";
    } else {
        std::cout << "Password strength is \x1b[32mstrong\x1b[0m.";
    }
    return 0;
}