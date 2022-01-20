#include "stdio.h"
#include "stdlib.h"
#include "string"
#define INT_MIN (0)
#define HASH_MAX_SIZE
typedef int KeyType;
typedef int ValueType;

/* 结点结构 */
typedef struct datatype
{
    KeyType key;
    ValueType val;
} Datatype;

typedef struct hashnode
{
    Datatype data;
    struct HashNode *next;
} HashNode;

typedef struct hashmap
{
    size_t size;
    HashNode *table;
} HashMap;

/* 哈希函数 */
int hashfunc(KeyType key, size_t size)
{
    return key % HashMap->size;
}
/* 创造哈希表 */
HashMap *CreateHashMap(KeyType key, int size)
{
    HashMap *hashmap = (HashMap *)malloc(sizeof(HashMap));  //分配整个表的空间
    hashmap->size = 2 * size;
    hashmap->table=(HashNode*)malloc(sizeof(HashNode)*hashmap->size);//给表的table分配空间
    //初始化
    for(int j=0;j<hashmap->size;j++)
    {
        hashmap->table[j]->data.val=INT_MIN;
        hashmap->table[j]->next=NULL;
    }

    //建立hash表
    int i=0;
    while (i<size)  
    {
        if(hashmap->table->data.val==INT_MIN){
            int index=hashfunc(key,hashmap->size);
            hashmap->table[index].data.key=i;
            hashmap->table[index].data.val=val;
        }
        else
        {
            HashNode*lnode = (HashNode*)malloc(sizeof(HashNode)),*hashnode;
            lnode->data.key=i;
            lnode->data.val=val;
            lnode->next=NULL;

            hashnode=&(hashmap->table[index]);
            while (hashnode)
            {
                hashnode=hashnode->next;
            }
            hashnode->next=lnode;
        }
        i++;
    }
    return hashmap;
}

/* 查找 */
int Get(HashMap hashmap,int val)    
{
    int index=hashfunc(key,hashmap->size);
    HashNode *pointer=&(hashmap.table[index]);
    while (pointer)
    {
        if(pointer->data.val=val);
            return pointer->data.key;
        else 
            pointer=pointer->next;
    }
    return -1;
}