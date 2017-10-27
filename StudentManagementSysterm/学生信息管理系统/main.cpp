//
//  main.cpp
//  学生信息管理系统
//
//  Created by tamchikit on 2017/10/15.
//  Copyright © 2017年 tamchikit. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include<string>
using namespace std;


typedef struct StuBasic{ //基本信息
    int stunum;//学号  
    string name; //姓名
    string sex;  //性别
    string doornum;//宿舍号码
    string tel;//电话(七位)  
}StuB;  
typedef struct StuResult{//成绩信息  
    int stunum;//学号  
    string cou;//课程
    float cre;//学分  
    float ures;//平时成绩  
    float tres;//实验成绩  
    float eres;//考试成绩
    float tolres;//总成绩  
    float tolcre;//总学分  
}StuR;  
StuB stub[1001];  
StuR stur[1001];  

//定义函数
void Add();
void Addtolres(StuR stu);//计算总成绩
void Addtolcre(StuR stu);//计算总学分

void Input();//添加记录
void Inputstub();//录入学生基本信息
void Inputstur();//录入学生成绩信息

void Show();//显示记录

int Select();//信息查询
int Selectstubnum();//查询基本信息函数(按学号)
int Selectstudoor();//查询宿舍函数
int Selectsturnum();//查询成绩(按学号)

int Delete();//删除记录
int Deletestu();//删除一个学生信息
int Deletedoor(string dor);//删除一个寝室信息

void Rewrite();//修改记录
void Rewritestub();//修改基本信息(按学号)
void Rewritestur();//修改成绩信息(按学号)

void Compare(StuR s1,StuR s2);//排序比较函数
void Sortstu();//排序函数

void Modify();//修改密码

int c;  //全局变量
int student_all=0; //表示已经储存了多少个
int student_num; //本次要输入的学生数量

void rootmenu()                              //跟用户菜单选择系统函数
{
        system("clear");
        std::cout<<"\t\t     ╭♈♉♊♋♌♎══■□■□══════╮\n";
        std::cout<<"\t\t     │       学生信息管理系统     |\n";
        std::cout<<"\t\t     ╰══════■□■□══♏♐♑♓♒♍╯\n";
        std::cout<<"\t\t    ┌──────────────────────────┐\n";
        std::cout<<"\t\t    │ 1. 添加记录    2. 显示记录  │\n";
        std::cout<<"\t\t    │                          |\n";
        std::cout<<"\t\t    │ 3. 信息查询    4. 数据计算  │\n";
        std::cout<<"\t\t    │                          │\n";
        std::cout<<"\t\t    │ 5. 修改记录    6. 删除记录  │\n";
        std::cout<<"\t\t    │                          │\n";
        std::cout<<"\t\t    │ 7. 修改密码    0. 退出程序  |\n";
        std::cout<<"\t\t    └──────────────────────────┘\n";
        std::cout<<"\t\t请您选择(0-6):";
    cin>>c;
    while(c<0||c>7){
    cout<<"输入错误请重新输入"<<endl;
    cin>>c;
    }
    switch (c) {
        case 1:
            Input();
            break;
        case 2:
            Show();
            break;
        case 3:
            Select();
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        default:
            break;
    }
}

void guestmenu()                              //客人用户菜单选择系统函数
{
        system("clear");
        std::cout<<"\t\t    ╭♈♉♊♋♌♎══■□■□══════╮\n";
        std::cout<<"\t\t    │       学生信息管理系统     |\n";
        std::cout<<"\t\t    ╰══════■□■□══♏♐♑♓♒♍╯\n";
        std::cout<<"\t\t    ┌──────────────────────────┐\n";
        std::cout<<"\t\t    │ 1. 信息查询    2. 显示记录  │\n";
        std::cout<<"\t\t    │                          |\n";
        std::cout<<"\t\t    │ 3. 数据计算               │\n";
        std::cout<<"\t\t    │                          │\n";
        std::cout<<"\t\t    │ 0. 退出程序               |\n";
        std::cout<<"\t\t    └──────────────────────────┘\n";
        std::cout<<"\t\t请您选择(0-3):";
    cin>>c;
    while(c<0||c>3){
    cout<<"输入错误请重新输入"<<endl;
    cin>>c;}
    switch (c) {
        case 1:
            Select();
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        default:
            break;
    }
}

