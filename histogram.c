#include <stdio.h>

#define LOWER 26 /* number of lowercase letters for array */

int toLower(int input); // converts an upper case letter to a lower case letter

int main(){
	
	int c; // holds each character
	int characterFreq[LOWER] = {0}; // frequency array 
	int i; // loop variable
	
	while ((c = getchar()) != EOF){
		toLower(c);
		// if c is a lowercase letter, update its count in characterFreq 
		if(c >= 'a' && c <= 'z'){
			characterFreq[c - 'a']++;
		}
	}
	// display the results as a histogram
	int j;
	for(i=0; i < LOWER; i++){
		printf("%c: ", 'a' + i);
		for(j=0; j < characterFreq[i]; j++){
			printf("*");
		}
		printf("|\n");
	}
}

// converts an upper case letter to a lower case letter
int toLower(int input){
	if(input >= 'A' && input <= 'Z'){
		return input + 32;
	}
}