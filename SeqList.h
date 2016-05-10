#ifndef SEQLIST_H
#define SEQLIST_H
#include<assert.h>
#include<string.h>

#define MAX_SIZE 10
typedef int DataType;
typedef unsigned int size_t;

typedef struct SeqList
{
	DataType arr[MAX_SIZE];
	size_t size;
}SeqList, *PSeqList;





// ��ʼ��˳���
void InitSeqList();
//β��
void PushBack(PSeqList pSeqList, DataType data);
////βɾ
void PopBack(PSeqList pSeqList);
//��ӡ
void PrintfSeqList(PSeqList pSeqList);
//ͷ��
void PushFront(PSeqList pSeqList, DataType data);
//ͷɾ
void PopFront(PSeqList pSeqList);
// ����λ�ò���
void Insert(PSeqList pSeqList, int pos, DataType data);
// ��˳����в���Ԫ��data
int Find(PSeqList pSeqList, DataType data);

// ɾ��˳�����posλ���ϵ�Ԫ��
void Erase(PSeqList pSeqList, int pos);
//�Ƴ�˳����е�Ԫ��data
void Remove(PSeqList pSeqList, DataType data);
// �Ƴ�˳���������Ԫ��data
void RemoveAll(PSeqList pSeqList, DataType data);

#endif