void login()   //登录界面
{
    string username,pwd;
    system("clear");
    cout<<"请输入用户名："<<endl;
    cin>>username;
    cout<<"请6位数输入密码："<<endl;
    cin>>pwd;
    while ((username!="root"&&username!="guest")||(pwd!="123456"&&pwd!="654321")) {
        cout<<"账户或密码错误,请重新输入!"<<endl<<endl;
        cout<<"请输入用户名：";
        cin>>username;
        cout<<"请6位数输入密码：";
        cin>>pwd;
    }
    cout<<"输出正确，欢迎登录"<<endl;
    while(username=="root"&&pwd=="123456")
    {
        rootmenu();
    }
    while(username=="guest"&&pwd=="654321")
    {
        guestmenu();
    }
}

void Inputstub(){//录入学生基本信息
    cout<<"请输入学生个数:";
    cin>>student_num;
    for(int i=student_all;i<student_all+student_num;i++){
        
        cout<<"输入学号:";
        cin>>stub[i].stunum;
        
        cout<<"输入姓名:";
        cin>>stub[i].name;
        
        cout<<"输入性别:";
        cin>>stub[i].sex;
        
        cout<<"输入寝室号:";
        cin>>stub[i].doornum;
        
        cout<<"输入电话:";
        cin>>stub[i].tel;
        }
    student_all=student_all+student_num;//学生总数增加
}

void Inputstur(){//录入学生成绩信息
    cout<<"请输入学生个数:";
    cin>>student_num;
    for(int i=student_all;i<student_all+student_num;i++){
        cout<<"输入学号:";
        cin>>stur[i].stunum;
    
        cout<<"输入课程:";
        //string cou;//课程
        cin>>stur[i].cou;
        
        cout<<"输入学分:";
        //int cre;//学分
        cin>>stur[i].cre;
        
        cout<<"输入平时成绩:";
        //int ures;//平时成绩
        cin>>stur[i].ures;
        
        cout<<"输入实验成绩:";
        //int tres;//实验成绩
        cin>>stur[i].tres;
        
        cout<<"试卷成绩:";
        //int pres;//试卷成绩
        cin>>stur[i].eres;
        
        float tolres;//总成绩
        float tolcre;//总学分
        if(stur[i].tres==-1){
            tolres=stur[i].eres*0.7+stur[i].ures*0.3;
        }else{
            tolres=stur[i].eres*0.7+stur[i].ures*0.15+stur[i].tres*0.15;
        }
        stur[i].tolres=tolres;
        //cout<<stur[i].tolres<<endl;
        if(tolres>=90&&tolres<=100){
            tolcre=stur[i].cre;
        }else if(tolres>=80&&tolres<90){
            tolcre=stur[i].cre*0.8;
        }else if(tolres>=70&&tolres<80){
            tolcre=stur[i].cre*0.75;
        }else if(tolres>=60&&tolres<70){
            tolcre=stur[i].cre*0.6;
        }else{
            tolcre=0;
        }
        stur[i].tolcre=tolcre;
    }
    student_all=student_all+student_num;//学生总数增加
}

void Input(){//添加记录
    char in;
    cout<<"     1.录入学生基本信息"<<endl;
    cout<<"     2.录入学生成绩信息"<<endl;
    int key1;
    cout<<"请选择: ";
    cin>>key1;
    while(key1!=1&&key1!=2){
        cout<<"输入错误,请重新输入:";
        cin>>key1;
    }
    switch (key1){
        case 1:
            Inputstub();
            break;
        case 2:
            Inputstur();
            break;
        default :
            break;
    }
    cout<<"输入y继续当前操作,输入n(或其他)返回上一层:";
    cin>>in;
    while (in=='y')
        break;
}

