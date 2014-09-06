#ifndef _SORT__H_
#define _SORT__H_

void quickSort(int *a,int start,int end)
{
    int i,j,temp;
    i = start;
    j = end;
    temp = a[start];

    if(i>=j) return ;  //  this condition is easily forgetd

    while(i<j)
    {
        while(a[j]>=temp &&j>i) // j>i  must has
        {
            j--;
        }
        a[i]=a[j];
        i++;

        while(a[i]<=temp &&j>i)
        {
            i++;
        }
        a[j]=a[i];
        j--;
    }

    a[i] = temp;        
    quickSort(a,start,i-1);  // start != 0
    quickSort(a,i+1,end);
}

void merge( int *data,int start, int mid, int end )
{
   int *temp = (int*) malloc((end-start+1)*sizeof(int));
   int i = start ;
   int j = mid+1 ;
   int k = 0 ; 

   while( i <= mid && j <= end )
   {   
      temp[k++] = (data[i]<=data[j])?data[i++]:data[j++] ;
   }   

   while( i <= mid )
   {   
      temp[k++] = data[i++] ;
   }   

   while( j <= end )
   {   
      temp[k++] = data[j++] ;
   }   

   k = 0 ; 

   // i start's with start, k start's with 0
   for( i = start; i <= end; i++ )
   {   
      data[i] = temp[k++] ;
   }   

   free( temp ) ; 
}

void mergeSort(int *data, int start,int end )
{
   if (start == end)
   {
      return ;
   }

   int mid = (end+start)/2 ;
   mergeSort(data,start,mid);
   mergeSort(data,mid+1,end);
   merge(data,start,mid,end);
}

#endif
