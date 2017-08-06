/*******************************************************************
		说明：创建内存连续的二维数组用以提高cash命中率，
		      提高二维数组的访问速度。方法见
			  http://blog.csdn.net/morewindows/article/details/7664479
*******************************************************************/

//后面会用到malloc与free进行内存操作
#include <stdlib.h>

//创建大小为row*col的矩阵并每一项初始化为0
template <typename T>  
T** malloc_Array2D(int row, int col)  
{  
    int size = sizeof(T);  
    int point_size = sizeof(T*);  
    //先申请内存，其中point_size * row表示存放row个行指针  
    T **arr = (T **) malloc(point_size * row + size * row * col);  
    if (arr != NULL)  
    {     
        memset(arr, 0, point_size * row + size * row * col);  
        T *head = (T*)((int)arr + point_size * row);  
        while (row--)  
            arr[row] = (T*)((int)head + row * col * size);  
    }  
    return (T**)arr;  
}  

//释放二维数组  
void free_Array2D(void **arr)  
{  
    if (arr != NULL)  
        free(arr);  
}  