void Show()//显示记录
{
    int in;
    cout<<"     1.显示所有学生基本信息"<<endl;
    cout<<"     2.显示所有学生成绩信息"<<endl;
    cin>>in;
    switch (in) {
        case 1:
            for (int i=0; i<student_all; i++) {
                cout<<"姓名："<< stub[i].name<<endl;
                cout<<"学号："<<stur[i].stunum<<endl;
                cout<<"性别:"<<stub[i].sex<<endl;
                cout<<"寝室号："<<stub[i].doornum<<endl;
                cout<<"电话：" <<stub[i].tel<<endl;
            }
            cout<<"已经显示完毕";
            break;
        default:
            for (int i=0; i<student_all; i++) {
                cout<<"姓名："<< stub[i].name<<endl;
                cout<<"学号："<<stur[i].stunum<<endl;
                cout<<"课程:"<<stur[i].cou<<endl;
                cout<<"学分："<<stur[i].cre<<endl;
                cout<<"平时成绩："<< stur[i].ures<<endl;
                cout<<"试卷成绩" <<stur[i].eres<<endl;
                cout<<"实验成绩:"<<stur[i].tres<<endl<<endl;
            }
            cout<<"已经显示完毕";
            break;
    }
}

int Selectsturnum()//按学号查询成绩
{
    char in;
    int num;
    int flag=0;//显示未找到
    cout<<"输入需查看的学生学号：" <<endl;
    cin>>num;
    for (int i=0;i<student_all;i++)
        if (stub[i].stunum==num&&flag!=0) {
            cout<<"学号为"<<num<<"的学生基本信息如下"<<endl;
            cout<<"姓名："<< stub[i].name<<endl;
            cout<<"学号："<<stur[i].stunum<<endl;
            cout<<"课程:"<<stur[i].cou<<endl;
            cout<<"学分："<<stur[i].cre<<endl;
            cout<<"平时成绩："<< stur[i].ures<<endl;
            cout<<"试卷成绩" <<stur[i].eres<<endl;
            cout<<"实验成绩:"<<stur[i].tres<<endl<<endl;
            flag=1;
            cout<<"输入y继续当前操作,输入n(或其他)返回上一层:";
            cin>>in;
            while (in=='y')
                break;
        }
        else if(stub[i].stunum==num&&flag!=0){
            cout<<"学号重复"<<endl;
        }
    return 0;
}

int Selectstubnum()//按学号查询基本信息
{
    char in;
    int num;
    int flag=0;//显示未找到
    cout<<"输入需查看的学生学号：" <<endl;
    cin>>num;
    for (int i=0;i<student_all;i++)
        if (stub[i].stunum==num&&flag!=0) {
            cout<<"学号为"<<num<<"的学生基本信息如下"<<endl;
            cout<<"姓名："<< stub[i].name<<endl;
            cout<<"学号："<<stur[i].stunum<<endl;
            cout<<"性别:"<<stub[i].sex<<endl;
            cout<<"寝室号："<<stub[i].doornum<<endl;
            cout<<"电话：" <<stub[i].tel<<endl;
            flag=1;
            cout<<"输入y继续当前操作,输入n(或其他)返回上一层:";
            cin>>in;
            while (in=='y')
                break;
        }
        else if(stub[i].stunum==num&&flag!=0){
            cout<<"学号重复"<<endl;
        }
    return 0;
}

int  Select()//信息查询
{
    cout<<"  1.查询学生基本信息"<<endl;
    cout<<"  2.查询学生成绩信息"<<endl;
    cout<<" 3.返回上一层"<<endl<<endl;
    cout<<"请选择你要进行的操作："<<endl;
    int key2;
    cin>>key2;
    while(key2!=1&&key2!=2&&key2!=3){
        cout<<"输入错误,请重新输入:";
        cin>>key2;}
    if (key2==1)
        Selectstubnum();
    else if(key2==2)
        Selectsturnum();
    while(key2==3)
        break;
        return 0;
}

int main(int argc, const char * argv[]) {
    login();

    return 0;
}
