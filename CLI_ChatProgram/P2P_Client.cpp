#include "P2P_Client.h"



P2P_Client::P2P_Client()
	: Client_State(false)
	, others_server_ipAddress(nullptr)
	, others_sever_port(1)
{

}

P2P_Client::~P2P_Client()
{
	this->Client_State = false;
	this->others_server_ipAddress = nullptr;
	this->others_sever_port = 1;
}

void P2P_Client::Start()
{
	if (Client_State == true) {
		this->SendDataToServer();
	}
	else {
		this->ConnectToServer();
	}
}

const bool P2P_Client::Get_Client_State()
{
	return Client_State;
}

void P2P_Client::SendDataToServer()
{
	//if (textBox1->Text != "" && Client_State == true) {
	//	DateTime^ dt = gcnew DateTime;
	//	TimeSpan^ s = dt->TimeOfDay;
	//	String^ str = s->ToString();

	//	ListViewItem^ item = gcnew ListViewItem(dt->Now.ToString("HH:mm:ss"));

	//	item->Checked = true;
	//	item->SubItems->Add("���M:" + textBox1->Text);

	//	listView1->Items->Add(item);

	//	int count = listView1->Items->Count - 1;
	//	listView1->EnsureVisible(count);



	//}

	//�\�P�b�g���쐬
	System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();

	//�ڑ���̃T�[�o�[�ɐڑ�
	client->Connect(others_server_ipAddress, others_sever_port);

	// �N���C�A���g�̃l�b�g���[�N�X�g���[�����擾(����M���邽�߂̂���)
	System::Net::Sockets::NetworkStream^ stream = client->GetStream();

	//���M����f�[�^��UTF-8�G���R�[�f�B���O�Ńo�C�g�z��ɕϊ�
	array<System::Byte>^ data = System::Text::Encoding::UTF8->GetBytes("�ڑ����܂����B");



	//���M
	stream->Write(data, 0, data->Length);

	//�\�P�b�g�����
	client->Close();

	// �X�g���[�������
	stream->Close();
}


void P2P_Client::ConnectToServer()
{
	//������ԐF�ɂ���
	label->ForeColor = System::Drawing::SystemColors::ControlText.Red;
	//�E�B���h�E��ɕ`��
	label->Text = "�ڑ���";

	//IP�A�h���X�擾
	others_server_ipAddress = System::Net::IPAddress::Parse(others_sever_ipAddress_textBox->Text);
	//�|�[�g�ԍ��擾
	others_sever_port = System::Int32::Parse(others_sever_port_textBox->Text);

	//�\�P�b�g���쐬
	System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();
	try {
		//�ڑ���̃T�[�o�[�ɐڑ�
		client->Connect(others_server_ipAddress, others_sever_port);

		//������ΐF�ɂ���
		label->ForeColor = System::Drawing::SystemColors::ControlText.Green;
		//�E�B���h�E��ɕ`��
		label->Text = "�ڑ����܂����B";

		// �N���C�A���g�̃l�b�g���[�N�X�g���[�����擾(����M���邽�߂̂���)
		System::Net::Sockets::NetworkStream^ stream = client->GetStream();

		//���M����f�[�^��UTF-8�G���R�[�f�B���O�Ńo�C�g�z��ɕϊ�
		array<System::Byte>^ data = System::Text::Encoding::UTF8->GetBytes("�ڑ����܂����B");

		//���M
		stream->Write(data, 0, data->Length);

		//�\�P�b�g�����
		client->Close();

		// �X�g���[�������
		stream->Close();

		//�ڑ��ł��Ă��邩��true
		Client_State = true;
	}
	catch (System::ArgumentNullException^) {
		//nullptr�̏ꍇ��O����

		//�\�P�b�g�����
		client->Close();

		//�ڑ��ł��ĂȂ�����false
		Client_State = false;
	}
	catch (System::Net::Sockets::SocketException^)
	{
		//�\�P�b�g�G���[�̏ꍇ��O����

		//�\�P�b�g�����
		client->Close();
		//�ڑ��ł��ĂȂ�����false
		Client_State = false;
	}
	catch (System::ObjectDisposedException^) {
		//�j�����ꂽ�I�u�W�F�N�g�ő��삪���s�����ƃX���[������O����

		//�\�P�b�g�����
		client->Close();
		//�ڑ��ł��ĂȂ�����false
		Client_State = false;
	}
}