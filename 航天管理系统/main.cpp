
#include"tool.h"

using namespace std;

int main()
{
	AriportRoutes *airportrouts = new AriportRoutes[SIZE];//������Ϣ
	Pananger *pananger,*backpananger;//backpananger�Ǻ�Ʊ����
	pananger = new Pananger();
	backpananger = new Pananger();
	ceratbackpananger(backpananger);//����
	creatairport(airportrouts);//����������Ϣ�����飬����
	creatpananger(pananger);//����
	
	int choice;//�û�ѡ��ı���
	string name;
	printf("��ӭʹ�ú������ϵͳ,��ѡ��������\n");
	printf("1-----����������Ա      2------�˿�\n");
	
	while (1)
	{
		cin>>choice;
		if (choice == 2)
		{
			pannager_show();
			cout << "������������"<<endl;
			cin >> name;
			
			while (1)
			{
				cout<<"�����������ţ�"<<endl;
				cin >> choice;
				switch (choice)
				{
				case 0://�˳�ϵͳ
					write(pananger, airportrouts,backpananger);
					cout<<"��ӭ�´�ʹ��"<<endl;
					exit(0);
				case 1://1.��    Ʊ
					booktiket(pananger, airportrouts,name, backpananger);
					break;
				case 2://2.��ѯ����
					serchairport(airportrouts);
					break;
				case 3://3.��    ǩ
					changeticket(pananger, airportrouts,name);
					break;
				case 4://4.��    Ʊ
					refund(pananger, airportrouts,name,backpananger);
					break;
				case 5://5.��ʾ��Ʊ��Ϣ
					showperson(pananger,name);
					break;
				case 6:
					cout << "������������" << endl;
					cin >> name;
					break;
					

				default:
					cout << "�����������������" << endl;
					break;
				}
			}

		}
		else if (choice == 1) {
			
			while (1)
			{
				airpote_show();
				cout << "�����������ţ�" << endl;
				cin >> choice;
				switch (choice)
				{
				case 0://�˳�ϵͳ
					cout << "��ӭ�´�ʹ��" << endl;
					exit(0);
				case 1://3.�鿴������Ϣ
					showairport(airportrouts);
					break;
				case 2://4.�鿴��Ʊ��Ϣ
					showallpananger(pananger);
					break;
				case 3://5.�鿴������
					showall(backpananger);
					break;
					

				default:
					cout<<"�����������������"<<endl;
					break;
				}
			}
		}
		else
		{
			printf("�����������������");
		}
	}
	system("pause");
	return 0;
}