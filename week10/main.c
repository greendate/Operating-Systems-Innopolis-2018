#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    int n = 1000, count = 0;
    long int* inode = malloc(n * sizeof(long int));
    
    DIR *dir;
    struct dirent *dp;
    char * file_name;
    dir = opendir(".");
    
    while ((dp=readdir(dir)) != NULL) {
        if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        {
            
        } else {
            file_name = dp->d_name; 
	    if(count >= n) {
		n *= 2;		 
		inode = (long int*) realloc(inode, n);
	    }
	    inode[count] = (*dp).d_ino;
	    count++; 
        }
    }

    int* done = calloc(count, sizeof(int));
 
    for(int i = 0; i < count; i++) {
	if(done[i] == 1) continue;
	int pass = 0;
	for(int j = i + 1; j < count; j++) {
		if(inode[i] == inode[j]) done[j] = 1, pass++;	
	}
	
	if(!pass) continue;
	printf("%ld ", inode[i]);

	dir = opendir(".");
	while ((dp=readdir(dir)) != NULL) {
        	if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        	{
            
        	} else {
            		file_name = dp->d_name; 
			if((*dp).d_ino == inode[i]) printf("%s ", file_name);     	
        	}
       }
       printf("\n");	
    }

    closedir(dir);
    return 0;
}
