#include <stdio.h>
//最大子列和问题
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

    int ThisSum, MaxSum;
    ThisSum = MaxSum = 0;
    for (int i=0; i<num; i++) {
    	ThisSum += data[i];
    	if (ThisSum>MaxSum) {
    		MaxSum = ThisSum;
    	} else if ( ThisSum<0) {
    		ThisSum = 0;
    	}
    }
    printf("%d",MaxSum);
    // for(int i=0; i<num; i++){
    // 	printf("%d\n ",data[i]);
    // };
    //printf("%@",data);
    return 0;
}