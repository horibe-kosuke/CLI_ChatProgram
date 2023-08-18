#include "MyForm.h"



void CLIChatProgram::MyForm::P2P_Server()
{

	int port = 12345;
	server_ipAddress = IPAddress::Parse(server_ipAddress_textBox->Text);
	try {
		if (state->InvokeRequired) {
			stateLabelDelegate^ invoker = (gcnew stateLabelDelegate(this, &MyForm::stateLabel));
			state->Invoke(invoker, "接続中");

		}
		else {
			state->ForeColor = SystemColors::ControlText.Red;
			state->Text = "接続中";
		}



		listener = gcnew TcpListener(server_ipAddress, port);

		listener->Start();




		while (Thread_State) {



			array<Byte>^ buffer = gcnew array<Byte>(1024);
			String^ message;
			TcpClient^ client = listener->AcceptTcpClient();



			if (state->InvokeRequired) {
				stateLabelDelegate^ invoker = (gcnew stateLabelDelegate(this, &MyForm::stateLabel));
				state->ForeColor = SystemColors::ControlText.Green;
				state->Invoke(invoker, "接続しました。");
			}
			else {
				state->ForeColor = SystemColors::ControlText.Green;
				state->Text = "接続しました。";
			}



			NetworkStream^ stream = client->GetStream();


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


	}
	catch (SocketException^ e) {

	}


}


void CLIChatProgram::MyForm::P2P_Client()
{

	int port = 12345;
	others_server_ipAddress = IPAddress::Parse(others_server_ipAddress_textBox->Text);

	TcpClient^ client = gcnew TcpClient();

	//接続
	client->Connect(others_server_ipAddress, port);

	NetworkStream^ stream = client->GetStream();;

	array<Byte>^ data = Encoding::UTF8->GetBytes(textBox1->Text);


	stream->Write(data, 0, data->Length);

	client->Close();
	stream->Close();
}

void CLIChatProgram::MyForm::stateLabel(String^ str)
{
	state->Text = str;
}

void CLIChatProgram::MyForm::ListViews(ListViewItem^ item)
{
	listView1->Items->Add(item);
	int count = listView1->Items->Count - 1;
	listView1->EnsureVisible(count);
}

System::Void CLIChatProgram::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	DateTime^ dt = gcnew DateTime;
	TimeSpan^ s = dt->TimeOfDay;
	String^ str = s->ToString();

	ListViewItem^ item = gcnew ListViewItem(dt->Now.ToString("HH:mm:ss"));

	item->Checked = true;
	item->SubItems->Add("送信" + textBox1->Text);

	listView1->Items->Add(item);

	int count = listView1->Items->Count - 1;
	listView1->EnsureVisible(count);

	P2P_Client();
}


System::Void CLIChatProgram::MyForm::button_connect_Click(System::Object^ sender, System::EventArgs^ e)
{

	//サーバー側かクライアント側を決めている
	if (comboBox1 != nullptr) {

		if (comboBox1->SelectedItem->ToString() == nullptr) {
			return;
		}

		String^ str = comboBox1->SelectedItem->ToString();



		//サーバー側
		if (str == comboBox1->Items[0]->ToString()) {

			if (sever_thread == nullptr) {
				sever_thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::P2P_Server));
				sever_thread->Start();


			}
		}
		//クライアント側
		else if (str == comboBox1->Items[1]->ToString()) {
			if (sever_thread == nullptr) {
				sever_thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::P2P_Server));
				sever_thread->Start();

			}

		}
	}
}



int main(array<System::String^>^ args) {

	CLIChatProgram::MyForm^ Form = gcnew CLIChatProgram::MyForm;
	System::Windows::Forms::Application::Run(Form);



	if (Form->sever_thread != nullptr) {
		Form->listener->Stop();
		Form->Thread_State = false;
		auto a = Form->sever_thread->Join(1000);
	}

	if (Form->client_thread != nullptr) {
		Form->client_thread->Join();
	}

	return 0;
}