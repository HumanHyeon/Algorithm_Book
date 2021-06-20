result = 0

def treeInorderTraversal(num, count, a, graph, visited):
    global result

    visited[num] = True
    for node in graph[num]:
        if not visited[node]:
            a[num] += treeInorderTraversal(node, count, a, graph, visited)
    result += abs(a[num])
    return count + a[num]


def solution(a, edges):
    sumWeight = 0
    isZero = True

    for weight in a:
        sumWeight += weight
        if a != 0:
            isZero = False

    if sumWeight != 0:
        return -1
    elif isZero:
        return 0
    else:
        graph = [[] for _ in range(len(a))]
        visited = [False] * len(a)

        for edge in edges:
            x, y = edge
            graph[x].append(y)
            graph[y].append(x)

        treeInorderTraversal(0, 0, a, graph, visited)
        return result
