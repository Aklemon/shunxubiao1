#include "SeqList.h"

// ��ʼ��˳���
void InitSeqList(PSeqList seqList)
{
	assert(NULL != seqList);
	memset(seqList->arr, 0, MAX_SIZE*sizeof(DataType));
	seqList->size = 0;
}

// ˳���β��
// ��ƺ���ԭ��
// �������
// �߽���������
// �߼�����
// β��
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
//βɾ	
void PopBack(PSeqList pSeqList)
{
	assert(NULL != pSeqList);
	if (pSeqList->size <= 0)
	{
		return;
	}
	pSeqList->size--;
}
//��ӡ˳���
void PrintfSeqList(PSeqList pSeqList)
{
	int iIdx = 0;
	for (; iIdx < pSeqList->size; iIdx++)
	{
		printf("%d", pSeqList->arr[iIdx]);
	}
	printf("\n");
}

//ͷ��
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

// ͷɾ
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
	//����Ҫ����ָ�룬��Ҫ����pos��λ�õ�˳���û�з�����ʱ������
	//�����ڿ�ͷ��ĩβ�����,ע��insert������λ��
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

// ��˳����в���Ԫ��data
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

// ɾ��˳�����posλ���ϵ�Ԫ��
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
//�Ƴ�˳����е�Ԫ��data
void Remove(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	Erase(pSeqList, Find(pSeqList, data));
}

// �Ƴ�˳���������Ԫ��data
void RemoveAll(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	int iIdx = 0;
	//����˳��� �������Ͳ����
	for (; iIdx < pSeqList->size; iIdx++)
	{
		if (pSeqList->arr[iIdx] == data)
		{
			Remove(pSeqList, data);
			iIdx--;
		}
	}
	


	//��find ������ �ҵ��˾�ɾ��һ�� ����Ԫ����ǰ��λ ����

	//assert(NULL != pSeqList);
	//Erase(pSeqList, Find(pSeqList, data));


}




