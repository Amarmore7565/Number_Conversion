// NUMBER SYSTEM CONVERSION MINI PROJECT

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

// Function declaration

void deci_to_binary();
void binary_to_deci();
void deci_to_octal();
void oct_to_deci();
void deci_to_hexa();
void hexa_to_deci();

// Global variables
int cnt = 0, i, number;
int bin[16];

int main()
{
    int choice;
  
    system("cls");
    printf("\n\n\n\n");
    printf("-----------------------------------------------------\n");
    printf("          Welcome to Number System Converter  \n");
    printf("-----------------------------------------------------\n");
    printf("\n\n\n\n");
    printf("Enter any key to continue......");

    getch();
    system("cls");
    
    while (choice != 7)
    {
        // Display Menu list
        printf("\n____________________________________________________________________________________________");
        printf("\n\n1) Decimal to Binary. \n2) Binary to Decimal. \n3) Decimal to Octal. \n4) Octal to Decimal. \n5) Decimal to Hexadecimal. \n6) Hexadecimal to Decimal \n7) Exit.\n\n");
        printf("Enter option from above list = ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deci_to_binary();           // function call for conversion of decimal no to binary no.
            break;

        case 2:
            binary_to_deci();           // function call for conversion of binary no to decimal no.
            break;

        case 3:
            deci_to_octal();            // function call for conversion of decimal no to octal no.
            break;

        case 4:
            oct_to_deci();              // function call for conversion of octal no to decima no.
            break;

        case 5:
              deci_to_hexa();           // function call for conversion of decimal no to hexadecimal no.
            break;

        case 6:
              hexa_to_deci();           // function call for conversion of hexadecimal no to decimal no.
             break;
   
        case 7:
            printf("Exit Successful.");
            exit(0);
        
        default:
            printf("Invalid Option.");
        }
    }
}


/*C program to convert number from decimal to binary*/
// Function defination
void deci_to_binary()
{ 
    // File pointers for input and output files
    FILE *InputFile,*OutputFile;                    
    InputFile=fopen("Input.txt","a+");     
     
    // Open input file
    printf("\nEnter decimal number: ");
    scanf("%d", &number);

    if(number <= 65535)
    {
        fprintf(InputFile,"\nDecimal number : ");  
        fprintf(InputFile,"%d",number);             
        fclose(InputFile);

        // Logic for conversion decimal number to binary number.
        while (number > 0)
        {
            bin[cnt] = number % 2;
            number = number / 2;
            cnt++;
        }

        OutputFile=fopen("Output.txt","a+");
        /*print value in reverse order*/
        printf("\nRESULT\n");
        printf("----------------------\n");
        printf("Binary value is: ");
        // Write output to file
        fprintf(OutputFile,"\nBinary number : ");
        for (i = (cnt - 1); i >= 0; i--)
        {
            printf("%d",bin[i]);
            fprintf(OutputFile, "%d",bin[i]);
        }
        // Close output file
        fclose(OutputFile);
        printf("\n----------------------");
        
    }
    else 
    {
        printf("Enter Number is out of range.");
    }
}


/*C program to convert number from binary to decimal*/
// Function defination
void binary_to_deci()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file 
    InputFile = fopen("Input.txt", "a+");
    int binary_num,j,flag=0,numb;

    printf("\nEnter a Binary number:");
    scanf("%d",&binary_num);
    numb = binary_num;

    // Logic to check enter number is binary or not.
    while (numb > 0) 
    {  
        flag = 0;
        j = numb % 10;
        if (j != 0 && j != 1) 
        {
          flag = 1;
          break;
        }
        numb = numb / 10;
    }

    if(flag == 0)
    {
        fprintf(InputFile,"\nBinary number : ");
        fprintf(InputFile,"%d",binary_num);
        fclose(InputFile);

        int i=0,decimal_num=0,rem;

        // Logic for conversion binary number to decimal number.
        while(binary_num != 0)
        {
            rem = binary_num % 10;

            if(rem==1)
            {
                decimal_num = decimal_num + pow(2,i);
            }
            binary_num = binary_num /10;
            i++;
        }
        OutputFile=fopen("Output.txt","a+");
  
        printf("\n\nRESULT\n");
        printf("----------------------\n");
        printf("Decimal value is: ");
    
        // Write output to file
        fprintf(OutputFile,"\nDecimal number : ");
        printf("%d",decimal_num);
        fprintf(OutputFile, "%d",decimal_num);
        printf("\n"); 

        // Close output file
        fclose(OutputFile);
        printf("----------------------");
    }
    else
    {
        printf("Enter number is not in binary");
    }
}


