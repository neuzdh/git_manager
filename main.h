#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;
#define true 1

class student
{
public:
	student();
	~student();

private:

	char student_name[];
	int student_age;
	
};

/*传数组给一个函数，数组类型自动转换为指针类型，因而传的实际是地址*/
//就函数而言，数组的长度是无关紧要的，因为 C++ 不会对形式参数执行边界检查
float get_average_1(float arry[], int size)
{
	//int arry_size = sizeof(arry) / sizeof(arry[0]);
	/*数组作为形参，退化为指针，sizeof（指针）= 8，因此不能再被调用函数中利用sizeof（数组名）/sizeof（数组类型）求数组的长度*/

	float sum = 0.0f;
	for(int i = 0; i < size; i++)
	{
		sum = sum + arry[i];
	}
	return (sum / size);
}

float get_average_2(float *p , int size)
{
	// 
	int ptr_size = sizeof(p);
	// printf("ptr_size=%d\n", ptr_size);
	cout << "ptr_size:" << ptr_size << endl;
	float sum = 0.0f;
	for(int i = 0; i < size; i++)
	{
		sum = sum + *(p + i);
	}
	return (sum / size);
}

float *get_array(void)
{

	/*err address of local variable ‘arry’ returned*/
	// C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量
	// float arry[] = {2.4,2.5,5.2,4.6};
	// return arry;	//address of local variable ‘arry’ returned

	static float arry[] = {2.4, 2.5, 5.2, 4.6};
	cout << "address:" << arry << endl;
	return arry;
}
