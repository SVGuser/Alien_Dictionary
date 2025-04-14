class Solution {
public:
    bool dfs(int start, vector<vector<int>>& graph, vector<int>& visit, vector<int>& record, string &answer) {
        visit[start] = 1;
        record[start] = 1;
        //Coded by Shreshth Vardhan Godaria
        for (int i = 0; i < 26; i++) {
            if (graph[start][i] == 1) {
                if (!visit[i]) {
                    if (!dfs(i, graph, visit, record, answer)) {
                        return false;
                    }
                } else if (record[i]) {
                    
                    return false;
                }
            }
        }

        answer += ('a' + start);
        record[start] = 0;
        return true;
    }

    string findOrder(vector<string>& words) {
        vector<vector<int>> graph(26, vector<int>(26, 0));
        vector<int> exist(26, 0);
        vector<int> visit(26, 0);
        vector<int> record(26, 0);
        string answer = "";

        for (auto& word : words) {
            for (char ch : word) {
                exist[ch - 'a'] = 1;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            const string &a = words[i], &b = words[i + 1];
            int n = a.size(), m = b.size(), ind = 0;

            while (ind < n && ind < m && a[ind] == b[ind]) {
                ind++;
            }

            if (ind < n && ind == m) {
                // Invalid ordering: prefix case
                return "";
            }

            if (ind < n && ind < m) {
                graph[a[ind] - 'a'][b[ind] - 'a'] = 1;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (exist[i] && !visit[i]) {
                if (!dfs(i, graph, visit, record, answer)) {
                    return "";
                }
            }
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};
