/*
HACKERRANK: Attending Workshops
https://www.hackerrank.com/challenges/attending-workshops
*/

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start;
    int duration;
    int end;
};

struct Available_Workshops
{
    int n;
    struct Workshop *ws;
};

struct Available_Workshops * initialize (int *st, int *du, int n)
{
    struct Available_Workshops *aw = (struct Available_Workshops *) malloc (sizeof(Available_Workshops));
    aw->n = n;
    aw->ws = (struct Workshop *) malloc(n * sizeof(struct Workshop));

    for (int i=0; i<n; ++i)
    {
        aw->ws[i].start = st[i];
        aw->ws[i].duration = du[i];
        aw->ws[i].end = st[i] + du[i];
    }

    return aw;
}

// just a helper to confirm the load and sorting is working fine
void print_aw(struct Available_Workshops *aw)
{
    cout << "\n>>>\nN: " << aw->n;
    for (int i=0; i<aw->n; ++i)
        cout << "\nstart: " << aw->ws[i].start << "   stop: " << aw->ws[i].end << "   duration: " << aw->ws[i].duration;
    cout << "\n>>>\n";
}

int CalculateMaxWorkshops(Available_Workshops *aw)
{
    // this is regular interval scheduling algorithm
    // sort the end points
    sort(aw->ws, aw->ws + aw->n, [] (Workshop &a, Workshop &b) { return a.end < b.end; } );
    int curEnd = 0;
    int count = 0;
    // if we pass the previous end, we increase the counter
    for (int i=0; i<aw->n; ++i)
    {
        if( aw->ws[i].start >= curEnd )
        {
            ++count;
            curEnd = aw->ws[i].end;
        }
    }
    return count;
}



int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    print_aw(ptr);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
