void mumble(const char *name,float balance,char acct_type)
{
    Account acct;
    if(!name)
        return;//可能在此处调用析构函数
    if(balance<=99)
        return;//可能在此处调用析构函数
    switch(acct_type)
    {
        case 'z':return;//可能在此处调用析构函数
        case 'a':
        case 'b':return;//可能在此处调用析构函数
    }
    //可能在函数末尾调用析构函数
}