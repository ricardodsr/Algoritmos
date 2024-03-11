def quickselect(arr, k):
    if k < 1 or k > len(arr):
        return None

    pivot = arr[random.randint(0, len(arr) - 1)]
    smaller = [x for x in arr if x < pivot]
    larger = [x for x in arr if x > pivot]

    if k - 1 < len(smaller):
        return quickselect(smaller, k)
    elif k - 1 >= len(arr) - len(larger):
        return quickselect(larger, k - (len(arr) - len(larger)))
    else:
        return pivot
