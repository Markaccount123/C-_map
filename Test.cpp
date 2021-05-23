#include<iostream>
#include<map>
#include<string>
using namespace std;

void test_map()
{
	map<string, string> dict;
	dict.insert(make_pair("�ַ���", "string"));
	dict.insert(make_pair("����", "sort"));
	dict.insert(make_pair("��", "left"));
	//��Ȼ֧��[]��ʹ�ã����ﲻ���������в���
	//�����Kֵ��ͬ�������V��ֵ��ͬ
	dict["����"] = "finish";
	dict["����"] = "begin";//ֻ����Kֵ�����value�Ḳ��������Ǹ�valueֵ��finish��
	//�����Vֵ��ͬ�������K��ֵ��ͬ
	dict["���"] = "beautiful";
	dict["����"] = "beautiful";

	//�ӽ��Ҳ���Կ��������ǰ���Kֵ��ASCIIֵ���е���������ֻ����Kֵ�����ں�Value��ֵ

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}


	string strs[] = { "sort", "insert", "sort", "sort", "insert", "erase" };
	map<string, int> CountMap;

	//[]ʵ�ֵ�ʹ�÷�����insert,insert�ķ���ֵ��pair<iterator,bool>

	//for (auto& s : strs)
	//{
	//	//����ɹ��򷵻��Ǹ��²������ָ�룬�ڶ�����������Ϊtrue
	//	//���ʧ�ܣ�˵���Ѿ����ڣ��Ǿͷ����Ǹ��Ѿ����ڽ���ָ�룬���ҵڶ�����������Ϊfalse
	//	pair<map<string, int>::iterator, bool> ret = CountMap.insert(make_pair(s, 1));
	//	//˵�����ֵ�Ѿ��洢����vector�У�����Ҫ�ڲ�����
	//	if (ret.second == false)
	//	{
	//		//ret��һ��pair��ret.first�õ�pair����ĵ�һ����������ȥsecond�õ�map�����int
	//		ret.first->second++;
	//	}

	//}


	//���ۣ�map[]����������
	//1.���K���ڣ�����pair(K,V())�����ҷ���value�����ã������޸ģ�
	//2.���K�ڣ������룬���ظ�K����Ǹ�����value������
	for (auto& s : strs)
	{
		CountMap[s]++;
	}

	for (auto& e : CountMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}


int main()
{
	test_map();
	return 0;
}
