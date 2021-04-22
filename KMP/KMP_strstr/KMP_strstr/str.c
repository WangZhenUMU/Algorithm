#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
/*---------------------------------------------------------------------------------------------------*/
void GetNext(const char substr[], int next[], int len)
{
	int j = 0, k = -1;
	next[0] = -1;//第一个字符前无字符串，给值负一
	while (j < len - 1)
		(k == -1 || substr[j] == substr[k]) ? (next[++j] = ++k) : (k = next[k]);
}
/*---------------------------------------------------------------------------------------------------*/
//模拟实现strstr函数
char *my_strstr(char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	int len = strlen(str2);
	int* NEXT = malloc(sizeof(int)*len);
	GetNext(str2, NEXT, len);
	int i = 0, j = 0;
	while (str1[i] != '\0'&&str2[j] != '\0')
	{
		if (str1[i] == str2[j])
		{
			i++; j++;
		}
		else
			(NEXT[j] == -1) ? i++ : (j = NEXT[j]);
	}
	return str2[j] ? NULL : str1 + i - j;
}
/*---------------------------------------------------------------------------------------------------*/
int main()
{
	char str1[] = "ABABCACAABCABABCABBABABABCABAACBA";
	char str2[] = "ABABCABAA";
	char* p = my_strstr(str1, str2);
	printf("str1:>  %s\n", str1);
	printf("str2:>  %s\n", str2);
	printf("strstr;>%p\n", p);
	printf("%s ", p);
	return 0;
}