#include"tool.h"
#include"AriportRoutes.h"
#include"Pananger.h"
//������Ϣ
void airpote_show() {
	cout<<"-------------��ӭʹ�ú������ϵͳ-----------"<<endl;
	cout << "-------------1.�鿴������Ϣ-----------------" << endl;
	cout << "-------------2.�鿴��Ʊ��Ϣ----------------- "<< endl;
	cout << "-------------3.�鿴������----------------- "<< endl;
	cout << "-------------0.�˳�ϵͳ--------------------- "<< endl;
}
//�˿Ͳ˵�
void pannager_show() {
	cout << "-------------��ӭʹ�ú������ϵͳ-----------" << endl;
	cout << "-------------1.��    Ʊ---------------------" << endl;
	cout << "-------------2.��ѯ����---------------------" << endl;
	cout << "-------------3.��    ǩ----------------------" << endl;
	cout << "-------------4.��    Ʊ----------------------" << endl;
	cout << "-------------5.��ʾ��Ʊ��Ϣ------------------" << endl;
	cout << "-------------6.�л��û�------------------" << endl;
	cout << "-------------0.�˳�ϵͳ----------------------" << endl;
}
//��ȡ�ļ�����������Ϣ
void creatairport(AriportRoutes *&airportrouts) {
	ifstream file;
	string endden, flight, plane, planetime, pangernumber,remain;
	int i=0, pangernumber1,remain1;
	file.open("domo.txt", ios::in);
	if (!file.is_open()) {
		cout << "���ļ�ʧ��" << endl;
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
//�����յ�վ��ѯ������Ϣ
void serchairport(AriportRoutes*& airportrouts) {
	string endden;
	cout << "�������յ�վ" << endl;
	cin >> endden;
	for (int i = 0; i < SIZE;i++) {
		if (airportrouts[i].getendden()==endden)
		{
			cout << "�յ�վ��" << airportrouts[i].getendden()<<endl;
			cout << "����ţ�" << airportrouts[i].getflight() << endl;
			cout << "�ɻ���" << airportrouts[i].getplane() << endl;
			cout << "�������գ�" << airportrouts[i].getplanetime() << endl;
			cout << "�˿Ͷ��" << airportrouts[i].getpangernumber() << endl;
			cout << "ʣ��Ʊ��:" << airportrouts[i].getremain() << endl;
			cout << endl;
			return;
        }
		
		}
	cout << "�޴˺���" << endl;
	
}
//��ȡ�ļ������򲹳˿���Ϣ
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
			cout << "���ļ�ʧ��" << endl;
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
					//cout << "������" << head->getNnme();
				}
				

			}

		}

	}
	

}

