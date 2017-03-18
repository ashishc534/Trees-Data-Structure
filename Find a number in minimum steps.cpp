#include<iostream>
using namespace std;
void getMinSteps(int n){
    int step = 1;
    int steps_sum = 0;
    //keep adding numbers until it exceeds the given n
    while(steps_sum < n){
        steps_sum += step;
        step++;
    }
    /*if the gap is 0 it means that the value is found or if gap is even then n can
    be found out by negating gap/2 from the step values which adds to steps_sum,
    hence the result is same 'step-1' */
    int gap = steps_sum - n;
    if(gap == 0 || gap%2==0){
        //-1 to take into account the last 'step' increment
        cout<<step-1<<endl;
    }
    else{
        /* this is the case when we have some odd gap, say n = 12. upto i = 5,
        it adds to 15 and we seek 12 so the gap is 3. When we have the even gap,
        we simply negate gap/2 but here negation of any previous number/s which
        sum-up to make steps-sum won't work as it will remove even value from 
        steps_sum. 
        so we look for the next steps_sum value which has the same parity as of n.
        Once we have the next number which has the same parity then the gap is even
        now which can be taken cared of by negating some of the prev values*/
        
		int parity = n%2;
        while(parity != (steps_sum%2)){
            steps_sum+= step;
            step++;
        }
        cout<<step-1<<endl;
    }

}
int main(){
    int number = 10;
    getMinSteps(number);
}

