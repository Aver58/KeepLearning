template<class T>
void Swap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
int GetLargestIndex(T a[],int length)
{
    int index = 0;
    for(int i = 0;i < length; i++)
    {
        cout<<a[i]<<endl;
        if(a[i] > a[index])
        {
            index = i;
        }
    }
    return index;
}
