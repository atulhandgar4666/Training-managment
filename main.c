#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void adminLogin();
void adminModules();
void addTrainer();
void createSchedule();
void updateSchedule();
void allotTrainer();
void generateReport();
void facultyLogin();
void facultyModules();
void viewSchedule();
void cancelSchedule();

struct Schedule{
  int BatchID;
  char Technology[20];
  char StartDate[20];
  char EndDate[20];
  int Days;
  char Venue[20];
  int Participants;
  char Month[20];
};
struct admin{
    char UserName[30];
    char Password[20];
};
// struct faculty{
//     char TechnologyName[30];
//     char FacultyName[30];
//     char Password[30];
// };
struct Trainer{
    char TrainerName[20];
    char Password[20];
    char TechnologyName[20];
};
int num=0;
int main(){
    int choice;
    printf("\n------------------------------------------------------"); 
    printf("\n      Training Schedule Management System             ");
    printf("\n------------------------------------------------------");
    printf("\nWelcome To Home Page");
    printf("\nPress 1 --> Admin Login");
    printf("\nPress 2 --> Faculty Login");
    printf("\nPress 3 --> Exit");
    printf("\nPlease Enter Your Choice : ");
    scanf("%d",&choice);
    switch (choice)
        {
        case 1:
            adminLogin();
            
            break;
        case 2:
            facultyLogin();
            
            break;
        case 3:
            printf("See you again.");
            break;
        default:
            printf("\nPlease select from the options given above");
            main();
        }
    return 0;
}
void adminLogin()       
{
   
    char id[30];
    char pass[20];
    printf("\n----------------------------------------");
    printf("\n         Welcome To The Admin Page      ");
    printf("\n----------------------------------------");
    printf("\nPlease Enter Your Username & Password For Authentiocation");

    printf("\nEnter Your Username : ");
    scanf("%s",id);

    printf("\nEnter Your Password : ");
    scanf("%s",pass);

    if (strcmp(id,"admin")==0 && strcmp(pass,"12345")==0)
    {
        printf("\nCongratulations %s",id);
        printf("\nYour login as administrator is successfull. Thanks for logging in.\n");
         int choice;
         printf("press 1--> to open admin modules ");
         printf("\npress 2--> To add Trainer ");
         printf("\nEnter admin choice : ");
         scanf("%d",&choice);
         switch(choice){
             case 1:
                 adminModules();
                 break;
            case 2:
                addTrainer();
                
                break;
            default:
                printf("Enter the correct choice : ");
                main();
         }
        
    }
    else
    {
        printf("\n!!!Login Error!!!");
        printf("Please check your username and password again\n");
             
        num += 1;
        if (num == 3)
        {
            printf("\nACCESS DENIED");
           
        }
        main();
    }
}
void adminModules()
    {
        printf("\nHere's your Dashboard \nPlease enter your choice to perform particular tasks");
        printf("\n-------------------------------------------------------");
        printf("\nEnter 1 -> To Create New Schedule");
        printf("\nEnter 2 -> To Update Existing Schedule");
        printf("\nEnter 3 -> To Allot A Trainer");
        printf("\nEnter 4 -> To Generate Report");
        printf("\nEnter 5 -> To Quit From This Session");
        printf("\n--------------------------------------------------------");

        int choice;
        printf("\nPlease enter your choice : ");
        scanf("%d",&choice);

        
            switch (choice)
            {
            case 1:
                createSchedule();
                
                break;
            case 2:
                updateSchedule();
               
                break;
            case 3:
                allotTrainer();
                
                break;
            case 4:
                generateReport();
                
                break;
            case 5:
                int n;
                printf("\nWhere you want to move \nPlease choose from below options");
                printf("\nChoose 1 -> Go Back To Dashboard \nChoose 2 -> Exit From The System");

                printf("\nPlease enter your choice here : ");
                scanf("%d",&n);

                if (n == 1)
                {
                    adminModules();
                }
                else if (n == 2)
                {
                    printf("See you again");
                    
                }
                else
                {
                    printf("Please choose correct option");
                    adminModules();
                }
                break;

            default:
                printf("Please choose valid Option");
                adminModules();
                break;
            }
            main();
        
    }
