#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> graph;

        // Build the graph and calculate indegrees
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int pre = prereq[1];
            graph[pre].push_back(course);
            indegree[course]++;
        }

        // Initialize a queue for courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            // Decrease the indegree of neighboring courses
            for (int neighbor : graph[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If count equals numCourses, it is possible to finish all courses
        return count == numCourses;
    }
};