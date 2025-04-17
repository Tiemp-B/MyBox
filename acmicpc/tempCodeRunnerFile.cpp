
    for(int d =0 ;d<65; d++){
        for(int i=0; i<box[d].size();i++){
            if (i == 0){
                cout << box[d][i];
            }else{
                int ctt = func(box[d][i]);
                cout <<box[d][i];
                for(int t=0; t<17-ctt; t++){
                    cout << 0;
                }
            }
        }
        cout <<endl;
    }
