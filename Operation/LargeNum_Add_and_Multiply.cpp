
/*-----�������⣺���ַ������������Ӻ����-----*/

/*----------add---------------*/
// assume m is bigger than n.
char* add(char *a, char *b, int m, int n)
{
    // Ϊ��������ڴ�ռ䡣
    char *c = (char*)malloc((m + 2)* sizeof(char));
    memset(c, 0, (m + 2) * sizeof(char));  //���ѿ����ڴ�ռ�c����(m + 2) * sizeof(char)���ֽڵ�ֵ��Ϊֵ 0��
    
    // ���ַ���0 + 0x30 �� 9 + 0x30��ת��Ϊ���֣�0��9�����м��㡣
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
    // ���ɴ�������ɵĽ��ת��Ϊ�ַ�������ȥ���ײ����ܻ����ڵ��㡣
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
    // Ϊ��������ڴ�ռ䡣
    char *c = (char*)malloc((m + n + 1) * sizeof(char));
    memset(c, 0, (m + n + 1) * sizeof(char));
 
    // ���ַ���0 + 0x30 �� 9 + 0x30��ת��Ϊ���֣�0��9�����м��㡣
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
 
    // ���ɴ�������ɵĽ��ת��Ϊ�ַ�������ȥ���ײ����ܻ����ڵ��㡣
    c[m + n] = '/0';
    for (int i = 0; i != m + n; ++i)
        c[i] += 0x30;
    if (c[0] == 0x30)
        for (int i = 0;  c[i] != '/0'; ++i)
            c[i] = c[i + 1];

    return c;
}
