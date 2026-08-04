#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    unsigned int* buckets;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    
    obj->buckets = (unsigned int*)calloc(31251, sizeof(unsigned int));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int bucketIndex = key / 32;
    int bitIndex = key % 32;
    
    obj->buckets[bucketIndex] |= (1U << bitIndex);
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int bucketIndex = key / 32;
    int bitIndex = key % 32;
    
    obj->buckets[bucketIndex] &= ~(1U << bitIndex);
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int bucketIndex = key / 32;
    int bitIndex = key % 32;

    return (obj->buckets[bucketIndex] & (1U << bitIndex)) != 0;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->buckets);
    free(obj);
}


