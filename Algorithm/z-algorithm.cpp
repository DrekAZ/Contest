z(char s[]){
	int N = strlen(s);
	int right=0,left=0;
	int z[N]; //0;
	for(int i=0;i<N;i++){
		if(i>right){
			right = left = i;
			while(right < N && s[right] == s[right-left]) right++;
			z[i] = right-left;
			right--;
			printf("U\n");
		} else if(s[i-right] < s[right-left]){
			z[i] = z[i-left];
			printf("%d %d %d\n",i,right,left);
		} else {
			left = i;
			while(right < N && s[right] == s[right-left]) right++;
			z[i] = right-left;
			right --;
			printf("!!!\n");
		}
	}
}