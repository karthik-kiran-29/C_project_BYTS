
#include <stdio.h>
void login_page();

int main()
{
    char filename[] = "login.txt";

    FILE *fptr = fopen(filename, "r");  // Open for reading to check existence
    if (fptr != NULL) {
        login_page();
    }
    else{
        fptr = fopen(filename, "w");  // "w" mode creates a new file for writing
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

void login_page(){
    printf("**All the passwords will be deleted if 5 wrong attemps**\n \n");
    char admin[10];
    char pass[10];
    
    
    printf("Enter the Username::  (Default:admin)  ");
    scanf("%s \n",admin);
    
    printf("Enter the passwords::  (Default:admin)  ");
    scanf("%s \n",pass);
    
}
    
    
    
    
