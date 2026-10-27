#include <stdio.h>
#include <unistd.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

int main(void)
{
    int pin;
    int attempt = 0;
    const int correct_pin = 1221;

    while (attempt < 3)
    {
        printf(YELLOW "Enter pin: " RESET);
        if (scanf("%d", &pin) != 1)
        {
            printf(RED "Invalid input.\n" RESET);
            return 1;
        }

        if (pin == correct_pin)
        {
            printf(GREEN "Access granted\n" RESET);
            break;
        }

        printf(RED "Access denied\n" RESET);
        attempt++;
        if (attempt == 3)
        {
            printf(RED "Too many attempts. Try later.\n" RESET);
            return 0;
        }
    }

    int choice;
    do
    {
        printf("\n" BLUE "=== TERMINAL INTERFACE ===\n" RESET);
        printf(GREEN "1. Run network scan...\n" RESET);
        printf(RED "2. Logout\n" RESET);
        printf(YELLOW "Enter your choice: " RESET);

        if (scanf("%d", &choice) != 1)
        {
            printf(RED "Invalid input.\n" RESET);
            return 1;
        }

        if (choice == 1)
        {
            printf("\n" BLUE "Starting network scan...\n" RESET);
            for (int i = 1; i <= 10; i++)
            {
                printf(GREEN "Scanning target...[%d%% Complete]\n" RESET, i * 10);
                usleep(500000);
            }
        }
        else if (choice == 2)
        {
            printf(YELLOW "Logging out...\n" RESET);
            usleep(500000);
            printf(BLUE "Welcome again\n" RESET);
        }
        else
        {
            printf(RED "Invalid command\n" RESET);
            printf(YELLOW "Communicate to the server\n" RESET);
        }
    }
    while (choice != 2);

    return 0;
}
