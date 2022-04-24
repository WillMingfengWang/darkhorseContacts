#include <iostream>
using namespace std;
#define MAX 1000 // 宏常量

// -封装函数显示该界面
// -在main函数中调用封装好的函数
void showMenu()
{
    cout << "***********************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出联系人 *****" << endl;
    cout << "***********************" << endl;
}

struct Person // 联系人结构体
{
    string m_Name;
    int m_Sex;
    int m_age;
    string m_Phone;
    string m_Add;
};

struct Addressbooks // 通讯录结构体：包含一个数组和大小；结构体嵌套结构体
{
    struct Person personArray [MAX];
    int m_Size = 0; // 人员个数
};

// 1、添加联系人功能
void addPerson (struct Addressbooks * abs)
{
    if(abs->m_Size==MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return; // 返回到主函数
    }

    while(true)
    {
        cout << "\n";
        cout << "添加--------1" << endl;
        cout << "返回主菜单---2" << endl;
        int flag; // 添加旗变量
        cin >> flag;

        if (flag == 1)
        {
            // 开始添加联系人
            // 姓名
            string name;
            cout << "请输入姓名：" << endl;
            cin >> name;
            abs->personArray[abs->m_Size].m_Name = name;

            cout << "请输入性别：" << endl;
            cout << "1---男" << endl;
            cout << "2---女" << endl;
            int sex = 0;

            // 性别
            while(true)
            {
                // 如果输入的是1或2可以退出循环
                // 如果输入有误，重新输入
                cin >> sex;
                if (sex==1 || sex ==2) // 逻辑选择｜｜
                {
                    abs->personArray[abs->m_Size].m_Sex = sex;
                    break;
                }
                else
                {
                    cout << "输入有误请重新输入！" << endl;
                }
            }

            // 年龄
            int age;
            cout << "请输入年龄：" << endl;
            cin >> age;
            abs->personArray[abs->m_Size].m_age = age;

            // 电话
            string phone;
            cout << "请输入联系电话：" << endl;
            cin >> phone;
            abs->personArray[abs->m_Size].m_Phone = phone;

            // 地址
            string address;
            cout << "请输入家庭住址：" << endl;
            cin >> address;
            abs->personArray[abs->m_Size].m_Add = address;

            // 更新人数
            abs->m_Size++;

            // 提示
            cout << "恭喜您添加成功！" << endl;
        }
        else if (flag==2)
        {
            return;
        }
    }



}

//2、显示联系人
void showPerson (const struct Addressbooks * abs)
{
    if(abs->m_Size==0)
    {
        cout << "记录为空，请先添加联系人！" << endl;
    }
    else
    {
        for(int i = 0; i<abs->m_Size; i++)
        {
            cout << "第" << i+1 << "个人的信息如下：" << endl;
            cout << "\t" << "姓名：" << abs->personArray[i].m_Name
                 << "\t" << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女")
                 << "\t" << "年龄：" << abs->personArray[i].m_age
                 << "\t" << "电话：" << abs->personArray[i].m_Phone
                 << "\t" << "住址：" << abs->personArray[i].m_Add
                 << "\n";
        }
        cout << "所有联系人显示完成！" << endl;
    }
}

