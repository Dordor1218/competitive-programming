//
//  main.cpp
//  cow coin
//
//  Created by Dordor Zheng on 2018-07-15.
//  Copyright © 2018 Dordor Zheng. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int types;
    cin>>types;
    int cointype[types];
    for (int i=0; i<types; i++) {
        cin>>cointype[i];
    }
    int need;
    cin>>need;
    int randint[need+1][types];
    //memset(randint, 1, sizeof(randint[0][0])*(need+1)*types);
    for (int i=0; i<need+1; i++) {
        for (int j=0; j<types; j++) {
            randint[i][j]=0;
        }
    }
    for (int i=0; i<types; i++) {
        randint[0][i]=1;
    }
    for (int i=1; i<need+1; i++) {
        for (int j=0; j<types; j++) {
            int x=0,y=0;
            if (j>0) {
                x=randint[i][j-1];
            }
            if (i-cointype[j]>=0) {
                y=randint[i-cointype[j]][j];
            }
            randint[i][j]=x+y;
        }
    }
    cout<<randint[need][types-1];
}
