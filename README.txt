readme main.cpp

a1_cmaketest
    --简单使用cmake 创建cpp项目

a2_string_test
    --简单使用cpp string 

    需要fmt, 由于环境问题，无法直接使用c++20的fmt
    直接使用其他开源fmt替换
    git clone https://github.com/fmtlib/fmt.git
	cd fmt
	mkdir build
	cd build
	cmake ..
	make
    sudo make install

a3_array_test
    --简单使用array
    /workspaces/CppTest/a3_array_test/src/MyArray.cpp:8:10: fatal error: span: No such file or directory
    8 | #include <span>
    还是gcc版本问题：
    默认版本是g++ (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0
    升级步骤：
        sudo apt update
        sudo apt install build-essential
        sudo add-apt-repository ppa:ubuntu-toolchain-r/test #添加 GCC 开发工具链 PPA
        sudo apt update
        sudo apt install gcc-11 g++-11
        sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 120 --slave /usr/bin/g++ g++ /usr/bin/g++-11
        g++ --version
        升级后的版本是：g++ (Ubuntu 11.4.0-2ubuntu1~20.04) 11.4.0


b1_stl_test_vector
    stl 中 容器 vector 使用