// 查找联系人，在删除练习人中的查找函数
int isExist (struct Addressbooks *abs, string name)
{
    for(int i = 0;i < abs->m_Size;i++)
    {
        if(abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;

}

// 3、删除联系人
void delPerson(struct Addressbooks *abs)
{

    string delName;
    cout << "请输入删除人的姓名：" << endl;
    cin >> delName;

    int rec = isExist(abs, delName); // 这里为什么不是&abs？因为这里的abs直接就是指针
    // rec为返回值
    if(rec != -1) // !==不等于
    // 查到此人
    {
        for(int i = rec; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i+1]; // 数据前移
        }
        abs->m_Size--; // 更新通讯录中的人员数
        cout << "删除成功" << endl;
    }
    else // 未查到此人！
    {
        cout << "查无此人！" << endl;
    }

}

// 4、查找联系人
void searPerson(struct Addressbooks *abs)
{
    string searName;
    cout << "请输入姓名：" << endl;
    cin >> searName;

    for(int i = 0;i< abs->m_Size;i++)
    {
        if (abs->personArray[i].m_Name == searName)
        {
            cout << searName << "的信息如下：" << endl;
            cout << "\t" << "姓名：" << abs->personArray[i].m_Name
                 << "\t" << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女")
                 << "\t" << "年龄：" << abs->personArray[i].m_age
                 << "\t" << "电话：" << abs->personArray[i].m_Phone
                 << "\t" << "住址：" << abs->personArray[i].m_Add
                 << "\n";
        }
        else
        {
            cout << "查无此人！" << endl;
        }
    }

}

// 5、修改联系人
void modifyPerson (struct Addressbooks *abs)
{

    while(true)
    {
        cout << "\n";
        cout << "修改--------1" << endl;
        cout << "返回主菜单---2" << endl;
        int flag; // 添加旗变量
        cin >> flag;

        if (flag==1)
        {
            string modName;
            cout << "请输入要修改人的姓名：" << endl;
            cin >> modName;
            int rec = isExist(abs, modName);
            int select;
            if(rec != -1)
            {
                cout << "1---修改姓名" << endl;
                cout << "2---修改性别" << endl;
                cout << "3---修改年龄" << endl;
                cout << "4---修改电话" << endl;
                cout << "5---修改地址" << endl;
                cout << "0---退出修改" << endl;
                cin >> select;
                switch (select)
                {
                    case 1:
                    {
                        cout << "请输入修改后的姓名：" << endl;
                        string mName;
                        cin >> mName;
                        abs->personArray[rec].m_Name=mName;
                        break;
                    }
                    case 2:
                    {
                        cout << "请输入修改后的性别：" << endl;
                        cout << "1---男" << endl;
                        cout << "2---女" << endl;
                        int mSex;

                        while(true)
                        {
                            cin >> mSex;
                            if(mSex==1||mSex==2)
                            {
                                abs->personArray[rec].m_Sex=mSex;
                                break; // break的位置很关键
                            }

                            cout << "输入有误，请重新输入！" << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "请输入修改后的年龄：" << endl;
                        int mAge;
                        cin >> mAge;
                        abs->personArray[rec].m_age=mAge;
                        break;
                    }
                    case 4:
                    {
                        cout << "请输入修改后的电话：" << endl;
                        string mPhone;
                        cin >> mPhone;
                        abs->personArray[rec].m_Phone=mPhone;
                        break;
                    }
                    case 5:
                    {
                        cout << "请输入修改后的地址：" << endl;
                        string mAdd;
                        cin >> mAdd;
                        abs->personArray[rec].m_Add=mAdd;
                        break;
                    }
                    case 0:
                        break;
                }
                cout << "修改成功！" << endl;


            }
            else
            {
                cout << "查无此人！" << endl;
            }

        }
        else if (flag == 2)
        {
            return;
        }
    }
}

// 6、清空联系人
void clearPerson (struct Addressbooks *abs)
{
    abs->m_Size=0;
    cout << "通讯录已清空！" << endl;
}


int main() {

    struct Addressbooks abs; // 创建通讯录结构体变量
    abs.m_Size=0; // 当前人员人数为零

    int select = 0; // 创建用户输入的变量

    while(true)
    {
        showMenu();
        cin >> select;
        switch (select) {
            case 1: // 1、添加
                addPerson (&abs); // 通过地址传递，可以达到修饰实参的结果。此时是传递结构体的地址
                break;
            case 2: // 2、显示
                showPerson(&abs); // 通过常量指针，使得值不会被误操作
                break;
            case 3: // 3、删除
                delPerson(&abs);
                break;
            case 4: // 4、查找
                searPerson(&abs);
                break;
            case 5: // 5、修改
                modifyPerson(&abs);
                break;
            case 6: // 6、清空
                clearPerson(&abs);
                break;
            case 0: // 7、退出
                cout << "欢迎下次使用！" << endl;
                cin.get();
                return 0; // 即结束本代码的意思
                break;
            default:
                break;
        }
    }
    return 0;
}
