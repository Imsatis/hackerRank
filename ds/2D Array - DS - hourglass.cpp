#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int maxVal = -63;
    int size = 6;
    int offset = 2;
    for(int i = 0; i < size - offset; i++) {
        for (int j = 0; j < size - offset; j++) {
            int top = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            int mid = arr[i+1][j+1];
            int bottom = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            int max = top + mid + bottom;
            if (max > maxVal) maxVal = max;  
        }
    }
    return maxVal;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
