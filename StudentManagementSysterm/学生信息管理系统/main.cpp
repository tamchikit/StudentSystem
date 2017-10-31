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
#include<fstream>
using namespace std;


typedef struct StuBasic{ //基本信息
    int stunum;//学号  
    string name; //姓名
    string sex;  //性别
    string doornum;//宿舍号码
    string tel;//电话(七位)  
}StuB;  
typedef struct StuResult{//成绩信息  
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
void Add();//数据计算
void Addtolres();//计算总成绩
void Addtolcre();//计算总学分

void Input();//添加记录
void Inputstub();//录入学生基本信息
void Inputstur();//录入学生成绩信息

void Show();//显示记录

int Select();//信息查询
int Selectstubnum();//查询基本信息函数(按学号)
int Selectstudoor();//查询宿舍函数
int Selectsturnum();//查询成绩(按学号)

void Delete();//删除记录
void Deletestu();//删除一个学生信息
void Deletedoor();//删除一个寝室信息

void Rewrite();//修改记录
void Rewritestub();//修改基本信息(按学号)
void Rewritestur();//修改成绩信息(按学号)

void Compare(StuR s1,StuR s2);//排序比较函数
void Sortstu();//排序函数

int Modify();//修改密码

void store();//导出为doc

void logout();//登出

int c;  //全局变量
int student_all=0; //表示已经储存了多少个
int student_num; //本次要输入的学生数量
int pp;



void rootmenu()                              //跟用户菜单选择系统函数
{
        system("cls");
        std::cout<<"\t\t     ╭♈♉♊♋♌♎══■□■□══════╮\n";
        std::cout<<"\t\t     │       学生信息管理系统     |\n";
        std::cout<<"\t\t     ╰══════■□■□══♏♐♑♓♒♍╯\n";
        std::cout<<"\t\t    ┌──────────────────────────┐\n";
        std::cout<<"\t\t    │ 1. 添加记录    2. 显示记录  │\n";
        std::cout<<"\t\t    │                          |\n";
        std::cout<<"\t\t    │ 3. 信息查询    4. 数据计算  │\n";
        std::cout<<"\t\t    │                          │\n";
        std::cout<<"\t\t    │ 5. 修改记录    6. 修改密码  │\n";
        std::cout<<"\t\t    │                          │\n";
        std::cout<<"\t\t    │ 7. 退出登录    8. 导出信息  |\n";
        std::cout<<"\t\t    │                          │\n";
        std::cout<<"\t\t    │               0. 退出程序  |\n";
        std::cout<<"\t\t    └──────────────────────────┘\n";
        std::cout<<"\t\t请您选择(0-8):";
    cin>>c;
    while(c<0||c>8){
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
            Add();
            break;
        case 5:
            Rewrite();
            break;
        case 6:
            Modify();
            break;
        case 7:
            logout();
            break;
        case 8:
            store();
            break;
        default:
            break;
    }
}

int Modify()//修改密码
{
    int pp, verpsw,tempsw1;//pp为原始正确密码，verpsw为验证密码,tempsw为临时密码
    pp = 123456;
    cout << "请输入6位数原始密码:"<<endl;
    cin >> verpsw;
    while (verpsw != pp)
    {
        cout << "密码错误，请重新输入:" << endl;
        cin >> verpsw;
    }
    cout << "密码正确，验证成功." << endl;
    cout << "请输入6位数新密码,输入1退出至主界面" << endl;
    cin >> tempsw1;
    if (tempsw1 == 1)
    {
        rootmenu();
        
    }
    else
    { cout << "请再次输入新密码." << endl;
        cin >> pp;
    }
    cout << "修改成功."<<endl;
    return pp;
}


void guestmenu()                              //客人用户菜单选择系统函数
{
        system("cls");
        std::cout<<"\t\t    ╭♈♉♊♋♌♎══■□■□══════╮\n";
        std::cout<<"\t\t    │       学生信息管理系统     |\n";
        std::cout<<"\t\t    ╰══════■□■□══♏♐♑♓♒♍╯\n";
        std::cout<<"\t\t    ┌──────────────────────────┐\n";
        std::cout<<"\t\t    │ 1. 信息查询    2. 显示记录  │\n";
        std::cout<<"\t\t    │                          |\n";
        std::cout<<"\t\t    │ 3. 数据计算    4.退出登录   │\n";
        std::cout<<"\t\t    │                          │\n";
        std::cout<<"\t\t    │ 5. 导出信息    0. 退出程序  |\n";
        std::cout<<"\t\t    └──────────────────────────┘\n";
        std::cout<<"\t\t请您选择(0-5):";
    cin>>c;
    while(c<0||c>5)
    {
    cout<<"输入错误请重新输入"<<endl;
    cin>>c;
    }
    switch (c) {
        case 1:
            Select();
            break;
        case 2:
            Show();
            break;
        case 3:
            Add();
            break;
        case 4:
            logout();
            break;
        case 5:
            store();
            break;
        default:
            break;
    }
}

void login()   //登录界面
{
    pp=123456;
    string username;
    int pwd;
    system("cls");
    cout<<"欢迎来到学生信息管理系统"<<endl<<endl;
    cout<<"请输入用户名："<<endl;
    cin>>username;
    cout<<"请6位数输入密码："<<endl;
    cin>>pwd;
    while ((username!="root"&&username!="guest")||(pwd!=pp&&pwd!=654321)) {
        cout<<"账户或密码错误,请重新输入!"<<endl<<endl;
        cout<<"请输入用户名：";
        cin>>username;
        cout<<"请6位数输入密码：";
        cin>>pwd;
    }
    cout<<"输出正确，欢迎登录"<<endl;
    while(username=="root"&&pwd==pp)
    {
        rootmenu();
    }
    while(username=="guest"&&pwd==654321)
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
        
        system("cls");
        }
    student_all=student_all+student_num;//学生总数增加
}

