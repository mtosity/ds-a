#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
using namespace std;

#define MAX 26

struct Node
{
    struct Node *child[MAX];
    int countWord;
};

struct Node *newNode()
{
    struct Node *node = new Node;
    node->countWord = 0;
    for (size_t i = 0; i < 26; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

int main()
{
    struct Node *head = newNode();
    return 0;
}