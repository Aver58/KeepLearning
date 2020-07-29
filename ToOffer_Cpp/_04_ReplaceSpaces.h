#pragma once
// 4. 替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

class _04_ReplaceSpaces
{
public:
	void Test() {
		//cout << ReplaceBlank();
	}

	/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
	void ReplaceBlank(char str[], int length)
	{
		if (str == nullptr || length <= 0)
			return;
		/*originalLength 为字符串str的实际长度*/
		int originalLength = 0;
		int numberOfBlank = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			++originalLength;

			if (str[i] == ' ')
				++numberOfBlank;

			++i;
		}
		/*newLength 为把空格替换成'%20'之后的长度*/
		int newLength = originalLength + numberOfBlank * 2;
		if (newLength > length)
			return;

		int indexOfOriginal = originalLength;
		int indexOfNew = newLength;
		// 在原来内存进行操作，
		// 先计算出所需内存，
		while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
		{
			// 然后由后向前存字符串
			if (str[indexOfOriginal] == ' ')
			{
				str[indexOfNew--] = '0';
				str[indexOfNew--] = '2';
				str[indexOfNew--] = '%';
			}
			else
			{
				str[indexOfNew--] = str[indexOfOriginal];
			}

			--indexOfOriginal;
		}



	}
};

