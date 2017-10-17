//
//  main.cpp
//  学生信息管理系统
//
//  Created by tamchikit on 2017/10/15.
//  Copyright © 2017年 tamchikit. All rights reserved.
//

#include <iostream>
#include <unistd.h>
using namespace std;

int menu_select()                              //菜单选择系统函数
{
    char c;
    do{
        std::cout<<"\t\t    ╭♈♉♊♋♌♎══■□■□══════╮\n";
        std::cout<<"\t\t    │       学生信息管理系统     |\n";
        std::cout<<"\t\t    ╰══════■□■□══♏♐♑♓♒♍╯\n";
        std::cout<<"\t\t    ┌──────────────────────────┐\n";
        std::cout<<"\t\t    │ 1. 添加记录    2. 显示记录  │\n";
        std::cout<<"\t\t    │                          |\n";
        std::cout<<"\t\t    │ 3. 信息查询    4. 数据计算  │\n";
        std::cout<<"\t\t    │                          │\n";
        std::cout<<"\t\t    │ 5. 修改记录    6. 删除记录  │\n";
        std::cout<<"\t\t    │                          │\n";
        std::cout<<"\t\t    │ 0. 退出程序                |\n";
        std::cout<<"\t\t    └──────────────────────────┘\n";
        std::cout<<"\t\t请您选择(0-6):";
        c=getchar();
    }while(c<'0'||c>'6');
    return (c-'0');                                      //字符减去’0‘得到的是数字整型//
}

int main(int argc, const char * argv[]) {
   
    return 0;
}
