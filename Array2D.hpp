/*******************************************************************
		˵���������ڴ������Ķ�ά�����������cash�����ʣ�
		      ��߶�ά����ķ����ٶȡ�������
			  http://blog.csdn.net/morewindows/article/details/7664479
*******************************************************************/

//������õ�malloc��free�����ڴ����
#include <stdlib.h>

//������СΪrow*col�ľ���ÿһ���ʼ��Ϊ0
template <typename T>  
T** malloc_Array2D(int row, int col)  
{  
    int size = sizeof(T);  
    int point_size = sizeof(T*);  
    //�������ڴ棬����point_size * row��ʾ���row����ָ��  
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

//�ͷŶ�ά����  
void free_Array2D(void **arr)  
{  
    if (arr != NULL)  
        free(arr);  
}  