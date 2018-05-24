#include <stdio.h>
//Maximum Subsequence Sum
int main (void)
{
    int num;
    
    scanf("%d", &num);
    int data[num];
    //scanf("%d", &data);
    
    for(int i=0; i<num; i++)
    {
      scanf("%d",&data[i]);
    }
    //printf("%d\n",num);

    int ThisSum, MaxSum, first, last;
    ThisSum = MaxSum = 0;
    first = 0;
    last = num-1;
    int count = 0;
    int countZero = 0;
    for (int i=0; i<num; i++) {
    	ThisSum += data[i];
        if (MaxSum == data[i] && data[i] == 0){
            countZero ++;
            //printf("countZero %d MaxSum %d data[i] %d\n",i,MaxSum,data[i]);
            if ( countZero ==1){

                first = i;
                last = i;
            }
        }
    	if (ThisSum>MaxSum) {
    		MaxSum = ThisSum;
            count ++;
            if (count==1){
               first = i;
               last = i;
            }  else {
               last = i;
            }           
    	} else if ( ThisSum<0) {
            count = 0;
            // if (i>1){
            //     last = data[i-1]
            // }
    		ThisSum = 0;

    	}

    }
    printf("%d %d %d",MaxSum,data[first],data[last]);
    // for(int i=0; i<num; i++){
    // 	printf("%d\n ",data[i]);
    // };
    return 0;
}