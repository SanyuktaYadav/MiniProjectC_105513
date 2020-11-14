#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* function for reading particular field from csv file */
const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;

}


/*function to show question and answer, user input, and calculate marks */
int quiz_QnA(FILE *stream){
    char line[1024];
    int marks = 0;
    while (fgets(line, 1024, stream)){
        int correct_ans, ans;
        char* tmp1 = strdup(line);
        printf("\n%s\n", getfield(tmp1, 1));
        char* tmp2 = strdup(line);
        printf("%d) %s\n",1,getfield(tmp2, 2));
        char* tmp3 = strdup(line);
        printf("%d) %s\n",2,getfield(tmp3, 3));
        char* tmp4 = strdup(line);
        printf("%d) %s\n",3,getfield(tmp4, 4));
        char* tmp5 = strdup(line);
        printf("%d) %s\n",4,getfield(tmp5, 5));
        char* tmp6 = strdup(line);
        correct_ans = atoi(getfield(tmp6, 6));
        scanf("%d",&ans);

        if(ans==correct_ans){
            printf("Correct\n");
            marks++;
            }
        else
            printf("Wrong\n");
        printf("\n");

        free(tmp1);
        free(tmp2);
        free(tmp3);
        free(tmp4);
        free(tmp5);
        free(tmp6);
    }
    return marks;
}



int main()
{
    int choice, i;

    int c_final_marks = 0;
    int cpp_final_marks = 0;
    int python_final_marks = 0;
    int sql_final_marks = 0;

    int c_percent = 0;
    int python_percent = 0;
    int cpp_percent = 0;
    int sql_percent = 0;

    char name[100];

    printf("Hi Guest!!\n");
    printf("Please Enter your name: ");
    scanf("%s", name);

    int ch;
    printf("\n%s, Welcome to the Programming Quiz!! \n", name);

    while(1){
        printf("\nType 1 if want to continue, type any other number to exit: ");
        scanf("%d", &ch);
        if(ch == 1){
            printf("\nSections \n");
            printf("--------------------------------------------------------------------------\n");
            printf("|1. C                                                                    |\n");
            printf("|2. C++                                                                  |\n");
            printf("|3. Python                                                               |\n");
            printf("|4. SQL                                                                  |\n");
            printf("|5. Report                                                               |\n");
            printf("--------------------------------------------------------------------------\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice){
                case 1: printf("\n*******Section C*******");
                        FILE* stream_c = fopen("c_file.csv", "r");
                        c_final_marks = quiz_QnA(stream_c);
                        printf("\nC Total Marks = %d", c_final_marks);

                        break;
                case 2: printf("\n*******Section CPP*******");
                        FILE* stream_cpp = fopen("cpp_file.csv", "r");
                        cpp_final_marks = quiz_QnA(stream_cpp);
                        printf("\nCPP Total Marks = %d", cpp_final_marks);
                        break;

                case 3: printf("\n*******Section Python*******");
                        FILE* stream_python = fopen("python_file.csv", "r");
                        python_final_marks = quiz_QnA(stream_python);
                        printf("\nPython Total Marks = %d", python_final_marks);
                        break;

                case 4: printf("\n*******Section SQL*******");
                        FILE* stream_sql = fopen("sql_file.csv", "r");
                        sql_final_marks = quiz_QnA(stream_sql);
                        printf("\nSQL Total Marks = %d", sql_final_marks);
                        break;

                case 5: printf("\nYour Report: %s", name);


                        c_percent = c_final_marks * 100 / 5;
                        cpp_percent = cpp_final_marks * 100 / 5;
                        python_percent = python_final_marks * 100 / 5;
                        sql_percent = sql_final_marks * 100 / 5;


                        printf("c_percent = %d", c_percent);
                        printf("cpp_percent = %d", cpp_percent);
                        printf("python_percent = %d", python_percent);
                        printf("sql_percent = %d", sql_percent);

                        printf("\nC percentage = %d%%\n", c_percent);
                        if(c_percent == 0){
                                printf("Please work hard on C...\n");
                                break;
                            }
                        for (i = 0;i<c_percent; i++){
                            printf("|");
                        }

                        printf("\n");

                        printf("\nCPP percentage = %d%%\n", cpp_percent);
                        if(cpp_percent == 0){
                            printf("Please work hard on CPP...\n");
                        }
                        for (i = 0;i<cpp_percent; i++){
                            printf("|");
                        }


                        printf("\n");
                        printf("\nPython percentage = %d%%\n", python_percent);
                        if(python_percent == 0){
                                printf("Please work hard on Python...\n");
                            }
                        for (i = 0;i<python_percent; i++){
                            printf("|");
                        }


                        printf("\n");


                        printf("\n");
                        printf("\nSQL percentage = %d%%\n", sql_percent);
                        if(sql_percent == 0){
                                printf("Please work hard on SQL...\n");
                            }
                        for (i = 0;i<sql_percent; i++){
                            printf("|");
                        }
                        printf("\n");

                        printf("Goal has to be......\n");
                        printf("Language percentage = %d%%\n", 100);
                        for (i = 0;i<100; i++){
                            printf("|");
                        }
                        printf("\n");
                        break;


                default:printf("Invalid Choice");
                        break;
        }
        }
        else{
            break;
        }

    }
   
    return 0;
}