void createSchedule()     
    {
        struct Schedule s;
        int BatchID,Days,Participants;
        char Technology[20];
        char StartDate[20],EndDate[20],Venue[20],Month[10];
        printf("\nBelow are the mandatory details for creating new schedule");
        printf("\n1. Batch Id                        2. Technology Name");
        printf("\n3. Start Date                      4. End Date");
        printf("\n5. Total Number of Days            6. Venue Details");
        printf("\n7. No. of Participants             8. Month");

        printf("\nNow please enter the details below carefully.");

        printf("\nEnter the batch id : ");
        scanf("%d",&s.BatchID);
        
        printf("\nEnter Technology Name : ");
        scanf("%s",&s.Technology);
        // gets(s.Technology);
        
        printf("\nEnter Start Date : ");
        scanf("%s",&s.StartDate);
        struct tm date;
             if(strptime(s.StartDate,"%d-%m-%Y",&date) == NULL){
                printf("\nInvalid Date Format");
                createSchedule();
            }
        
        printf("\nEnter End Date : ");
        scanf("%s",&s.EndDate);
            if(strptime(s.EndDate,"%d-%m-%Y",&date) == NULL){
                printf("\nInvalid Date Format");
                createSchedule();
            }
        
        printf("\nEnter Total Number of Days : ");
        scanf("%d",&s.Days);
        
        printf("\nEnter Venue details : ");
        scanf("%s",&s.Venue);
        // gets(s.Venue);
        
        printf("\nEnter No of Participants : ");
        scanf("%d",&s.Participants);
        
        printf("\nEnter Month : ");
        scanf("%s",&s.Month);
        
        FILE *fptr;
        fptr=fopen("createSchedule.txt","a");
        if(fptr!=NULL){
            printf("File created successfull");
        }
        else{
            printf("Error in opening file");
        }
        fseek(fptr,0,SEEK_END);
        fprintf(fptr,"%d %s %s %s %d %s %d %s\n",s.BatchID,s.Technology,s.StartDate,s.EndDate,s.Days,s.Venue,s.Participants,s.Month);
        fseek(fptr,0,SEEK_END);
        // char opt[4];

        // printf("\nDo you want to create another schdedule (yes/no) : ");
        // scanf("%s",opt);

        // if (opt == "yes" || opt == "y" || opt == "YES" || opt == "Y")
        // {
        //     createSchedule();
        // }
        // else
        // {
        //     adminModules();
        // }
        fclose(fptr);
        
    }

