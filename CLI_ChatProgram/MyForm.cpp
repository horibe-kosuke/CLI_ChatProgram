#include "MyForm.h"


void CLIChatProgram::MyForm::P2P_Server()
{
	int port = 12345;
	IPAddress^ ipAddress = IPAddress::Parse("127.0.0.1");
	try {
		TcpListener^ listener = gcnew TcpListener(ipAddress, port);

		listener->Start();

		state->ForeColor=SystemColors::ControlText.Red;
		state->Text="接続中";

		while (true) {
			TcpClient^ client=listener->AcceptTcpClient();

			NetworkStream^ stream=client->GetStream();



			String^ str;
			array<Byte>^ buffer=gcnew array<Byte>(1024);
			str,stream->Read(buffer,0,1024);
		}
	}
	catch (SocketException^ e) {

	}
}

System::Void CLIChatProgram::MyForm::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

}

System::Void CLIChatProgram::MyForm::button_connect_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (comboBox1 != nullptr) {

		if (comboBox1->SelectedItem->ToString() == nullptr) {
			return;
		}

		String^ str = comboBox1->SelectedItem->ToString();
		if (str == comboBox1->Items[0]->ToString()) {
			state->ForeColor= SystemColors::ControlText.Green;
			state->Text = "サーバー立てました";
		}
	}
}



 
int main(array<System::String^>^args) {
	System::Windows::Forms::Application::Run(gcnew CLIChatProgram::MyForm);
	return 0;
}