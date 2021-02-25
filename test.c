#include <stdio.h>
int main(void){
    // Your code here!
    int h,w,i,j,c=0;
    scanf("%d %d",&h,&w);
    char ma[h][w];
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf("%c",&ma[i][j]); //-1 0 1 2
        }
        //ma[i][w+1] = '0';
    }
    
    for(i=0;i<h;i++) for(j=0;j<w;j++) printf("%c",ma[i][j]);
    
    i=0; j=0; 
    int hk = 1;
    printf("%c\n",ma[0][2]);
    
    while(i>=0 && i<= h && j>=0 && j<=w){
        
        c++;
        if(ma[i][j] == '/'){
            if(hk==0) hk++;
            else if(hk==-1) hk = 2;
            else if(hk==1) hk--;
            else if(hk == 2) hk = -1;
            printf("%d",hk);
            if(hk==-1) j = j - 1;
            else if(hk==0) i = i-1;
            else if(hk==1) j = j+1;
            else if(hk==2) i = i+1;
            //printf("%d %c",hk, ma[i][j]);

            //c++;
        } 
        else if(ma[i][j] == '\\'){
            if(hk==-1 || hk==1) hk++;
            else hk--;
            printf("%d %d",i,j);
            if(hk==-1) j = j - 1;
            else if(hk==0) i = i-1;
            else if(hk==1) j = j+1;
            else if(hk==2) i = i+1;
            
            printf("%c",ma[i][j]);
            //c++;
        } 
        else {
            if(hk==-1) j = j - 1;
            else if(hk==0) i = i-1;
            else if(hk==1) j = j+1;
            else if(hk==2) i = i+1;
        }
        
        printf("%d %d\n",i,j);
    }
    printf("%d\n",c);
    
    return 0;
}