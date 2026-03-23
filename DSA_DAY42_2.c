#include <stdlib.h>

typedef struct {
    int* maxHeap;
    int* minHeap;
    int maxSize, minSize;
} MedianFinder;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int* heap, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] >= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

void maxHeapifyDown(int* heap, int size, int i) {
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, largest = i;
        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;
        if (largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}

void minHeapifyUp(int* heap, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

void minHeapifyDown(int* heap, int size, int i) {
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, smallest = i;
        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxHeap = (int*)malloc(50000 * sizeof(int));
    obj->minHeap = (int*)malloc(50000 * sizeof(int));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void addNum(MedianFinder* obj, int num) {
    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        obj->maxHeap[obj->maxSize] = num;
        maxHeapifyUp(obj->maxHeap, obj->maxSize++);
    } else {
        obj->minHeap[obj->minSize] = num;
        minHeapifyUp(obj->minHeap, obj->minSize++);
    }

    if (obj->maxSize > obj->minSize + 1) {
        int val = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
        maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);

        obj->minHeap[obj->minSize] = val;
        minHeapifyUp(obj->minHeap, obj->minSize++);
    } else if (obj->minSize > obj->maxSize) {
        int val = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);

        obj->maxHeap[obj->maxSize] = val;
        maxHeapifyUp(obj->maxHeap, obj->maxSize++);
    }
}

double findMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize) return obj->maxHeap[0];
    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}