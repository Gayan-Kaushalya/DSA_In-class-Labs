#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{  
	int largest; 
	int left = 2 * root + 1; 
	int right = 2 * root + 2; 

	if (left < n && arr[left] > arr[root]){
		largest = left;
   } else{
		largest = root;
	}

	if (right < n && arr[right] > arr[largest]){
		largest = right;
   }

	if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

		heapify(arr, n, largest);
	}
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{  
   // build heap 
   for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
   }
     
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 1; i--) {                   
		int temp = arr[i];
      arr[i] = arr[0];
      arr[0] = temp;

		heapify(arr, i, 0);
	}
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{  int a,sz;

   cout << "Input array size - ";
   cin >> sz;
   int heap_arr[sz];

   
   for (int i = 0; i < sz; i++){
      cout << "Input element " << i + 1 << " - " ;
      cin >> a;
      heap_arr[i] = a ;
   }

   cout << "\n";

   cout<<"Input array:"<<endl;
   displayArray(heap_arr,sz);
  
   heapSort(heap_arr, sz);
  
   cout << "Sorted array:"<<endl;
   displayArray(heap_arr, sz);
}