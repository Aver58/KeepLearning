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