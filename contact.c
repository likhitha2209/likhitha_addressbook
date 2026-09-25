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
    printf("Enter the name of the contact: ");
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
            int i=0;
            while(addressBook->contacts[addressBook->contactCount].name[i] != '\0')
            {
                char ch = addressBook->contacts[addressBook->contactCount].name[i];
                if (!isalpha(ch) && !isblank(ch))
                {
                    found=1;
                    break;
                }
                i++;
            }
        }
        if(found)
        {
            printf("Invalid name. Please enter a valid name (only letters and spaces, at least 2 characters): ");
        }
    }
    
    

    printf("Enter the phone number of the contact: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].phone);
    printf("Enter the email of the contact: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].email);
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
