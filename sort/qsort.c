#include <stdio.h>

void quickSort(int* arr, int low, int high);
int partition(int* arr, int low, int high);

int main(){
    int arr[] = {1, 8, 2, 9, 3, 7, 0, 1, 0, 10};
    printf("输入的数组序列为：");
    for(int i=0; i<10; i++){
        printf("[%d] ", arr[i]);
    }
    printf("\n");
    quickSort(arr, 0, 9);
    printf("单路快排的结果为：");
    for(int i=0; i<10; i++){
        printf("[%d] ", arr[i]);
    }
    return 0;
}

void quickSort(int* arr, int low, int high){
    if(low >= high){
        return;
    }
    /* 在每次递归开始前，先选取分界点index，
     * 每次选取分界点的过程就是一次快排的过程。*/
    int index = partition(arr, low, high);
    /* 对分界点左边进行递归快排 */
    quickSort(arr, low, index-1);
    /* 对分界点右边进行递归快排 */
    quickSort(arr, index+1, high);
}

/* 改例程负责对数组元素的“应有位置”进行交换，
   凡是小于枢轴的元素都应该位列枢轴的左端，
   凡是大于枢轴的元素都应该位列枢轴的右端。 */
int partition(int* arr, int low, int high){
    int pivot = arr[low];
    while(low < high){
        while(low < high && arr[high] >= pivot){
            high--;
        }
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot){
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}
