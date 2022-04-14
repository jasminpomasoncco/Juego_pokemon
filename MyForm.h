#pragma once
#include"Controladora.h"

namespace Pokemondejas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Controladora* objcontroladora;
		Bitmap^ imgpokebola;
		Bitmap^ imgpokemones;
		Bitmap^ imgpared;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(924, 554);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		objcontroladora = new Controladora(ClientRectangle.Width, ClientRectangle.Height);
		imgpokebola = gcnew Bitmap("Sprite\\pokebola.png");
		imgpokemones = gcnew Bitmap("Sprite\\Pokemon.png");
		imgpared = gcnew Bitmap("Sprite\\Pared.png");
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		Graphics^ g = this->CreateGraphics();
		BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(g, this->ClientRectangle);
		if (objcontroladora->ejecutar(buffer->Graphics, imgpokebola, imgpokemones, imgpared) == true) {
			timer1->Enabled = false;
			MessageBox::Show("pasaste los niveles :v ");
		}

		buffer->Render(g);
		delete buffer;
		delete g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:objcontroladora->movimiento_pikachu(1); break;
		case Keys::S:objcontroladora->movimiento_pikachu(2); break;
		case Keys::W:objcontroladora->movimiento_pikachu(3); break;
		case Keys::D:objcontroladora->movimiento_pikachu(4); break;

		default:
			break;
		}

	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		objcontroladora->movimiento_pikachu(5);

	}
	};

}
