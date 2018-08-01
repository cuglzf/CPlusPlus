
/*
��ָoffer�����⣺
��һ������Ϊn���������������ֶ���0~n-1֮�䣬��Щ�������ظ��ģ�����������һ���ظ�������
˼·��
1������������Ȼ���ͷ�������ɣ�ʱ�临�Ӷ�O(n)
2�����ù�ϣ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
3����Ϊÿ�����ֶ���0~n-1�����û���ظ������������±�һһ��Ӧ�����˼·���ǽ����ֻ�ԭ����Ӧ
���±��У���ô������ظ�����ԭ��ʱ��ᷢ���Ѿ������±��Ӧ��Ԫ���ˣ���������־��ظ���
*/
/*
���裺
1���ж������Ƿ����
2����������е�Ԫ���Ƿ���ȷ
3�����±�Ϊindex=0��ʼ��λ��������,
  3.1 ���number[index]������index���������Ҫ��λ�����ж�����λ��λ���Ƿ��Ѿ�������ȷ������
      �����λ��λ���Ѿ�������ȷ�����֣�������ظ�������
  3.2 ���number[index]����index����index+1������һλ��ʼ
4������false�����ظ�
*/
//ͨ��deplication�����ظ������֣����������Ƿ����ظ�������
bool duplicate(int numbers[], int length, int *deplication)
{
	//1�������ж������Ƿ����
	if (length < 1 || numbers == nullptr)
		return false;

	//2���ж������Ƿ�Ϸ�
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	//3����numbers[0]��ʼ��λ��������
	int index = 0;
	while (index < length)
	{
		int currentNumber = numbers[index];
		//��������±������������ֲ�ͬ
		if (currentNumber != index)
		{
			//�������������ж���Ҫ�������ĵط��Ƿ��Ѿ�������ȷ�������ˣ�
			//������ڣ���ô������־����ظ��ģ��˳�
			if (numbers[currentNumber] == currentNumber)
			{
				*deplication = numbers[currentNumber];
				return true;
			}
			//���򣬵�����������
			int temp = numbers[currentNumber];
			numbers[currentNumber] = currentNumber;
			numbers[index] = temp;
		}
		else
			++index;
	}

	return false;
}