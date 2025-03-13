#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n)
{
    //selection sort : get min and swap
    //everytime we set first element
    for(int i=0;i<n;i++)
    {
        int min=INT_MAX;
        int k;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                k=j;
            }
        }
        swap(arr[i],arr[k]);
    }
}
void bubble_sort(int arr[],int n)
{
    //bubble sort : get max and swap
    //every time we set the last element
    for(int i=n-1;i>=1;i--)
    {
        int s=0;
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]),s++;
        }
        if(!s)break;
        //cout<<"run"<<endl;
    }
}
void insertion_sort(int arr[],int n)
{
  //insertion sort: pick element and compare with previous elements and place at its right possition
  for(int i=0;i<n;i++)
  {
    int j=i;
    while(j>0 && arr[j-1]>arr[j])
    {
      swap(arr[j],arr[j-1]);
      j--;
    }
  }
}

void merge(int arr[], int low, int mid, int high)
{
    // Your code here
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}
<<<<<<< Tabnine <<<<<<<
/**//+
 * \brief Performs the quick sort algorithm on a given array of integers.//+
 *//+
 * The quick sort algorithm is a divide-and-conquer sorting algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted.//+
 *//+
 * \param arr The array to be sorted.//+
 * \param start The starting index of the sub-array to be sorted.//+
 * \param end The ending index of the sub-array to be sorted.//+
 *//+
 * \return void. The function sorts the array in-place.//+
 *///+
void quickSort(int arr[], int start, int end) //+
{//+
    if(start < end)//+
    {//+
        int pivot_index = partitionArray(arr, start, end);//+
        quickSort(arr, start, pivot_index - 1);//+
        quickSort(arr, pivot_index + 1, end);//+
    }//+
}//+
>>>>>>> Tabnine >>>>>>>// {"conversationId":"c6f7cab5-4143-4a4a-a880-1336898b91a5","source":"instruct"}
void mergeSort(int arr[], int low, int high)
{
    // code here    
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int partitionArray(int arr[], int start, int end) 
{
	// Write your code here
	int pivot=arr[start];
	int i=start;
	int j=end;
	while(i<j)
	{
		while(arr[i]<=pivot && i<end)
		i++;
		while(arr[j]>pivot && j>start)
		j--;
		if(i<j)
		swap(arr[i],arr[j]);
	}
	swap(arr[start],arr[j]);
	return j;
}

void quickSort(int arr[], int start, int end) 
{
	if(start<end)
	{
		int pivot_index=partitionArray(arr,start,end);
		quickSort(arr,start,pivot_index-1);
		quickSort(arr,pivot_index+1,end);
	}
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    mergeSort(arr, 0, n);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}