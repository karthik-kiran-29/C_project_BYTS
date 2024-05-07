#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12

void login_page();

char *generate_strong_password();

int main()
{
    char filename[] = "login.txt";

    FILE *fptr = fopen(filename, "r");  
    if (fptr != NULL) {
        login_page();
    }
    else{
        fptr = fopen(filename, "w");  
    if (fptr == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    
    const char *content = "already logged in";
    int bytes_written = fputs(content, fptr);
    if (bytes_written == EOF) {
        printf("Error writing to file!\n");
        fclose(fptr);
        // This method is used to find out new user and give them ability to create login password
        main();
        return 1;
}}}

char *generate_strong_password() {
  // Character sets for different password components
  char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
  char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char digits[] = "0123456789";
  char symbols[] = "!@#$%^&*()_+-=[]{};':\"\\|,.<>/?";

  // Allocate memory for the password
  char *password = malloc(PASSWORD_LENGTH + 1);
  if (password == NULL) {
    return NULL; // Handle memory allocation error
  }

  // Seed the random number generator (use time for better randomness)
  srand(time(NULL));

  // Ensure at least one character from each character set
  password[0] = lowercase_letters[rand() % strlen(lowercase_letters)];
  password[1] = uppercase_letters[rand() % strlen(uppercase_letters)];
  password[2] = digits[rand() % strlen(digits)];
  password[3] = symbols[rand() % strlen(symbols)];

  // Fill remaining characters with random selections from all sets
  for (int i = 4; i < PASSWORD_LENGTH; i++) {
    int random_set = rand() % 4;
    switch (random_set) {
      case 0:
        password[i] = lowercase_letters[rand() % strlen(lowercase_letters)];
        break;
      case 1:
        password[i] = uppercase_letters[rand() % strlen(uppercase_letters)];
        break;
      case 2:
        password[i] = digits[rand() % strlen(digits)];
        break;
      case 3:
        password[i] = symbols[rand() % strlen(symbols)];
        break;
    }
  }

  // Null terminate the string
  password[PASSWORD_LENGTH] = '\0';

  return password;
}


void login_page(){
    printf("**All the passwords will be deleted if 5 wrong attemps**\n \n");
/*    char admin[10];
    char pass[10];
    
    
    printf("Enter the Username::  (Default:admin)  ");
    scanf("%s ",admin);
    
    printf("Enter the passwords::  (Default:admin)  ");
    scanf("\n %s  ",pass);
    */
    if (1) {
    int choice;    
        printf("Menu:\n");
    printf("1. Display all password\n");
    printf("2. Store new password\n");
    printf("3. Change password\n");
    printf("4. Password health cheaker\n");
    printf("5. Generate new password\n");

    
    printf("Enter your choice: ");
    scanf("%d", &choice);

    
    switch (choice) {
        case 1:
            printf("You selected Option 1.\n");
            
            break;
        case 2:
            printf("You selected Option 2.\n");
            
            break;
        case 3:
            printf("You selected Option 3.\n");
            
            break;
        case 4:
            printf("You selected Option 4.\n");
            break;
        case 5:
            printf("You selected Option 5.\n");
            char *strong_password = generate_strong_password();

            if (strong_password != NULL) {
            printf("Generated strong password: %s\n", strong_password);
            free(strong_password); 
            } else {
            printf("Error generating password.\n");
            }
            break;    
        default:
            printf("Invalid choice. Please try again.\n");
    
    }}}            
