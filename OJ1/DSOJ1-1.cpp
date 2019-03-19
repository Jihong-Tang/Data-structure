//
//  DSOJ1-1.cpp
//  OJ1
//
//  Created by Jihong Tang on 2019/3/16.
//  Copyright © 2019 Jihong Tang. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int m, n = 0;
    cin >> m >> n;
    int array_a[m], array_b[n];
    for (int i = 0; i < m; i++){
        cin >> array_a[i];
    }
    for (int j = 0; j < n; j++){
        cin >> array_b[j];
    }
    
    int a_index = 0, b_index = 0;
    int k = 0;
    for (int i = 0, j = 0 ; i <= m - 1 && j <= n - 1; ){
        if (array_a[i] < array_b[j]){
            if (k == 0){
                cout << array_a[i];
                i++;
                a_index ++;
            }
            else{
                cout << ' ' << array_a[i];
                i++;
                a_index ++;
            }
            k ++;
        }
        else{
            if (k == 0){
                cout << array_b[j];
                j++;
                b_index ++;
            }
            else{
                cout << ' ' << array_b[j];
                j++;
                b_index ++;
            }
            k++;
        }
    }
    for (int q = a_index ; q <= m - 1; q++){
        cout << ' ' << array_a[q];
    }
    for (int t = b_index ; t <= n - 1; t++){
        cout << ' ' << array_b[t];
    }
    
    return 0;
}
