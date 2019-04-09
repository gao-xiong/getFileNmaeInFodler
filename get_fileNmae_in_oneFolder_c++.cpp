#include<iostream>

// 以下两个即为获取目录所需的文件
// 详情可查 opendir readdir closedir三个函数
#include<sys/types.h>
#include<dirent.h>

// /mnt/d/opencv_data/s41
using namespace std;

int main()
{
    cout<<"getFiles usage: getFiles <dir>"<<endl;

    cout<<"input the dir:"<<endl; // 输入需要获取的Linux目录
    string dir;
    //cin>>dir;
	dir = "/mnt/d/opencv_data/s41";
    DIR * dir_ptr;
	dir_ptr = opendir(dir.data());
    if( dir_ptr == NULL){  // 打开目录
        cout<<"OpenDirFile error!"<<endl;
        return 1; 
    }
  
    cout<<"the files in the dir:"<<endl;
    dirent * dir_file;
    while((dir_file = readdir(dir_ptr))!=NULL){ // 读取目录中的文件信息
        cout <<dir_file->d_name<<"   " <<endl; // 输出目录下文件的名称
    }
	
    closedir(dir_ptr); // 关闭目录
    return 0;
}