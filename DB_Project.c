#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct employee
{
    int id;
    char name[20];
    int salary;
};

void append();
void display();
void modify();
void delete();
void search();
void re_name();
void re_move();

int main(void)
{
    int choice;
    while(1)
    {
        printf("Employee Management System");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:append();
                break;
            case 2:display();
                break;
            case 3:modify();
                break;
            case 4:delete();
                break;
            case 5:search();
                break;
            case 6:re_name();
                break;
            case 7:re_move();
                break;
        }
    }
}

void append()
{
    struct employee emp;
    FILE *fp;
    fp=fopen("employee.txt","ab");
    printf("Enter employee ID: ");
    scanf("%d",&emp.id);
    printf("\nEnter name: ");
    scanf("%s",&emp.name);
    printf("\nEnter salary");
    scanf("%d",&emp.salary);
    fwrite(&emp,1,sizeof(emp),fp);
    fclose(fp);
}

void display()
{
    struct employee emp;
    int count,e_id;
    FILE *fp;
    fp=fopen("employee.txt","rb");
    printf("\nEnter employee ID");
    scanf("%d",&e_id);
    while (1)
    {
        fread(&emp,1,sizeof(emp),fp);
        if(feof(fp))break;
        if(emp.id==e_id)
        {
            count=1;
            printf("\nDetails of employee ID %d is\n",emp.id);
            printf("%s\n\n",emp.name);
            printf("%d\n\n",emp.salary);
            //break;
        }
    }
    if(count==0)
    printf("\nNo record found\n");
    fclose(fp);
}

void modify()
{
    struct employee emp;
    FILE *fp,*fp1;
    fp=fopen("employee.txt","rb");
    fp1=fopen("temp.txt","wb");
    int count=0,e_id,choice;
    char s[20];
    printf("Enter employee ID: ");
    scanf("%d",&e_id);
    while(fread(&emp,1,sizeof(emp),fp))
    {
        //fread(&emp,1,sizeof(emp),fp);
        //printf("%d\t%s\t%d\n",emp.id,emp.name,emp.salary);
        if(emp.id==e_id)
        {
            printf("1.Change Name\t2.Change salary");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\nEnter name: ");
                scanf("%s",&emp.name);
                //emp.name[count]=s;
                fwrite(&emp,1,sizeof(emp),fp1);
            }
        }
        else
        fwrite(&emp,1,sizeof(emp),fp1);
        count++;
    }
    fclose(fp);
    fclose(fp1);
    //remove("employee.txt");
    //rename("temp.txt","employee.txt");

    //remove("employee.txt");
    //rename("temp.txt","employee.txt");
    fp=fopen("employee.txt","wb");
    fp1=fopen("temp.txt","rb");
    while(fread(&emp,1,sizeof(emp),fp1))
    {
    	//fread(&emp,1,sizeof(emp),fp1);
    	fwrite(&emp,1,sizeof(emp),fp);
	}

    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    fp=fopen("employee.txt","rb");
    while(fread(&emp,1,sizeof(emp),fp))
    {
    	//fread(&emp,1,sizeof(emp),fp);
    	printf("%d\t%s\t%d\n",emp.id,emp.name,emp.salary);
	}
	fclose(fp);
}

void delete()
{
    FILE *fp,*fp1;
    fp=fopen("employee.txt","rb");
    fp1=fopen("temp.txt","wb");
    struct employee emp;
    int e_id;
    printf("Enter employee ID you want to delete: ");
    scanf("%d",&e_id);
    while (fread(&emp,1,sizeof(emp),fp))
    {
        if(emp.id==e_id)continue;
        fwrite(&emp,1,sizeof(emp),fp1);
    }
    fclose(fp);
    fclose(fp1);
    remove("employee.txt");
    rename("temp.txt","employee.txt");
}

void search()
{
    FILE *fp;
    fp=fopen("employee.txt","rb");
    struct employee emp;
    char s[20];
    printf("Enter employee name: ");
    scanf("%s",&s);
    while (fread(&emp),1,sizeof(emp),fp)
    {
        if(strcmp(s==emp.name))
        printf("Employee details of %s is",s);
        printf("\nName= %s",emp.name);
        printf("\nID= %d",emp.id);
        printf("\nSalary= %d",emp.salary);
    }
}

void re_name()
{

}

void re_move()
{

}