void updateSchedule(){
    struct Schedule s1;
    FILE *fp1,*fp2;
    int BatchID;
    printf("Enter batch id to be update");
    scanf("%d",&BatchID);
    
    fp1=fopen("createSchedule.txt","r");
    fp2=fopen("copy.txt","w");
    if(fp1==NULL){
        printf("ERROR");
        exit(0);
    }
    while(fscanf(fp1,"%d %s %s %s %d %s %d %s\n",&s1.BatchID,s1.Technology,s1.StartDate,s1.EndDate,&s1.Days,s1.Venue,&s1.Participants,s1.Month)!=EOF){
        if(s1.BatchID!=BatchID){
          
             fprintf(fp2,"%d %s %s %s %d %s %d %s\n",s1.BatchID,s1.Technology,s1.StartDate,s1.EndDate,s1.Days,s1.Venue,s1.Participants,s1.Month);
           
        }
        else if(s1.BatchID==BatchID){
            struct Schedule s2;
            printf("\nEnter the batch id : ");
            scanf("%d",&s2.BatchID);
            
            printf("\nEnter Technology Name : ");
            scanf("%s",&s2.Technology);
            
            printf("\nEnter Start Date : ");
            scanf("%s",&s2.StartDate);
            
            printf("\nEnter End Date : ");
            scanf("%s",&s2.EndDate);
            
            printf("\nEnter Total Number of Days : ");
            scanf("%d",&s2.Days);
            
            printf("\nEnter Venue details : ");
            scanf("%s",&s2.Venue);
            
            printf("\nEnter No of Participants : ");
            scanf("%d",&s2.Participants);
            
            printf("\nEnter Month : ");
            scanf("%s",&s2.Month);
            fprintf(fp2,"%d %s %s %s %d %s %d %s\n",s2.BatchID,s2.Technology,s2.StartDate,s2.EndDate,s2.Days,s2.Venue,s2.Participants,s2.Month);
            
        }
        else{
            printf("exit");
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("createSchedule.txt");
    rename("copy.txt","createSchedule.txt");
}
    void addTrainer(){
        struct Trainer t;
        int TrainerId;
        char Password[20];
        int choice;
        printf("Enter Trainer Name : ");
        scanf("%s",&t.TrainerName);
        
        printf("Enter Trainer password : ");
        scanf("%s",&t.Password);
        
        printf("Enter Trainer Technology :");
        scanf("%s",&t.TechnologyName);
        
        FILE *fp;
        fp=fopen("FacultyList.txt","a");
        if(fp!=NULL){
            printf("File created successfull");
        }
        else{
            printf("Error in opening file");
        }
        fseek(fp,0,SEEK_END);
        fprintf(fp,"%s %s %s\n",t.TrainerName,t.Password,t.TechnologyName);
        fseek(fp,0,SEEK_END);
        printf("\n press 1---> addTrainer");
        printf("\n press 2---> adminLogin");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addTrainer();
                break;
            default:
                adminLogin();
                break;
        }
    }
    void allotTrainer(){
        struct Schedule s1;
        struct Trainer t;
        char Trainer[20];
        char techName[20];
        int BatchID;
        int flag = 0;
        printf("\n Please enter a faculty name : ");
        scanf("%s",Trainer);
       
        printf("\n Please enter a technology name for which you want to assign tariner : ");
        scanf("%s",techName);
        
        printf("\n Please Enter BatchID to which Trainer to be allocate");
        scanf("%d",&BatchID);
        FILE *FL,*CS,*FA;
        FL=fopen("FacultyList.txt","r");
        CS=fopen("createSchedule.txt","r");
        FA=fopen("FacultyAllotment.txt","a");
        while(fscanf(CS,"%d %s %s %s %d %s %d %s\n",&s1.BatchID,s1.Technology,s1.StartDate,s1.EndDate,&s1.Days,s1.Venue,&s1.Participants,s1.Month)!=EOF){
            if(strcmp(s1.Technology,techName)==0 && s1.BatchID==BatchID ){
                   flag=1;
               }
            if(flag==1){
            while(fscanf(FL,"%s %s %s",t.TrainerName,t.Password,t.TechnologyName)!=EOF){
                if(strcmp(t.TechnologyName,techName)==0 && strcmp(t.TrainerName,Trainer)==0){
                    flag=2;
                }
                if(flag==2){
                
                fprintf(FA,"%d %s %s %s %d %s %d %s %s\n",s1.BatchID,s1.Technology,s1.StartDate,s1.EndDate,s1.Days,s1.Venue,s1.Participants,s1.Month,t.TrainerName);
                printf("\nsuccessfull allotment is done"); 
                flag=0;
                }
            }
        }
        }
        fclose(FL);
        fclose(CS);
        fclose(FA);
    }
    void generateReport(){
        struct Schedule s;
        // int BatchID;
        char Month[20];
        int flag=0;
        printf("Enter the Month to generateReport : ");
        // scanf("%d",&BatchID);
        scanf("%s",Month);
        FILE *GR;
        GR=fopen("createSchedule.txt","r");
        while(fscanf(GR,"%d %s %s %s %d %s %d %s\n",&s.BatchID,s.Technology,s.StartDate,s.EndDate,&s.Days,s.Venue,&s.Participants,s.Month)!=EOF)
        {
            
            // if(s.BatchID==BatchID &&flag==0){
            if(strcmp(s.Month,Month)==0){
                flag=1;
                
            }
            if(flag==1){
                printf("\nBatchID : %d",s.BatchID);
                printf("\nTechnology : %s",s.Technology);
                printf("\nStart Date : %s",s.StartDate);
                printf("\nEndDate : %s",s.EndDate);
                printf("\nNumOfDays : %d",s.Days);
                printf("\nVenue Details : %s",s.Venue);
                printf("\nNumber of Participants : %d",s.Participants);
                printf("\nMonth : %s",s.Month);
                flag=0;
            }
        }
        fclose(GR);
    }
void facultyLogin(){
    int num=0;
    char id[30];
    char pass[20];
    printf("\n----------------------------------------");
    printf("\n         Welcome To The Faculty Page      ");
    printf("\n----------------------------------------");
    printf("\nPlease Enter Your Username & Password For Authentiocation");

    printf("\nEnter Your Username : ");
    scanf("%s",id);

    printf("\nEnter Your Password : ");
    scanf("%s",pass);
    struct Trainer t;
    FILE *fp;
    fp=fopen("FacultyList.txt","r");
    while(fscanf(fp,"%s %s %s",t.TrainerName,t.Password,t.TechnologyName)!=EOF){
        if(strcmp(t.TrainerName,id)==0 && strcmp(t.Password,pass)==0){
            printf("faculty Login successfull");
            facultyModules();
        }
        // else{
        //     printf("\n!!!Login Error!!!");
        //     printf("\nPlease check your username and Password again");
        //     num+=1;
        //     if(num==3){
        //         printf("\n ACCESS DENIED");
        //         exit(0);
        //     }
            
        // }
    }
    fclose(fp);
}
 void facultyModules()
    {
        printf("\nHere's your Dashboard \nPlease enter your choice to perform particular tasks");
        printf("\n------------------------------------");
        printf("\nEnter 1 -> To View Schedule");
        printf("\nEnter 2 -> To Cancel Schedule");
        printf("\nEnter 3 -> To Quit From This Session");
        printf("\n------------------------------------");

        int choice;
        printf("\nPlease enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                viewSchedule();
                break;
            case 2:
                 cancelSchedule();
                 break;
            case 3:
                printf("see you again..");
                exit(0);
                break;
            default:
                printf("Please selectthe choice from the above...");
                facultyModules();
        }
        
    }
    void viewSchedule(){
        char name[20];
        printf("\n Enter Your Name : ");
        scanf("%s",name);
        struct Schedule s;
        struct Trainer t;
        int flag=0;
        int n=1;
        FILE *VS;
        VS=fopen("FacultyAllotment.txt","r");
        while(fscanf(VS,"%d %s %s %s %d %s %d %s %s\n",&s.BatchID,s.Technology,s.StartDate,s.EndDate,&s.Days,s.Venue,&s.Participants,s.Month,t.TrainerName)!=EOF)
        {
            if(strcmp(t.TrainerName,name)==0){
                flag=1;
            }
            if(flag==1){
                printf("\nBatch Number %d : ",n);
                printf("\nBatchID : %d",s.BatchID);
                printf("\nTechnology : %s",s.Technology);
                printf("\nStart Date : %s",s.StartDate);
                printf("\nEndDate : %s",s.EndDate);
                printf("\nNumOfDays : %d",s.Days);
                printf("\nVenue Details : %s",s.Venue);
                printf("\nNumber of Participants : %d",s.Participants);
                printf("\nMonth : %s",s.Month);
                printf("\n---------------------------");
                flag=0;
                n=n+1;
            }
        }
        fclose(VS);
        
    }
    
    void cancelSchedule(){
        struct Schedule s;
        struct Trainer t;
        viewSchedule();
        int BatchID;
        printf("\nEnter BatchID you want cancelSchedule");
        scanf("%d",&BatchID);
        FILE *CS,*RC;
        CS=fopen("FacultyAllotment.txt","r");
        RC=fopen("copy.txt","a");
        if(CS==NULL || RC==NULL){
            printf("ERROR");
            exit(0);
        }
        while(fscanf(CS,"%d %s %s %s %d %s %d %s %s\n",&s.BatchID,s.Technology,s.StartDate,s.EndDate,&s.Days,s.Venue,&s.Participants,s.Month,t.TrainerName)!=EOF)
        {
           if(s.BatchID!=BatchID){
               fprintf(RC,"%d %s %s %s %d %s %d %s %s\n",s.BatchID,s.Technology,s.StartDate,s.EndDate,s.Days,s.Venue,s.Participants,s.Month,t.TrainerName);
                printf("Schedule Canceled successfully....");
           } 
        
        }
        fclose(CS);
        fclose(RC);
        remove("FacultyAllotment.txt");
        rename("copy.txt","FacultyAllotment.txt");
        main();
    }