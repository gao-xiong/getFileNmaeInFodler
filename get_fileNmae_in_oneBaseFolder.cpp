extern "C"{
	#include <dirent.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <dirent.h>
	#include <unistd.h>
}

int GFile::readFileList(char *basePath){
	
    DIR *dir;
    struct dirent *ptr;
    char base[1000];

    if ((dir=opendir(basePath)) == NULL)
    {
        printf("Open dir error... %s", basePath);
        exit(1);
    }

    while ((ptr=readdir(dir)) != NULL)
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
            continue;
        else if(ptr->d_type == 8){    ///file
            
			string tmpString = ptr->d_name;
		    if(tmpString.find(".jpg") != string::npos || tmpString.find(".png") != string::npos || tmpString.find(".jpeg") != string::npos){
				picFileName.push_back(string(basePath) + string("/") + tmpString);
				//printf("file name:%s/%s \n", basePath, ptr->d_name);
			}
			
		
       } else if(ptr->d_type == 10){    ///link file
            //printf("d_name:%s/%s \n",basePath,ptr->d_name);
       	}
        else if(ptr->d_type == 4)    ///dir
        {
			//printf("dir name:%s/%s \n",basePath,ptr->d_name);
            memset(base,'\0',sizeof(base));
            strcpy(base,basePath);
            strcat(base,"/");
            strcat(base,ptr->d_name);
            readFileList(base);
        }
    }
    closedir(dir);
    return 1;
}




