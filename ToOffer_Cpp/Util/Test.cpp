void TestTime() {
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   tm *ltm = localtime(&now);
 
   // 输出 tm 结构的各个组成部分
   cout << "年: "<< 1900 + ltm->tm_year << endl;
   cout << "月: "<< 1 + ltm->tm_mon<< endl;
   cout << "日: "<<  ltm->tm_mday << endl;
   cout << "时间: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}

struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book,book2;

void TestReference() {
    int i;
    double d;

    // 声明引用变量
    int& r = i;
    int r1 = i;
    double& s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r << endl;
    cout << "Value of r1 reference : " << r1 << endl;
}

void TestGoto() {
    int a = 10;

    LOOP:do
    {
        if (a == 15)
        {
            // 跳过迭代
            a = a + 1;
            goto LOOP;
        }
        cout << "a 的值：" << a << endl;
        a = a + 1;
    } while (a < 20);
}

void TestFileStream(){
       // 以写模式打开文件
   ofstream outfile;
   outfile.open("afile.dat");
 
   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);
 
   // 向文件写入用户输入的数据
   outfile << data << endl;
 
   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // 再次向文件写入用户输入的数据
   outfile << data << endl;
 
   // 关闭打开的文件
   outfile.close();
 
   // 以读模式打开文件
   ifstream infile; 
   infile.open("afile.dat"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 
 
   // 在屏幕上写入数据
   cout << data << endl;
   
   // 再次从文件读取数据，并显示它
   infile >> data; 
   cout << data << endl; 
 
   // 关闭打开的文件
   infile.close();
}

template <typename T>
inline T const& IsEquals(T const& a, T const& b) 
{ 
    return a == b; 
} 