#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

int addrecord();
void viewrecord();
void editrecord();
void deleterecord();
int changepass();
int timea();
int mainmenu();

struct data
{
   char rpassword[15];
};

int main()
{
    struct data e;

    FILE *ptr;
    int j=0;
    char you;
    char ch;
    char password[16],cont[16];
    int value=15;
    int i=0,ct=0;

    printf("                ***************************\n");
    printf("                ****PASSWORD PROTECTED*****\n");
    printf("                ***************************\n\n\n\n");

    printf("Enter the password to access the software \n\n\n");
    while(1)
    {

    ch=getch();
    if(ch==13)
    {
        break;
    }
    else if(ch==8)
    {
        i--;
        password[i]='\0';
        printf("\b \b");

    }
        else if(ch==32 || ch==9)
        {
            continue;
        }
    else
    {
        if(i<value)
        {
            password[i]=ch;
            ch='*';
            printf("%c",ch);
            i++;
        }else
        {
            printf("\n\n\tYou exceed the limit, only limited character taken.....");
            getch();
            break;
        }
    }
  }
        password[i]='\0';
       ptr=fopen("pass","rb");
       if(ptr==NULL)
       {
           printf("\n\n\t The password file is missing....\n\n\tYou cannot access the software...\n");
       }else
       {
           while(!feof(ptr))
           {
               you=fgetc(ptr);
                cont[j]=you;
                j++;
           }
                  cont[j-1]='\0';
      strcpy(e.rpassword,cont);

       if(strcmp(password, e.rpassword)==0)
      {
            printf("\n\n\n     You access the software successfully.......");
            getch();
            mainmenu();

      }
       else{
        printf("\n\n\nEnter the wrong password...");
       }

       }

      fclose(ptr);
  return 0;
}
int mainmenu()
{
    system("cls");
    while(1)
    {

    int a;

    printf("           ***************************\n");
    printf("           *******PERSONAL DIARY******\n");
    printf("           ***************************\n\n\n\n");

    printf("1. ADD RECORD\n");
    printf("2. VIEW RECORD\n");
    printf("3. DELETE RECORD\n");
    printf("4. CHANGE PASSWORD\n");
    printf("5. EXIT\n\n");

    scanf("%d",&a);

    switch(a)
    {
    case 1:
        addrecord();
        break;

    case 2:
        viewrecord();
        break;

    case 3:
        deleterecord();
        break;

    case 4:
        changepass();
        break;

    case 5:
        printf("\n       Thank you for using software...\n");
        getch();
        exit(0);

    default:
        printf("YOU ENTERED A WRONG KEY\n\n\t");
        printf("Press any key to choose again...");
        getch();
        break;
        }

        system("cls");

    }

    return 0;

}
int addrecord()
{
    system("cls");
    int time[10],date[20];
    char name[25];
    char choose;
    char det[500],plac[25];
    int dur;

    printf("           *****************************\n");
    printf("           ********ADD RECORD***********\n");
    printf("           *****************************\n\n\n\n");
    printf("   (Enter Details...)\n\n\n");

    FILE *ptr;

    ptr=fopen("record","ab+");
  if(ptr==NULL)
        {
            printf("file does not create.");
        }else{
            timea();
            fflush(stdin);

        printf("Enter Name :\t ");
        gets(name);
        fflush(stdin);

        fprintf(ptr,"\nEnter Name :%s\t\n\n",name);

        printf("Duration (in hours) : ");
        scanf("%d",&dur);
        fflush(stdin);


        fprintf(ptr,"Duration(hours) :%d\t\n\n",dur);

        printf("Place :\t ");
        gets(plac);
        fflush(stdin);

        fprintf(ptr,"Place : %s\t\n\n",plac);

        printf("NOTE :\t ");
        gets(det);
        fflush(stdin);

        fprintf(ptr,"NOTE : %s\t\n\n\n",det);

        printf(" Data enter successfully.....\n\n");

        fclose(ptr);

        printf("     Do you want to add more record (Y/N) :");
        scanf("%c",&choose);

        fflush(stdin);

        if(choose=='Y'|| choose=='y')
        {
            addrecord();
        }
        else
        {
            printf("\n\tPress any to return.");
            getch();
        }

    }
    return 0;

}
void viewrecord()
{
    system("cls");
    FILE *ptr;
    char ch;

    printf("           ******************************\n");
    printf("           ********VIEW RECORD MENU******\n");
    printf("           ******************************\n\n\n");

    ptr=fopen("record","rb+");

    if(ptr==NULL)
    {
        printf("   No Record Found...");
        getch();
    }else{
            while(!feof(ptr))
            {
            ch=fgetc(ptr);
            printf("%c",ch);
            }
            getch();
    }
    fclose(ptr);
}