void Inputstur(){//录入学生成绩信息
    int num;
    int flag=0;//显示未找到
    int key;
    cout<<"请输入学生个数:";
    cin>>student_num;
    for(int i=student_all;i<student_all+student_num;i++){
        cout<<"请输入学号:";
        cin>>num;
        while (num!=stub[i].stunum)
        {
            cout<<"学号不存在,请输入："<<endl;
            cout<<"1.添加该学生"<<endl;
            cout<<"2.录入另一个已存在学生的成绩"<<endl;
            cout<<"请选择你要进行的操作："<<endl;
            cin>>key;
            switch (key) {
                case 1:
                    Inputstub();
                    num=stub[i].stunum;
                    break;
                default:
                    cout<<"请输入学号"<<endl;
                    cin>>num;
                    break;
            }
            break;
        }
        if (stub[i].stunum==num&&flag!=0){
            cout<<"学号重复"<<endl;
        }
        else
        {
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
      
            flag=1;
            system("cls");
        }
    }
}

void Input(){//添加记录
    char in;
    cout<<"     1.录入学生基本信息"<<endl;
    cout<<"     2.录入学生成绩信息"<<endl;
    cout<<"     3.按任意键返回菜单"<<endl;
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
    cout<<"输入y继续当前操作,输入n(或其他)返回菜单:";
    cin>>in;
    while (in=='y')
        break;
}

