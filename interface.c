//Subroutines used in the interface module
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include"interface_headers.h"

void quit()
{
    //Free space and destroys root variables
    
    system("clear");
    printf("Program will terminate.\n");
    sleep(1);
    system("clear");
}
void top_level_menu()
{
    int top_level_menu_choice;
    
    while(true)
    {
        system("clear");
        printf("///CALL MENU///\n\n\n"
            "To quit, enter 0.\n"
            "To make a Call, enter 1.\n"
            "To see Contact Menu, enter 2.\n"
            "To see Call Logs Menu, enter 3.\n"
            "Choice: \n");
        top_level_menu_choice = getchar();
        sleep(1);        
        
        //If input char is not integer, re-iterates.
        if(isdigit(top_level_menu_choice))
            top_level_menu_choice -= '0';
        else
        {
            printf("Please enter valid input\n");
            continue;
        }
        //Breaks out of loop if option is to quit, otherwise menu is chosen.
        if(top_level_menu_choice == 0)
            break;
        
        switch(top_level_menu_choice)
        {
            case 1:
                make_call_prompt();
                break;
            case 2:
                contact_menu();
                break;
            case 3:
                call_logs_menu();
                break;
            default:
                //If input is integer but not valid option
                system("clear");
                printf("Please enter a valid input\n");
                sleep(1);
                break;
        }
    }
}
void contact_menu()
{
    char contact_menu_choice;
    
    while(true)
    {
        system("clear");
        printf("///CONTACTS MENU///\n\n\n"
        "To quit to top menu, enter 0.\n"
        "To view contact, enter 1.\n"
        "To add contact, enter 2.\n"
        "To delete contact, enter 3.\n"
        "Choice: \n");
        contact_menu_choice = getchar();
        sleep(1);
        
        //If input char is not integer, re-iterates.
        if(isdigit(contact_menu_choice))
            contact_menu_choice -= '0';
        else
        {
            printf("Please enter valid input\n");
            continue;
        }
        //Breaks out of loop if option is to quit, otherwise menu is chosen.
        if(contact_menu_choice == 0)
            break;
        
        switch(contact_menu_choice)
        {
            case 1:
                view_contacts_prompt();
                break;
            case 2:
                add_contact_prompt();
                break;
            case 3:
                delete_contact_prompt();
                break;
            default:
                //If input is integer but not valid option
                system("clear");
                printf("Please enter a valid input\n");
                sleep(1);
                break;
        }
    }
}
void call_logs_menu()
{
    char call_logs_menu_choice;
    
    while(true)
    {
        system("clear");
        printf("///CALL LOGS MENU///\n\n\n"
            "To quit to top menu, enter 0.\n"
            "To view call logs, enter 1.\n"
            "To delete all call logs, enter 2.\n"
            "Choice: \n");
//         call_logs_menu_choice = getchar();
        scanf(" %c%*c", &call_logs_menu_choice);
        sleep(1);
        
        //If input char is not integer, re-iterates.
        if(isdigit(call_logs_menu_choice))
            call_logs_menu_choice -= '0';
        else
        {
            printf("Please enter valid input\n");
            continue;
        }
        //Breaks out of loop if option is to quit, otherwise menu is chosen.
        if(call_logs_menu_choice == 0)
            break;        
        
        switch(call_logs_menu_choice)
        {
            case 1:
                view_call_logs_prompt();
                break;
            case 2:
                destroy_call_logs_prompt();
                break;
            default:
                //If input is integer but not valid option
                system("clear");
                printf("Please enter a valid input\n");
                sleep(1);
                break;
        }
    }
}
int main()
{
    //Root variables initialised
    
    top_level_menu();
    quit();
    
    return 0;
}
