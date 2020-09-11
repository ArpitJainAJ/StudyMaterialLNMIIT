 #include<stdio.h> 
  #include<pthread.h> 
 
  
  int minimum();
  int maximum();
  int average();
 
  int arr[];
  int n;
 
  int main(){
 
  pthread_t tid1;
  pthread_t tid2;
  pthread_t tid3;
 
  printf("\nNo. of elements you would like to check for?\n");
  scanf("%d",&n);
 
  printf("Enter %d elements\n",n);
  for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
  }
 
  int min_f=pthread_create(&tid1,NULL,minimum,NULL);
  int max_f=pthread_create(&tid2,NULL,maximum,NULL);
  int avg_f=pthread_create(&tid3,NULL,average,NULL);
 
  if(min_f)
      minimum();
 
  if(max_f)
      maximum();
 
  if(avg_f)
      average();
 
  int x, y;
  int z;
 
  pthread_join(tid1,&x);
  pthread_join(tid2,&y);
  pthread_join(tid3,&z);
 
  printf("\nMinimum=%d",x);
  printf("\nmaximum=%d",y);
  printf("\naverage=%d\n",z);
 
  pthread_exit(NULL);
 
 
  }
 
 
  int minimum(){
     
      int mn=arr[0];
      for(int i=1;i<n;i++){
          if(arr[i]<mn)
              mn=arr[i];
          }
      return mn;
      //printf("\nmin=%d",mn);
     
      }
 
  int maximum(){
     
      int mx=arr[0];
      for(int i=1;i<n;i++){
          if(arr[i] > mx)
              mx=arr[i];
          }
      return mx;
      //printf("\nmax=%d",mx);
      }
 
  int average(){
     
      int sum=0;
      for(int i=0;i<n;i++){
          sum+=arr[i];
          }
      int a=(int)sum/n;
      return a;
      //printf("\navg=%d",a);
      }
      
