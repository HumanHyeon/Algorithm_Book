def strange_sort(strings, n): 
    return sorted(sorted(strings), key=lambda x: x[n])

strings = ["sun", "bed", "car"] 
print(strange_sort(strings, 1))