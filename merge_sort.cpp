#include<iostream>
using namespace std;
void merge(int a[], int lo, int mid, int hi, int aux[])
{
	int k =lo;
	for(k =lo; k<=hi;++k)
	{
		aux[k] = a[k];
	}
	int i = lo;
	int j = mid+1;
	for(k = lo; k<=hi;++k)
	{
		if(i>mid)
			a[k] = aux[j++];
		else if(j>hi)
			a[k] = aux[i++];
		else if(aux[i]>aux[j])
			a[k] = aux[j++];
		else
			a[k] = aux[i++];		
	
	}
}
void merge_sort(int a[], int lo, int hi, int a_size, int aux[])
{
	for(int sz=1; sz<a_size; sz=sz*2)
	{
		for(lo=0; lo<a_size-sz;lo+=sz*2)
		{
			merge(a, lo, lo+sz-1, min(lo+sz*2-1, a_size-1), aux);
		}
	}


}
int main(){

	int a[] ={27, 1, 28, 0, 67, 68, 93, 69, 74, 98};
	int aux[10];
	merge_sort(a, 0, 9, 10, aux);
	for(int i=0; i<10;++i)
		cout<<a[i]<<" ";	
}
