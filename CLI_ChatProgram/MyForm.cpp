#include "MyForm.h"



void CLIChatProgram::MyForm::P2P_Server()
{

	server_port = Int32::Parse(DC->server_port_textBox->Text);
	server_ipAddress = IPAddress::Parse(DC->server_ipAddress_textBox->Text);
	try {
		if (DC->server_state->InvokeRequired) {
			stateLabelDelegate^ invoker = (gcnew stateLabelDelegate(this, &MyForm::stateLabel));
			DC->server_state->ForeColor = SystemColors::ControlText.Green;
			DC->server_state->Invoke(invoker, DC->server_state, "サーバー立てました");

		}
		else {
			DC->server_state->ForeColor = SystemColors::ControlText.Green;
			DC->server_state->Text = "サーバー立てました";
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
	P2Pclient->Start();
}


System::Void CLIChatProgram::MyForm::button_connect_Click(System::Object^ sender, System::EventArgs^ e)
{
	P2Pclient->Start();
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