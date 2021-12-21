#include"tool.h"
#include"AriportRoutes.h"
#include"Pananger.h"
//航天信息
void airpote_show() {
	cout<<"-------------欢迎使用航天管理系统-----------"<<endl;
	cout << "-------------1.查看航线信息-----------------" << endl;
	cout << "-------------2.查看订票信息----------------- "<< endl;
	cout << "-------------3.查看候补名单----------------- "<< endl;
	cout << "-------------0.退出系统--------------------- "<< endl;
}
//乘客菜单
void pannager_show() {
	cout << "-------------欢迎使用航天管理系统-----------" << endl;
	cout << "-------------1.订    票---------------------" << endl;
	cout << "-------------2.查询航线---------------------" << endl;
	cout << "-------------3.改    签----------------------" << endl;
	cout << "-------------4.退    票----------------------" << endl;
	cout << "-------------5.显示订票信息------------------" << endl;
	cout << "-------------6.切换用户------------------" << endl;
	cout << "-------------0.退出系统----------------------" << endl;
}
//读取文件创建航班信息
void creatairport(AriportRoutes *&airportrouts) {
	ifstream file;
	string endden, flight, plane, planetime, pangernumber,remain;
	int i=0, pangernumber1,remain1;
	file.open("domo.txt", ios::in);
	if (!file.is_open()) {
		cout << "打开文件失败" << endl;
	}
	else 
	{
		while (!file.eof())
		{
			getline(file, endden);
			getline(file, flight);
			getline(file, plane);
			getline(file, planetime);
			getline(file, pangernumber);
			getline(file, remain);
			pangernumber1 = atoi(pangernumber.c_str());
			remain1 = atoi(remain.c_str());
			airportrouts[i].setData(endden, flight, plane, planetime, pangernumber1,remain1);
			i++;
		}

	}
	SIZE = i;
	//cout << SIZE << endl;
}
//根据终点站查询航班信息
void serchairport(AriportRoutes*& airportrouts) {
	string endden;
	cout << "请输入终点站" << endl;
	cin >> endden;
	for (int i = 0; i < SIZE;i++) {
		if (airportrouts[i].getendden()==endden)
		{
			cout << "终点站：" << airportrouts[i].getendden()<<endl;
			cout << "航班号：" << airportrouts[i].getflight() << endl;
			cout << "飞机号" << airportrouts[i].getplane() << endl;
			cout << "飞行周日：" << airportrouts[i].getplanetime() << endl;
			cout << "乘客定额：" << airportrouts[i].getpangernumber() << endl;
			cout << "剩余票数:" << airportrouts[i].getremain() << endl;
			cout << endl;
			return;
        }
		
		}
	cout << "无此航线" << endl;
	
}
//读取文件创建候补乘客信息
void ceratbackpananger(Pananger*& backpananger)
{
	Pananger* head, * temp;
	int titlenumber1;
	head = backpananger;
	string name, flight, titlenumber;
	ifstream file;
	file.open("backpananger.txt", ios::in);
	if (head)
	{
		if (!file.is_open())
		{
			cout << "打开文件失败" << endl;
		}

		else {
			while (!file.eof())
			{
				getline(file, name);
				getline(file, titlenumber);
				getline(file, flight);
				titlenumber1 = atoi(titlenumber.c_str());
				if (name!="")
				{
					temp = new Pananger(name, titlenumber1, flight);
					temp->next = NULL;
					head->next = temp;
					head = temp;
					//cout << "姓名：" << head->getNnme();
				}
				

			}

		}

	}
	

}