void Show()//显示记录
{
    int in;
    cout<<"     1.显示所有学生基本信息"<<endl;
    cout<<"     2.显示所有学生成绩信息"<<endl;
    cout<<"     3.显示所有学生所有信息"<<endl;
    cout<<"请选择你要进行的操作："<<endl;
    cin>>in;
    switch (in) {
        case 1:
            for (int i=0; i<student_all; i++) {
                cout<<"姓名："<< stub[i].name<<endl;
                cout<<"学号："<<stub[i].stunum<<endl;
                cout<<"性别:"<<stub[i].sex<<endl;
                cout<<"寝室号："<<stub[i].doornum<<endl;
                cout<<"电话：" <<stub[i].tel<<endl;
            }
            cout<<"已经显示完毕";
            break;
        case 2:
            for (int i=0; i<student_all; i++) {
                cout<<"姓名："<< stub[i].name<<endl;
                cout<<"学号："<<stub[i].stunum<<endl;
                cout<<"课程:"<<stur[i].cou<<endl;
                cout<<"学分："<<stur[i].cre<<endl;
                cout<<"平时成绩："<< stur[i].ures<<endl;
                cout<<"试卷成绩" <<stur[i].eres<<endl;
                cout<<"实验成绩:"<<stur[i].tres<<endl<<endl;
            }
            cout<<"已经显示完毕";
            break;
        default:
            for (int i=0; i<student_all; i++) {
                cout<<"姓名："<< stub[i].name<<endl;
                cout<<"学号："<<stub[i].stunum<<endl;
                cout<<"性别:"<<stub[i].sex<<endl;
                cout<<"寝室号："<<stub[i].doornum<<endl;
                cout<<"电话：" <<stub[i].tel<<endl;
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

int SelectStuDoor()//查询宿舍函数
{
    string s1;
    cout<<"请输入查询寝室号:";
    cin>>s1;
    cout<<" 学号  "<<" 姓名  "<<" 性别  "<<" 寝室  "<<" 电话  "<<endl;
    //cout<<" 学号  "<<"  姓名  "<<"  性别  "<<"  寝室  "<<"  电话  "<<endl;
    int ok=0;
    for(int i=0;i<student_all;i++){
        if(stub[i].doornum==s1){
            ok=1;
            cout<<"  "<<stub[i].stunum<<" ";
            cout<<"  "<<stub[i].name<<" ";
            cout<<"  "<<stub[i].sex<<" ";
            cout<<"  "<<stub[i].doornum<<" ";
            cout<<"  "<<stub[i].tel<<endl;
        }
    }
    if(ok==0) cout<<" 不存在这个寝室,请查对后在输入!"<<endl;
    return 0;
}

int Selectsturnum()//按学号查询成绩
{
    char in;
    int num;
    int flag=0;//显示未找到
    cout<<"输入需查看的学生学号：" <<endl;
    cin>>num;
    for (int i=0;i<student_all;i++)
        if (stub[i].stunum==num&&flag==0) {
            cout<<"学号为"<<num<<"的学生基本信息如下"<<endl;
            cout<<"姓名："<< stub[i].name<<endl;
            cout<<"学号："<<stub[i].stunum<<endl;
            cout<<"课程:"<<stur[i].cou<<endl;
            cout<<"学分："<<stur[i].cre<<endl;
            cout<<"平时成绩："<< stur[i].ures<<endl;
            cout<<"试卷成绩" <<stur[i].eres<<endl;
            cout<<"实验成绩:"<<stur[i].tres<<endl<<endl;
            flag=1;
            cout<<"输入y继续当前操作,输入n(或其他)返回菜单:";
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
        if (stub[i].stunum==num&&flag==0) {
            cout<<"学号为"<<num<<"的学生基本信息如下"<<endl;
            cout<<"姓名："<< stub[i].name<<endl;
            cout<<"学号："<<stub[i].stunum<<endl;
            cout<<"性别:"<<stub[i].sex<<endl;
            cout<<"寝室号："<<stub[i].doornum<<endl;
            cout<<"电话：" <<stub[i].tel<<endl;
            flag=1;
            cout<<"输入y继续当前操作,输入n(或其他)返回菜单:";
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
    cout<<"  3.按照宿舍号查询"<<endl;
    cout<<" 4.返回上一层"<<endl<<endl;
    cout<<"请选择你要进行的操作："<<endl;
    int key2;
    cin>>key2;
    while(key2!=1&&key2!=2&&key2!=3&&key2!=4){
        cout<<"输入错误,请重新输入:";
        cin>>key2;}
    if (key2==1)
        Selectstubnum();
    else if(key2==2)
        Selectsturnum();
    else if(key2==3)
        SelectStuDoor();
    while(key2==4)
        break;
        return 0;
}

void Add()//数据计算
{
    cout<<"  1.计算学生总成绩"<<endl;
    cout<<"  2.计算学生总学分"<<endl;
    cout<<" 3.返回上一层"<<endl<<endl;
    cout<<"请选择你要进行的操作："<<endl;
    int key2;
    cin>>key2;
    while(key2!=1&&key2!=2&&key2!=3)
    {
        cout<<"输入错误,请重新输入:";
        cin>>key2;
    }
    if (key2==1)
        Addtolres();
    else if(key2==2)
        Addtolcre();
    while(key2==3)
        break;
}

void Addtolres()//计算总成绩
{
    int num,flag=0,in;
    cout<<"  请输入要计算数据的学生学号："<<endl;
    cin>>num;
    for (int i=0;i<student_all;i++)
        if (stub[i].stunum==num&&flag==0)
        {
            float tolres;//总成绩
            if(stur[i].tres==-1)
            {
                tolres=stur[i].eres*0.7+stur[i].ures*0.3;
            }
            else
            {
                tolres=stur[i].eres*0.7+stur[i].ures*0.15+stur[i].tres*0.15;
            }
            stur[i].tolres=tolres;
            cout<<"  学号为"<<num<<"的学生的总成绩为："<<endl;
            cout<<stur[i].tolres<<endl;
            flag=1;
            
        }
        else if(stub[i].stunum==num&&flag!=0){
            cout<<"学号重复"<<endl;
        }
    cout<<"输入y继续当前操作,输入n(或其他)返回上一层:";
    cin>>in;
    while (in=='y')
        break;
}
void Addtolcre()//计算总学分
{
    int num,flag=0,in;
    cout<<"  请输入要计算数据的学生学号："<<endl;
    cin>>num;
    for (int i=0;i<student_all;i++)
        if (stub[i].stunum==num&&flag==0)
        {
        float tolcre;//总学分
        float tolres=stur[i].tolres;//总成绩
            if(tolres>=90&&tolres<=100)
            {
                tolcre=stur[i].cre;
            }
            else if(tolres>=80&&tolres<90)
            {
                tolcre=stur[i].cre*0.8;
            }
            else if(tolres>=70&&tolres<80)
            {
                tolcre=stur[i].cre*0.75;
            }
            else if(tolres>=60&&tolres<70)
            {
                tolcre=stur[i].cre*0.6;
            }
            else
            {
                tolcre=0;
            }
            stur[i].tolcre=tolcre;
            cout<<"  学号为"<<num<<"的学生的总学分为："<<endl;
            cout<<stur[i].tolcre<<endl;
            flag=1;
            cout<<"输入y继续当前操作,输入n(或其他)返回菜单:";
            cin>>in;
            while (in=='y')
                break;
        }
        else if(stub[i].stunum==num&&flag!=0){
            cout<<"学号重复"<<endl;
        }
}

void Rewritestub()//修改基本信息(按学号)
{
    int num;
    cout<<"请输入需要修改的学号:";
    cin>>num;
    for(int i=0;i<student_all;i++){
        cout<<stub[i].stunum<<endl;
        if(stub[i].stunum==num){
            cout<<"输入学号:";
            cin>>stub[i].stunum;
         
            cout<<"输入姓名:";
            string name;
            cin>>name;
            stub[i].name=name;
            
            cout<<"输入性别:";
            string sex;
            cin>>sex;
            stub[i].sex=sex;
            
            cout<<"输入寝室号:";
            string dornum;
            cin>>dornum;
            stub[i].doornum=num;
            
            cout<<"输入电话:";
            string tel;
            cin>>tel;
            stub[i].tel=tel;
        }
        cout<<"修改成功！"<<endl;
    }
}

void Rewritestur()//录入学生成绩信息
    {
        int num;
        cout<<"请输入修改的学号:";
        cin>>num;
        for(int i=0;i<student_all;i++){
            //cout<<stur[i].stunum<<endl;
            if(stub[i].stunum==num){
                cout<<"输入学号:";
                cin>>stub[i].stunum;
                
                cout<<"输入课程:";
                string cou;//课程
                cin>>cou;
                stur[i].cou=cou;
                
                cout<<"输入学分:";
                float cre;//学分
                cin>>cre;
                stur[i].cre=cre;
                
                cout<<"输入平时成绩:";
                float ures;//平时成绩
                cin>>ures;
                stur[i].ures=ures;
                
                cout<<"输入实验成绩:";
                float tres;//实验成绩
                cin>>tres;
                stur[i].tres=tres;
                
                cout<<"试卷成绩:";
                float pres;//考试成绩
                cin>>pres;
                stur[i].eres=pres;
                
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
            cout<<"修改成功！"<<endl;
        }
}

    
void Rewrite()  //修改记录
    {
    cout<<"  1.修改学生基本信息"<<endl;
    cout<<"  2.修改学生成绩信息"<<endl;
    cout<<" 3.返回上一层"<<endl<<endl;
    cout<<"请选择你要进行的操作："<<endl;
    int key3;
    cin>>key3;
    while (key3!=1&&key3!=2&&key3!=3)
    {
        cout<<"输入错误,请重新输入:";
        cin>>key3;
    }
    switch (key3)
           {
           case 1:
           Rewritestub();
           break;
           case 2:
           Rewritestur();
           break;
           default:
           break;
          }
     }

void store()//导出信息
{
    char in;
    ofstream fout("/Users/tanzhijie/Desktop/Studentsysterm.txt");
    fout<<"学号   学生姓名   学生性别   寝室号   电话            课程    学分    平时成绩    实验成绩    考试成绩    总成绩    总学分"<<endl;
    for (int i=0; i<student_all; i++)
    {
        fout<<stub[i].stunum;
        fout<<"      "<<stub[i].name;
        fout<<"         "<<stub[i].sex;
        fout<<"        "<<stub[i].doornum;
        fout<<"      "<<stub[i].tel;
        fout<<"     "<<stur[i].cou;
        fout<<"      "<<stur[i].cre;
        fout<<"       "<<stur[i].ures;
        fout<<"         "<<stur[i].tres;
        fout<<"          "<<stur[i].eres;
        fout<<"         "<<stur[i].tolres;
        fout<<"    "<<stur[i].tolcre<<endl;
    }
    cout<<"导出成功"<<endl;
    cout<<"输入y继续当前操作,输入n(或其他)返回菜单:";
    cin>>in;
    while (in=='y')
        break;
}

void logout()//登出
{
    string username;
    int pwd;
    system("cls");
    cout<<"欢迎来到学生信息管理系统"<<endl<<endl;
    cout<<"请输入用户名："<<endl;
    cin>>username;
    cout<<"请6位数输入密码："<<endl;
    cin>>pwd;
    while ((username!="root"&&username!="guest")||(pwd!=pp&&pwd!=654321)) {
        cout<<"账户或密码错误,请重新输入!"<<endl<<endl;
        cout<<"请输入用户名：";
        cin>>username;
        cout<<"请6位数输入密码：";
        cin>>pwd;
    }
    cout<<"输出正确，欢迎登录"<<endl;
    while(username=="root"&&pwd==pp)
    {
        rootmenu();
    }
    while(username=="guest"&&pwd==654321)
    {
        guestmenu();
    }
}

int main(int argc, const char * argv[]) {
    login();

    return 0;
}
