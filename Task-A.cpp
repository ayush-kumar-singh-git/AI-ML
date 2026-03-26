/*
Task : You are given a starting integer a and a target integer b. (both >= 0)
Your goal is to reach from a to b by repeatedly applying any of the following four operations :
x -> 2*x
x -> [x/2]
x -> x^2
x -> x + 1
where [x] is the floor function.
If there exists a sequence of operations find it. (Bonus: Find the shortest sequence)
*/

#include <bits/stdc++.h>
#define MAX 10000

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::set<int> seen;
    std::queue<int> q;
    std::map<int, int> parent;
    q.push(a);
    seen.insert(a);
    while (!q.empty())
    {
        int curr = q.front();
        if (curr == b)
            break;
        std::vector<int> nextNodes = {curr + 1, curr / 2, 2 * curr, curr * curr};
        for (int node : nextNodes)
        {
            if (node < MAX && !seen.count(node))
            {
                q.push(node);
                seen.insert(node);
                parent[node] = curr;
            }
        }
        q.pop();
    }

    int node = b;
    std::vector<int> path;
    while (node != a)
    {
        path.emplace_back(node);
        node = parent[node];
    }
    path.emplace_back(a);
    reverse(path.begin(), path.end());
    for (int x : path)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}