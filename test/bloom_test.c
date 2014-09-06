#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "bloom.h"

unsigned int sax_hash(const char *key)
{
   unsigned int h=0;

   while(*key) h^=(h<<5)+(h>>2)+(unsigned char)*key++;

   return h;
}

unsigned int sdbm_hash(const char *key)
{
   unsigned int h=0;
   while(*key) h=(unsigned char)*key++ + (h<<6) + (h<<16) - h;
   return h;
}

int main( int argc ,char **argv )
{
   FILE *fp ;
   char line[1024] ;
   char *p ;
   bloom_t *bloom ;
   
   if( argc < 2 )
   {
      fprintf(stderr,"Error: No word file specified.\n") ;
      return -1 ;
   }

   if(!(bloom=bloomCreate(2500000, 2, sax_hash, sdbm_hash)))
   {
      fprintf(stderr, "Error: Could not create bloom filter.\n") ;
      return -1 ;
   }

   if(!(fp=fopen(argv[1],"r")))
   {
      fprintf(stderr,"Error: Could not open file.\n") ;
      return -1 ;
   }

   while(fgets(line,1024,fp))
   {
      if((p=strchr(line,'\r'))) *p = '\0' ;
      if((p=strchr(line,'\n'))) *p = '\0' ;

      bloomAdd(bloom,line) ;
   }

   fclose(fp) ;

   while(fgets(line, 1024, stdin))
   {
      if((p=strchr(line,'\r'))) *p = '\0' ;
      if((p=strchr(line,'\n'))) *p = '\0' ;

      if(strcmp(line,"quit")==0)
      {
         break ;
      }
      p = strtok(line, "\t,.;:\r\n?!-/()") ;
      while(p)
      {
         if(!bloomCheck(bloom,p))
         {
            printf("No match for word \"%s\"\n",p) ;
         }
         else  
            printf("%s is match.\n",p) ;
   
         p = strtok(NULL, "\t,.;:\r\n?!-/()") ;
      }
   }
   
   bloomDestroy(bloom) ;
   return 1 ;
}

