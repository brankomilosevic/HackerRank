/*
HACKERRANK: Lower Bound Problem
https://www.hackerrank.com/challenges/cpp-lower-bound
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, Q, c, left, right, mid;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i)
        cin >> A[i];
    
    cin >> Q;
    // Finding the values in vector by iterating was producing time-limit
    // Binary search instead
    for (int i=0; i<Q; ++i)
    {
        cin >> c;
        left = 0;
        right = A.size();
        mid = (right + left) / 2;
        bool found = false;
        
        while (left <= right && !found)
        {
            if (A[mid] > c)
                right = mid - 1;
            if  (A[mid] < c)
                left = mid + 1; 
            if (A[mid] == c)
                found = true;

            mid = (right + left) / 2;
        }   
        if (found)
        {
            while (mid >= 0 && A[mid] == c)
                --mid;
            cout << "Yes " << mid+2 << '\n';
        }
        else
        {
            while (mid >= 0 && A[mid] > c)
                --mid;
            cout << "No " << mid+2 << '\n';
        }
    }
    return 0;
}
