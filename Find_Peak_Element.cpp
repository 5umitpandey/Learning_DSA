int findPeakElement(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2;

    // Check if mid is a peak element
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
        return mid;
    }

    // If the left neighbor is greater, then the peak lies on the left side
    if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeakElement(arr, low, mid - 1, n);
    }

    // If the right neighbor is greater, then the peak lies on the right side
    return findPeakElement(arr, mid + 1, high, n);
}