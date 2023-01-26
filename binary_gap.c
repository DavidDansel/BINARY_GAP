#include<stdio.h>
#define STACK_SIZE 100
int STACK[STACK_SIZE];
int stack_ptr=-1;

void push(int n){
    stack_ptr++;
    if(stack_ptr==STACK_SIZE-1){
        printf("Stack is full\n");
               return;
    }
    STACK[stack_ptr]=n;
}


int pop(){
    int temp;
    if(stack_ptr!=-1){
        temp=STACK[stack_ptr];
        stack_ptr--;
        return temp;
    }
    return -1;
}

int convert_to_binary(int n){
    int binary_length=0;
    stack_ptr=-1;
    while(n!=0){
     push(n%2);
     binary_length++;
      n=n/2;
    }
    return binary_length;
}


int binaryGap(int n){
 int binary_length=convert_to_binary(n);
 int index=binary_length-1;
 int start_index=-1;
 int end_index=-1;
 int max_distance=0;
 int distance;
 int temp=pop();
 index--;
 while (temp!=-1)
 {  
    if(temp==1){
      if(start_index==-1)
         start_index=index+1;
      else{
         end_index=index+1;
         distance=start_index-end_index;
         if(distance>max_distance)
              max_distance=distance;
        start_index=end_index;
      }  
  }   
    temp=pop();
    index--; 
 }
 return max_distance;        
}

int main(){
  printf("%d\n",binaryGap(8));
}