/*C program to convert number from decimal to octal*/
// Function defination
void deci_to_octal()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file
    InputFile = fopen("Input.txt", "a+");
    int decimal_num,i=0;
    
    printf("\nEnter Decimal number:");
    scanf("%d",&decimal_num);

    if(decimal_num <= 2097152)
    {
        fprintf(InputFile,"\nDecimal number : ");
        fprintf(InputFile,"%d",decimal_num);
        fclose(InputFile);

        int octal_num[8];

        // Logic for conversion decimal number to octal number.
        while(decimal_num != 0)
        {
           octal_num[i] = decimal_num % 8; 
           decimal_num = decimal_num/8;
           i++;
        }
        // Open output file 
        OutputFile=fopen("Output.txt","a+");

        /*print value in reverse order*/
        printf("\n\nRESULT\n");
        printf("----------------------\n");
        printf("Octal value is: ");
        // Write output to file
        fprintf(OutputFile,"\nOctal number : ");
        for(int j= i-1;j>=0;j--)
        {
            printf("%d",octal_num[j]);
            fprintf(OutputFile, "%d",octal_num[j]);

        }
        printf("\n----------------------");
        // Close output file
        fclose(OutputFile);
    }
    else
    {
        printf("Enter Number is out of range.");
    }
    
}


/*C program to convert number from octal to decimal*/
// Function defination
void oct_to_deci()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file
    InputFile= fopen("Input.txt", "a+");
    int rem=0,number,count=0,dec=0,numb,j,flag = 0;

    printf("\nEnter octal Number=");
    scanf("%d", &number);
    numb = number;

    // Logic to check enter number is octal or not
    while (numb > 0) 
    {
        flag = 0;
        j = numb % 10;
        if (j <= 0 || j >=7) 
        {
          flag = 1;
          break;
        }
        numb = numb / 10;
    }

    if(flag == 0)
    {
        fprintf(InputFile,"\nOctal number : ");
        fprintf(InputFile,"%d",number);
        fclose(InputFile);

        // Logic for conversion octal number to decimal number.
        while(number)
        {
            rem=number%10;
            dec=dec+rem*pow(8,count);
            number=number/10;
            count++;
        }
        // Open output file 
        OutputFile=fopen("Output.txt","a+");
  
        printf("\n\nRESULT\n");
        printf("----------------------\n");
        printf("Decimal value is: ");
        // Write output to file
        fprintf(OutputFile,"\nDecimal number : ");
        printf("%d",dec);
        fprintf(OutputFile, "%d",dec);
        // Close output file
        fclose(OutputFile);
        printf("\n----------------------");
    }
    else
    {
        printf("Enter number is not in octal");
    }
    
}


/*C program to convert number from decimal to hexadecimal*/
// Function defination
void deci_to_hexa()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file
    InputFile = fopen("Input.txt", "a+");
    int num,temp,rem,i=1,j;
    char hexa[8];
    printf("\nEnter Decimal number:");
    scanf("%d",&num);
    temp=num;

    if(num <= 268435455)
    {
        fprintf(InputFile,"\nDecimal number : ");
        fprintf(InputFile,"%d",num);
        fclose(InputFile);

        // Logic for conversion decimal number to hexadecimal number.
        while(temp!=0)
        {
            rem=temp%16;
            if(rem<10)
            {
                rem=rem+48;
            }
            else
            {
            rem=rem+55;
            }
            hexa[i++]=rem;
            temp=temp/16;
        }

        // Open output file 
        OutputFile=fopen("Output.txt","a+");
        printf("\n\nRESULT\n");
        printf("------------------------\n");
        printf("Hexadecimal number is :");
        // Write output to file
        fprintf(OutputFile,"\nHexadecimal number : ");
        for(j=i-1;j>0;j--)
        {
            printf("%c",hexa[j]);
            fprintf(OutputFile, "%c",hexa[j]);
        }
        // Close output file
        fclose(OutputFile);
        printf("\n------------------------");
    }
    else
    {
        printf("Enter Number is out of range.");
    }
    
}


/*C program to convert number from hexadecimal to decimal*/
// Function defination
void hexa_to_deci()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file 
    InputFile = fopen("Input.txt", "a+");
    char hexa[16];
    int sum=0,i,len=0,j=0;

    printf("\nEnter Hexadecimal number:");
    scanf("%s",&hexa);
    
    fprintf(InputFile,"\nHexadecimal number : ");
    fprintf(InputFile,"%s",hexa);
    fclose(InputFile);

    len=strlen(hexa);

    // Logic for conversion hexadecimal number to decimal number.
    if(len <= 7)
    {
        for(i=len-1;i>=0;i--)
        {
            if(hexa[i]>='0'&& hexa[i]<='9')
            {
                sum=sum+(hexa[i]-48)*pow(16,j);
                j++;
            }
            else if(hexa[i]>='A'&& hexa[i]<='F')
            {
                sum=sum+(hexa[i]-55)*pow(16,j);
                j++;

            }
        }
        // Open output file 
        OutputFile=fopen("Output.txt","a+");
        printf("\n\nRESULT\n");
        printf("----------------------\n");
        printf("Decimal value is %d",sum);
        printf("\n----------------------");
        // Write output to file
        fprintf(OutputFile,"\nDecimal number : ");
        fprintf(OutputFile, "%d",sum);
        // Close output file
        fclose(OutputFile);
    }
    else
    {
        printf("Enter Number is out of range.");
    }
}