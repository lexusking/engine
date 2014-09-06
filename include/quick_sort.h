void qsort(int a,int start,int end)
{
    int i,j,temp;
    i = start;
    j = end;
    temp = a[start];

    if(i>=j) return ;  // 这步经常会忘记写，忘记写的话，每次都会进入到后面的递归调用中

    while(i<j)
    {
        while(a[j]>=temp &&j>i) // 这步经常 忘记j>i
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

    a[i] = temp;        //因为a[i]此时是没有值的，所以temp应该赋值给a[i]
    qsort(a,start,i-1);  //这步经常会把start 写成是0 ，注意
    qsort(a,i+1,end);
}
