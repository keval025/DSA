#include <bits/stdc++.h>
using namespace std;

void builtSegmentTree(int i, int st, int end, vector<int> &segmentTree, vector<int> nums){
    if(st == end){
        segmentTree[i] = nums[st];
        return;
    }

    int mid = st + (end - st) / 2;
    builtSegmentTree(2*i+1, st, mid, segmentTree, nums);
    builtSegmentTree(2*i+2, mid+1, end, segmentTree, nums);
    segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
}

int querySum(int st, int end, int i, int l, int r, vector<int> segmentTree){
    if(l > end || r < st){
        return 0;
    }

    if(l >= st && r <= end){
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;

    return querySum(st, end, 2*i+1, l, mid, segmentTree) + 
    querySum(st, end, 2*i+2, mid+1, end, segmentTree);
}

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> nums(n, 0);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    vector<vector<int>> queries(q, vector<int>(2, 0));

    for(int i=0;i<q;i++){
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> segmentTree(4*n, 0);
    builtSegmentTree(0, 0, n-1, segmentTree, nums);

    vector<int> result(q, 0);

    for(int i=0;i<q;i++){
        int l = queries[i][0];
        int r = queries[i][1];

        result[i] = querySum(l, r, 0, 0, n-1, segmentTree);
    }
    for(int i=0;i<q;i++){
        cout << result[i] << " ";
    }
};