#include "main.h"
#include "string.h"

const int MAX = 10;

int main(int argc, char *argv[])
{
	while (true)
	{
		int test_data = 4.2f;//整型变量存储浮点型数据，会导致精度丢失，舍弃浮点数据的小数
		cout << "data:" << test_data <<"data1=" <<  test_data/10 <<"data2:" <<test_data/10.0f << endl;
		for(int i = 0; i < MAX; i++)
		{
			// printf("i=%d\n",i);
			// sleep(1);
		}
		// MAX = 0; err MAX is const  read-only
		// printf("start next loop\n");
		float balence[5] = {1.0,2.0,4.2,2.4};
		// char test_arry[10] = {'a'/* ,'b','c','d','\0','e' */};//strlen 结果为1
		char test_arry[] = {'a'/* ,'b','c','d','\0','e' */};//strlen结果为2  test_arry[1] = 'W' test_arry[2] = '\0'
		// char test_arry[] = {'a','\0','c','d','\0'};//strlen结果为1
		char arr[10] = "W";

		// 通过字节大小，计算数组大小
		int arry_size = sizeof(balence) / sizeof(balence[0]);
		cout << "arry_size:" << arry_size << "arry_count: " << strlen(test_arry) << endl;
		cout << "arry_count: " << strlen(test_arry) << "arry1= "<<test_arry[1] << " arry2= " << test_arry[2]<< endl;
		if (test_arry[2] == '\0')
		{
			cout << "true" << endl;
		}
		// printf("arry_size=%d\n",arry_size);

		float balence_ave = 0.0f;
		balence_ave = get_average_1(balence,arry_size);

		printf("balence_ave = %.2f\n",balence_ave);
		sleep(1);

		balence_ave = get_average_2(balence, arry_size);
		printf("balence_ave = %.2f\n",balence_ave);
		sleep(1);

		// 调用函数返回数组
		printf("get array from fun\n");
		float * ptr_array = get_array();
		for (int count = 0; count < 4; count++)
		{
			printf("get_array[%d]=%.2f\n",count,*(ptr_array + count));
			sleep(1);
		}

	}
	
	return 0;
}