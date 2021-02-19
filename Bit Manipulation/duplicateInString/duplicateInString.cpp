// Assumptions : (1) str contains only characters 
//                   from 'a' to 'z' 
//               (2) integers are stored using 32 
//                   bits 

#include <iostream>

using namespace std;

int main()
{ 
    char s[] = "finding";
    
    // An integer to store presence/absence 
    // of 26 characters using its 32 bits.
    int a = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        int val = s[i] - 'a';
        
        if (((1 << val) & a) > 0) {
            cout << s[i] << " is duplicate" << endl;
        } else {
            a = ((1 << val) | a);
        }
        
    }
    
    return 0;
    
}