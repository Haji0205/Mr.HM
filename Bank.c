#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 10

struct account {
    char name[50];
    int account_number;
    float balance;
};

void create_account(struct account accounts[], int *count);
void deposit(struct account accounts[], int count);
void withdraw(struct account accounts[], int count);
void print_account_info(struct account accounts[], int count);

int main() {
    int count = 0;
    struct account accounts[MAX_ACCOUNTS];

    int option;
    do {
        printf("\nBanking System\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Print account info\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                create_account(accounts, &count);
                break;
            case 2:
                deposit(accounts, count);
                break;
            case 3:
                withdraw(accounts, count);
                break;
            case 4:
                print_account_info(accounts, count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, try again\n");
        }
    } while (option != 5);

    return 0;
}

void create_account(struct account accounts[], int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    printf("Enter account name: ");
    scanf("%s", accounts[*count].name);

    printf("Enter account number: ");
    scanf("%d", &accounts[*count].account_number);

    printf("Enter initial deposit: ");
    scanf("%f", &accounts[*count].balance);

    printf("Account created successfully\n");
    (*count)++;
}

void deposit(struct account accounts[], int count) {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Account not found\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    accounts[index].balance += amount;
    printf("Deposit successful\n");
}

void withdraw(struct account accounts[], int count) {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

      int index = -1;
    for (int i = 0; i < count; i++) {
        if (accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Account not found\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (accounts[index].balance < amount) {
        printf("Insufficient balance\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("Withdrawal successful\n");
}

void print_account_info(struct account accounts[], int count) {
    int account_number;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Account not found\n");
        return;
    }

    printf("\nAccount Information\n");
    printf("Name: %s\n", accounts[index].name);
    printf("Account Number: %d\n", accounts[index].account_number);
    printf("Balance: %.2f\n", accounts[index].balance);
}
