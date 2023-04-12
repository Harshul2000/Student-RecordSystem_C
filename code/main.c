#include<stdio.h>
#include<conio.h>
void add();
void display();
void del();
int emp_no, year, salary,name, city;
struct employee
{
 int emp_no,year,salary;
 char name[20];
 char city[40];
}emp;
void main()
{
 int choice;
 
 {
  printf("\t\tMain Menu\n");
  printf("\t\t1.Add\n");
  printf("\t\t2.Display record\n");
  printf("\t\t3.Delete\n");
  again:
  printf("Enter choice");
  scanf("%d",&choice);
  if(choice==1)
  {
   void add()
   {
    FILE*fp;
    fp=fopen("Employee","a");
    printf("enter ID,year,salary,name and city");
    scanf("%d%d%d%s%s",&emp_no,&year,&salary,&name,&city);
    fwrite(&emp,sizeof(emp),1,fp);
    fclose(fp);
    };
  }
    else
       {
       if(choice==2)
    {
     void display()
      {
       FILE*fp1;
        int r,s,avl;
         printf("Enter Employee id to display");
         scanf("%d",&r);
         avl=avlemp_no(r);
         if(avl==0)
          printf("Does not exist\n");
          else
        {
         fp1=fopen("Employee","r");
         while(fread(&emp,sizeof(emp),1,fp1))
          {
           s=emp.emp_no;
           if(s==r)
            {
             printf("\n employeeID %d",emp.emp_no);
             printf("\nname is %s",emp.name);
             printf("\ year is %d",emp.year);
             printf("\n salary is %d",emp.salary);
             printf("\n city is %s",emp.city);

            }
            }
            fclose(fp1);
          }
         };
        }
        else
          {
           if(choice==3)
           {
            void del()
             {
              FILE*fpo;
              FILE*fpt;
              int r,s,avl;
              printf("Enter id to delete");
              scanf("%d",&r);
              if(avlemp_no(r)==0)
               printf("Not available");
               else
             {
              fpo=fopen("Employee","w");
              fpt=fopen("TempFile","r");
              while(fread(&emp,sizeof(emp),1,fpo))
              {
               s=emp.emp_no;
               if(s!=r)
               fwrite(&emp,sizeof(emp),1,fpt);
              }
              fclose(fpo);
              fclose(fpt);
              fpo=fopen("Employee","w");
              fpt=fopen("TempFile","r");
              while(fread(&emp,sizeof(emp),1,fpt))
               fwrite(&emp,sizeof(emp),1,fpo);
               printf("\nRecord Deleted\n");
               fclose(fpo);
               fclose(fpt);
              }
             };
               }
               else
            {
             printf("invalid choice");
            }

              }
            }
          }
          getch();
        }