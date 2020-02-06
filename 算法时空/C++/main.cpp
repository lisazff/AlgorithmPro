//
//  main.cpp
//  C++
//
//  Created by 佐毅 on 2019/12/13.
//  Copyright © 2019年 dfjr. All rights reserved.
//

#include <iostream>
using namespace std;

class A{
public:
    static int x;    // 声明一个静态成员变量
    // static int x = 10;    // error 声明一个静态成员变量
    static void fun(); // 声明一个静态成员函数
    
    int y1 = 10;
    int y2;
    
};

//作用域：作用域仍为局部作用域，当定义它的函数或者语句块结束的时候，作用域结束。
//但是当局部静态变量离开作用域后，并没有销毁，而是仍然驻留在内存当中，只不过我们不能再对它进行访问，直到该函数再次被调用，并且值不变；
int f(){
    static int i=0;
    static int s=1;
    s+=i;
    i++;
    return s;
}

// int A::x = 10; // 定义静态成员变量并初始化
int A::x = 40; // 默认初始化为0，必须定义静态数据成员，不然会报错，在类内只能是声明

void A::fun(){
    cout<<x<<endl;
//     cout<<y1<<endl;  //error 不能访问非静态成员函数
//     cout<<y2<<endl;
}


int main(int argc, const char * argv[]) {
    A a;   // 创建一个 类 A 对象
    A *b = &a;
    cout<<A::x<<'\t'<<a.x<<'\t'<<b->x<<endl;  // 访问静态数据成员的方式 A::x  / a.x  / b->x
    A::fun();    // 访问静态成员函数的方式 A::fun()  / a.fun()
    a.fun();
    b->fun();   // b->fun()

    
    int i,c=0;
    for(i=0;i<5;i++)
        c+=f();
    cout<<c;
    return 0;
}
