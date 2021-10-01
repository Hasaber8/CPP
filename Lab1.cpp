#include <iostream>

using namespace std;

//GCD

int min(int x, int y) { return x < y ? x : y; }

int getGCD(int a, int b) {
  int minimum = min(a, b);
  int gcd;
  for (int i = minimum; i > 0; --i) {
    if (a % i == 0 && b % i == 0) {
      gcd = i;
      return gcd;
    }
  }
  return 1;
}

int main() {
  int a, b;
  cout << "Enter two numbers: ";
  cin >> a >> b;

  cout << "GCD of " << a << " and " << b << ": " << getGCD(a, b) << '\n';

  return 0;
}


//Max,Average,Mode

#include <iostream>

using namespace std;

class Array {
 private:
  int size;
  int *a;

 public:
 Array::Array(int size) {
  this->size = size;
  this->a = new int[size];
}

void Array::inputArray() {
  cout << "Enter " << size << " array elements: \n";
  for (int i = 0; i < size; ++i) {
    cin >> a[i];
  }
}

void Array::printArray() {
  cout << "Array elements: \n";
  for (int i = 0; i < size; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int Array::max() {
  int maximum = a[0];
  for (int i = 1; i < size; ++i) {
    if (a[i] > maximum) {
      maximum = a[i];
    }
  }
  return maximum;
}

double Array::average() {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += a[i];
  }
  return (double)sum / size;
}

int Array::mode() {
  int maximum = max();

  int count[maximum + 1];
  for (int i = 0; i < maximum + 1; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; ++i) {
    count[a[i]]++;
  }

  int mod = 0;
  int k = count[0];
  for (int i = 1; i < maximum + 1; ++i) {
    if (count[i] > k) {
      k = count[i];
      mod = i;
    }
  }

  return mod;
}



};

int main() {
  cout << "Enter size of array: ";
  int n;
  cin >> n;

  Array arr(n);
  arr.inputArray();
  arr.printArray();
  cout << "Max: " << arr.max() << '\n';
  cout << "Average: " << arr.average() << '\n';
  cout << "Mode: " << arr.mode() << '\n';

  return 0;
}

//Search

#include <iostream>

using namespace std;

class Array {
 private:
  int *a;
  int size;

 public:
Array::Array(int size) {
  this->size = size;
  this->a = new int[size];
}

void Array::inputArray() {
  cout << "Enter " << size << " array elements: \n";
  for (int i = 0; i < size; ++i) {
    cin >> a[i];
  }
}

void Array::printArray() {
  cout << "Array elements: \n";
  for (int i = 0; i < size; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int Array::linearSearch(int key) {
  for (int i = 0; i < size; ++i) {
    if (a[i] == key) {
      return i;
    }
  }
  return -1;
}

int Array::binarySearch(int key) {
  int l = 0;
  int h = size - 1;
  int i = 0;

  while (l <= h) {
    int mid = l + (h - l) / 2;

    if (key == a[mid]) {
      return mid;
    } else if (key > a[mid]) {
      l = mid + 1;
    } else if (key < a[mid]) {
      h = mid - 1;
    }
    i++;
  }
  return -1;
}

};


int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  Array arr(n);
  arr.inputArray();
  int key;
  cout << "Enter element to search (linear search): ";
  cin >> key;

  cout << "Index: " << arr.linearSearch(key) << '\n';

  cout << "Enter element to search (binary search): ";
  cout << "Index: " << arr.binarySearch(key) << '\n';

  return 0;
}

//Sort


#include <iostream>

using namespace std;

class Array {
 private:
  int size;
  int *a;

 public:
  Array::Array(int size) {
  this->size = size;
  this->a = new int[size];
}

void Array::inputArray() {
  cout << "Enter " << size << " array elements: \n";
  for (int i = 0; i < size; ++i) {
    cin >> a[i];
  }
}

void Array::printArray() {
  cout << "Array elements: \n";
  for (int i = 0; i < size; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

void Array::insertionSort() {
  for (int i = 1; i < size; ++i) {
    int key = a[i];

    int j = i - 1;
    // moving the elements of a[0..i-1], that are greater than key, to one
    // position ahead of their current position
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

};


void quickSort(int[], int, int);
int partition(int[], int, int);
void swap(int *, int *);
void printArray(int arr[], int n);

int main() {
  cout << "Enter size of array: ";
  int n;
  cin >> n;

  Array arr(n);
  arr.inputArray();
  arr.printArray();

  arr.insertionSort();

  arr.printArray();

  return 0;
}

