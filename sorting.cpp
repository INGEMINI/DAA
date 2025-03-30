#include <vector>
#include <iostream>
using namespace std;

void bubblesort(vector<int> &v)
{
  int n = v.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (v[j] > v[j + 1])
      {
        swap(v[j], v[j + 1]);
      }
    }
  }
}

void selectionsort(vector<int> &v)
{
  int n = v.size();
  for (int i = 0; i < n - 1; i++)
  {
    int minindex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (v[j] < v[minindex])
      {
        minindex = j;
      }
    }

    swap(v[i], v[minindex]);
  }
}

void insertionsort(vector<int> &v)
{
  int n = v.size();
  for (int i = 1; i < n; i++)
  {
    int key = v[i], j = i - 1;
    while (j >= 0 && v[j] > key)
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}
int partition(vector<int> &v, int low, int high)
{
  int pivot = v[high], i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (v[j] < pivot)
    {
      i++;
      swap(v[i], v[j]);
    }
  }

  swap(v[i + 1], v[high]);
  return i + 1;
}

void quicksort(vector<int> &v, int low, int high)
{

  if (low < high)
  {
    int pi = partition(v, low, high);
    quicksort(v, low, pi - 1);
    quicksort(v, pi + 1, high);
  }
}

void merge(vector<int> &v, int left, int mid, int right)
{

  int n1 = mid - left + 1, n2 = right - mid;
  vector<int> l(n1), r(n2);

  for (int i = 0; i < n1; i++)
  {
    l[i] = v[left + i];
  }
  for (int j = 0; j < n2; j++)
  {
    r[j] = v[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (l[i] <= r[j])
    {
      v[k++] = l[i++];
    }
    else
    {
      v[k++] = r[j++];
    }
  }

  while (i < n1)
  {
    v[k++] = l[i++];
  }

  while (j < n2)
  {
    v[k++] = r[j++];
  }
}

void mergesort(vector<int> &v, int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    mergesort(v, left, mid);
    mergesort(v, mid + 1, right);
    merge(v, left, mid, right);
  }
}

void printvector(vector<int> &v)
{
  for (int num : v)
  {
    cout << num << " ";
    cout << endl;
  }
}

int main()
{
  int n, choice;
  cout << "enter no of elements";
  cin >> n;

  vector<int> v(n);
  cout << "enter elements";
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  do
  {
    cout << "\nsorting algorithm menu: ";
    cout << "1 bubble sort";
    cout << "2 selection sort";
    cout << "3 insertion sort";
    cout << "4 quick sort";
    cout << "5 merge sort";
    cout << "6 heap sort";
    cout << "7 exit";
    cout << "enter yr choice ";
    cin >> choice;
    vector<int> temp = v;
    switch (choice)
    {
    case 1:
      bubblesort(temp);
      cout << "sorted vector is ";
      printvector(temp);
      break;

    case 2:
      selectionsort(temp);
      cout << "sorted vector is ";
      printvector(temp);
      break;

    case 3:
      insertionsort(temp);
      cout << "sorted vector is ";
      printvector(temp);
      break;

    case 4:
      quicksort(temp, 0, n - 1);
      cout << "sorted vector is ";
      printvector(temp);
      break;

    case 5:
      mergesort(temp, 0, n - 1);
      cout << "sorted vector is ";
      printvector(temp);
      break;

    case 6:
      // heapsort(temp);
      cout << "not made function for this..itne main itna hi  milega";
      printvector(temp);
      break;

    case 7:

      cout << "exit";

      break;

    default:
      cout << "invalid choice ..enter again";
    }
  }

  while (choice != 7);

  return 0;
}