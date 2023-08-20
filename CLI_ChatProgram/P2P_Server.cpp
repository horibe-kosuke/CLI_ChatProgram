#include "P2P_Server.h"

P2P_Server::P2P_Server(DesignControls^ dc)
	:sever_thread(nullptr)
{
	DC = dc;
}

P2P_Server::~P2P_Server()
{
	if (sever_thread != nullptr) {
		listener->Stop();
		Server_Thread_State = false;
		sever_thread->Join(1000);
	}
}

void P2P_Server::Server_Stand()
{
	if (sever_thread == nullptr) {
		sever_thread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &P2P_Server::Server));
		sever_thread->Start();
	}
	else {
		listener->Stop();
		Server_Thread_State = false;
		if (sever_thread->Join(1000)) {
			sever_thread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &P2P_Server::Server));
			sever_thread->Start();
		}
		else {
			DC->server_state->Text = "サーバーエラー";
		}
	}
}

void P2P_Server::Server()
{
	server_port = System::Int32::Parse(DC->server_port_textBox->Text);
	server_ipAddress = System::Net::IPAddress::Parse(DC->server_ipAddress_textBox->Text);
	try {
		if (DC->server_state->InvokeRequired) {
			stateLabelDelegate^ invoker = (gcnew stateLabelDelegate(this, &P2P_Server::stateLabel));
			DC->server_state->ForeColor = System::Drawing::SystemColors::ControlText.Green;
			DC->server_state->Invoke(invoker, DC->server_state, "サーバー立てました");

		}
		else {
			DC->server_state->ForeColor = System::Drawing::SystemColors::ControlText.Green;
			DC->server_state->Text = "サーバー立てました";
		}



		listener = gcnew System::Net::Sockets::TcpListener(server_ipAddress, server_port);

		listener->Start();



		while (Server_Thread_State) {
			System::Net::Sockets::TcpClient^ client;
			System::Net::Sockets::NetworkStream^ stream;
			array<System::Byte>^ buffer = gcnew array<System::Byte>(1024);
			System::String^ message;
			client = listener->AcceptTcpClient();

			stream = client->GetStream();


			int byteread = stream->Read(buffer, 0, 1024);

			message = System::Text::Encoding::UTF8->GetString(buffer, 0, byteread);


			System::DateTime^ dt = gcnew System::DateTime;
			System::TimeSpan^ s = dt->TimeOfDay;
			System::String^ str = s->ToString();

			System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(dt->Now.ToString("HH:mm:ss"));

			item->Checked = true;
			item->SubItems->Add("受信:" + message);



			if (DC->listView1->InvokeRequired) {
				ListViewsDelegate^ invoker = (gcnew ListViewsDelegate(this, &P2P_Server::ListViews));
				DC->listView1->Invoke(invoker, item);

			}
			else {
				DC->listView1->Items->Add(item);
				int count = DC->listView1->Items->Count - 1;
				DC->listView1->EnsureVisible(count);
			}


			client->Close();
			stream->Close();
		}

	}
	catch (System::Net::Sockets::SocketException^) {

	}

}

void P2P_Server::stateLabel(System::Windows::Forms::Label^ label, System::String^ str)
{
	label->Text = DC->server_ipAddress_textBox->Text + str;
}

void P2P_Server::ListViews(System::Windows::Forms::ListViewItem^ item)
{
	DC->listView1->Items->Add(item);
	int count = DC->listView1->Items->Count - 1;
	DC->listView1->EnsureVisible(count);
}
