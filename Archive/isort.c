#include "main.h"

void sort_integer_array(int *begin, int *end, int ascending);

int main(void)
{
   srandom(time(NULL));
   int size = 0;

   printf("size array : ");
   scanf("%d", &size);

   int* original = (int*)malloc(size * sizeof(int));
   int *ascending1 = (int*)malloc(size * sizeof(int));
   int *descending = (int*)malloc(size * sizeof(int));

   if(original == NULL) 
   {
       perror("malloc failed");
       exit(1);
   }
   if(ascending1 == NULL) 
   {
       perror("malloc failed");
       exit(1);
   }
   if(descending == NULL) 
   {
       perror("malloc failed");
       exit(1);
   }

   int i;
   for(i = 0; i < size; i++ )
   {
       original[i] = random()%100;
   }

   printf("original: ");
   for(i = 0; i < size; i++ )
   {
       printf("%d ",original[i]);
   }

   free(original);

   for(i = 0; i < size; i++)
   {
       ascending1[i] = original[i];
   }
   
   sort_integer_array(ascending1, ascending1 + size + 1, 1);

   for(i = 0; i < size; i++)
   {
       descending[i] = original[i];
   }

   sort_integer_array(descending, descending + size + 1, 0);


   printf("\nascending: ");
   for(i = 0; i < size; i++)
   {
       printf("%d ",ascending1[i]);
   }

   printf("\ndescending: ");
   for(i = 0; i < size; i++)
   {
       printf("%d ",descending[i]);
   }

   printf("\n");
   
   free(ascending1);
   free(descending);
   
}
int Asc(const void *start, const void *ending)
{
   const int *s= (const int *)start;
   const int *e = (const int *)ending;
   return *s - *e;
}

int Des(const void *start, const void *ending)
{
   const int *s = (const int *)start;
   const int *e = (const int *)ending;
   return *e - *s;
}

void sort_integer_array(int *begin, int *end, int ascending)
{
    int difference = end-begin;
   if(ascending == 1)
   {
       qsort(begin, difference-1, sizeof(int), Asc);
   }else if(ascending == 0)
   {
       qsort(begin, difference-1, sizeof(int), Des);
   }
}