#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
#include <ctype.h>

void name(AddressBook *addressBook);
void phone(AddressBook *addressBook);
void email(AddressBook *addressBook);


void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the choosen criteria
    int criteria;
    printf("Sort based on:\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    scanf("%d",&criteria);
    int i=0,j=0;
    switch(criteria)
    {
        case 1: // Sort by name
            for(i=0;i<addressBook->contactCount-1;i++)
            {
                for(j=0;j<addressBook->contactCount-i-1;j++)
                {
                    if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
                    {
                        Contact temp=addressBook->contacts[j];       // contact datatype coz we are swapping the whole contact structure
                        addressBook->contacts[j]=addressBook->contacts[j+1];
                        addressBook->contacts[j+1]=temp;
                    }
                }   
            }
            break;
        case 2: // Sort by phone
            for(i=0;i<addressBook->contactCount-1;i++)
            {
                for(j=0;j<addressBook->contactCount-i-1;j++)
                {
                    if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0)
                    {
                        Contact temp=addressBook->contacts[j];       // contact datatype coz we are swapping the whole contact structure
                        addressBook->contacts[j]=addressBook->contacts[j+1];
                        addressBook->contacts[j+1]=temp;
                    }
                }   
            }
            break;
        case 3: // Sort by email
            for(i=0;i<addressBook->contactCount-1;i++)
            {
                for(j=0;j<addressBook->contactCount-i-1;j++)
                {
                    if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0)
                    {
                        Contact temp=addressBook->contacts[j];       // contact datatype coz we are swapping the whole contact structure
                        addressBook->contacts[j]=addressBook->contacts[j+1];
                        addressBook->contacts[j+1]=temp;
                    }
                }   
            }
            break;
    } 
    printf("\n-----------------------------------------------------------------\n");
    printf("%-20s %-15s %-30s\n","| Name","| Phone Number","| Email-Id                 |");
    printf("-----------------------------------------------------------------\n");
    for(i=0;i<addressBook->contactCount;i++)
    {
        printf("%-20s\t%-15s\t%-30s\t\n",addressBook-> contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }   
    printf("-----------------------------------------------------------------\n");    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    
    name(addressBook);
    phone(addressBook);
    email(addressBook);    
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int criteria;
    printf("search based on:\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    scanf("%d", &criteria);
    //strcasestr();
    switch (criteria)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int criteria;
    printf("search based on:\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    scanf("%d", &criteria);
    switch (criteria)
    {
    case 1:
        int choice;
        printf("Enter the name to search: ");
        //delete logic
        printf("Edit the contact details:\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the name to edit: ");
            //validation
            
            /* code */
            break;
        case 2:
            printf("Enter the phone to edit: ");
            //validate
            /* code */
            break;
        case 3:
            printf("Enter the email to edit: ");
            //validate
            /* code */
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int criteria;
    printf("search based on:\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    scanf("%d", &criteria);
    switch (criteria)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
   
}


//create contact functions name,phone number and mailid validations

void name(AddressBook *addressBook)
{
    int found=1;
    printf("Enter the name: ");
    while(found)
    {
        found=0;
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
        if(strlen(addressBook->contacts[addressBook->contactCount].name)<2)
        {
            found=1;
        }
        else
        {
            int j=0;
            while(addressBook->contacts[addressBook->contactCount].name[j] != '\0')
            {
                char ch = addressBook->contacts[addressBook->contactCount].name[j];
                if (!isalpha(ch) && !isblank(ch) && !isdigit(ch))
                {
                    found=1;
                    break;
                }
                j++;
            }
        }
        if(found)
        {
            printf("Invalid!! Please enter a valid name (only letters, numbers,and spaces, at least 2 characters): ");
        }
    }
}

void phone(AddressBook *addressBook)
{
    int found =1;
    printf("Enter the phone number: ");
    while(found)
    {
        found=0;
        scanf(" %s", addressBook->contacts[addressBook->contactCount].phone);
        if(strlen(addressBook->contacts[addressBook->contactCount].phone)!=10)
        {
            found=1;
        }
        else
        {
            int j=0;
            while(addressBook->contacts[addressBook->contactCount].phone[j] != '\0')
            {
                char ch = addressBook->contacts[addressBook->contactCount].phone[j];
                if (!isdigit(ch))
                {
                    found=1;
                    break;
                }
                j++;
            }
        }
        if(found)
        {
            printf("Invalid!! Please enter a valid phone number (only digits 10 characters): ");
        }
        else if(addressBook->contacts[addressBook->contactCount].phone[0]>='6' && addressBook->contacts[addressBook->contactCount].phone[0]<='9')
        {
            found=0;
        }
        else
        {
            found=1;
            printf("Invalid!! Please enter a valid phone number (first digit should be between 6 and 9): ");
        }
        for(int j=0;j<addressBook->contactCount;j++)
        {
            if(strcmp(addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[j].phone)==0)
            {
                found=1;
                printf("phone number already exists!! enter different number");
            }
        }
    }
}

void email(AddressBook *addressBook)
{
    int found=1;
    printf("Enter the email: ");
    while (found)
    {
        found=0;
        scanf(" %s", addressBook->contacts[addressBook->contactCount].email);
        char *dot=strstr(addressBook->contacts[addressBook->contactCount].email, ".com");
        char *at=strchr(addressBook->contacts[addressBook->contactCount].email, '@');
        if(strlen(addressBook->contacts[addressBook->contactCount].email)<5)
        {
            found=1;
            printf("Invalid!! Please enter a valid email (at least 5 characters): ");
        }
        else
        {
            int j=0;
            while(addressBook->contacts[addressBook->contactCount].email[j] != '\0')
            {
                char ch = addressBook->contacts[addressBook->contactCount].email[j];
                if (!islower(ch) && !isdigit(ch) && ch != '@' && ch != '.')
                {
                    found=1;
                    break;
                }
                j++;
            }
            if(found)
            {
                printf("Invalid!! Please enter a valid email (only lowercase letters, digits, '@' and '.'): ");
            }
        }
        if(!found)
        {
            if(dot==NULL || at==NULL)
            {
                found=1;
                printf("Invalid!! Please enter a valid email (should contain '@' and '.com'): ");
            }
            else if(at>dot)
            {
                found=1;
                printf("Invalid!! Please enter a valid email ('.com' should come after '@'): ");
            }
            else if((at+1)==dot)
            {
                found=1;
                printf("Invalid!! Please enter a valid email (there should be at least one character between '@' and '.com'): ");
            }
            else if(dot!=addressBook->contacts[addressBook->contactCount].email+strlen(addressBook->contacts[addressBook->contactCount].email)-4)
            {
                found=1;
                printf("Invalid!! Please enter a valid email ('.com' should be at the end): ");
            }
            
            else if(at==addressBook->contacts[addressBook->contactCount].email || dot==addressBook->contacts[addressBook->contactCount].email)
            {
                found=1;
                printf("Invalid!! Please enter a valid email (should not start with '@' or '.'): ");
            }
            
        }
        for(int j=0;j<addressBook->contactCount;j++)
        {
            if(strcmp(addressBook->contacts[addressBook->contactCount].email,addressBook->contacts[j].email)==0)
            {
                found=1;
                printf("Email already exists!! Enter different mail ID");
            }
        }
    }
}