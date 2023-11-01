#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

char * convert(char * s, int numRows){
    int wordLength = strlen(s);
    char **buff = (char**)malloc(numRows * sizeof(char*));  // Allocate memory
    
    // Allocate memory and initialize each elements in the array
    for(int i=0; i<numRows; i++){
        buff[i] = (char*)malloc(wordLength * sizeof(char));
        memset(buff[i], 0, wordLength);
    }
    // char buff[numRows][numRows * 2 - 1];

    int row = 0;
    int col = 0;
    int down = 1;

    for(int i=0; i<wordLength; i++){
        buff[row][col] = s[i];
        
        // First row, down
        if(row == 0)
            down = 1;
        // Row reach the desired number of Rows, reverse direction
        else if(row == numRows -1)
            down = -1;
            
        row += down;
        col += (down == 1) ? 0 : 1;
    }

    // Copy array to the result
    char *result = (char*)malloc((wordLength + 1) * sizeof(char));
    int idx = 0;
    for(int i=0; i<numRows; i++){
        for(int j=0; j<wordLength; j++){
            if(buff[i][j] != 0){
                result[idx++] = buff[i][j];
            }
        }
    }
    result[wordLength] = ' ';
    return result;
}

int main(){
    char _input[] = "PAYPALISHIRING";
    int wordLength = sizeof(_input) / sizeof(_input[0]);
    int numRows = 3;

    char * result = convert(_input, numRows);
    for(int i=0; i<wordLength; i++){
        printf("%c", result[i]);
    }

    return 0;
}