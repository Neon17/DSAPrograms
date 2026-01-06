int hello(){
    //the below code I typed in hacker rank problem solving(basic) as sneon
    int i,j,k,l,strd, strq;
    int aq, ad;
    int countOne = 0;
    int *counts = malloc(query_count*sizeof(int));
    int temp, status;
    
    for (i=0;i<query_count;i++){
        for (j=0;j<dictionary_count;j++){
            strd = strlen(dictionary[j]);
            strq = strlen(query[i]);
            if (strq==strd){
                // printf("Length Equal\n");
                int aq[strq], ad[strd];
                for (k=0;k<strq;k++){
                    ad[k] = dictionary[j][k];
                    aq[k] = query[i][k];
                    // printf("ASCII = (d)%d (q)%d\n",ad[k],aq[k]);
                }
                
                //sort each array
                for (k=0;k<strq;k++){
                    for (l=(k+1);l<strq;l++){
                        if (ad[k]>ad[l]){
                            ad[k] = ad[k] + ad[l];
                            ad[l] = ad[k] - ad[l];
                            ad[k] = ad[k] - ad[l];
                        }
                        if (aq[k]>aq[l]){
                            aq[k] = aq[k] + aq[l];
                            aq[l] = aq[k] - aq[l];
                            aq[k] = aq[k] - aq[l];
                        }
                    }
                }
                //compare each
                status = 0;
                // printf("After sorting..\n");
                for (k=0;k<strq;k++){
                    // printf("ad[%d] = %d; aq[%d] = %d\n",k,ad[k],k,aq[k]);
                    if (ad[k]!=aq[k]){
                        status = 1;
                    }
                } 
                if (status == 0)
                    countOne = countOne + 1;
                                 
            }
        }
        *(counts+i) = countOne;
        // printf("counts = %d\n",*(counts+i));
        countOne = 0;
    }
    
    *result_count = query_count;
    return counts;
}
    