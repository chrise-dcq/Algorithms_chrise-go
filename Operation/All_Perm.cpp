
/*------È«ÅÅÁĞ----------*/
template <typename T>
void perm(T array[], int k, int m)
{

	if (k == m)
	{
		for(int i = 0; i <= m; i++)
			cout<<array[i];
		cout<<endl;
	}
	else{
		for (int i = k;i <= m; i++)
		{
			swap(array[k], array[i]);
			perm(array, k+1, m);
			swap(array[k], array[i]);
		}
	}
}