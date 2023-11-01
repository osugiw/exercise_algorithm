#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Return if the number of rows <= 1
        if(numRows <= 1){
            return s;
        }

        int row = 0;
        bool down = true;
        string buffer[numRows];
        
        // Initialize the string array with zero
        for(int i=0; i<numRows; i++)
            buffer[i] = "";
        
        // Traverse the string
        for(int idx=0; idx<s.size(); idx++){
            buffer[row] += s[idx];
            
            // Continue the down direction
            if(row == 0)
                down = true;
            // Reverse the down direction
            else if(row == numRows - 1)
                down = false;

            // Increment the row if down, else decrement
            row += down ? 1 : -1; 
        }
        
        string result = "";
        for(int idx=0; idx<numRows; idx++){
            result += buffer[idx];
        }
        return result;
    }
};

int main() {
    Solution solution;
    string _input = "PAYPALISHIRING";
    cout << solution.convert(_input, 3) << endl;
    return 0;
}