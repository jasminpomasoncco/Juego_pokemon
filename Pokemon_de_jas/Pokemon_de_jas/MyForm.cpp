#include "MyForm.h"
#include<time.h>
using namespace System;
using namespace System::Windows::Forms;

void main() {

srand(time(NULL));
	Application::EnableVisualStyles;
	Application::Run(gcnew(Pokemondejas::MyForm));
}