
#include"tool.h"

using namespace std;

int main()
{
	AriportRoutes *airportrouts = new AriportRoutes[SIZE];//航线信息
	Pananger *pananger,*backpananger;//backpananger是候补票序列
	pananger = new Pananger();
	backpananger = new Pananger();
	ceratbackpananger(backpananger);//链表
	creatairport(airportrouts);//构建航班信息，数组，不动
	creatpananger(pananger);//链表
	
	int choice;//用户选择的变量
	string name;
	printf("欢迎使用航天管理系统,请选择你的身份\n");
	printf("1-----机场管理人员      2------乘客\n");
	
	while (1)
	{
		cin>>choice;
		if (choice == 2)
		{
			pannager_show();
			cout << "请输入姓名："<<endl;
			cin >> name;
			
			while (1)
			{
				cout<<"请输入操作序号："<<endl;
				cin >> choice;
				switch (choice)
				{
				case 0://退出系统
					write(pananger, airportrouts,backpananger);
					cout<<"欢迎下次使用"<<endl;
					exit(0);
				case 1://1.订    票
					booktiket(pananger, airportrouts,name, backpananger);
					break;
				case 2://2.查询航线
					serchairport(airportrouts);
					break;
				case 3://3.改    签
					changeticket(pananger, airportrouts,name);
					break;
				case 4://4.退    票
					refund(pananger, airportrouts,name,backpananger);
					break;
				case 5://5.显示订票信息
					showperson(pananger,name);
					break;
				case 6:
					cout << "请输入姓名：" << endl;
					cin >> name;
					break;
					

				default:
					cout << "输入错误请重新输入" << endl;
					break;
				}
			}

		}
		else if (choice == 1) {
			
			while (1)
			{
				airpote_show();
				cout << "请输入操作序号：" << endl;
				cin >> choice;
				switch (choice)
				{
				case 0://退出系统
					cout << "欢迎下次使用" << endl;
					exit(0);
				case 1://3.查看航天信息
					showairport(airportrouts);
					break;
				case 2://4.查看订票信息
					showallpananger(pananger);
					break;
				case 3://5.查看候补名单
					showall(backpananger);
					break;
					

				default:
					cout<<"输入错误，请重新输入"<<endl;
					break;
				}
			}
		}
		else
		{
			printf("输入错误请重新输入");
		}
	}
	system("pause");
	return 0;
}