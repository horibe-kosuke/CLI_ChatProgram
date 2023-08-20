#include "P2P_Server.h"

P2P_Server::P2P_Server(DesignControls^ dc)
	:sever_thread(nullptr)
{	
	//�f�U�C���R���g���[����DC�ɓ����DC�Ŏg����悤�ɂ��Ă���
	DC = dc;
}

P2P_Server::~P2P_Server()
{
	//�T�[�o�[�X���b�h���g���Ă��珉����
	if (sever_thread != nullptr) {
		//�N���C�A���g����̐ڑ��҂����~
		listener->Stop();
		//�X���b�h���I�����邽�߂�false
		Server_Thread_State = false;
		//�I��
		sever_thread->Join(1000);
	}
}

void P2P_Server::Server_Stand()
{
	//�T�[�o�[�X���b�h�̏�Ԃ��m�F
	if (sever_thread == nullptr) {
		sever_thread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &P2P_Server::Server));
		sever_thread->Start();
	}
	else {
		//�T�[�o�[�X���b�h���g���Ă��珉��������
		listener->Stop();
		Server_Thread_State = false;
		if (sever_thread->Join(1000)) {
			sever_thread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &P2P_Server::Server));
			sever_thread->Start();
		}
		else {
			DC->server_state->Text = "�T�[�o�[�G���[";
		}
	}
}

void P2P_Server::Server()
{
	//�T�[�o�[��IP�A�h���X���擾
	server_ipAddress = System::Net::IPAddress::Parse(DC->server_ipAddress_textBox->Text);
	//�T�[�o�[�̃|�[�g�ԍ��擾
	server_port = System::Int32::Parse(DC->server_port_textBox->Text);


	try {
		//���S��UI���A�N�Z�X����
		if (DC->server_state->InvokeRequired) {
			stateLabelDelegate^ invoker = (gcnew stateLabelDelegate(this, &P2P_Server::stateLabel));
			DC->server_state->ForeColor = System::Drawing::SystemColors::ControlText.Green;
			DC->server_state->Invoke(invoker, DC->server_state, "�T�[�o�[���Ă܂���");

		}
		else {
			DC->server_state->ForeColor = System::Drawing::SystemColors::ControlText.Green;
			DC->server_state->Text = "�T�[�o�[���Ă܂���";
		}



		listener = gcnew System::Net::Sockets::TcpListener(server_ipAddress, server_port);

		
		listener->Start();



		while (Server_Thread_State) {
			System::Net::Sockets::TcpClient^ client;
			System::Net::Sockets::NetworkStream^ stream;
			array<System::Byte>^ buffer = gcnew array<System::Byte>(1024);
			System::String^ message;

			//�N���C�A���g�̐ڑ��҂�
			client = listener->AcceptTcpClient();

			// �N���C�A���g�̃l�b�g���[�N�X�g���[�����擾(����M���邽�߂̂���)
			stream = client->GetStream();

			//��M
			int byteread = stream->Read(buffer, 0, 1024);

			//��M����f�[�^��UTF-8�G���R�[�f�B���O�Ńo�C�g�z��ɕϊ�
			message = System::Text::Encoding::UTF8->GetString(buffer, 0, byteread);

			//��/��/���Ԃ̎擾
			System::DateTime^ dt = gcnew System::DateTime;

			//���Ԃ����擾
			System::TimeSpan^ s = dt->TimeOfDay;

			//String�^�ɑ��
			System::String^ str = s->ToString();

			System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(dt->Now.ToString("HH:mm:ss"));

			item->Checked = true;
			//��M�������������X�g�r���[�A�C�e���ɒǉ�
			item->SubItems->Add("��M:" + message);


			//���S��UI���A�N�Z�X����
			if (DC->listView1->InvokeRequired) {
				ListViewsDelegate^ invoker = (gcnew ListViewsDelegate(this, &P2P_Server::ListViews));
				DC->listView1->Invoke(invoker, item);

			}
			else {
				DC->listView1->Items->Add(item);
				int count = DC->listView1->Items->Count - 1;
				DC->listView1->EnsureVisible(count);
			}

			//�\�P�b�g����
			client->Close();

			//�X�g���[�������
			stream->Close();
		}

	}
	catch (System::Net::Sockets::SocketException^) {

	}

}

void P2P_Server::stateLabel(System::Windows::Forms::Label^ label, System::String^ str)
{
	//�����`��
	label->Text = DC->server_ipAddress_textBox->Text + str;
}

void P2P_Server::ListViews(System::Windows::Forms::ListViewItem^ item)
{
	//���X�g�r���[�ɒǉ�
	DC->listView1->Items->Add(item);

	//���X�g�r���[�̍Ō�̍s���擾
	int count = DC->listView1->Items->Count - 1;

	//���X�g�r���[�̃X�N���[���ʒu���Ō�ɐݒ�
	DC->listView1->EnsureVisible(count);
}
