#include <stdio.h>
#include<unistd.h>
int main()
{
    int pin;
    int attempt = 0;
    int correct_pin = 1221;

    while(attempt<3)
{
    printf("Enter pin: ");
    scanf("%d",&pin);
    if(pin == correct_pin)
    {
    printf("acces granted\n");
    break;
    }
    else
    {
        printf("Acces denied\n");
        attempt++;
    }
    if( attempt == 3)
    {
        printf("To many attempt try latter");
    }
}

int choice;
do
{
    printf("\n ===TERMINAL INTERFACE ====\n");
    printf("1. run network scan...\n");
    printf("2. logout\n");
    printf("enter your choice: ");
    scanf("%d",&choice);

    if(choice == 1)
    {
    printf("\nStarting network scan....\n");
    for(int i = 1;i <= 10; i++)
    {
        printf("scanning target...[%d%% Complete]\n",i*10);
        usleep(500000);
    }

    }
    else if(choice == 2)
    {
        printf("loging out\n");
        usleep(500000);
        printf("welcome again");

    }
    else
    {
        printf("Invalid command\n");
        printf("Communicate to the server\n");
    }


}
while(choice != 2);

return 0;    
}