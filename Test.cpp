#include<iostream>
#include<map>
#include<string>
using namespace std;

void test_map()
{
	map<string, string> dict;
	dict.insert(make_pair("字符串", "string"));
	dict.insert(make_pair("排序", "sort"));
	dict.insert(make_pair("左", "left"));
	//既然支持[]的使用，这里不妨这样进行插入
	//插入的K值相同的情况，V的值不同
	dict["结束"] = "finish";
	dict["结束"] = "begin";//只关心K值，这个value会覆盖上面的那个value值（finish）
	//插入的V值相同的情况，K的值不同
	dict["糟糕"] = "beautiful";
	dict["美好"] = "beautiful";

	//从结果也可以看出来，是按照K值的ASCII值进行的排序，其中只关心K值，不在乎Value的值

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}


	string strs[] = { "sort", "insert", "sort", "sort", "insert", "erase" };
	map<string, int> CountMap;

	//[]实现的使用方法是insert,insert的返回值是pair<iterator,bool>

	//for (auto& s : strs)
	//{
	//	//如果成功则返回那个新插入结点的指针，第二个参数设置为true
	//	//如果失败，说明已经存在，那就返回那个已经存在结点的指针，并且第二个参数设置为false
	//	pair<map<string, int>::iterator, bool> ret = CountMap.insert(make_pair(s, 1));
	//	//说明这个值已经存储在了vector中，不需要在插入了
	//	if (ret.second == false)
	//	{
	//		//ret是一个pair，ret.first拿到pair里面的第一个参数，再去second拿到map里面的int
	//		ret.first->second++;
	//	}

	//}


	//结论：map[]有两层作用
	//1.如果K不在，插入pair(K,V())，并且返回value的引用（便于修改）
	//2.如果K在，不插入，返回跟K相等那个结点的value的引用
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