//订票功能的实现,创建候补票链表
void booktiket(Pananger*& pananger, AriportRoutes*& airportrouts, string name, Pananger*& backpananger) {
	string endden;
	int number,choice;//航班票的票数
	Pananger* head;
	head = pananger->next;
	
	while (head)
	{
		if (head->getNnme()==name)
		{

			
			cout << "请输入您的终点站" << endl;
			cin >> endden;
			cout << "请输入订购的票数";
			cin >> number;
			for (int i = 0; i < SIZE; i++) 
			{
				if (airportrouts[i].getendden() == endden)
				{
					if (airportrouts[i].getremain() < number)
					{
						cout << "剩余票数不足,是否开始候补票\n1------是    2-----否" << endl;
						cin >> choice;
						switch (choice)
						{
						case 1://加入候补票序列 
							init(backpananger, name, airportrouts[i].getflight(), number);
							return;
							break;
						case 2:
							break;
						default:
							break;
						}
					}
					else {
						airportrouts[i].setremain(airportrouts[i].getremain() - number);
						head->setFlight(airportrouts[i].getflight());
						head->setTitlenumber(number);
						cout << "恭喜你订票成功" << endl;
						return;

					}

				
				}

			}
			cout << "无此航线" << endl;
			
			return;
		}
		head = head->next;

	}
	cout << "查无此人" << endl;	
}
//退票,//检索候补票链表，给了第一个
void refund(Pananger*& pananger, AriportRoutes*& airportrouts, string name,Pananger *&backpananger) {
	Pananger* head,*low;
	int number;
	head = pananger->next;
	low = backpananger;
	cout << "请输入要退票的张数" << endl;
	cin >> number;
	while (head)
	{
		if (head->getNnme() == name) 
		{
			for (int i = 0; i < SIZE; i++) 
			{
				if (airportrouts[i].getflight() == head->getFlight()) 
				{
					if (head->getTitlenumber()>=number)
					{
						head->setTitlenumber(head->getTitlenumber() - number);
						if(head->getTitlenumber()==0) head->setFlight("");
						
						
						airportrouts[i].setremain(airportrouts[i].getremain() + number);
						houbu(pananger, backpananger, airportrouts[i]);
						cout << "退票成功";
						break;
					}
				}
		
			}
			return;
		}
		
		head = head->next;

	}
	cout << "查无此人" << endl;

}
//3.改    签
void changeticket(Pananger*& pananger, AriportRoutes*& airportrouts, string name) {
	string endden;
	int number;
	Pananger* head;
	head = pananger->next;
	while (head)
	{
		if (head->getNnme()==name)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (airportrouts[i].getflight() == head->getFlight())
				{
					airportrouts[i].setremain(airportrouts[i].getremain() + head->getTitlenumber());

				}
			}
			
			head->setFlight("");
			head->setTitlenumber(0);
			cout << "请输入终点站" << endl;
			cin >> endden;
			cout << "请输入订购票数" << endl;
			cin >> number;
			for (int i = 0; i < SIZE; i++) 
			{
				if (airportrouts[i].getendden()==endden)
				{
					head->setFlight(airportrouts[i].getflight());
					if (airportrouts[i].getremain() < number)
					{
						cout << "查无此人" << endl;
					}
					else
					{
						head->setTitlenumber(number);
					}
					return;
				}

			}
		
		}
		head = head->next;

	}

}
//显示个人信息
void showperson(Pananger*& pananger, string name) {
	Pananger* head;
	head = pananger->next;
	while (head)
	{
		if (head->getNnme() == name) {
			cout << "用户名："<< head->getNnme() << endl;
			cout << "订购票数：" << head->getTitlenumber() << endl;
			cout << "航班号:" << head->getFlight() << endl;
			cout << endl;
			return;
		}
		head = head->next;
	}
	cout << "查无此人" << endl;
	
}
//创建乘客类
 void creatpananger(Pananger*& pananger) {
	Pananger *head ,*temp;
	int titlenumber1;
	head = pananger;
	string name, flight, titlenumber;
	ifstream file;
	file.open("pananger.txt", ios::in);
	if (!file.is_open())
	{
		cout << "打开文件失败" << endl;
	}
		
	else {
		while (!file.eof())
		{
			getline(file, name);
			getline(file, titlenumber);
			getline(file, flight);
			titlenumber1 = atoi(titlenumber.c_str());
			temp = new Pananger(name, titlenumber1, flight);
			temp->next = NULL;
			head->next = temp;
			head = temp;
		    
		}

	}
	
}
 //传递航班号和用户名姓名创建链表
 void init(Pananger*& backpananger, string name, string flight, int ticketnumber)
 {
	 Pananger* head, * temp;
	
	 head = backpananger;
	 while (head->next)
	 {
		 
		 head = head->next;
		 
	 }
	     temp = new Pananger(name,ticketnumber,flight);
		 temp->next = NULL;
		 head->next = temp;
		 cout <<"航班号为" << temp->getFlight() << "候补票添加成功" << endl;
 }
 //根据用户名删除候补票链表
 void delatebackpananger(Pananger*& backpananger, string name)
 {
	 Pananger* head, * temp;
	 head = backpananger;
	 temp = NULL;
	 if (head->next->getNnme()==name)
	 {
		 temp = head->next;
		 head->next = head->next->next;
		 delete temp;
		 
	 }
	 else
	 {
		 while (head)
		 {
			 if (head->next->getNnme() == name)
			 {
				 temp = head->next;
				 head->next = temp->next;
				 delete temp;
				 cout << "删除成功" << endl;
				
			 }
			 head = head->next;
		 }
	 }
		 /*while (head)
	 {
		 if (head->next->getNnme() == name)
		 {
			 temp = head;
			 head->next->next = temp->next;
			 temp->next = NULL;
			 delete temp;
			 cout << "删除成功" << endl;
			 return;
		 }
		 head = head->next;
	 }*/
 }
 //当检测到有人退票时，遍历候补票链表
 void houbu(Pananger*& pananger, Pananger*& backpananger, AriportRoutes& airportrouts)
 {
	 Pananger* backhead, * head;
	 backhead = backpananger->next;
	 head = pananger;
	 while (backhead)
	 {
		 if (airportrouts.getflight() == backhead->getFlight())
		 {
			 while (head)
			 {
				 if (airportrouts.getremain() >= backhead->getTitlenumber())
				 {
					 if (head->getNnme() == backhead->getNnme())
					 {
						 head->setTitlenumber(backhead->getTitlenumber());
						 head->setFlight(backhead->getFlight());
						 airportrouts.setremain(airportrouts.getremain() - head->getTitlenumber());
						 cout << head->getNnme() << "的" << head->getTitlenumber() << "候补票订购成功" << endl;
						 delatebackpananger(backpananger, head->getNnme());
						 return;
					 }
				 }
				 else
				 {
					 if (head->getNnme() == backhead->getNnme())
					 {
						 head->setTitlenumber(airportrouts.getremain());
						 head->setFlight(backhead->getFlight());
						 cout << head->getNnme() << "的" << head->getTitlenumber() << "候补票订购成功" << endl;
						 delatebackpananger(backpananger, head->getNnme());
						 return;
					 }
				 }
				 head = head->next;
			 }

		 }
		 backhead = backhead->next;
	 }
 }
 //将内容写入文件
 void write(Pananger* pananger, AriportRoutes airportrouts[],Pananger *backpananger)
 {
	 int error=0;
	 Pananger* head;
	 head = pananger->next;
	 ofstream file;
	 file.open("pananger.txt",ios::out);
	 while (head)
	 {
		 file << head->getNnme() << endl;
		 file << head->getTitlenumber() << endl;
		 file << head->getFlight();
		 if (head->next)
		 {
			file << endl;
		 }
		 head = head->next;
	 }
	 file.close();

	 ofstream filea;
	 filea.open("domo.txt", ios::out);
	 for (int i = 0; i < SIZE; i++)
	 {
		 filea << airportrouts[i].getendden() << endl;
		 filea << airportrouts[i].getflight() << endl;
		 filea << airportrouts[i].getplane() << endl;
		 filea << airportrouts[i].getplanetime() << endl;
		 filea << airportrouts[i].getpangernumber() << endl;
		 filea << airportrouts[i].getremain();
		 if (i != SIZE - 1)
		 {
			 filea << endl;

		 }
	 }
	 filea.close();
	 //将backpananger写入文件
	 Pananger* headb,*head1,*temp;
	 headb = backpananger->next;
	
	 ofstream fileb;
	 fileb.open("backpananger.txt", ios::out);
	 /*if (error<2)
	 {
		 cout << "没有数据" << endl;
	 }
	 else
	 {*/
		 while (headb)
		 {
			 cout << headb->getNnme() << endl;
			 if (headb->getNnme()!="")
			 {
				 
				 fileb << headb->getNnme() << endl;
				 fileb << headb->getTitlenumber() << endl;
				 fileb << headb->getFlight() << endl;

			 }

			 
			 headb = headb->next;

		 }
	 
	 fileb.close();
	 
 }
 //5.查看候补名单
 void showall(Pananger*& backpananger)
 {
	 Pananger* head;
	 head = backpananger;
	 
	 if (!head->next)
	 {
		 cout << "无候补乘客" << endl;
	 }
	 else
	 {
		 while (head)
		 {
			 if (head->getNnme()!="")
			 {
				 cout << "乘客姓名：" << head->getNnme() << endl;
				 cout << "候补票数" << head->getTitlenumber() << endl;
				 cout << "候补航班号" << head->getFlight() << endl;
				 cout << endl;

			 }
			 
			 head = head->next;
			 
		 }
	 }
 }
 //显示订票名单
 void showallpananger(Pananger*& pananger)
 {
	 Pananger* head;
	 head = pananger->next;
	 int number=0;
	 while (head)
	 {
		 if (head->getFlight()!="")
		 {
			 cout << "乘客姓名：" << head->getNnme() << endl;
			 cout << "订购票数" << head->getTitlenumber() << endl;
			 cout << "航班号" << head->getFlight() << endl;
			 cout << endl;
			 number++;
		 }
		 head = head->next;
	 }
	 if (number==0)
	 {
		 cout << "无人订票" << endl;
	 }
 }
 //查看航线信息
 void showairport(AriportRoutes *&airportrouts)
 {
	 for (int i = 0; i < SIZE; i++)
	 {
		 cout << "终点站：" << airportrouts[i].getendden()<< endl;
		 cout << "航班号：" << airportrouts[i].getflight() << endl;
		 cout << "飞机号" << airportrouts[i].getplane() << endl;
		 cout << "飞行周日：" << airportrouts[i].getplanetime() << endl;
		 cout << "乘客定额：" << airportrouts[i].getpangernumber() << endl;
		 cout << "剩余票数:" << airportrouts[i].getremain() << endl;
		 cout << endl;
	 }
 }

 