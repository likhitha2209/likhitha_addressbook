#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
#include <ctype.h>

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the choosen criteria
    int criteria;
    printf("Sort based on:\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    scanf("%d",&criteria);
    int i=0,j=0;
    for(i=0;i<addressBook->contactCount;i++)
    {
        for(j=i;j<addressBook->contactCount-i-1;j++)
        {
            if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0)
            {
                Contact temp=addressBook->contacts[i];       // contact datatype coz we are swapping the whole contact structure
                addressBook->contacts[i]=addressBook->contacts[j];
                addressBook->contacts[j]=temp;
            }
        }
    } 
    for(i=0;i<addressBook->contactCount;i++)
    {
        printf("%s\t%s\t%s\t",addressBook-> contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }   

    
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
    int i=0;
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
                if (!isalpha(ch) && !isblank(ch))
                {
                    found=1;
                    break;
                }
                j++;
            }
        }
        if(found)
        {
            printf("Invalid name. Please enter a valid name (only letters and spaces, at least 2 characters): ");
        }
        i++;
    }

    i=0;
    found =1;
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
            printf("Invalid phone number. Please enter a valid phone number (only digits, at least 10 characters): ");
        }
        else if(addressBook->contacts[addressBook->contactCount].phone[0]>='6' && addressBook->contacts[addressBook->contactCount].phone[i]<='9')
        {
            found=0;
        }
        else
        {
            found=1;
            printf("Invalid phone number. Please enter a valid phone number (first digit should be between 6 and 9): ");
        }
        i++;
    }
    
    i=0;
    found=1;
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
            printf("Invalid email. Please enter a valid email (at least 5 characters): ");
        }
        else
        {
            int j=0;
            while(addressBook->contacts[addressBook->contactCount].email[j] != '\0')
            {
                char ch = addressBook->contacts[addressBook->contactCount].email[j];
                if (!islower(ch) && !isdigit(ch) && ch != '@' && ch != '.' )
                {
                    found=1;
                    break;
                }
                j++;
            }
            if(found)
            {
                printf("Invalid email. Please enter a valid email (only lowercase letters, digits, '@' and '.'): ");
            }
        }
        if(!found)
        {
            if(dot==NULL || at==NULL)
            {
                found=1;
                printf("Invalid email. Please enter a valid email (should contain '@' and '.com'): ");
            }
            else if(at>dot)
            {
                found=1;
                printf("Invalid email. Please enter a valid email ('.com' should come after '@'): ");
            }
            else if((at+1)==dot)
            {
                found=1;
                printf("Invalid email. Please enter a valid email (there should be at least one character between '@' and '.com'): ");
            }
            else if(dot!=addressBook->contacts[addressBook->contactCount].email+strlen(addressBook->contacts[addressBook->contactCount].email)-4)
            {
                found=1;
                printf("Invalid email. Please enter a valid email ('.com' should be at the end): ");
            }
            
            else if(at==addressBook->contacts[addressBook->contactCount].email || dot==addressBook->contacts[addressBook->contactCount].email)
            {
                found=1;
                printf("Invalid email. Please enter a valid email (should not start with '@' or '.'): ");
            }
        }
    }
    
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int criteria;
    printf("search based on:\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    scanf("%d", &criteria);
    //strcasestr();
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */

   
}
