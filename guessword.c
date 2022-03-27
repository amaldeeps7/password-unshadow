/*
Creating hashes and finding username:password using comparison
Usage : ./md5crack <dictionary file> <unshadow file>
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#include <time.h>
int main(int argc, char *argv[])
{
  char c[1000],*temp,d[1000];

/*
//getopt
while((option = getopt(argc, argv, ":i:d:o:")) != -1)
    {
      switch (option)
      {
      case 'i':
        ar = optarg;
        break;

      case 'd':
        br = optarg;

      case 'o':
      cr= optarg;  
      break;
      default:
        break;
      }
    }
//The program shows error while using getopt, hence commented the section
*/

  FILE *file1,*file2,*file3,*foutput;
  file1 = fopen(argv[1], "r");
  if(file1==NULL)
    {
    printf("Error in file opening");
    exit(0);
    }
  file2 = fopen("passhash.txt","w"); // Hash of plain text in file1 is saved here
  foutput=fopen("allcrackpasswd.txt","w"); //File to which output is saved
  int count=0;

//time check
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

//Extracting each line of file1 - dictionary file and store in token and which inturn store in var one by one
  while (fgets(c,1000,file1))
{
  char str1[1000];
  strcpy (str1,c);
  char *token = strtok(str1, "\t\n");
  int i=0;
  char var[20];

  while (token != NULL)
  {
  if(i==3)
  {
      strcpy (var,token);
    }
      token = strtok(NULL, "\t\n");

  i++;
  }
temp = crypt(var,"$1$GC"); //creating md5 hashes from dictionary file

fputs(temp,file2);
fputs("\n",file2);
file3 = fopen(argv[2],"r"); //opens the unshadow file
if(file1==NULL)
    {
    printf("Error in file opening");
    exit(0);
    }
while(fgets(d,1000,file3))
{
  char str1[1000];
  strcpy (str1,d);
  char *token = strtok(str1, ":");
  int i=0;
  char var1[20],var2[20];
  
  while (token != NULL)
  {
  if(i==0)
  {
      strcpy (var1,token);
    }
    if(i==1)
    {
        strcpy (var2,token);
      }
      token = strtok(NULL, ":");

  i++;
}
//comparing the hash values
  if (strcmp(var2,temp)==0){
    count++;
    printf ("%d:%s:%s\n",count,var1,var);
    fputs(var1,foutput);
    fputs(":",foutput);
    fputs(var,foutput);
    fputs("\n",foutput);
  }
}
fclose (file3);
}

//Details of execution
printf("\n");
printf("Number of users cracked : %d\n\n",count ); //Prints the number of passwords cracked
//get runtime
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e6 + (stop.tv_nsec - start.tv_nsec) / 1e3;    // time in microseconds
    
    printf("===============\nElapsed Time: %lf sec\n\n",elapsed/1000000); //printing detailes about time taken for execution in seconds
    return 0;
    }
