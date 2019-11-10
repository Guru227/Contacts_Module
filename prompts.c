//prompts.c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include"prompts_headers.h"

void make_call_prompt()
{
    char name[25];
    _Bool found = false;
    while(!found)
    {
        system("clear");
        printf( "Enter the name of the contact you would like to call.\n"
                "If you want to quit to the Call Menu, enter 0.\n"
                "Name:\n");
        scanf(" %[^\n]%*c", name);    // [] is scanset character. 
        // %*c reads newline character and discards it
        
        if(name[0] == '0')
            break;
        
        found = make_call(name);             //TO BE CONTINUED
        
        if(!found)
        {
            system("clear");
            printf("Please enter an existing contact name.\n");
            sleep(1);
        }
        else
        {
            system("clear");
            printf("Call has been successfully made\n");
            sleep(1);
        }
    }
    system("clear");
    printf("Going back to Call Menu\n");
    sleep(1);
}
void view_contacts_prompt()
{   
    char queryString[25];
    char continue_char;
    system("clear");
    
    printf("Enter the first few letters of the name of the contact you want to look up.\nTo display all contacts, type in '*'. \n");
    scanf(" %[^\n]%*c", queryString);
    
    system("clear");
    printf("///YOUR CONTACTS///\n");
    _Bool has_contacts = view_contacts(queryString);
    if(!has_contacts)
    {
        system("clear");
        printf("There are no contacts stored yet.\n");
        sleep(1);
    }
    else
    {
        printf("\n\nPress the Enter key to continue.\n");
        continue_char = getchar();
    }
}
void add_contact_prompt()
{
    char confirm_input = 'n';
    char name[25];
    long int phone_num;
    
    while(confirm_input == 'n') //Taking confirmed inputs
    {
        system("clear");
        printf("To add contact, enter the following details.\n");
        printf("Name of Person:\n");
        scanf(" %[^\n]%*c",name); 
        printf("Phone number of Person:\n");
        scanf("%ld%*c",&phone_num);
        
        printf("Can this contact be saved, or do you want to input again?(y/n)\n");
        confirm_input = getchar();
        while(confirm_input != 'y' && confirm_input != 'n')
        {
            printf("Please Enter 'y' or 'n'\n\n");
            printf("Can this contact be saved, or do you want to input again?(y/n)\n");
            confirm_input = getchar();
        }
    }
    
    add_contact(name, phone_num);  
    
}
void delete_contact_prompt()
{
    char name[25];
    _Bool found = false;
    while(!found)
    {
        system("clear");
        printf( "Enter the name of the contact you would like to delete.\n"
                "If you want to quit to the Call Menu, enter 0.\n"
                "Name:\n");
        scanf(" %[^\n]%*c", name);    // [] is scanset character. 
        // %*c reads newline character and discards it
        
        if(name[0] == '0')
            break;
        
        found = delete_contact(name);             //TO BE CONTINUED
        
        if(!found)
        {
            system("clear");
            printf("Please enter an existing contact name.\n");
            sleep(1);
        }
    }
    if(found == true)   //condition is met only when contact has been deleted
    {
        system("clear");
        printf("Contact has been succesfully deleted\n");
        sleep(1);
    }
}
void view_call_logs_prompt()
{
    if(call_logs_is_empty())
    {
        system("clear");
        printf("Call logs is empty.\n");
        sleep(1);
    }
    else
    {
        system("clear");
        printf("///CALL LOGS///\n");
        view_call_logs();
        
        printf("\nPress the Enter key to continue\n");
        char continue_char1 = getchar(); 
    }
}
void destroy_call_logs_prompt()
{
    char confirm_input = '\0';
    
    while(confirm_input != 'y' && confirm_input != 'n') //Taking confirmed inputs
    {
        system("clear");       
        printf("Are you sure you want to delete all call logs?(y/n)\n");
        confirm_input = getchar();
        
        if(confirm_input != 'y' && confirm_input != 'n')
        {
            system("clear");
            printf("Please Enter 'y' or 'n'\n\n");
            sleep(1);
        }
    }
    
    if(confirm_input=='y')
    {
        destroy_call_logs();
        printf("Call logs deleted\n");
        sleep(1);
    }
}
