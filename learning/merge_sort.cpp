#include <bits/stdc++.h>

using namespace std;

void swap(int &a,int &b) {
    int temp = a;
    a=b;
    b=temp;
}

void merge(int arr[], int l, int m, int r) {

    int n1 = m-l+1;
    int n2 = r-m;
    
    int left[n1], right[n2];
    for(int i=0;i<n1;i++) {
        left[i] = arr[l+i]; 
        cout<<left[i]<<" ";
    }
    for(int i=0;i<n2;i++) {
        right[i] = arr[m+1+i];
        cout<<right[i]<<" "; 
    }

    int i=0,j=0;
    int k=l;
    while(i<n1 && j<n2) {
        cout<<k<<" "<<i<<" "<<j<<"-";
        if(left[i]<right[j])  {
            arr[k++]=left[i++];
        } else {
            arr[k++] = right[j++];
        }
        cout<<arr[k-1]<<" ";
    }
    while(i<n1) {
        arr[k++] = left[i++];
        cout<<arr[k-1]<<" ";
    }
    while(j<n2) {
        arr[k++] = right[j++];
        cout<<arr[k-1]<<" ";
    }

}

void merge_sort(int arr[], int l, int r) {
    
    cout<<l<<" "<<r<<endl;
  
    if(l==r) return;
    if(r-l+1==2 ) {
        if(arr[l]>arr[r]) swap(arr[l],arr[r]);
        return;
    }

    int m = (l+r)/2;

    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    if(l==0 && r==2 || true) {
        cout<<"s";
        for(int i=l;i<=r;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    merge(arr,l,m,r);
    if(l==0 && r==2 || true) {
        for(int i=l;i<=r;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}


void solve() {

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

}

int main(){
    int tc=1;
    // cin>>tc;

    while(tc--) solve();
    return 0;
}