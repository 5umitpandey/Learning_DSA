#include <iostream>
#include <chrono>
using namespace std;

class Timer {
public:
    Timer() : start(std::chrono::high_resolution_clock::now()) {}

    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }

    double elapsedMicroseconds() const {
        return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() - start).count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};


void PrintArray(int arr[], int n)
{
    for( int i=0; i<n; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Timer timer;
    
    int arr[] = {900, 500, 44, -12, 88, -77, 215};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nArray is "; PrintArray(arr, n);

    //BubbleSort(arr, n);

    cout << "\nSorted Array: "; PrintArray(arr, n);

    std::cout << "Time elapsed: " << timer.elapsedMicroseconds() << " microseconds\n";
    return 0;
}
