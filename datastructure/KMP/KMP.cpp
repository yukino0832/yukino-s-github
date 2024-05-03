#include <iostream>
#include <fstream>
template <typename T>
void get_nextval(T s1, int nextval[]){
    int i = 1, j = 0;
    nextval[0] = 0;
    while(i < s1.length())
    {
        if(j == 0 || s1[i-1] == s1[j-1])
        {
            ++i;
            ++j;
            if(s1[i-1] != s1[j-1])
                nextval[i-1] = j;
            else
                nextval[i-1] = nextval[j-1];
        }
        else
            j = nextval[j-1];
    }
}
template <typename T>
bool KMP(T s1, T s2)
{
    int len = s1.length();
    s1 += s1;
    std::string s = s1;
    for (int i = 0; i < len; i++)
    {
        s = s1.substr(i, len);
        int nextval[len];
        get_nextval(s, nextval);
        int j = 1, k = 1;
        while (j <= len && k <= s2.length())
        {
            if (j==0||s2[k-1]==s[j-1])
            {
                ++j;
                ++k;
            }
            else
            {
                j = nextval[j-1];
            }
        }
        if(j > len)
            return true;
    }
    return false;
}

int main()
{
    std::string filename;
    std::string s1, s2;
    int num;
    std::cout << "请输入想要读取的文件名称：" << std::endl;
    std::cin >> filename;
    std::ifstream inf;
    inf.open(filename);
    inf >> num;
    std::ofstream outf;
    outf.open("outputdata.txt");
    outf << "以下为本次病毒检测结果：" << std::endl;
    for (int i = 0; i < num; i++)
    {
        inf >> s1 >> s2;
        if (KMP(s1, s2))
        {
            outf << "YES  " << s1 << "   " << s2 << std::endl;
        }
        else
            outf << "NO   " << s1 << "   " << s2 << std::endl;
    }
    inf.close();
    outf.close();
    return 0;
}