#include "MyForm.h"

using namespace WSIZ_Project3_Mastermind_G;

[STAThread]
void Main(array<String^>^ args)
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);

  MyForm form;
  Application::Run(%form);
}

