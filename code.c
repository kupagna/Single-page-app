#include <stdio.h>

int main()
{
    int n=2;
    int op;
    int seatno;
    int age1,age2;
    int seat1=0;
    int seat2=0;
    int bookedseats=0;
    char name1[50],name2[50];
    while(1){
        printf("1.New booking\n");
        printf("2.Cancel booking\n");
        printf("3.View booking\n");
        printf("0.Quit\n");
        printf("Enter your op : ");
        scanf("%d",&op);
        switch(op){
            case 1:
    if (bookedseats == 2)
    {
        printf("No seats available\n");
    }
    else
    {

        printf("Enter your seat no : ");
        scanf("%d", &seatno);

        if (seatno < 1 || seatno > 2)
        {
            printf("Not valid\n");
        }
        else if (seatno == 1 && seat1 == 1)
        {
            printf("Seat 1 is already booked\n");
        }
        else if (seatno == 2 && seat2 == 1)
        {
            printf("Seat 2 is already booked\n");
        }
        else
        {
            if (seatno == 1){
                
                 printf("Enter your name : ");
                 scanf("%s", name1);

                 printf("Enter your age : ");
                 scanf("%d", &age1);

                seat1 = 1;
            }
            else{
            printf("Enter your name : ");
        scanf("%s", name2);

        printf("Enter your age : ");
        scanf("%d", &age2);

                seat2 = 1;
            }
            bookedseats++;

            printf(" Thankyou,you have Successfully booked seat no : %d\n", seatno);
            printf("No.of seats available : %d\n",
                   2 - bookedseats);
        }
    }
    break;
            case 2:
    if (bookedseats == 0)
    {
        printf("No booking available to cancel\n");
    }
    else
    {
        printf("Enter your seat number : ");
        scanf("%d", &seatno);

        if (seatno < 1 || seatno > 2)
        {
            printf("Sorry, your seat number is not valid\n");
        }
        else if (seatno == 1 && seat1 == 0)
        {
            printf("Seat 1 is not booked\n");
        }
        else if (seatno == 2 && seat2 == 0)
        {
            printf("Seat 2 is not booked\n");
        }
        else
        {
            if (seatno == 1){
                seat1 = 0;
            }
            else{
                seat2 = 0;
}
            bookedseats--;

            printf("Successfully cancelled your ticket\n");
            printf("No. of available seats : %d\n",
                   2 - bookedseats);
        }
    }
    break;
            case 3:
    if (bookedseats == 0)
    {
        printf("No bookings available\n");
    }
    else
    {
        if (seat1 == 1)
        {
            printf("Name : %s\n", name1);
            printf("Age : %d\n", age1);
            printf("Seat no : 1\n");
        }

        if (seat2 == 1)
        {
            printf("Name : %s\n", name2);
            printf("Age : %d\n", age2);
            printf("Seat no : 2\n");
        }
    }
    break;
            case 0:
                  printf("Quit");
                  return 0;
            default:
                  printf("Invalid option\n");
        }
    }

    return 0;
}