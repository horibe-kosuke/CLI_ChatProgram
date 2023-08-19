#include "MyForm.h"



void CLIChatProgram::MyForm::P2P_Server()
{

	server_port = Int32::Parse(DC->server_port_textBox->Text);
	server_ipAddress = IPAddress::Parse(DC->server_ipAddress_textBox->Text);
	try {
		if (DC->server_state->InvokeRequired) {
			stateLabelDelegate^ invoker = (gcnew stateLabelDelegate(this, &MyForm::stateLabel));
			DC->server_state->ForeColor = SystemColors::ControlText.Green;
			DC->server_state->Invoke(invoker, DC->server_state, "�T�[�o�[���Ă܂���");

		}
		else {
			DC->server_state->ForeColor = SystemColors::ControlText.Green;
			DC->server_state->Text = "�T�[�o�[���Ă܂���";
		}



		listener = gcnew TcpListener(server_ipAddress, server_port);

		listener->Start();


		TcpClient^ client;
		NetworkStream^ stream;
		while (Server_Thread_State) {
			array<Byte>^ buffer = gcnew array<Byte>(1024);
			String^ message;
			client = listener->AcceptTcpClient();




			stream = client->GetStream();


			int byteread = stream->Read(buffer, 0, 1024);

			message = System::Text::Encoding::UTF8->GetString(buffer, 0, byteread);


			{
				DateTime^ dt = gcnew DateTime;
				TimeSpan^ s = dt->TimeOfDay;
				String^ str = s->ToString();

				ListViewItem^ item = gcnew ListViewItem(dt->Now.ToString("HH:mm:ss"));

				item->Checked = true;
				item->SubItems->Add("��M:" + message);



				if (DC->listView1->InvokeRequired) {
					ListViewsDelegate^ invoker = (gcnew ListViewsDelegate(this, &MyForm::ListViews));
					DC->listView1->Invoke(invoker, item);

				}
				else {
					DC->listView1->Items->Add(item);
					int count = DC->listView1->Items->Count - 1;
					DC->listView1->EnsureVisible(count);
				}

			}

			client->Close();
			stream->Close();
		}

		client->Close();
		stream->Close();
	}
	catch (SocketException^ e) {

	}


}


void CLIChatProgram::MyForm::P2P_Client_State()
{
	DC->state->ForeColor = SystemColors::ControlText.Red;
	DC->state->Text = "�ڑ���";


	others_sever_port = Int32::Parse(DC->others_sever_port_textBox->Text);
	others_server_ipAddress = IPAddress::Parse(DC->others_server_ipAddress_textBox->Text);

	TcpClient^ client = gcnew TcpClient();
	try {
		//�ڑ�
		client->Connect(others_server_ipAddress, others_sever_port);
		DC->state->ForeColor = SystemColors::ControlText.Green;
		DC->state->Text = "�ڑ����܂����B";
		NetworkStream^ stream = client->GetStream();

		array<Byte>^ data = Encoding::UTF8->GetBytes("�ڑ����܂����B");


		stream->Write(data, 0, data->Length);

		client->Close();
		stream->Close();

		Client_State = true;
	}
	catch (System::ArgumentNullException^) {
		client->Close();
		Client_State = false;
	}
	catch (SocketException^)
	{
		client->Close();
		Client_State = false;
	}
	catch (ObjectDisposedException^) {
		client->Close();
		Client_State = false;
	}
}

void CLIChatProgram::MyForm::P2P_Client_T() {
	TcpClient^ client = gcnew TcpClient();
	//�ڑ�
	client->Connect(others_server_ipAddress, others_sever_port);
	NetworkStream^ stream = client->GetStream();

	array<Byte>^ data = Encoding::UTF8->GetBytes(DC->textBox1->Text);


	stream->Write(data, 0, data->Length);

	client->Close();
	stream->Close();
}

void CLIChatProgram::MyForm::stateLabel(System::Windows::Forms::Label^ label, String^ str)
{

	label->Text = DC->server_ipAddress_textBox->Text + str;
}



void CLIChatProgram::MyForm::TimerCallback(Object^ sender, System::Timers::ElapsedEventArgs^ e)
{
	if (Server_Thread_State == false) {
		listener->Stop();
		sever_thread->Join(1000);
		sever_thread = nullptr;
		Server_Thread_State = true;
	}
}

void CLIChatProgram::MyForm::ListViews(ListViewItem^ item)
{
	DC->listView1->Items->Add(item);
	int count = DC->listView1->Items->Count - 1;
	DC->listView1->EnsureVisible(count);
}

System::Void CLIChatProgram::MyForm::Send_button_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (DC->textBox1->Text != "" && Client_State == true) {
		DateTime^ dt = gcnew DateTime;
		TimeSpan^ s = dt->TimeOfDay;
		String^ str = s->ToString();

		ListViewItem^ item = gcnew ListViewItem(dt->Now.ToString("HH:mm:ss"));

		item->Checked = true;
		item->SubItems->Add("���M:" + DC->textBox1->Text);

		DC->listView1->Items->Add(item);

		int count = DC->listView1->Items->Count - 1;
		DC->listView1->EnsureVisible(count);

		if (Client_State == true) {
			P2P_Client_T();
		}
		else {
			P2P_Client_State();
		}
	}
}


System::Void CLIChatProgram::MyForm::button_connect_Click(System::Object^ sender, System::EventArgs^ e)
{
	P2P_Client_State();
}



int main(array<System::String^>^ args) {

	CLIChatProgram::MyForm^ Form = gcnew CLIChatProgram::MyForm;
	System::Windows::Forms::Application::Run(Form);



	if (Form->sever_thread != nullptr) {
		Form->listener->Stop();
		Form->Server_Thread_State = false;
		auto a = Form->sever_thread->Join(1000);
	}

	return 0;
}