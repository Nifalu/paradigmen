#include <iostream>
#include <string>

// reverses the given String by iterating over it from right to left
// and appending every character to sf.
std::string reverse(std::string s) {
    std::string sf;
    for (int i = s.length()-1; i >= 0; i--) {
        sf.append(1, s[i]);
    }
    return sf;
}

// input strings are given via command line arguments.
int main(int argc, char* argv[]) {

    // Parse arguments
    std::string sa = argv[1]; 
    std::string sb = argv[2];
    std::string sc;
    std::string sr;


    // Check if two strings were passed. Return if not.
    if (argc != 3) {
        std::cout << "Please provide two params";
        return 0;
    }

    // for every char in String a, iterate through string b and check if char exists.
    for (int i = 0; i < sa.length(); i++) {
            
        // if char i from string a is not found in b , add it to sc.
        if (!(sb.find(sa[i]) != std::string::npos)) {
            sc.append(1, sa[i]);
        }
    }
    // Vice versa
    for (int i = 0; i < sb.length(); i++) {
        if (!(sa.find(sb[i]) != std::string::npos)) {
            sr.append(1, sb[i]);
        }
    }
    
    // print result
    std::cout << "String a: " << sa << "\n";
    std::cout << "String b: " << sb << "\n";

    std::cout << "a - b = " << sc << "\n"; // Aufgabe a
    std::cout << "b - a = " << sr << "\n"; // Aufgabe b

    sr = reverse(sc);
    std::cout << sc << " reversed: " << sr << "\n"; // Aufgabe c

    return 0; // Tell OS that program finished successfully.
}