void deleterecord()
{
    system("cls");
    int status;
    int read;

    printf("            *****************************\n");
    printf("            *********Delete Menu*********\n");
    printf("            *****************************\n\n\n");

    printf("1. Delete the whole record\n\n");
    scanf("%d",&read);

    switch(read)
    {
     case 1:

    status=remove("record");
    if(status==0)
    {
        printf("    The records of the file is deleted...........");
        getch();
        break;
    }else{
        printf("      The records is already deleted......");
        getch();
        break;
    }

     default:
        printf("You entered wrong key..\n\n");
        printf("\tPress any key to return");
        getch();
        break;
    }
}

int changepass()
{
        system("cls");

        struct data e;

        FILE *ptr;

        int i=0,l;
        int value=16;
        char password[16];
        char cont[16];
        char ts,ch;

        int j=0;
        char td;
        char cpassword[16];

        int k=0;char er;
        char ccpassword[16];

        printf("                 ********************************\n");
        printf("                 *********PASSWORD MENU**********\n");
        printf("                 ********************************\n\n\n\n");

        printf("Enter the current password :");

        while(1)
        {
            ch=getch();
            if(ch==13)
            {
                break;
            }
            else if(ch==8)
            {
                i--;
                password[i]='\0';
                printf("\b \b");
            }
            else if(ch==32 || ch==9)
            {
                continue;
            }
            else
            {
                if(i<value)
                {
                    password[i]=ch;
                    ch='*';
                    printf("%c",ch);
                    i++;
                }else
                {
                    printf("You exceed the limit, only first 15 character are taken...");
                    getch();
                    break;
                }
            }
        }
        password[i]='\0';

        l=0;

        ptr=fopen("pass","rb");
        if(ptr==NULL)
        {
            printf("Their no password");
        }
        else
        {
            while(!feof(ptr))
            {
                ts=fgetc(ptr);
                cont[l]=ts;
                l++;
            }
        }
        cont[l-1]='\0';
        fclose(ptr);

        strcpy(e.rpassword,cont);

        if(strcmp(e.rpassword,password)==0)
        {
            printf("\n\n\n\t Enter the new password :");

            while(1)
            {
                td=getch();
                if(td==13)
                {
                    break;
                }
                else if(td==8)
                {
                    j--;
                    cpassword[j]='\0';
                    printf("\b \b");
                }
                else if(td==32 || td==9)
                {
                    continue;
                }
                else
                {
                    if(j<16)
                    {

                    cpassword[j]=td;
                    td='*';
                    printf("%c",td);
                    j++;

                    }
                    else
                    {
                        printf("You exceed the limit of the password, only first 15 character are taken..");
                        getch();
                        break;
                    }
                }
            }
            cpassword[j]='\0';

        printf("\n\n\n\t Confirm password :");

        while(1)
        {
            er=getch();
            if(er==13)
            {
                break;
            }
            else if(er==8)
            {
                k--;
                ccpassword[j]='\0';
                printf("\b \b");
            }
            else if(er==32 || er==9)
            {
                continue;
            }
            else
            {
                if(k<16)
                {
                    ccpassword[k]=er;
                    er='*';
                    printf("%c",er);
                    k++;
                }
                else
                {
                    printf("You exceed the limit of the password only 15 character are taken..");
                    getch();
                }
            }
        }

        ccpassword[k]='\0';

        if(strcmp(ccpassword,cpassword)==0)
        {
            ptr=fopen("pass","wb");
            if(ptr==NULL)
            {
                printf("\n\n\tSystem Error...");
            }
            else
            {
                fprintf(ptr,"%s",ccpassword);
                printf("\n\n\t Your password changed successfully..");
                getch();
            }
        }else
        {
            printf("\n\n\tYou enter the wrong password");
            getch();
        }
        }
        else{
            printf("\n\nYou enter the wrong password");
            getch();
        }

        return 0;
}

int timea()
{
    FILE *ptr;
    ptr=fopen("record","ab+");
    time_t a;
      time(&a);
        fprintf(ptr,"Date and Time :  %s",ctime(&a));
        fclose(ptr);
      return 0;
}
