#include "P2P_Client.h"



P2P_Client::P2P_Client(DesignControls^ dc)
	: Client_State(false)
	, others_server_ipAddress(nullptr)
	, others_sever_port(1)
{
	DC=dc;
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
		//�ڑ����Ă���Ƃ�
		this->SendDataToServer();
	}
	else {
		//�ڑ����ĂȂ��Ƃ�
		this->ConnectToServer();
	}
}

void P2P_Client::Disconnection()
{
	//�ڑ���ɐڑ������Ƃ������ؒf����
	if (Client_State == true) {

		//�\�P�b�g�쐬
		System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();

		//�ڑ���̃T�[�o�[�ɐڑ�
		client->Connect(others_server_ipAddress, others_sever_port);

		// �N���C�A���g�̃l�b�g���[�N�X�g���[�����擾(����M���邽�߂̂���)
		System::Net::Sockets::NetworkStream^ stream = client->GetStream();

		//���M����f�[�^��UTF-8�G���R�[�f�B���O�Ńo�C�g�z��ɕϊ�
		array<System::Byte>^ data = System::Text::Encoding::UTF8->GetBytes("�ؒf����܂����B");


		//���M
		stream->Write(data, 0, data->Length);

		//�\�P�b�g�����
		client->Close();

		// �X�g���[�������
		stream->Close();

		//�����̐F��F�ɂ���
		DC->state->ForeColor = System::Drawing::SystemColors::ControlText.Blue;
		//�E�B���h�E��ɕ����`��
		DC->state->Text = "�ؒf���܂����B";

		//�ڑ����Ă��Ȃ��̂�false
		Client_State = false;
	}
}

const bool P2P_Client::Get_Client_State()
{
	return Client_State;
}

void P2P_Client::SendDataToServer()
{
	if (DC->textBox1->Text != "" && Client_State == true) {
		//��/��/���Ԃ̎擾
		System::DateTime^ dt = gcnew System::DateTime;

		//���Ԃ����擾
		System::TimeSpan^ s = dt->TimeOfDay;

		//String�^�ɑ��
		System::String^ str = s->ToString();

		//���X�g�r���[�A�C�e����(��:��;�b)����
		System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(dt->Now.ToString("HH:mm:ss"));

		//�A�C�e���̃`�F�b�N��ݒ�
		item->Checked = true;

		//���X�g�r���[�̃T�u�A�C�e���Ƀe�L�X�g�ǉ�
		item->SubItems->Add("���M:" + DC->textBox1->Text);

		//���Ԃ�ǉ�
		DC->listView1->Items->Add(item);

		//���X�g�r���[�̍Ō�̍s���擾
		int count = DC->listView1->Items->Count - 1;

		//�X�N���[���ʒu�͍Ō�̈ʒu
		DC->listView1->EnsureVisible(count);


		//�\�P�b�g���쐬
		System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();

		//�ڑ���̃T�[�o�[�ɐڑ�
		client->Connect(others_server_ipAddress, others_sever_port);

		// �N���C�A���g�̃l�b�g���[�N�X�g���[�����擾(����M���邽�߂̂���)
		System::Net::Sockets::NetworkStream^ stream = client->GetStream();

		//���M����f�[�^��UTF-8�G���R�[�f�B���O�Ńo�C�g�z��ɕϊ�
		array<System::Byte>^ data = System::Text::Encoding::UTF8->GetBytes(DC->textBox1->Text);



		//���M
		stream->Write(data, 0, data->Length);

		//�\�P�b�g�����
		client->Close();

		// �X�g���[�������
		stream->Close();

	}


}


void P2P_Client::ConnectToServer()
{
	//������ԐF�ɂ���
	DC->state->ForeColor = System::Drawing::SystemColors::ControlText.Red;
	//�E�B���h�E��ɕ`��
	DC->state->Text = "�ڑ���";

	//IP�A�h���X�擾
	others_server_ipAddress = System::Net::IPAddress::Parse(DC->others_server_ipAddress_textBox->Text);
	//�|�[�g�ԍ��擾
	others_sever_port = System::Int32::Parse(DC->others_sever_port_textBox->Text);

	//�\�P�b�g���쐬
	System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();
	try {
		//�ڑ���̃T�[�o�[�ɐڑ�
		client->Connect(others_server_ipAddress, others_sever_port);

		//������ΐF�ɂ���
		DC->state->ForeColor = System::Drawing::SystemColors::ControlText.Green;
		//�E�B���h�E��ɕ`��
		DC->state->Text = "�ڑ����܂����B";

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