#include <stdio.h>
#include <string.h>

//returns 1 if the characters in input are the same forwards and backwards (e.g. civic and deified).  Assume that the parameter input is a '\0' terminated string
int isPalindrome(char input[]);

int main(int argc, char* argv[]){
	int i;
	
	if(argc < 1){
		printf("Must have at least one command line argument present");
		return -1; // non-zero return value in main indicates error
	} else {
		for(i = 1; i < argc; i++){
			// TODO: print out if each argument is a palindrome
			if(isPalindrome(argv[i])){ // if the argument is a palindrome
				printf("Arg %d: %s IS a palindrome\n", i, argv[i]);
			}
			else {
				printf("Arg %d: %s IS NOT a palindrome\n", i, argv[i]);
			}
		}
	}
}

/* returns 1 if the characters in input are the same forwards and backwards */
int isPalindrome(char input[]){
	// create a character array to store the reverse of the input string
	int length;
	length = strlen(input);
	char reverseInput[length];
	strcpy(reverseInput, input); // copy input into reverseInput
	strrev(reverseInput); // now reverse the input 
	if(strcmp(input, reverseInput) == 0){
		return 1; // it is a palindrome
	} else {
		return 0;
	}
}