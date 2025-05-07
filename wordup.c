//Trent Foster
//Final Project
//5.6.25

#include <stdio.h>
#include <stdbool.h>
#define WORD "mystery.txt"
#define SIZE 10 

int fileStuff(char array[]);
int guessLength(char str[]);
void lengthCheck(char array[][SIZE], int i);
void getGuess(char array[][SIZE], int n);
void convUp(char *str);
void convDn(char *str);
void sameSpots(char array1[],char array2[][SIZE], int n);
void barrier();
int checkWin(char array1[], char array2[][SIZE], int n);

int main(){
 char secret[SIZE];
 char guesses[5][SIZE]; 
 int guessNum=0;
//getting the secret word
 fileStuff(secret);
//The good stuff
printf("Welcome to wordup! \nYou have 5 guesses.\n");
//The loop
while(guessNum<5){
 //storing the guess
 getGuess(guesses, guessNum);
 //checking correct length
 lengthCheck(guesses, guessNum);
 sameSpots(secret, guesses, guessNum);
 //printing previous guesses
  for(int i=0; i<5; i++){
  printf("%s\n", guesses[i]);
 }
 barrier();
 checkWin(secret, guesses, guessNum);
guessNum++;

}

return 0; 
}

//FILEIO stuff
int fileStuff(char array[]){
 FILE* fp = fopen(WORD, "r");
 if(fp == NULL){
  printf("Cannot access the secret word :( \n");
  return 0; 
 }
 fscanf(fp, "%s", array); 
 fclose(fp);
return 1; 
}

void getGuess(char array[][SIZE], int n){
 //prompting and storing guess
 printf("Guess %d: ", (n+1));
 scanf("%s",array[n]);
 //converting to lowercase
  convDn(array[n]);
  barrier();
}

//User guesses
int guessLength(char str[]){
 int l=0;
  while(str[l] != '\0'){
   l++;
  }
return l;
}

//Checking for appropriate length  
void lengthCheck(char array[][SIZE], int i){
 int wrdLength=0;
  wrdLength  = guessLength(array[i]);
  while (guessLength(array[i]) !=5){
   printf("Guess must contain 5 letters, try again\n");
   getGuess(array, i);
   barrier();
  }
}

//converts string to all uppercase 
void convUp(char *str){
 while (*str){
  if (*str >= 'a' && *str <= 'z'){
   *str = *str - ('a' - 'A');
  }
  str++;
 }
}

//converts string to all lowercase
void convDn(char *str){
 while (*str){
  if (*str >= 'A' && *str <= 'Z'){
   *str = *str + ('a' - 'A');
  }
  str++;
 }
}

//checking for same spots
void sameSpots(char array1[],char array2[][SIZE], int n){
 for(int i=0; i<5; i++){
  if(array1[i] == array2[n][i]){
   array2[n][i] = array2[n][i] - ('a' - 'A');
  }
 }
}

//checking for same letters
void sameLett(char array1[], char array2[][SIZE]){
 int i; 
  
}

//creating barrier
void barrier(){
for(int j=0; j<15; j++){
  printf("=");
 }
 printf("\n");
}

int checkWin(char array1[], char array2[][SIZE], int n){
 bool match = true;
  for (int i=0; i<5; i++){
   if (array1[i] != array2[n][i]){
    match = false;
   } else if (match){
  printf("Congrats! You guessed the word! \n");
  return 0; 
   }
  }
}
