#include<bits/stdc++.h>
using namespace std;
int comparision;
int partition(int A[],int l,int r){
    int pivot = A[l];
    int i = l + 1;
    for(int j = l + 1;j<=r;j++){
        if(A[j] < pivot){
            swap(A[i],A[j]);
            i++;
        }
    }
    swap(A[i-1],A[l]);
    return (i-1);
}
int partition2(int arr[],int left, int right)
{
	int pos=right;
	swap(arr[left],arr[pos]);
	int pivot=arr[left];
	int i=left+1;
	for(int j=left+1;j<=right;j++){
		if(arr[j]<pivot){
			swap(arr[i],arr[j]);
			i++;
		}
	}
	swap(arr[left],arr[i-1]);
	return i-1;
}
int partition3(int arr[],int left,int right)
{
	int pos;
	int mid=(left+right)/2;
	if(mid==left || mid==right)
		pos=mid;
	else
	{
		int mini=min(arr[left],min(arr[right],arr[mid]));
		int maxi=max(arr[left],max(arr[right],arr[mid]));
		int ar[]={left,right,mid};
		for(int i=0;i<3;i++){
			if(arr[ar[i]]!=mini and arr[ar[i]]!=maxi)
				pos=ar[i];
		}
	}
	swap(arr[left],arr[pos]);
	int pivot=arr[left];
	int i=left+1;
	for(int j=left+1;j<=right;j++){
		if(arr[j]<pivot){
			swap(arr[i],arr[j]);
			i++;
		}
	}
	swap(arr[left],arr[i-1]);
	return i-1;
}
void quicksort(int arr[],int l,int h){
	int p;
	if(h<=l)
		return;
	comparision+=h-l;
    p = partition(arr,l,h);
 	quicksort(arr,l,p-1);
 	quicksort(arr,p+1,h);
}
void quicksort2(int arr[],int l,int h){
	int p;
	if(h<=l)
		return;
	comparision+=h-l;
    p = partition2(arr,l,h);
 	quicksort2(arr,l,p-1);
 	quicksort2(arr,p+1,h);
}
void quicksort3(int arr[],int l,int h){
	int p;
	if(h<=l)
		return;
	comparision+=h-l;
    p = partition3(arr,l,h);
 	quicksort3(arr,l,p-1);
 	quicksort3(arr,p+1,h);
}
int main(){
    int n;
    FILE *fp=freopen("QuickSort.txt","r",stdin);
    int arr1[10003];
    int arr2[10003];
    int arr3[10003];
    int i=0;
    while(scanf("%d",&n)>0){
		arr1[i]=n;
		arr2[i]=n;
		arr3[i]=n;
		i++;
	}
	comparision=0;
    quicksort(arr1,0,i-1);
    cout << "Total no of comparision when first element="<<comparision << endl;
	comparision=0;    
    quicksort2(arr2,0,i-1);
    cout << "Total no of comparision when last element="<<comparision << endl;
	comparision=0;
	quicksort3(arr3,0,i-1);
    cout << "Total no of comparision when median element="<<comparision << endl;
    return 0;
}

