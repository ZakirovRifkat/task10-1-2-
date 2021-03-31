#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define size 80

int main()
{
    setlocale(LC_ALL,"Rus");

    char *str, *istr, *last, *str_copy, *str_copy_2, *str_copy_3, *str_copy_4;

    int i;

    str_copy=(char*)malloc(sizeof(char)*size);
    last=(char*)malloc(sizeof(char)*size);
    str=(char*)malloc(sizeof(char)*size);
    str_copy_2=(char*)malloc(sizeof(char)*size);
    str_copy_3=(char*)malloc(sizeof(char)*size);
    str_copy_4=(char*)malloc(sizeof(char)*size);

    printf("Пожалуйста,введите строку:\n");
    printf("\n");

    FILE *f;

    f=fopen("text.txt","w");

    fgets(str,size,stdin);
    fputs(str,f);

    fclose(f);


    f=fopen("text.txt", "r");
    fscanf(f,"%[^\n]",str);

    strcpy(str_copy, str);
    strcpy(str_copy_2, str);
    strcpy(str_copy_3, str);
    strcpy(str_copy_4, str);
    fclose(f);
    printf("Смотрите результат в text.txt\n");


    f=fopen("text.txt", "w");
    fclose(f);

    f=fopen("text.txt", "a");

    fputs("Введенная строка:\n",f);
    fputs(str,f);
    fputs("\n",f);
    fputs("\nСтрока без лишних пробелов:\n",f);
    istr=strtok(str," ");
    while (istr!= NULL)
    {
        fputs(istr, f);
        istr=strtok (NULL, " ");
        if (istr!=NULL && strcmp(".",istr)!=0)
        {
            fputs(" ",f);
        }

    }
    fputs("\n", f);


    fputs("\nСтрока без последнего слова, совпадающих с ним\n", f);
    char *a=strtok(str_copy_2," .");
    while (a!=NULL)
    {
        last=a;
        a=strtok (NULL," .");
    }


    char *p=strtok(str_copy_3," .");
    int h=0;
    while (p!=NULL)
    {

        if (strcmp(p,last)!=0)
        {
            fputs(p,f);
            for(int i=0; i<strlen(p); i++)
            {
                str_copy_4[h]=p[i];
                h++;
            }
            str_copy_4[h]=' ';
            fputs(" ",f);
            h++;
        }
        p=strtok(NULL," .");
    }
    str_copy_4[h]='\0';

    return 0;

}
