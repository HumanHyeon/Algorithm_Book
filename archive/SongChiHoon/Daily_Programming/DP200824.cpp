// 이진탐색트리안에 X보다 크고 Y보다 작은 모든 노드 값을 프린트 하시오.



// Given a binary search tree, print all node values that are bigger than X and smaller than Y.

#include <iostream>
using namespace std;

class NODE
{
private:
    int value;
    NODE* right;
    NODE* left;
public:
    NODE();
    ~NODE();
};

NODE::NODE()
{
}

NODE::~NODE()
{
}

int main() {
    NODE node;
}