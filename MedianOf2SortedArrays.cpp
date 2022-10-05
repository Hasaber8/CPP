#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define all(c) (c).begin(),(c).end()


class Solution {
public:
    double mediann(vi&a,vi&b){
        int m=a.size();
        int n=b.size();
        if(m>n)
            return mediann(b,a);
        int l=0,r=m;
        while(l<=r){

            int partx=l+(r-l)/2;
            int party=(m+n+1)/2-partx;
            int maxlx=(partx==0)?INT_MIN:a[partx-1];
            int minrx=(partx==m)?INT_MAX:a[partx];
            int maxly=(party==0)?INT_MIN:b[party-1];
            int minry=(party==n)?INT_MAX:b[party];

            if(maxlx<=minry&&maxly<=minrx){
                if((m+n)%2==0)
                    return (double)(max(maxlx,maxly)+min(minrx,minry))/2;
                else
                    return (double)(max(maxlx,maxly));
            }else if(maxlx>minry)
                r=partx-1;
            else
                l=partx+1;
        }
        return -1.0;
    }
    double findMedianSortedArrays(vi& nums1, vi& nums2) {
        double ans;
        ans=mediann(nums1,nums2);
        return ans;   
    }
};


int main() {
    
    Solution s;
    vi a = {1, 2};
    vi b = {3, 4};
    
    cout << s.findMedianSortedArrays(a,b);

    return 0;
}