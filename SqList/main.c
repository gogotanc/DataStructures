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

    printf("请按提示对空表进行操作：\n");
    printf("\t一、添加元素请输入0\n");
    printf("\t二、随机添加请输入1\n");
    printf("\t三、查看元素请输入2\n");
    printf("\t四、删除元素请输入3\n");
    printf("\t五、清空链表请输入4\n");
    printf("\t六、打印链表请输入5\n");
    printf("\t七、退出程序请输入-1\n");

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

                printf("请输入要添加的数据：");
                scanf("%d",&data);
                printf("请输入插入的位置：");
                scanf("%d",&index);

                result = ListInsert(data,index,SqList);
                if(result==OK)
                    printf("添加成功。\n");
                else
                    printf("添加失败。\n");
                break;
            case 1: ;
                srand( (unsigned)time( NULL ) );
                result = ListInsert(rand()%100+1,SqList->length+1,SqList);
                if(result==OK)
                    printf("添加成功。\n");
                else
                    printf("添加失败。\n");
                break;
            case 2: ;
                printf("请输入要查看元素的位置：");
                scanf("%d",&data);
                result = GetElem(index,SqList);
                if(result!=-1)
                    printf("查看的元素为：%d\n",result);
                break;
            case 3: ;
                printf("请输入要删除的元素位置");
                scanf("%d",&index);
                result = ListDelete(SqList,index);
                if(result==OK)
                    printf("删除成功。\n");
                else
                    printf("删除失败。\n");
                break;
            case 4: ;
                InitList(SqList);
                printf("清空成功。\n");
                break;
            case 5: ;
                PrintfList(SqList);
                break;
            case -1: return 0;
                break;
            default:
                printf("请按提示输入。\n");
        }
    }
    return 0;
}
