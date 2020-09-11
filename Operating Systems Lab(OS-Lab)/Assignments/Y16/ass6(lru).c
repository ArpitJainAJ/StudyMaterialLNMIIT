#include<stdio.h>

int lru(int used[], int n){
    int i, minimum = used[0], pos = 0;

    for(i = 1; i < n; ++i){
        if(used[i] < minimum){
            minimum = used[i];
            pos = i;
        }
    }

    return pos;
}

int main()
{
    int framesNum, pagesNum, frames[10], pages[30], counter = 0, used[10], flag1, flag2, i, j, pos, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &framesNum);

    printf("Enter number of pages: ");
    scanf("%d", &pagesNum);

    printf("Enter reference string: ");

    for(i = 0; i < pagesNum; ++i){
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < framesNum; ++i){
        frames[i] =-1 ;
       }

    for(i = 0; i < pagesNum; i++){
        flag1=flag2=0;
        for(j = 0; j < framesNum; j++){
          if(frames[j]==pages[i]){
            counter++;
            used[j] = counter;
            flag1=flag2=1;
            break;
          }
        }

        if(flag1==0){
            for(j = 0; j < framesNum; j++){
                if(frames[j]==-1){
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    used[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            pos = lru(used , framesNum);
            counter++;
            faults++;
            frames[pos] = pages[i];
            used[pos] = counter;
        }

        printf("\n%d:\t [", pages[i]);
        for(j = 0; j < framesNum; j++){
                if(j==framesNum-1){
                    if(frames[j]==-1)
                        printf("  ]");
                    else
                        printf("%d ]", frames[j]);
                }
                else{
                        if(frames[j]==-1)
                            printf("  \t| ");
                        else
                            printf("%d\t| ", frames[j]);
                }

        }
        if(flag1==0 || flag2==0)
            printf("  FAULT");


    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}


