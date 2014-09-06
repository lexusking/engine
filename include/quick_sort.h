void qsort(int a,int start,int end)
{
    int i,j,temp;
    i = start;
    j = end;
    temp = a[start];

    if(i>=j) return ;  // �ⲽ����������д������д�Ļ���ÿ�ζ�����뵽����ĵݹ������

    while(i<j)
    {
        while(a[j]>=temp &&j>i) // �ⲽ���� ����j>i
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

    a[i] = temp;        //��Ϊa[i]��ʱ��û��ֵ�ģ�����tempӦ�ø�ֵ��a[i]
    qsort(a,start,i-1);  //�ⲽ�������start д����0 ��ע��
    qsort(a,i+1,end);
}
