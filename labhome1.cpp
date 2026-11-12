#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct Entry {
    string number;
};

void bubbleSort(Entry arr[], int n) {
    auto start = high_resolution_clock::now();

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[j].number > arr[j + 1].number) {
                Entry temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }

            for (int k = 0; k < n; k++) {
                cout << arr[k].number << ' ';
            }

            cout << '\n';
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << fixed << setprecision(6)
     << "bubbleSort() time: " 
     << duration.count() / 1e6 
     << " sec\n";
};



void selectionSort(Entry arr[], int n) {
    auto start = high_resolution_clock::now();

    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].number < arr[min_idx].number) {
                min_idx = j; 
            }
            for (int k = 0; k < n; k++) {
                cout << arr[k].number << ' ';
            }

            cout << '\n';
        }

        if (min_idx != i) {
            Entry temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;

            for (int k = 0; k < n; k++) {
                cout << arr[k].number << ' ';
            }

            cout << '\n';
        }
    }

        auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << fixed << setprecision(6)
     << "selectionSort() time: " 
     << duration.count() / 1e6 
     << " sec\n";
};

void insertionSort(Entry arr[], int n) {
    auto start = high_resolution_clock::now();

    for (int i = 1; i < n; i++) {
        Entry key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].number > key.number) {
            arr[j + 1] = arr[j];
            j--;
            for (int k = 0; k < n; k++) {
            cout << arr[k].number << ' ';
            }

            cout << '\n';
        }

        
        arr[j + 1] = key;
                for (int k = 0; k < n; k++) {
                cout << arr[k].number << ' ';
            }

            cout << '\n';
    }

          auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << fixed << setprecision(6)
     << "insertionSort() time: " 
     << duration.count() / 1e6 
     << " sec\n";
};

int partition(Entry arr[], int low, int high, int n) {
    Entry pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].number < pivot.number) {
            i++;
            Entry temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

            for (int k = 0; k < n; k++) {
                cout << arr[k].number << ' ';
            }
            cout << '\n';
        }
    }
    Entry temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    
    return i + 1;
}


void rec(Entry arr[], int low, int high, int n) {
            
    if (low < high) {
        for (int k = 0; k < n; k++) {
        cout << arr[k].number << ' ';
    }
    cout << endl;
        int p = partition(arr, low, high, n);
        rec(arr, low, p - 1, n);
        rec(arr, p + 1, high, n);
    }


}

void quickSort(Entry arr[], int low, int high, int n) {
auto start = high_resolution_clock::now();
    rec(arr, low, high, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << fixed << setprecision(6)
     << "quickSort() time: " 
     << duration.count() / 1e6 
     << " sec\n";
}


void printD (int n, Entry arr[]) {
    cout << "    " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i].number << endl;
    }
    cout << "    " << endl;
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    Entry arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the number: ";
        cin >> arr[i].number;
    }
    cout << "Directory before sorting: " << endl;
    printD(n, arr);
    Entry b[n];

    copy(arr, arr + n, b);
    cout << "SelectionSort: " << endl;
    selectionSort(b, n);
    printD(n, b);

    copy(arr, arr + n, b);
    cout << "InsertionSort: " << endl;
    insertionSort(b, n);
    printD(n, b);


    copy(arr, arr + n, b);
    cout << "BubbleSort: " << endl;
    bubbleSort(b, n);
    printD(n, b);

    copy(arr, arr + n, b);
    cout << "QuickSort: " << endl;
    quickSort(b, 0, n - 1, n);
    printD(n, b);

    return 0;
}