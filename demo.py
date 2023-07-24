import _sort

arr = [5, 2, 7, 1, 9]
#n = len(arr)

print("Original Array: ", arr)

_sort.Bubble_Sort(arr)
print("Bubble Sorted Array: ", arr)

_sort.Merge_Sort(arr)
print("Merge Sorted Array: ", arr)

_sort.Quick_Sort(arr)
print("Quick Sorted Array: ", arr)

_sort.Insertion_Sort(arr)
print("Insertion Sorted Array: ", arr)
