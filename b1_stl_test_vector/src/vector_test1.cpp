#include "vector_test1.h"

//仿函数
class print_fun
{
public:
    void operator() (const int num) 
    {
         std::cout << num << " ";
    }
};


/**
 * vector 初始化
 **/
void vector_test1(){
    // 1.默认构造：无参构造
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), print_fun());//需要algorithm头文件
    cout << "\n";

    //2.通过区间方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    for_each(v2.begin(), v2.end(), print_fun());
    cout << "\n";


    //3.指定长度和初始值的初始化
    //vector<int> v3(10);//长度为10
    vector<int> v3(10, 100);// v3[0] 到 v3[n - 1]所有的元素初始值均为100
    for_each(v3.begin(), v3.end(), print_fun());
    cout << "\n";


    //4.拷贝构造
    vector<int> v4(v3);
    vector<int> v5 = v3;
    for_each(v4.begin(), v4.end(), print_fun());
    cout << "\n";
    for_each(v5.begin(), v5.end(), print_fun());
    cout << "\n";

    //对于2维vector待补充
    vector<vector<int> > v6;//相当于二维数组inta[n][n]
    vector<int>  v7[5];//相当于二维数组inta[5][n]

}


/**
 * 赋值
*/
void vector_test2(){
    //1.push_back
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);//也可emplace_back
    }

    //2.operator=
    vector<int> v2;
    v2 = v1;

    //3.assign
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());

    vector<int> v4;
    v4.assign(10, 100);
}

/**
 * 访问
*/
void vector_test3(){
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    // 1.[]下标访问
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    // 2.at访问
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;



    //3.正向迭代器
    vector<int>::iterator it_start = v1.begin(); 
    for( vector<int>::iterator it = it_start;it != v1.end(); it++ )
    {
        cout << *it <<" ";
    }
    cout << "\n";
    
    // 第一个数据元素
    cout << "v1 的首元素为 " << v1.front() << endl;

    // 最后一个元素
    cout << "v1 的末元素为 " << v1.back() << endl;


}


