
/*-----大数问题：用字符串解决大数相加和相乘-----*/

/*----------add---------------*/
// assume m is bigger than n.
char* add(char *a, char *b, int m, int n)
{
    // 为结果分配内存空间。
    char *c = (char*)malloc((m + 2)* sizeof(char));
    memset(c, 0, (m + 2) * sizeof(char));  //将已开辟内存空间c的首(m + 2) * sizeof(char)个字节的值设为值 0。
    
    // 将字符（0 + 0x30 到 9 + 0x30）转换为数字（0到9）进行计算。
    for (int i = m, j = n - 1; j >= 0; --i, --j)
        c[i] += (b[j] - 0x30);
    for (int i = m, j = m - 1; j >= 0; --i, --j)
    {
        c[i] += (a[j] - 0x30);
        if (c[i] > 9)
        {
            c[i - 1] += 1;
            c[i] -= 10;
        }
    }
    // 将由纯数字组成的结果转换为字符串，并去除首部可能还存在的零。
   c[m + 1] = '/0';
    for (int i = 0; i != m + 1; ++i)
        c[i] += 0x30;
    if (c[0] == 0x30)
        for (int i = 0; c[i] != '/0'; ++i)
            c[i] = c[i + 1];
    
    return c;
}


/*----------multiply--------------*/
// assume m is bigger than n.
char* mult(char *a, char *b, int m, int n)
{
    // 为结果分配内存空间。
    char *c = (char*)malloc((m + n + 1) * sizeof(char));
    memset(c, 0, (m + n + 1) * sizeof(char));
 
    // 将字符（0 + 0x30 到 9 + 0x30）转换为数字（0到9）进行计算。
    for (int i = m - 1, r = m + n - 1; i >= 0; --i, --r)
    {
        for (int j = n - 1, k = r; j >= 0; --j, --k)
        {
            c[k] += (a[i] - 0x30) * (b[j] - 0x30);
            int tmp = c[k] / 10;
            if (tmp > 1)
            {
                c[k - 1] += tmp;
                c[k] -= tmp * 10;
            }
        }
    }
 
    // 将由纯数字组成的结果转换为字符串，并去除首部可能还存在的零。
    c[m + n] = '/0';
    for (int i = 0; i != m + n; ++i)
        c[i] += 0x30;
    if (c[0] == 0x30)
        for (int i = 0;  c[i] != '/0'; ++i)
            c[i] = c[i + 1];

    return c;
}
