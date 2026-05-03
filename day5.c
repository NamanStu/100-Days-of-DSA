/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include <stdio.h>
#include <stdlib.h>


int main(){

int m,n;
printf("Enter the size of 1st array:");
scanf("%d",&m);

printf("Enter the size of 2nd array:");
scanf("%d",&n);
int rs=m+n;
int*a1,*a2,*res;
a1=(int*)malloc(m*sizeof(int));
a2=(int*)malloc(n*sizeof(int));
res=(int*)malloc(rs*sizeof(int));

for(int i=0;i<m;i++){
    printf("Enter %d\n element of 1st array:",i);
    scanf("%d",&a1[i]);
}
printf("Array 1:");
for(int i=0;i<m;i++){
    printf("%d\t",a1[i]);
}

for(int i=0;i<n;i++){
    printf("Enter %d\n element of 2nd array:",i);
    scanf("%d",&a2[i]);
}
printf("Array 2:");
for(int i=0;i<n;i++){
    printf("%d\t",a2[i]);
}

int i=0;
int j=0;
int k=0;

while(i<m && j<n){
    if(a1[i]<a2[j]){
        res[k]=a1[i];
        i++;
    }
    else{
        res[k]=a2[j];
        j++;
    }
    k++;
}

while(i<m){
    res[k++]=a1[i++];
}
while(j<n){
    res[k++]=a2[j++];
}
printf("Resultant Array:");
for(int i=0;i<rs;i++){
    printf("%d\t",res[i]);
}

free(a1);
free(a2);
free(res);




    return 0;
}