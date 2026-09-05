#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int choice, seatno;
    int bookedseats = 0;

    int seat1 = 0, seat2 = 0;

    char name1[50], name2[50];
    int age1, age2;

    long long phone1, phone2, phone;

    while (1)
    {
        
        printf("1. New Booking\n");
        printf("2. Cancel Booking\n");
        printf("3. View Booking\n");
        printf("0. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (bookedseats == 2)
                {
                    printf("All seats are already booked.\n");
                    break;
                }

                printf("Enter seat number : ");
                scanf("%d", &seatno);

                if (seatno != 1 && seatno != 2)
                {
                    printf("Invalid seat number.\n");
                    break;
                }

                if ((seatno == 1 && seat1 == 1) ||
                    (seatno == 2 && seat2 == 1))
                {
                    printf("Seat is already booked.\n");
                    break;
                }

                char name[50];
                int validname = 1;

                printf("Enter your name: ");
                scanf(" %[^\n]", name);

                for (int i = 0; name[i] != '\0'; i++)
                {
                    if (!isalpha(name[i]) && name[i] != ' ')
                    {
                        validname = 0;
                        break;
                    }
                }

                if (validname == 0)
                {
                    printf("Invalid name. Use alphabets and spaces only.\n");
                    break;
                }

                char input[50];
                int validage = 1;

                printf("Enter your age: ");
                scanf("%s", input);

                for (int i = 0; input[i] != '\0'; i++)
                {
                    if (!isdigit(input[i]))
                    {
                        validage = 0;
                        break;
                    }
                }

                if (validage == 0)
                {
                    printf("Invalid age. Please enter numbers only.\n");
                    break;
                }

                sscanf(input, "%d", &age1);

                if (age1 <= 0)
                {
                    printf("Invalid age. Age must be greater than 0.\n");
                    break;
                }

                printf("Enter your phone number: ");
                scanf("%lld", &phone);

                if (phone < 6000000000LL || phone > 9999999999LL)
                {
                    printf("Invalid phone number.\n");
                    printf("Phone number must start with 6, 7, 8 or 9 and contain exactly 10 digits.\n");
                    break;
                }

            
                if (seatno == 1)
                {
                    strcpy(name1, name);
                    phone1 = phone;
                    seat1 = 1;
                }
                else
                {
                    strcpy(name2, name);
                    age2 = age1;
                    phone2 = phone;
                    seat2 = 1;
                }

                bookedseats++;

                printf("You have successfully booked seat number : %d\n",seatno);
                printf("Available Seats: %d\n", 2 - bookedseats);

                break;


            case 2:
                if (bookedseats == 0)
                {
                    printf("No booking available to cancel.\n");
                    break;
                }

                printf("Enter your seat number: ");
                scanf("%d", &seatno);

                printf("Enter your registered phone number: ");
                scanf("%lld", &phone);

                if (seatno != 1 && seatno != 2)
                {
                    printf("Invalid seat number.\n");
                    break;
                }

                if (seatno == 1 && seat1 == 0)
                {
                    printf("Seat 1 is not booked.\n");
                    break;
                }

                if (seatno == 2 && seat2 == 0)
                {
                    printf("Seat 2 is not booked.\n");
                    break;
                }

                if (seatno == 1 && phone != phone1)
                {
                    printf("Invalid phone number.\n");
                    break;
                }

                if (seatno == 2 && phone != phone2)
                {
                    printf("Invalid phone number.\n");
                    break;
                }

                if (seatno == 1)
                    seat1 = 0;
                else
                    seat2 = 0;

                bookedseats--;

                printf("Booking cancelled successfully.\n");
                printf("Available Seats: %d\n", 2 - bookedseats);

                break;


            case 3:
            {
                int viewseat;

                if (bookedseats == 0)
                {
                    printf("No bookings available.\n");
                    break;
                }

                printf("Enter your seat number: ");
                scanf("%d", &viewseat);

                printf("Enter your registered phone number: ");
                scanf("%lld", &phone);

                if (viewseat != 1 && viewseat != 2)
                {
                    printf("Invalid seat number.\n");
                    break;
                }

                if (viewseat == 1 && seat1 == 0)
                {
                    printf("Seat 1 is not booked.\n");
                    break;
                }

                if (viewseat == 2 && seat2 == 0)
                {
                    printf("Seat 2 is not booked.\n");
                    break;
                }

                if (viewseat == 1 && phone != phone1)
                {
                    printf("Invalid phone number.\n");
                    break;
                }

                if (viewseat == 2 && phone != phone2)
                {
                    printf("Invalid phone number.\n");
                    break;
                }

                if (viewseat == 1)
                {
                    printf("Name : %s\n", name1);
                    printf("Age : %d\n", age1);
                    printf("Phone : %lld\n", phone1);
                    printf("Seat Number : 1\n");
                }
                else
                {
                    
                    printf("Name : %s\n", name2);
                    printf("Age : %d\n", age2);
                    printf("Phone : %lld\n", phone2);
                    printf("Seat Number : 2\n");
                }

                break;
            }


            case 0:
                printf("Thank you for using the Seat Booking System.\n");
                return 0;


            default:
                printf("Invalid choice. Please select 0, 1, 2 or 3.\n");
        }
    }

    return 0;
}