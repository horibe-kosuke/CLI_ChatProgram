#include "MyForm.h"



void CLIChatProgram::MyForm::P2P_Server()
{

	server_port = Int32::Parse(server_port_textBox->Text);
	server_ipAddress = IPAddress::Parse(server_ipAddress_textBox->Text);
	try {
		if (server_state->InvokeRequired) {
			stateLabelDelegate^ invoker = (gcnew stateLabelDelegate(this, &MyForm::stateLabel));
			server_state->ForeColor = SystemColors::ControlText.Green;
			server_state->Invoke(invoker, server_state, "サーバー立てました");

		}
		else {
			server_state->ForeColor = SystemColors::ControlText.Green;
			server_state->Text = "サーバー立てました";
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
				item->SubItems->Add("受信:" + message);



				if (listView1->InvokeRequired) {
					ListViewsDelegate^ invoker = (gcnew ListViewsDelegate(this, &MyForm::ListViews));
					listView1->Invoke(invoker, item);

				}
				else {
					listView1->Items->Add(item);
					int count = listView1->Items->Count - 1;
					listView1->EnsureVisible(count);
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
	state->ForeColor = SystemColors::ControlText.Red;
	state->Text = "接続中";


	others_sever_port = Int32::Parse(others_sever_port_textBox->Text);
	others_server_ipAddress = IPAddress::Parse(others_server_ipAddress_textBox->Text);

	TcpClient^ client = gcnew TcpClient();
	try {
		//接続
		client->Connect(others_server_ipAddress, others_sever_port);
		state->ForeColor = SystemColors::ControlText.Green;
		state->Text = "接続しました。";
		NetworkStream^ stream = client->GetStream();

		array<Byte>^ data = Encoding::UTF8->GetBytes("接続しました。");


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

void CLIChatProgram::MyForm::P2P_Client() {
	TcpClient^ client = gcnew TcpClient();
	//接続
	client->Connect(others_server_ipAddress, others_sever_port);
	NetworkStream^ stream = client->GetStream();

	array<Byte>^ data = Encoding::UTF8->GetBytes(textBox1->Text);


	stream->Write(data, 0, data->Length);

	client->Close();
	stream->Close();
}

void CLIChatProgram::MyForm::stateLabel(System::Windows::Forms::Label^ label, String^ str)
{

	label->Text = server_ipAddress_textBox->Text + str;
}

void CLIChatProgram::MyForm::P2P_Disconnection()
{
	if (others_server_ipAddress_textBox->Text == "" && others_sever_port_textBox->Text == "")return;

	others_sever_port = Int32::Parse(others_sever_port_textBox->Text);
	others_server_ipAddress = IPAddress::Parse(others_server_ipAddress_textBox->Text);

	TcpClient^ client = gcnew TcpClient();

	try {
		//接続
		client->Connect(others_server_ipAddress, others_sever_port);

		NetworkStream^ stream = client->GetStream();

		array<Byte>^ data = Encoding::UTF8->GetBytes("");


		stream->Write(data, 0, data->Length);

		client->Close();
		stream->Close();

	}
	catch (System::ArgumentNullException^) {
		client->Close();
	}
	catch (SocketException^)
	{
		client->Close();
	}
	catch (ObjectDisposedException^) {
		client->Close();
	}
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
	listView1->Items->Add(item);
	int count = listView1->Items->Count - 1;
	listView1->EnsureVisible(count);
}

System::Void CLIChatProgram::MyForm::Send_button_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (textBox1->Text != "" && Client_State == true) {
		DateTime^ dt = gcnew DateTime;
		TimeSpan^ s = dt->TimeOfDay;
		String^ str = s->ToString();

		ListViewItem^ item = gcnew ListViewItem(dt->Now.ToString("HH:mm:ss"));

		item->Checked = true;
		item->SubItems->Add("送信:" + textBox1->Text);

		listView1->Items->Add(item);

		int count = listView1->Items->Count - 1;
		listView1->EnsureVisible(count);

		if (Client_State == true) {
			P2P_Client();
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

	if (Form->client_thread != nullptr) {
		Form->client_thread->Join();
	}

	return 0;
}