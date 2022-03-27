/*
Program to unshadow passwd and shadow files
Usage : ./unshadow <shadow file> <passwd file>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 
int main(int argc, char *argv[])
{
    char c[1000],c1[1000];
    FILE *file1,*file2,*file3;

  file1 = fopen(argv[1], "r"); //shadow
  if(file1==NULL)
    {
    printf("Error in file opening");
    exit(0);
    }
  file2 = fopen(argv[2], "r"); //passwd
  if(file2==NULL)
    {
    printf("Error in file opening");
    exit(0);
    }
  file3 = fopen("passwordfile.txt","w"); //File to which result is stored
  if(file3==NULL)
    {
    printf("Error in file creation");
    exit(0);
    }
int lines = 8196; // Number of lines in passwd/shadow file
while (lines)
{

    fgets(c,1000,file1);  // syntax : char *fgets(char *str, int n, FILE *stream)
      char str1[1000];
      strcpy (str1,c);
      char *token = strtok(str1, ":");
      int i=0;
      char var[20];
      
      while (token != NULL)
      {
      if(i==1)
      {
          strcpy (var,token);
        }
          token = strtok(NULL, ":");
      i++;
      }

    fgets(c1,1000,file2);
    char str[1000];
    strcpy (str,c1);
    char *token1 = strtok(str, ":");

    char temp[1000];
    strcpy (temp,"");
    while (token1 != NULL)
    {
      if (strcmp (token1,"x")!=0)
      {
      strcat(temp,token1);
      strcat(temp,":");
      }
      else
      {
        strcat(temp,var);
        strcat(temp,":");
      }

        token1 = strtok(NULL, ":");

    }

  fputs(temp,file3);
  lines--;
}

    fclose(file1);
    return 0;
}
