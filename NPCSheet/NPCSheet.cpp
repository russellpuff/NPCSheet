// NPCSheet.cpp - Contains main() and nothing else.
// NPCSheet by Benjamin Russell
// This application allows you to create generic NPC character sheets, supporting a variety of d20 tabletop game systems.

#include "CoreForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	NPCSheet::CoreForm f;
	Application::Run(% f);
}