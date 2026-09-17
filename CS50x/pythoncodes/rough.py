def allocate_pages(arr, n, m):

    # If only one student
    # that student gets all books
    if m == 1:
        return sum(arr)

    # If only one book
    if n == 1:
        return arr[0]

    answer = float('inf')

    # Try every possible place to divide
    for i in range(1, n):

        student1 = sum(arr[:i])

        student2 = allocate_pages(arr, n - i, m - 1)

        maximum = max(student1, student2)

        answer = min(answer, maximum)

    return answer


L = [12, 34, 67, 90]

print(allocate_pages(L, len(L), 2))