class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //at first we have to declare a distance array
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        //at first we have to make the all the diagonal elements as 0
        for(int i=0;i<n;i++)
        {
            dist[i][i]=0;
        }
        //now we have to assign as per the edges matrix
        for(auto &it:edges)
        {
            int from=it[0];
            int to=it[1];
            int wt=it[2];
            dist[from][to]=wt;
            dist[to][from]=wt;
        }

        //apply floyd warshall algo.
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dist[i][j]=min(dist[i][j],(dist[i][via]+dist[via][j]));
                }
            }
        }
        //now finding the number of cities,reached from each city in the threshold distance
        int mini=n,city=-1;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(mini >= count)
            {
                mini=count;
                city=i;
            }
        }

        return city;

    }
};
