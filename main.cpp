#include <iostream>
#include<stdio.h>

using namespace std;


struct node
{
    node *prev;
    int seatstatus;
    node *next;
};

node *head[8]={NULL};

void displayallseats()
{

    for (int i=0;i<8;i++)
    {

        node *temp=head[i];
        printf("%d: \t",i);
        while(temp!=NULL)
        {

            printf("%d\t",temp->seatstatus);
            temp=temp->next;
        }
        printf("\n");
    }

}

void booktheseat()
{

    int r,s;
    printf("Enter the Row number:");
    scanf("%d",&r);

    printf("Enter the seat number:");
    scanf("%d",&s);

    node *temp=head[r-1];
    int i=0;
    while(i<(s-1))
    {
        i++;
        temp=temp->next;
    }
    if (temp->seatstatus!=1)
    {
        temp->seatstatus=1;
        printf("\n\nTicket Booked Successfully\n");
    }
    else
    {
        printf("Already booked, choose other seat\n");

    }

}

void cancelseat()
{
    int r,s;
    printf("Enter the Row number\n");
    scanf("%d",&r);

    printf("Enter the seat number\n");
    scanf("%d",&s);
    node *temp=head[r-1];
    int i=0;
    while(i<(s-1))
    {
        i++;
        temp=temp->next;
    }
    if (temp->seatstatus==1)
    {
        temp->seatstatus=0;
        printf("Tickets has been cancelled\n");
    }
    else
    {
        printf("Already it is available\n");

    }
}

int main()
{
node *previous;
    for (int i=0;i<8;i++)
    {

        for (int j=0;j<6;j++)
        {
            node *temp=(node *)malloc(sizeof(node));
            temp->prev=NULL;
            temp->seatstatus=0;
            temp->next=NULL;

            if (head[i]==NULL)
            {
                head[i]=temp;
                previous=temp;
            }
            else
            {
                 previous->next=temp;
                 temp->prev=previous;
                 previous=temp;
            }



        }

    }
    int choice=0;
    int flag=0;
    while (choice !=4)
    {


    printf("\n\n1.Display the Available Seats\n2.Book the Tickets\n3.Cancel the tickets\n4.Exit\n");
    printf("Enter your Choice: ");

    scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            displayallseats();
            break;
        case 2:
            booktheseat();
            break;
        case 3:
            cancelseat();
            break;

        case 4:
            flag=1;
            break;

        }
        if (flag==1)
        {

            break;
        }

    }

    return 0;
}
