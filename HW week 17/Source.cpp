#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<math.h>
int BMIValue(int, int);
int weightFit(int);
int main()
{
	int l, n, j1, j2, answer, BMI[50], WeightProp[50];
	struct info
	{
		int year;
		char nickName[50];
		int Height;
		int Weight;
	};

	struct info student[50];
	printf("Number of students:");
	scanf_s("%d", &l);
	for (int i = 0; i < l; i++)
	{
		scanf("%d ", &student[i].year);
		scanf("%s ", student[i].nickName);
		scanf("%d ", &student[i].Height);
		scanf("%d", &student[i].Weight);
	}
	for (int i = 0; i < l; i++)
	{
		BMI[i] = BMIValue(student[i].Weight, student[i].Height);
	}
	for (int i = 0; i < l; i++)
	{
		WeightProp[i] = weightFit(student[i].Height);
	}
	printf("Student:\n");
	for (int i = 0; i < l; i++)
	{
		if (student[i].year >= 20)
		{
			if (BMI[i] == 1)
			{

				printf("%s ", student[i].nickName);
				printf(" is fat\n");
				printf("Ideal weight: %d \n", WeightProp[i]);
				printf("======================");
			}
			if (BMI[i] == 0)
			{

				printf("%s ", student[i].nickName);
				printf(" is healthy\n");
				printf("======================");
			}
			if (BMI[i] == 2)
			{

				printf("%s ", student[i].nickName);
				printf(" is thin\n");
				printf("Ideal weight: %d \n", WeightProp[i]);
				printf("======================");
			}
		}
		if (student[i].year < 20)
		{
			printf("%s ", student[i].nickName);
			printf("ages less than 20");
		}

		printf("\n");
	}
	return 0;
}
int BMIValue(int x, int y)
{
	float BMI;
	float z = pow(y, 2) / 10000;
	BMI = x / z;
	if (BMI > 24)
		return 1;
	if (BMI < 24 && BMI >18)
		return 0;
	if (BMI < 18)
		return 2;
}
int weightFit(int x)
{
	return x - 105;
}