//��Ʊ���ܵ�ʵ��,������Ʊ����
void booktiket(Pananger*& pananger, AriportRoutes*& airportrouts, string name, Pananger*& backpananger) {
	string endden;
	int number,choice;//����Ʊ��Ʊ��
	Pananger* head;
	head = pananger->next;
	
	while (head)
	{
		if (head->getNnme()==name)
		{

			
			cout << "�����������յ�վ" << endl;
			cin >> endden;
			cout << "�����붩����Ʊ��";
			cin >> number;
			for (int i = 0; i < SIZE; i++) 
			{
				if (airportrouts[i].getendden() == endden)
				{
					if (airportrouts[i].getremain() < number)
					{
						cout << "ʣ��Ʊ������,�Ƿ�ʼ��Ʊ\n1------��    2-----��" << endl;
						cin >> choice;
						switch (choice)
						{
						case 1://�����Ʊ���� 
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
						cout << "��ϲ�㶩Ʊ�ɹ�" << endl;
						return;

					}

				
				}

			}
			cout << "�޴˺���" << endl;
			
			return;
		}
		head = head->next;

	}
	cout << "���޴���" << endl;	
}
//��Ʊ,//������Ʊ�������˵�һ��
void refund(Pananger*& pananger, AriportRoutes*& airportrouts, string name,Pananger *&backpananger) {
	Pananger* head,*low;
	int number;
	head = pananger->next;
	low = backpananger;
	cout << "������Ҫ��Ʊ������" << endl;
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
						cout << "��Ʊ�ɹ�";
						break;
					}
				}
		
			}
			return;
		}
		
		head = head->next;

	}
	cout << "���޴���" << endl;

}
//3.��    ǩ
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
			cout << "�������յ�վ" << endl;
			cin >> endden;
			cout << "�����붩��Ʊ��" << endl;
			cin >> number;
			for (int i = 0; i < SIZE; i++) 
			{
				if (airportrouts[i].getendden()==endden)
				{
					head->setFlight(airportrouts[i].getflight());
					if (airportrouts[i].getremain() < number)
					{
						cout << "���޴���" << endl;
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
//��ʾ������Ϣ
void showperson(Pananger*& pananger, string name) {
	Pananger* head;
	head = pananger->next;
	while (head)
	{
		if (head->getNnme() == name) {
			cout << "�û�����"<< head->getNnme() << endl;
			cout << "����Ʊ����" << head->getTitlenumber() << endl;
			cout << "�����:" << head->getFlight() << endl;
			cout << endl;
			return;
		}
		head = head->next;
	}
	cout << "���޴���" << endl;
	
}
//�����˿���
 void creatpananger(Pananger*& pananger) {
	Pananger *head ,*temp;
	int titlenumber1;
	head = pananger;
	string name, flight, titlenumber;
	ifstream file;
	file.open("pananger.txt", ios::in);
	if (!file.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
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
 //���ݺ���ź��û���������������
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
		 cout <<"�����Ϊ" << temp->getFlight() << "��Ʊ��ӳɹ�" << endl;
 }
 //�����û���ɾ����Ʊ����
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
				 cout << "ɾ���ɹ�" << endl;
				
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
			 cout << "ɾ���ɹ�" << endl;
			 return;
		 }
		 head = head->next;
	 }*/
 }
 //����⵽������Ʊʱ��������Ʊ����
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
						 cout << head->getNnme() << "��" << head->getTitlenumber() << "��Ʊ�����ɹ�" << endl;
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
						 cout << head->getNnme() << "��" << head->getTitlenumber() << "��Ʊ�����ɹ�" << endl;
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
 //������д���ļ�
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
	 //��backpanangerд���ļ�
	 Pananger* headb,*head1,*temp;
	 headb = backpananger->next;
	
	 ofstream fileb;
	 fileb.open("backpananger.txt", ios::out);
	 /*if (error<2)
	 {
		 cout << "û������" << endl;
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
 //5.�鿴������
 void showall(Pananger*& backpananger)
 {
	 Pananger* head;
	 head = backpananger;
	 
	 if (!head->next)
	 {
		 cout << "�޺򲹳˿�" << endl;
	 }
	 else
	 {
		 while (head)
		 {
			 if (head->getNnme()!="")
			 {
				 cout << "�˿�������" << head->getNnme() << endl;
				 cout << "��Ʊ��" << head->getTitlenumber() << endl;
				 cout << "�򲹺����" << head->getFlight() << endl;
				 cout << endl;

			 }
			 
			 head = head->next;
			 
		 }
	 }
 }
 //��ʾ��Ʊ����
 void showallpananger(Pananger*& pananger)
 {
	 Pananger* head;
	 head = pananger->next;
	 int number=0;
	 while (head)
	 {
		 if (head->getFlight()!="")
		 {
			 cout << "�˿�������" << head->getNnme() << endl;
			 cout << "����Ʊ��" << head->getTitlenumber() << endl;
			 cout << "�����" << head->getFlight() << endl;
			 cout << endl;
			 number++;
		 }
		 head = head->next;
	 }
	 if (number==0)
	 {
		 cout << "���˶�Ʊ" << endl;
	 }
 }
 //�鿴������Ϣ
 void showairport(AriportRoutes *&airportrouts)
 {
	 for (int i = 0; i < SIZE; i++)
	 {
		 cout << "�յ�վ��" << airportrouts[i].getendden()<< endl;
		 cout << "����ţ�" << airportrouts[i].getflight() << endl;
		 cout << "�ɻ���" << airportrouts[i].getplane() << endl;
		 cout << "�������գ�" << airportrouts[i].getplanetime() << endl;
		 cout << "�˿Ͷ��" << airportrouts[i].getpangernumber() << endl;
		 cout << "ʣ��Ʊ��:" << airportrouts[i].getremain() << endl;
		 cout << endl;
	 }
 }

 