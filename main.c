
#include <stdio.h>
#include <string.h>

void addBigNumbers (char[], char[], char[]);
int MaxNumber (char first[], char second[]);
void sortBigNumbers (char *bigNumbers[], int N);
void reverse (unsigned char *str);
int
main ()
{
    char a[100], b[100], c[200];
    printf ("Enter first number:\n");
    scanf ("%s", a);
    printf ("Enter second number:\n");
    scanf ("%s", b);
    addBigNumbers (a, b, c);
    printf ("The result is: %s   \n", c);
    char *bigNumbers[5] = { "345778", "7865549", "1198076", "5437", "32456" };
    sortBigNumbers (bigNumbers, 5);
    printf ("bigNumbers after sorting");
    for (int i = 0; i < 5; i++)
    {
        printf ("= %s", bigNumbers[i]);
    }
}

void
addBigNumbers (char first[], char second[], char result[])
{
    reverse (first); //reverse the string
    reverse (second);//reverse the string
    int i = 0;
    int j = 0;
    int Max = 0, Min = 0;
    if (strlen (first) < strlen (second)) //save the small length in min value
    {
        Min = strlen (first);
    }
    else
        Min = strlen (second);
    char carry = 0;
    char sum = 0;
    for (i = 0; i < Min; i++, j++)
    {
        if (first[i] < '0' || first[i] > '9' || second[i] < '0'
            || second[i] > '9')
        { // if there an char that doesnt number fill the string "error" and exit from the method
            strcpy (result, "error");
            return;
        }//else
        sum = ((first[i] - '0') + (second[i] - '0') + carry); //"-'0'"give us the number like int to add it normal
        result[j] = sum % 10 + '0';//we add the ones to the result
        carry = sum / 10;//if there is a carry that should be in the tens of the sum save it to carry
    } // when finish the i and j should be arrive to the min length (so the small string is finished)
    while (i < strlen (first)) //if the first string doesn't finish yet
    {
        if (carry + '0' != 0) //if there's carry from the last addition add to the first and save it to result
        {
            sum = (first[i] - '0') + carry;
            result[j] = sum % 10 + '0';
            carry = sum / 10;
        }
        else //else just copy from first to result
            result[j] = first[i];
        i++;
        j++;
    }
    while (i < strlen (second))//if the second string doesn't finish yet
    {
        if (carry + '0' != 0)//if there's carry from the last addition add to the second and save it to result
        {
            sum = (second[i] - '0') + carry;
            result[j] = sum % 10 + '0';
            carry = sum / 10;
        }
        else
            result[j] = second[i];//else just copy from second to result
        j++;
        i++;
    }

    if (carry + '0' != '0')//after finish the two string maybe the last two numbers addition there is carry
    {
        result[j] = carry + '0'; //so add the carry to result
    }
    i = 0;
    while (i < strlen (result))//start from the start of result and check if there is any trash after put the new number in result
    {
        if (result[i] < '0' || result[i] > '9')
        {// if there's a trash it should be after the new number we put it in result so just stop the result there
            result[i] = '\0';
            break;
        }
        i++;
    }
    reverse (result);//reverse the result because the result is reversed because the first and two number are reversed
}

void
sortBigNumbers (char *bigNumbers[], int N)
{
    char *temp;
    for (int i = 0; i < N; i++) //bubble sort
    {
        for (int j = i + 1; j < N; j++)
        {
            if (MaxNumber (*(bigNumbers + i), *(bigNumbers + j)) == 0)//check if the bignumbers[i] is big than bignumbers[j]
            {//swap pointers
                temp = *(bigNumbers + i);//save the old value in temp
                *(bigNumbers + i) = *(bigNumbers + j);//put the big number pointer to point to the small number
                *(bigNumbers + j) = temp;//put the small number pointer to point to the big number
            }
        }
    }
}

int
MaxNumber (char first[], char second[])
{//0 means the first is bigger, 1 means the second is bigger
    if (strlen (first) > strlen (second))
    {//if the first number have more digit return 0;
        return 0;
    }
    else if (strlen (second) > strlen (first))
    {//if the second number have more digit return 1;
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen (first); i++)
        {//start from the highest digit and check if it bigger than the other (*note booth number are in same number of digits)
            if (first[i] > second[i])
                return 0;
            if (first[i] < second[i])
                return 1;
        }
    }
    return 0;
}

void
reverse (unsigned char *str) //it's from <string.h> but gdb don't recognize this
{
    int i;
    int j;
    unsigned char a;
    unsigned len = strlen ((const char *) str);
    for (i = 0, j = len - 1; i < j; i++, j--)
    {//swap the last to the first etc.
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
}

