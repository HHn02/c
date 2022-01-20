#include"stdio.h"
#include"stdlib.h"
#include"string"
#include"ctype.h"
#include"stddef.h"

/* 结构体声明 */

//键值对
typedef int keyType;
typedef int ValueType; 
//哈希函数指针
typedef int (*HashFunc)(keyType Key);

//哈希函数中元素的状态
typedef enum State
{
    EMPTY,//当前结点为空
    VALUE,//当前结点有元素
    DELETED,//当前结点已被删除，也可以当作空
}State;

//将键值对存放于结构体中
typedef struct keyValue
{
    keyType key;
    ValueType value;
    State state; //枚举变量
}keyValue;

//哈希表
typedef struct HashTable
{
    keyValue data[HashMaxSize];
    size_t size;
    HashFunc func;
}HashTable;


//哈希函数（取余散列法）
int HashFunction(keyType key)
{
    return key % HashMaxSize;
}

//哈希表初始化
void HashInit(HashTable*ht,HashFunc func)
{
    if (ht == 0)
    {
        return; //非法输入
    }
    ht->size = 0;
    ht->func=func;
    size_t i=0;
    for (; i<HashMaxSize; i++)
    {
        ht->data[i].state = EMPTY;
    }
}

//销毁哈希表
void HashDestroy(HashTable*ht)
{
    if(ht==0)return;
    ht->size = 0 ;
    ht->func = NULL;
}

/* ************************************************************************************** */

//往哈希表中插入数据
void HashInsert(HashTable* ht, KeyType key, ValueType value)
{
    if(ht == NULL)
    {
        return;
    }
    //负载因子，意思就是该哈希表只能存储最大容量的百分之八十的数据
    size_t size_max = 0.8 * HashMaxSize;
    if(ht->size >= size_max)
    {
        //达到载荷了
        return;
    }
    //1.先通过哈希函数算出 offset, 即当前元素对应到哈希表中的下标
    size_t offset = ht->func(key);
    //2.如果当前下标已经有了元素，就将新插入的元素后移
    while(1)
    {
        if(ht->data[offset].state != VALUE)
        {
            ht->data[offset].key = key;
            ht->data[offset].value = value;
            ht->data[offset].state = VALUE;
            ht->size++;
            break;
        }
    //3.如果碰到 key 相同的元素，则表示插入失败，或者更新 value
        else if(ht->data[offset].key == key)
        {
            //如果需要更新 value ,就放开下面的代码                                                                                      
            //ht->data[offset].value = value;
            break;
        }
            //4.如果到了哈希表的末尾，则将其换到头部，继续后移
        else if(offset >= HashMaxSize)
        {
            offset = 0;
        }
        offset++;
    }
}


/* ************************************************************************************** */

//删除指定元素
void HashRemove(HashTable* ht, KeyType key)
{
    if(ht == NULL)
    {
        return;
    }
    if(ht->size == 0)
    {
        return;
    }
    //1.先求出 offset, 拿着 offset 去哈希表中寻找指定元素
    size_t offset = ht->func(key);
    //2.如果当前下标元素的状态为 VALUE 的话，就判断 key是否相等
    while(ht->data[offset].state != EMPTY)
    {
    //  a)相等：将当前元素的状态设置为 DELETED, 
        if(ht->data[offset].state == VALUE && ht->data[offset].key == key)
        {
            ht->data[offset].state = DELETED;
            ht->size--;
        }
    //  b)不相等：offset++，继续往后查找，直到该元素下标为 EMPTY
        else{
    //      如果遇到的状态是 DELETED, 依旧需要往后找，因为可能后面还紧接着跟有有效元素
    //      如果 offset 已经到了哈希表末尾，则将其置为 0
            if(offset >= HashMaxSize)
            {
                offset = 0;
            }
            offset++;                                                                                                                   
        }
    }// 寻找 指定元素并删除
}


/* ************************************************************************************** */

//查找指定元素
KeyValue* HashFind(HashTable* ht, KeyType key)
{
    if(ht == NULL)
    {
        return NULL;
    }
    //1.先算出 offset,拿着 offset 到哈希表中去查找
    size_t offset = ht->func(key);
    //2.如果当前下标的元素状态为 VALUE ,则去比较 key
    while(ht->data[offset].state != EMPTY)
    {
        //  如果 key 相等的话，就返回结构体指针,
        if(ht->data[offset].key == key && ht->data[offset].state == VALUE)
        {
            return &ht->data[offset];
        }
        //  如果 key 不相等的话，就offset++,往后查找
        else
        {
            //如果 offset 到了哈希表末尾，则重新从头开始
            if(offset >= HashMaxSize)
            {
                offset = 0;
            }
            offset++;
        }
    }
    //3.如果当前下标元素的状态不为 VALUE 的话，说明没找到，返回NULL
    return NULL;                                                                                                                        
}
