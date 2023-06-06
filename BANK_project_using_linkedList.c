#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account
{
    int accountNumber;
    char customerName[100];
    double balance;
    char accountType[20];
    struct Account *next;
} Account;

Account *createAccount(int accountNumber, const char *customerName, double balance, const char *accountType)
{
    Account *newAccount = (Account *)malloc(sizeof(Account));
    newAccount->accountNumber = accountNumber;
    strcpy(newAccount->customerName, customerName);
    newAccount->balance = balance;
    strcpy(newAccount->accountType, accountType);
    newAccount->next = NULL;
    return newAccount;
}

void addAccount(Account **bank, int accountNumber, const char *customerName, double balance, const char *accountType)
{
    Account *newAccount = createAccount(accountNumber, customerName, balance, accountType);

    if (*bank == NULL)
    {
        *bank = newAccount;
    }
    else
    {
        Account *current = *bank;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newAccount;
    }

    printf("Account added successfully.\n");
}

Account *findAccount(Account *bank, int accountNumber)
{
    Account *current = bank;
    while (current != NULL)
    {
        if (current->accountNumber == accountNumber)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteAccount(Account **bank, int accountNumber)
{
    Account *current = *bank;
    Account *prev = NULL;

    while (current != NULL)
    {
        if (current->accountNumber == accountNumber)
        {
            if (prev == NULL)
            {
                *bank = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Account deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Account not found.\n");
}

void displayAccounts(Account *bank)
{
    if (bank == NULL)
    {
        printf("No accounts found.\n");
    }
    else
    {
        printf("Account List:\n");
        Account *current = bank;
        while (current != NULL)
        {
            printf("Account Number: %d\n", current->accountNumber);
            printf("Customer Name: %s\n", current->customerName);
            printf("Balance: %.2f\n", current->balance);
            printf("Account Type: %s\n", current->accountType);
            printf("-----------------\n");
            current = current->next;
        }
    }
}

void freeBank(Account *bank)
{
    Account *current = bank;
    while (current != NULL)
    {
        Account *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    Account *bank = NULL;

    addAccount(&bank, 1001, "John Doe", 5000, "Savings");
    addAccount(&bank, 1002, "Jane Smith", 10000, "Current");
    addAccount(&bank, 1003, "Bob Johnson", 2000, "Savings");
    displayAccounts(bank);

    Account *foundAccount = findAccount(bank, 1002);
    if (foundAccount != NULL)
    {
        printf("Account found: %s\n", foundAccount->customerName);
    }
    else
    {
        printf("Account not found.\n");
    }

    deleteAccount(&bank, 1002);
    displayAccounts(bank);

    freeBank(bank);

    return 0;
}
