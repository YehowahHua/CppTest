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
    cout << "\n";

    // 2.at访问
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << "\n";

    //3.正向迭代器
    vector<int>::iterator it_start = v1.begin(); //v1[i] 和 *(v1.begin() + i) 等价，与指针类似, v1[0] = *(v1.begin())
    for( vector<int>::iterator it = it_start;it != v1.end(); it++ )
    {
        cout << *it <<" ";
    }
    cout << "\n";

    auto it2 = v1.begin();
    while (it2 != v1.end()) {
        cout << *it2 << " ";
        it2++;
    }
    cout << "\n";


    //4.反向迭代器
    for(vector<int>::reverse_iterator iter = v1.rbegin();iter != v1.rend();iter++)
    {
        cout << *iter <<" "; // 9 8 7 6 5 4 3 2 1 0 
    }
    cout << "\n";

    //5.智能指针
    for(auto val : v1) {
        cout << val << " "; 
    }
    cout << "\n";

    // 第一个数据元素
    cout << "v1 的首元素为 " << v1.front() << endl;

    // 最后一个元素
    cout << "v1 的末元素为 " << v1.back() << endl;
}


/**
 * 方法
*/
void vector_test4(){
    //1.容量
    vector<int> v1;
    if(v1.empty()){
        cout << "v1 is empty " << "\n";
    }
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    if(!v1.empty()){
        cout << "v1 is not empty " << "\n";
        cout << "v1 容量为 " << v1.capacity() << "\n"; //16
        cout << "v1 大小为 " << v1.size() << "\n"; //10
    }
    
    //1.重新指定大小
    // v1.resize(15); // 如果新size大于原来的，默认用0填充
    // for_each(v1.begin(), v1.end(), print_fun());//0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 
    // cout << "\n";

    v1.resize(15, 10); // 也可以指定用10 填充, 若已填充则不会被覆盖
    for_each(v1.begin(), v1.end(), print_fun());//0 1 2 3 4 5 6 7 8 9 10 10 10 10 10
    cout << "\n";

    v1.resize(5); // 如果新size小于原来的，超出的部分会被删除
    for_each(v1.begin(), v1.end(), print_fun());//0 1 2 3 4 
    cout << "\n";


    //2.预留空间
    vector<int> v;

    // 利用 reserve 预留空间，不初始化，size大小还是原本大小，未初始化不可访问
    v.reserve(100000);

    int num = 0; // 统计开辟次数
    int *p = NULL;

    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);

        if (p != &v[0])//判断地址
        {
            p = &v[0];
            num++;
        }
    }

    cout << "开辟内存次数为 " << num << endl; // 1,如果没有reserve，那么返回18，提高了性能



}