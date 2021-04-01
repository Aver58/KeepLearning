void TestForeach(){
    for (int i = 0; i < 3; i++)
    {
        cout<<i;continue;
        cout<<"222";break;
        for (int i = 0; i < 3; i++)
        {
            cout<<"333";
        }
    }
}