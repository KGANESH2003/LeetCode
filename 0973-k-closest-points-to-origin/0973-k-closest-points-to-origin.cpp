class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>result;

        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0],y=points[i][1];
            int dist=x*x+y*y;
            pq.push({dist,{x,y}});

            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        while(!pq.empty())
        {
            result.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};