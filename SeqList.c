#include "SeqList.h"

// 初始化顺序表
void InitSeqList(PSeqList seqList)
{
	assert(NULL != seqList);
	memset(seqList->arr, 0, MAX_SIZE*sizeof(DataType));
	seqList->size = 0;
}

// 顺序表尾插
// 设计函数原型
// 参数检测
// 边界条件考虑
// 逻辑操作
// 尾插
void PushBack(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	if (pSeqList->size >= MAX_SIZE)
	{
		return;
	}
	pSeqList->arr[pSeqList->size] = data;
	//Insert(pSeqList, 0, data);
	pSeqList->size++;
}
//尾删	
void PopBack(PSeqList pSeqList)
{
	assert(NULL != pSeqList);
	if (pSeqList->size <= 0)
	{
		return;
	}
	pSeqList->size--;
}
//打印顺序表
void PrintfSeqList(PSeqList pSeqList)
{
	int iIdx = 0;
	for (; iIdx < pSeqList->size; iIdx++)
	{
		printf("%d", pSeqList->arr[iIdx]);
	}
	printf("\n");
}

//头插
void PushFront(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	if (pSeqList->size >= MAX_SIZE)
	{
		return;
	}
	int iIdx = pSeqList->size;
	for (; iIdx > 0; iIdx--)
	{
		pSeqList->arr[iIdx] = pSeqList->arr[iIdx - 1];
	}
	pSeqList->arr[0] = data;
	/*Insert(pSeqList, 0, data);*/
	pSeqList->size++;
}

// 头删
void PopFront(PSeqList pSeqList)
{
	assert(NULL != pSeqList);
	if (pSeqList->size <= 0)
	{
		return;
	}
	int iIdx = 1;
	for (; iIdx <pSeqList->size; iIdx++)
	{
		pSeqList->arr[iIdx-1] = pSeqList->arr[iIdx];
	}
	pSeqList->size--;
}

void Insert(PSeqList pSeqList, int pos, DataType data)
{
	//不仅要断言指针，还要考虑pos的位置当顺序表没有放满的时候它是
	//可以在开头和末尾放入的,注意insert是任意位置
	//assert(NULL != pSeqList);
	
	assert(NULL != pSeqList&& (pos >= 0 && pos <= pSeqList->size));
	if (pSeqList->size >= MAX_SIZE)
	{
		return;
	}
	int iIdx = pSeqList->size;
	for (; iIdx >pos; iIdx--)
	{
		pSeqList->arr[iIdx] = pSeqList->arr[iIdx - 1];
	}
	pSeqList->arr[pos]= data;
	pSeqList->size++;
}

// 在顺序表中查找元素data
int Find(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	int iIdx = 0;
	for (; iIdx < pSeqList->size; iIdx++)
	{
		if (pSeqList->arr[iIdx] == data)
		{
			return iIdx;
		}
	}
	
	return -1;

}

// 删除顺序表中pos位置上的元素
void Erase(PSeqList pSeqList, int pos)
{
	assert(NULL != pSeqList && (pos >= 0 && pos <= pSeqList->size));
	if (pSeqList->size >= MAX_SIZE)
	{
		return;
	}
	int iIdx = pos;
	for (; iIdx <pSeqList->size; iIdx++)
	{
		pSeqList->arr[iIdx] = pSeqList->arr[iIdx +1];
	}
	
	pSeqList->size--;
}
//移除顺序表中的元素data
void Remove(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	Erase(pSeqList, Find(pSeqList, data));
}

// 移除顺序表中所有元素data
void RemoveAll(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	int iIdx = 0;
	//遍历顺序表 遇到它就不输出
	for (; iIdx < pSeqList->size; iIdx++)
	{
		if (pSeqList->arr[iIdx] == data)
		{
			Remove(pSeqList, data);
			iIdx--;
		}
	}
	


	//用find 来查找 找到了就删除一个 所有元素向前移位 再找

	//assert(NULL != pSeqList);
	//Erase(pSeqList, Find(pSeqList, data));


}




