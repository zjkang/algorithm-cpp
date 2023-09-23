// PriorityQueue

// Q1 Heapify
// Given an integer array, heapify it into a min-heap array.
// For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].

// Example
// Example 1
// Input : [3,2,1,4,5]
// Output : [1,2,3,4,5]
// Explanation : return any one of the legitimate heap arrays

// Challenge
// O(n) time complexity


// Heapify 的具体实现方法。时间复杂度为 O(n)O(n)，使用的是 siftdown
// 之所以是 O(n) 是因为从第 N/2 个位置开始往下 siftdown，那么就有大约 N/4 个数在 siftdown 中最多交换 1 次，N/8 个数最多交换 2 次，N/16 个数最多交换 3 次。
// 所以 O(N/4 * 1 + N/8 * 2 + N/16 * 3 + ... + 1 * LogN) = O(N)O(N/4∗1+N/8∗2+N/16∗3+...+1∗LogN)=O(N)
class Solution {
    void heapify(vector<int> A) {
        for (int i = A.size() / 2, i >= 0; i--) {

        }
    }

    void siftdown(vector<int>& A, int index) {
        int N = A.size();
        while (index < N) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int minIndex = index;
            if (left < N && A[left] < A[minIndex]) {
                minIndex = left;
            }
            if (right < N && A[right] < A[minIndex]) {
                minIndex = right;
            }
            if (minIndex == index) {
                break;
            }
            swap(A[minIndex], A[index]);
            index = minIndex;
        }
    }
};



// Q2 Smallest k Elements in an Unsorted Array
// Find the kth smallest number in an unsorted integer array.

// Example
// Example 1:
// Input: [3, 4, 1, 2, 5], k = 3
// Output: 3

// Example 2:
// Input: [1, 1, 1], k = 2
// Output: 1

class Solution {
    int kthSmallest(int k, vector<int> nums) {
        priority_queue<int, vector<int>> pq;
        for (auto num : nums) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else if (num < pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.front();
    }

};



// Q3 Priority Queue - Custom type
// https://leetcode.com/problems/the-maze-ii/

struct State {
    int dist;
    int x;
    int y;
};

struct Comp {
    bool operator()(State l, State r) {
        if (l.dist == r.dist) {
            if (l.x == r.x) return l.y > r.y;
            return l.x > r.x;
        }
        return l.dist > r.dist;
    }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start[0] == destination[0] && start[1] == destination[1]) return 0;
        priority_queue<State, vector<State>, Comp> pq;
        pq.push({0, start[0], start[1]});
        auto pairCmp = [](auto& l, auto& r) {
            if (l.first == r.first) return l.second < r.second;
            return l.first < r.first;
        };
        set<pair<int,int>, decltype(pairCmp)> dequeued;
        while (!pq.empty()) {
            auto state = pq.top(); pq.pop();
            dequeued.insert({state.x, state.y});
            if (state.x == destination[0] && state.y == destination[1]) {
                return state.dist;
            }
            for (auto& s : getNextLocations(maze, state.x, state.y)) {
                if (dequeued.count({s.x, s.y})) continue;
                pq.push({s.dist + state.dist, s.x, s.y});
            }
        }
        return -1;
    }

    vector<State> getNextLocations(vector<vector<int>>& maze, int x, int y) {
        int m = maze.size(), n = maze[0].size();
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};
        vector<State> nextLocs;
        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            int dist = 1;
            while (isInBound(cx, cy, maze) && maze[cx][cy] == 0) {
                cx += dx[i];
                cy += dy[i];
                dist++;
            }
            cx -= dx[i];
            cy -= dy[i];
            dist--;
            if (cx != x || cy != y) {
                nextLocs.push_back({dist, cx, cy});
            }
        }
        return nextLocs;
    }

    bool isInBound(int x, int y , vector<vector<int>>& maze) {
        return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size();
    }
};       


// Q3.6 Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
































