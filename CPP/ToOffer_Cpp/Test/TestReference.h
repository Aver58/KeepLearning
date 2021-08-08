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