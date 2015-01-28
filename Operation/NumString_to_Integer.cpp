/*将一组字符串表示数字转成十进制表示*/

int NumString_to_Integer(char a[])
{
	int sum=0,k=0;
	int len = 0;
	bool flag = false;
	bool book = false;
	bool signalFlag = true;
	
	for (len = 0; a[len] != '\0'; len++);
	for (int i=0; i<len;i++)
	{
		if((a[i]=='-'||a[i]=='+') && signalFlag)
		{
			if (a[i]=='-')
			{
				book = true;
			} 
			signalFlag =false;
		}
		
		if (a[i]>='0' && a[i]<='9')
		{
			flag = true;
			sum = sum *10 +(a[i]-'0');
		}
		if ((a[i+1]<'0' || a[i+1]>'9') && flag )
		{
			if (book)
			{
				return -sum;
				
			}
			else {
				return sum;
			}
			
		}
	}
}