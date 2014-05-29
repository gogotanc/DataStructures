#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SequenceList;

void InitList(SequenceList *list)
{
    int i;
    for(i=0; i<MAXSIZE; i++);
        list->data[i] = 0;
    list->length = 0;
}

Status ListInsert(ElemType data, int index, SequenceList *list)
{
    if(list->length>=MAXSIZE)
    {
        printf("list is full\n");
        return FALSE;
    }
    if(index<1 || index>(list->length+1))
    {
        printf("wrong index\n");
        return FALSE;
    }
    int i;
    for(i=list->length; i>index-1; i--)
        list->data[i+1] = list->data[i];

    list->data[index-1] = data;
    list->length++;
    return OK;
}

Status ListDelete(SequenceList *list, int index)
{
    if(list->length==0)
    {
        printf("list is empty\n");
        return FALSE;
    }
    if(index<1 || index>(list->length+1))
    {
        printf("wrong index\n");
        return FALSE;
    }

    int i;
    for(i=index; i<list->length; i++)
    {
        list->data[i-1] = list->data[i];
    }
    list->length--;
    return TRUE;
}

ElemType GetElem(int index,SequenceList *list)
{
    if(list->length==0)
    {
        printf("list is empty\n");
        return -1;
    }
    if(index<1 || index>(list->length+1))
    {
        printf("wrong index\n");
        return -1;
    }
    return list->data[index-1];
}

Status PrintfList(SequenceList *list)
{
    if(list->length==0)
    {
        printf("list is empty\n");
        return OK;
    }

    printf("list.length= %d\n",list->length);

    int i;
    for(i=0; i<list->length; i++)
        printf("%d\t",list->data[i]);
    printf("\n");
    return OK;
}

int main()
{

    printf("�밴��ʾ�Կձ���в�����\n");
    printf("\tһ�����Ԫ��������0\n");
    printf("\t����������������1\n");
    printf("\t�����鿴Ԫ��������2\n");
    printf("\t�ġ�ɾ��Ԫ��������3\n");
    printf("\t�塢�������������4\n");
    printf("\t������ӡ����������5\n");
    printf("\t�ߡ��˳�����������-1\n");

    int input;
    Status result;
    ElemType data;
    int index;
    SequenceList *SqList;
    SqList = (SequenceList*)malloc(sizeof(SqList));
    InitList(SqList);

    while(TRUE)
    {
        scanf("%d",&input);
        switch(input)
        {
            case 0: ;

                printf("������Ҫ��ӵ����ݣ�");
                scanf("%d",&data);
                printf("����������λ�ã�");
                scanf("%d",&index);

                result = ListInsert(data,index,SqList);
                if(result==OK)
                    printf("��ӳɹ���\n");
                else
                    printf("���ʧ�ܡ�\n");
                break;
            case 1: ;
                srand( (unsigned)time( NULL ) );
                result = ListInsert(rand()%100+1,SqList->length+1,SqList);
                if(result==OK)
                    printf("��ӳɹ���\n");
                else
                    printf("���ʧ�ܡ�\n");
                break;
            case 2: ;
                printf("������Ҫ�鿴Ԫ�ص�λ�ã�");
                scanf("%d",&data);
                result = GetElem(index,SqList);
                if(result!=-1)
                    printf("�鿴��Ԫ��Ϊ��%d\n",result);
                break;
            case 3: ;
                printf("������Ҫɾ����Ԫ��λ��");
                scanf("%d",&index);
                result = ListDelete(SqList,index);
                if(result==OK)
                    printf("ɾ���ɹ���\n");
                else
                    printf("ɾ��ʧ�ܡ�\n");
                break;
            case 4: ;
                InitList(SqList);
                printf("��ճɹ���\n");
                break;
            case 5: ;
                PrintfList(SqList);
                break;
            case -1: return 0;
                break;
            default:
                printf("�밴��ʾ���롣\n");
        }
    }
    return 0;
}
