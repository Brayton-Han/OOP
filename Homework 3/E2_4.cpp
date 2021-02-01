bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

//字符串转化为整形数据
int stringint(string str)
{
    stringstream ss;
    ss << str;
    int result;
    ss >> result;
    return result;
}