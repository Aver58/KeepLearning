#pragma once

//��������Ϊ�βε��ú���ʱ����Ҫ��ͬ���鳤��һ�𴫽�����
//��������Ϊ�����������ݹ����У����˻���ָ�롣��Ҳ��Ϊʲôָ����Ϊ��������ʱ������Ҫһ�����ȡ�

/// ������������ֵ
void Swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}