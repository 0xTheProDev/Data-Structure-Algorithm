'''
    QUICK SORT
    DIVIDE AND COMPARE ALGORITHM
    
    BEST CASE RUNTIME : O(N logN)
    WORST CASE RUNTIME: O(N²)
    SPACE COMPLEXITY  : O(N)
'''
def partition(A, left, right, pivot):
    lIndex = left
    rIndex = right - 1
    while True:
        while(A[lIndex] < pivot):                       # Skip where element less than pivot are already
            lIndex += 1                                 #in the left of the wall
        while(rIndex > 0 and A[rIndex] > pivot):        # Skip where element greater than pivot are already
            rIndex -= 1                                 #in the right of the wall
        if(lIndex >= rIndex):                           # If both sides are already arranged, break the loop
            break
        else:
            A[lIndex], A[rIndex] = A[rIndex], A[lIndex] # Otherwise swap the elements according to position
    A[lIndex], A[right] = A[right], A[lIndex]           # Put Pivot in the border of the wall
    return lIndex                                       # Return current position of the wall

def qsort(A, left, right):
    if(right - left <= 0):                              # Trivial Case: Only one element in the array
        return
    pivot = A[right]                                    # PIVOT: Element against which the array has to be
                                                        #compared
    pIndex = partition(A, left, right, pivot)           # Partition Index: Both sides will be recursively
    qsort(A, left, pIndex - 1)                          #sorted and merge to final array
    qsort(A, pIndex + 1, right)

# Main:
A = [6, 5, 1, 3, 8, 4, 7, 9, 2]
qsort(A, 0, len(A) - 1)
print(A)
