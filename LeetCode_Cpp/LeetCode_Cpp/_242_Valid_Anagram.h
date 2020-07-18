#pragma once
/*
���������ַ��� s �� t����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
˵��������Լ����ַ���ֻ����Сд��ĸ��

ʾ�� 1
����: s = 'anagram', t = 'nagaram'
���: true

ʾ�� 2
����: s = 'rat', t = 'car'
���: false

��ĸ��λ�ʣ�Ҳ���������ַ����е���ͬ�ַ�������Ҫ��Ӧ��ȡ�
���磬s ���� ��anagram����t ���� ��nagaram����s �� t �ͻ�Ϊ��ĸ��λ�ʡ�
��Ϊ���Ƕ������������ַ� a��һ���ַ� g��һ���ַ� m��һ���ַ� n���Լ�һ���ַ� r��
���� s Ϊ ��rat����t Ϊ ��car����ʱ��s �� t ����Ϊ��ĸ��λ�ʡ�
*/

#include "Global.h"

class _242_Valid_Anagram
{
public:
	void Test() {
		string s = "anagram";
		string t = "nagaram";
		std::cout << _242_Valid_Anagram::isAnagram(s,t);
	}

	bool isAnagram(string s,string t) {
		// ��ʾ���ַ����ִ���һ��������λ��
		//1. ��2���ַ����飬�ַ����ִ��������Ƚ������ַ������Ƿ�һ��
		

		//2. ��1���ַ����飬��һ���ַ���ʱ���¼���ִ������ڶ����ַ���ʱ�򣬼������ִ��������Ϊ0��һ��
		// array 8ms 97%
		if (s.size() != t.size()) return false;
		int help[26] = { 0 };
		for (int i = 0; i < s.size(); ++i) {
			++help[s[i] - 'a'];
			--help[t[i] - 'a'];
		}
		for (int i = 0; i < 26; ++i) {
			if (help[i] != 0) return false;
		}
		return true;

		//map  16ms 62.5%
	/*	if (s.size() != t.size()) {
			return false;
		}
		unordered_map<char, int> umap;
		for (int i = 0; i < s.size(); ++i) {
			++umap[s[i]];
			--umap[t[i]];
		}
		for (auto c : umap) {
			if (c.second != 0) {
				return false;
			}
		}

		return true;*/
	}
};

