//Time: 28 ms (93.59%), Space: 89.4 MB (64.06%) - LeetHub
// O(log(min(m,n)))

#define INF (1<<20)

class Solution {
public:
    double MBS(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size();
        int N = nums2.size();
        
        if(M > N) return MBS(nums2, nums1);        // nums1의 길이는 nums2의 길이 이하여야함
        
        int medIdx = N+M+1>>1;
        bool odd = (M + N) % 2;
        
        int le = 0;
        int ri = M;
        
        while(le <= ri) {
    
            int Lp = le + ri >> 1;              // nums1의 이진탐색
            int Rp = medIdx - Lp;               // nums2는 이진탐색 없이 median idx에서 이진탐색된 nums1의 pointer를 빼서 설정
            
            //짝수일때 중앙값을 찾기 위해 두 인덱스가 필요
            int LL = (Lp == 0) ? -INF : nums1[Lp-1];    
            int LR = (Lp == M) ? INF : nums1[Lp];
            
            int RL = (Rp == 0) ? -INF : nums2[Rp-1]; 
            int RR = (Rp == N) ? INF : nums2[Rp];
            
            
            if(RR < LL) ri = Lp - 1;        // nums1 측 두 값이 nums2 측보다 크니까 nums1측 포인터를 올린다
            else if (LR < RL) le = Lp + 1;  // nums1 측 두 값이 nums2 측 보다 낮음, 포인터 낮춤
            else{   // LL > RR && RL > LR 인 상황은 없고, nums1 측과 nums2 측이 겹치는 상태
                if(odd) return (double)max(LL, RL);             //실제 median을 가리키는 인덱스는 두 포인터의 1 감소된 위치들중 큰값이다. 0부터 시작하기 때문
                return (double)(max(LL, RL) + min(LR, RR)) / 2;
            }
           
           
        }
        return -1.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return MBS(nums1, nums2);
    }
};
