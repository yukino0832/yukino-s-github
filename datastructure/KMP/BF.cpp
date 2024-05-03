#include <iostream>
#include <fstream>
template <typename T>
bool BF(T s1, T s2){
    int len = s1.length();
    s1 += s1;
    std::string s = s1;
    for (int i = 0; i < len; i++)
    {
        s = s1.substr(i,len);
        int j=0, k=0;
        while(j<len && k<s2.length())
        {
            if(s[j] == s2[k])
            {
                ++j;
                ++k;
            }
            else
            {
                k = k - j + 1;
                j = 0;
            }
        }
        if(j == len)
            return true;
    }
    return false;
}

int main(){
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
        if(BF(s1, s2))
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