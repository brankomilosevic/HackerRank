/*
HACKERRANK: Deque STL
https://www.hackerrank.com/challenges/deque-stl

findint the maximum of k-size slice sliding over n-sized array
*/

#include <iostream>
#include <deque> 
#include <vector>
#include <set>
using namespace std;

void printKMax(int arr[], int n, int k)
{
	//Write your code here.
   deque<int> dq;
   vector<int> res;

   // for First K elements
   for( int i = 0; i < k; ++i)
   {
       while( !dq.empty() && arr[i] >= arr[dq.back()])
           // Remove the indices of elements that are smaller than the current elements
           dq.pop_back();
       // add as a maximum    
       dq.push_back(i);
   }
   // the element at the front has index of the highest element in the window
   res.push_back(arr[dq.front()]);
   // for the rest of the array
   for ( int i = k; i < n; ++i )
   {
        // drop the elements that are out of window
        while(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();
        
        // repeat what we have done for first k elements
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();  
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
   }   
   
   for (int i : res)
    cout << i << " ";
    
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}