#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
int Swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void Display(struct Array arr){
    int i;
    printf("\nElements are: ");
    for (i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
}
void Append(struct Array *arr,int x){
    if (arr->length<arr->size)
    arr->A[arr->length++]=x;
}
void Insert(struct Array*arr,int index,int x){
    int i;
    if (index>=0 && index<=arr->length){
        for (i=arr->length;i>index;i--)
        arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}
int Delete(struct Array *arr,int index){
    int x=0;
    if (index>=0 && index<arr->length){
        x=arr->A[index];
        for (int i=index;i<arr->length-1;i++)
        arr->A[i]=arr->A[i+1];
        arr->length--;
    }
    return x;
}
int LinearSearch(struct Array arr,int key){
    int i;
    for (i=0;i<arr.length;i++){
        if(key==arr.A[i])
            return i;
    }
    return -1;
}
int BinSearch(struct Array arr,int key){
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else 
            l=mid+1;
    }
    return -1;
}
int RecurBinSearch(struct Array arr,int l,int h,int key){
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            return RecurBinSearch(arr,l,mid-1,key);
        else
            return RecurBinSearch(arr,mid+1,h,key);
    }
    return -1;
}
int Get (struct Array B, int index){
    if(index>=0 && index<B.length)
        return B.A[index];
    return -1;
}
void Set (struct Array *C, int index, int value){
    if (index>=0 && index<C->length)
        C->A[index]=value;
}
int Max (struct Array D){
    int max= INT_MIN;
    for (int i=0;i<D.length;i++)
        if(D.A[i]>max)  
            max=D.A[i];
    return max;

}
int Min(struct Array E){
    int min=INT_MAX;
    for (int i=0;i<E.length;i++)
        if(E.A[i]<min)
            min = E.A[i];
    return min;
}
int Sum(struct Array F){
    int total=0;
    for(int i=0;i<F.length;i++){
        total+=F.A[i];
    }
    return total;
}
void Reverse(struct Array *G){
    int *B;
    int i,j;
    B=(int *)malloc(G->length*sizeof(int));
    for (i=0,j=G->length-1;j>=0;i++,j--){
        B[i]=G->A[j];
    }
    for(i=0;i<G->length;i++){
        G->A[i]=B[i];
    }
}
void Reverse2(struct Array *H){
    int i,j;
    for (i=0,j=H->length-1;i<j;i++,j--){
        int temp=H->A[i];
        H->A[i]=H->A[j];
        H->A[j]=temp;

    }
}
void InsertinSort(struct Array *I,int value){
    if (I->length==I->size)
     return;
    int i=I->length-1;
    while ( i>=0 && I->A[i]>value) {
        I->A[i+1]= I->A[i];
        i--;
    }
    I->A[i+1]=value;
    I->length++;
}
int isSorted(struct Array J){
    for (int i=0;i<J.length-1;i++){
        if(J.A[i]>J.A[i+1])
            return 0;
    }
    return 1;
}
void Rearrange(struct Array *arr){
    int i=0,j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0){i++;}
        while (arr->A[j]>=0)    
        {
            j--;
        }
        if (i<j)
            Swap(&arr->A[i],&arr->A[j]);
         }
}

int main(){
    struct Array arr={{2,13,24,35,46},10,5};
    //Append(&arr,10); 
    //Insert(&arr,5,20);
    //printf("%d\n",Delete(&arr,0));
    Display(arr);
    printf("\nIndex of 5 is : %d",LinearSearch(arr,5));
    printf("\nIndex of 5 is : %d",BinSearch(arr,5));
    printf("\nIndex of 5 is : %d",RecurBinSearch(arr,0,5,4));
    // Set(&arr,2,20);
    printf("\nMax Element is: %d",Max(arr));
    printf("\nSum Is: %d ",Sum(arr));
    // Display(arr);
    // Reverse(&arr);
    // Reverse2(&arr);
    // printf("\n");
    Display(arr);
    InsertinSort(&arr,16);
    Display(arr);
    printf("\n%d",isSorted(arr));
    return 0;
}   
