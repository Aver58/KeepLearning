#include "_20_PrintMatrix.h"

// 顺时针打印
void PrintMatrix::PrintMaxtrixClockwisely(int **array,int row,int colum)
{
    if(row <=0 ||colum <=0 || array == NULL)
    {
        return;
    }

    int start = 0;
    // 这个条件看不懂啊！！！
    while(colum > start * 2 && row > start * 2)
    {
        PrintMaxtrixInCircle(array,row,colum,start);
        start ++;
    }
}

void PrintMaxtrixInCircle(int **array,int row,int colum,int start)
{
    int endX = colum - 1 - start;
    int endY = row - 1;

    //第一行：横列
    if(endX > start)
    {
        for(int i = start + 1;i < endX;i++)
        {
            cout<<array[start][i]<<endl;
        }
    }

    //第二行：纵列
    if(endY > start)
    {
        for(int i = start + 1;i <= endY;i++)
        {
            cout<<array[i][endX]<<endl;
        }
    }

    //第三行：横列，逆向
    if(endX > start && endY > start)
    {
        for(int i = endY - 1;i >= start;i--)
        {
            cout<<array[endY][i]<<endl;
        }
    }

    //第四行：纵列，逆向
    if(endX > start && endY - 1 > start)//？？-1
    {
        for(int i = endY - 1;i >= start + 1;i--)
        {
            cout<<array[i][start]<<endl;
        }
    }
}