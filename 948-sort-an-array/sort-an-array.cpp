class Solution {
public:
    void merge(vector<int>& arr,int si,int mid,int ei){
        vector<int> temp;
        int i = si;
        int j = mid+1;

        while(i<=mid && j<=ei){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }else {
                temp.push_back(arr[j++]);
            }
        }

        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<=ei){
            temp.push_back(arr[j++]);
        }

        int x = 0;
        for(int k = si;k<=ei;k++){
            arr[k] = temp[x++];
        }
    }

    void mergeSort(vector<int>& arr,int si,int ei){
        if(si>=ei) return;
        int mid = si + (ei-si)/2;
        mergeSort(arr,si,mid);
        mergeSort(arr,mid+1,ei);

        merge(arr,si,mid,ei);
    }

    vector<int> sortArray(vector<int>& arr) {
        mergeSort(arr,0,arr.size()-1);
        return arr;
    }
};