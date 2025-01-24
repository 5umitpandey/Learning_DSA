/*
Do Max number of activities, given their start and finish time.
(i)  Greedy Approach | Sort & Vector
(ii) Greedy Approach | Sort, Pair & Vector
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SortBasedOnFinish(vector<int> &s, vector<int> &f) 
{
    vector<int> indices(f.size());

    // Initialize indices with 0, 1, 2, ...
    for (size_t i = 0; i < indices.size(); ++i) {
        indices[i] = i;
    }

    // Sort indices based on the finish times in f
    sort(indices.begin(), indices.end(), [&f](int a, int b) {
        return f[a] < f[b];
    });

    // Reorder s and f based on the sorted indices
    vector<int> s_sorted(s.size()), f_sorted(f.size());
    for (size_t i = 0; i < indices.size(); ++i) {
        s_sorted[i] = s[indices[i]];
        f_sorted[i] = f[indices[i]];
    }

    // Copy the sorted vectors back to s and f
    s.swap(s_sorted);
    f.swap(f_sorted);
}

int MaxActivities(vector <int> s, vector <int> f)
{
    int n = s.size();

    int count = 1;  // The first activity is always selected
    int i = 0;

    // Sort based on finish times
    SortBasedOnFinish(s, f);

    // First Activity is always selected
    cout << "Start Times are : " << s[i] << " ";  

    for (int j = 1; j < n; j++) {
        if (s[j] >= f[i]) {
            cout << s[j] << " ";
            i = j;
            count++;
        }
    }

    cout << "\nTotal Activites = ";
    return count;

}

//Pair
void MaxActivities_Pair(vector<int> &start, vector<int> &finish) {
    int n = start.size();

    // Sort based on finish times
    vector<pair<int, int>> activities(n);
    for (int i = 0; i < n; ++i) {
        activities[i] = {finish[i], start[i]};
    }
    sort(activities.begin(), activities.end());

    vector<int> selectedActivities;
    int lastFinishTime = -1; // Initialize to a time before the first activity

    for (const auto &activity : activities) {
        if (activity.second >= lastFinishTime) {
            selectedActivities.push_back(activity.second);
            lastFinishTime = activity.first;
        }
    }

    cout << "Start Times are : ";
    for (int s : selectedActivities) {
        cout << s << " ";
    }
    cout << endl;
}

int main()
{                      
    vector <int> s = { 5, 8, 1, 3, 5, 0 };
    vector <int> f = { 9, 9, 2, 4, 7, 6 };

    //cout << MaxActivities(s, f);
    
    MaxActivities_Pair(s, f);

    return 0;
}