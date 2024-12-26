#define ll long long int
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map<int, int> booked;

        // Custom comparator for priority queue
        auto compare = [](const pair<ll, int>& a, const pair<ll, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            } else {
                return a.first > b.first; 
            }
        };

        // Priority queue to keep track of end time and room id
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(compare)> pq(compare);
        // Priority queue to manage free rooms (sorted by room id)
        priority_queue<int, vector<int>, greater<int>> freerooms;
        for (int i = 0; i < n; i++) {
            freerooms.push(i);
        }

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        for (auto& v : meetings) {
            ll start = v[0], end = v[1];
            // Free up rooms whose end time is less than or equal to the current start time
            while (!pq.empty() && pq.top().first <= start) {
                freerooms.push(pq.top().second);
                pq.pop();
            }

            if (!freerooms.empty()) {
                // Assign a free room
                booked[freerooms.top()]++;
                pq.push({end, freerooms.top()});
                freerooms.pop();
            } else {
                // No free room, extend the meeting in the room with the earliest end time
                booked[pq.top().second]++;
                auto p = pq.top();
                pq.pop();
                pq.push({p.first + end - start, p.second});
            }
        }

        // Find the room with the maximum bookings
        int maxrooms = 0, meetingroom = -1;
        for (auto p : booked) {
            if (p.second > maxrooms) {
                maxrooms = p.second;
                meetingroom = p.first;
            }
        }

        return meetingroom;
    }
};
