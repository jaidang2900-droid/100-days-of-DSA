#include <stdio.h>
#include <stdlib.h>

#define MAX 500000

typedef struct {
    int *maxHeap;
    int *minHeap;
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

/* ---------- MAX HEAP ---------- */

void maxInsert(MedianFinder *obj,int val){
    int i=obj->maxSize++;
    obj->maxHeap[i]=val;

    while(i>0){
        int p=(i-1)/2;

        if(obj->maxHeap[p]>=obj->maxHeap[i])
            break;

        swap(&obj->maxHeap[p],&obj->maxHeap[i]);
        i=p;
    }
}

int maxPop(MedianFinder *obj){

    int val=obj->maxHeap[0];
    obj->maxHeap[0]=obj->maxHeap[--obj->maxSize];

    int i=0;

    while(1){

        int l=2*i+1;
        int r=2*i+2;
        int largest=i;

        if(l<obj->maxSize && obj->maxHeap[l]>obj->maxHeap[largest])
            largest=l;

        if(r<obj->maxSize && obj->maxHeap[r]>obj->maxHeap[largest])
            largest=r;

        if(largest==i)
            break;

        swap(&obj->maxHeap[i],&obj->maxHeap[largest]);
        i=largest;
    }

    return val;
}

/* ---------- MIN HEAP ---------- */

void minInsert(MedianFinder *obj,int val){

    int i=obj->minSize++;
    obj->minHeap[i]=val;

    while(i>0){

        int p=(i-1)/2;

        if(obj->minHeap[p]<=obj->minHeap[i])
            break;

        swap(&obj->minHeap[p],&obj->minHeap[i]);
        i=p;
    }
}

int minPop(MedianFinder *obj){

    int val=obj->minHeap[0];
    obj->minHeap[0]=obj->minHeap[--obj->minSize];

    int i=0;

    while(1){

        int l=2*i+1;
        int r=2*i+2;
        int smallest=i;

        if(l<obj->minSize && obj->minHeap[l]<obj->minHeap[smallest])
            smallest=l;

        if(r<obj->minSize && obj->minHeap[r]<obj->minHeap[smallest])
            smallest=r;

        if(smallest==i)
            break;

        swap(&obj->minHeap[i],&obj->minHeap[smallest]);
        i=smallest;
    }

    return val;
}

/* ---------- MAIN ---------- */

MedianFinder* medianFinderCreate(){

    MedianFinder* obj=malloc(sizeof(MedianFinder));

    obj->maxHeap=malloc(sizeof(int)*MAX);
    obj->minHeap=malloc(sizeof(int)*MAX);

    obj->maxSize=0;
    obj->minSize=0;

    return obj;
}

void medianFinderAddNum(MedianFinder* obj,int num){

    if(obj->maxSize==0 || num<=obj->maxHeap[0])
        maxInsert(obj,num);
    else
        minInsert(obj,num);

    if(obj->maxSize>obj->minSize+1)
        minInsert(obj,maxPop(obj));

    if(obj->minSize>obj->maxSize)
        maxInsert(obj,minPop(obj));
}

double medianFinderFindMedian(MedianFinder* obj){

    if(obj->maxSize>obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0]+obj->minHeap[0])/2.0;
}

void medianFinderFree(MedianFinder* obj){

    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}