1. 完全等价的声明：
int max(int, int);
int max(const int, const int);

2. 无法共存的声明：
仅返回值不同不能构成函数重载
值传递：int max(int, int); 和 const int max(int, int);
非普通引用：int max(int&, int&); 、int& max(int&, int&); 和 const int& max(int&, int&);
常量引用：int& max(const int&, const int&); 和 const int& max(const int&, const int&);
这三个类间的函数可以构成重载
