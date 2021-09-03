int strConteins(char* a, char* str) 
{
	int it = -1;

	int i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == a[0])
		{
			bool was_found = true;
			int j = 0;
			while(a[j] != '\0')
			{
				if (a[j] != str[i + j])
				{
					was_found = false;
					break;
				}

				j++;
			}
			
			if (was_found)
			{
				it = i;
				break;
			}
		}

		i++;
	}

	return it;
}
