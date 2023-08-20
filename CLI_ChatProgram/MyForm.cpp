#include "MyForm.h"



void CLIChatProgram::MyForm::P2P_Server_T()
{

	

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





	return 0;
}